/* 4.4 �̷�Ž�� �˰���
 Ž�� �˰��� : �켱�� (Right Hand On Wall) 
  ������ �������� �켱������ ������ ��� ����. �������� ���� ��� ���� 
  up 1 right 2 down 4 left 8 bit������ >> <<�� �������� �����ϰ� ���ֱ� ���� �ǵ����� ���ο� 

 ���׿����� A?B:C == if A then B else C 
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
	
	// ����׸���
	DrawMouse(x, y, dir);
	Sleep(DELAY);			// �ð� ����
	Record(x, y);
	
//	GoForward(x, y, dir);	// ������ ���� 
	while(Still_In_Maze(x, y)){
		Turn_Right(dir);
		DrawMouse(x, y, dir);
		Sleep(DELAY);
		while(Wall_Ahead(x, y, dir)){
			Turn_Left(dir);
			DrawMouse(x, y, dir);
			Sleep(DELAY);
		}
		// ������ �����
		DrawMouse(x, y, 0); 
		
		// �̵� 
		Go_Forward(x, y, dir);
		Record(x, y);		// ���ο� ��ǥ ��� 
		DrawMouse(x, y, dir);
		Sleep(DELAY);
	}
	// Ž�� ��
	Record(-1, -1); 
}
bool CMaze::Record(int x, int y){
	if(m_indexRecord > MAZE_SIZE*MAZE_SIZE*2-3)	// �����÷ο� �߻�
		return false;
	m_arrayRecord[m_indexRecord++] = x; 
	m_arrayRecord[m_indexRecord++] = y;
	return true; 
}
void CMaze::InitRecord(){
	// �ʱ�ȭ
	memset(m_arrayRecord, -1, sizeof(m_arrayRecord));
	m_indexRecord = 0; 
}
int CMaze::DeletePath(int i, int j){
	int k = i;
	while(m_arrayRecord[j] > 0)
		m_arrayRecord[i++] = m_arrayRecord[j++];
	m_arrayRecord[i] = -1;
	m_arrayRecord[i+1] = -1;
	return k;	// k�� �����ǰ� �� ��, j�� ������ �� �� 
}


/* 4.5 �ִܰ�� ã��
�켱�� ���� ������ ��ǥ ����Ʈ�� ����
����� ��ǥ����Ʈ���� �ߺ��Ǵ� ��ǥ�κ��� �߶󳽴� 
��, ���ٰ� ������ ������ �ٽ� ���ƿ��� �κ��� �߶� �ָ� ��Ŵ� �κ� ��� �����Ǿ� �ִ� ��ΰ� �ȴ�.
 
�ִܰ�θ� �������迭�� x,y������ ���ʷ� ����. �������� -1, -1�� ��
*/
void CMaze::ShortestPath(){
	int i, j=0;
	int x, y;
	int x1, y1;
	while(m_arrayRecord[i] >= 0){
		x = m_arrayRecord[i];
		y = m_arrayRecord[i+1];
		j = i+2;				// �� ��ǥ�� �ΰ��� �����̹Ƿ� ������ǥ�� +2
		while(m_arrayRecord[j] >= 0){
			x1 = m_arrayRecord[j];
			y1 = m_arrayRecord[j+1];
			if(x==x1 && y==y1)	// ���� ��ǥ �߰ߵǸ� �ߺ� ��� ����
				j = DeletePath(i, j);
			j+=2; 
		} 
		i+=2;
	}
}
