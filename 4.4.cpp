/* 4.4 미로탐색 알고리즘
 탐색 알고리즘 : 우선법 (Right Hand On Wall) 
  갈림길 만났을때 우선적으로 오른쪽 길로 간다. 오른손을 벽에 대고 가기 
  up 1 right 2 down 4 left 8 bit연산자 >> <<로 값변경을 수월하게 해주기 위해 의도적인 값부여 

 삼항연산자 A?B:C == if A then B else C 
*/

void CMaze::GoForward(int &x, int &y, int dir){			// call by reference
	x = (dir==LEFT ? --x : dir==RIGHT ? ++x : x);
	y = (dir==UP ? --y : dir==DOWN ? ++y : y);
}
bool CMaze::StillInMaze(int x, int y){
	if(x>0 && x<MAZE_SIZE-1 && y>0 && y<MAZE_SIZE-1) return true;
	else return false;
}
bool CMaze::WallAhead(int x, int y, int dir){			// call by value
	x = (dir==LEFT ? --x : dir==RIGHT ? ++x : x);
	y = (dir==UP ? --y : dir==DOWN ? ++y : y);
	return m_arrayMaze[y][x] != 0;
}
void CMaze::TurnLeft(int &dir){
	dir >>= 1;
	dir = (dir==0 ? LEFT : dir);
}
void CMaze::TurnRight(int &dir){
	dir <<= 1;
	dir = (dir>LEFT ? UP : dir);
}

#define DELAY 100	// 100 msec
void CMaze::RightHandOnWall(int x, int y, int dir){
	
	InitRecord();
	
	// 생쥐그리기
	DrawMouse(x, y, dir);
	Sleep(DELAY);			// 시간 지연
	Record(x, y);
	
//	GoForward(x, y, dir);	// 앞으로 전진 
	while(Still_In_Maze(x, y)){
		Turn_Right(dir);
		DrawMouse(x, y, dir);
		Sleep(DELAY);
		while(Wall_Ahead(x, y, dir)){
			Turn_Left(dir);
			DrawMouse(x, y, dir);
			Sleep(DELAY);
		}
		// 이전거 지우고
		DrawMouse(x, y, 0); 
		
		// 이동 
		Go_Forward(x, y, dir);
		Record(x, y);		// 새로운 좌표 기록 
		DrawMouse(x, y, dir);
		Sleep(DELAY);
	}
	// 탐색 끝
	Record(-1, -1); 
}
bool CMaze::Record(int x, int y){
	if(m_indexRecord > MAZE_SIZE*MAZE_SIZE*2-3)	// 오버플로우 발생
		return false;
	m_arrayRecord[m_indexRecord++] = x; 
	m_arrayRecord[m_indexRecord++] = y;
	return true; 
}
void CMaze::InitRecord(){
	// 초기화
	memset(m_arrayRecord, -1, sizeof(m_arrayRecord));
	m_indexRecord = 0; 
}
int CMaze::DeletePath(int i, int j){
	int k = i;
	while(m_arrayRecord[j] > 0)
		m_arrayRecord[i++] = m_arrayRecord[j++];
	m_arrayRecord[i] = -1;
	m_arrayRecord[i+1] = -1;
	return k;	// k는 삭제되고 난 뒤, j가 가져야 할 값 
}


/* 4.5 최단경로 찾기
우선법 진행 과정의 좌표 리스트를 저장
저장된 좌표리스트에서 중복되는 좌표부분을 잘라낸다 
즉, 갔다가 벽으로 막혀서 다시 돌아오는 부분을 잘라내 주면 헤매는 부분 모두 삭제되어 최단 경로가 된다.
 
최단경로를 일차원배열에 x,y순으로 차례로 넣음. 마지막은 -1, -1로 함
*/
void CMaze::ShortestPath(){
	int i, j=0;
	int x, y;
	int x1, y1;
	while(m_arrayRecord[i] >= 0){
		x = m_arrayRecord[i];
		y = m_arrayRecord[i+1];
		j = i+2;				// 한 좌표가 두개의 정수이므로 다음좌표는 +2
		while(m_arrayRecord[j] >= 0){
			x1 = m_arrayRecord[j];
			y1 = m_arrayRecord[j+1];
			if(x==x1 && y==y1)	// 같은 좌표 발견되면 중복 경로 삭제
				j = DeletePath(i, j);
			j+=2; 
		} 
		i+=2;
	}
}
