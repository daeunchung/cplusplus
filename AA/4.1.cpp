/*
4.1 
배열의 이름은 배열이 저장된 메모리의 선두를 가리키는 상수(constant)포인터이다.
인덱스 연산자[] : array[n] == *(array+n) 

4.3 미로 표현과 그리기
 1 벽 0 길
 enum{ UP=1, RIGHT=2, DOWN=4, LEFT=8 };	조합해서 벽배치의 코드와 모양을 생성
 		2^0		2^1		2^2		2^3
		 bit단위로 나타냈을시에 한bit가 하나의 방향을 뜻할 수 있도록 
		 여러방향을 중복해서 표현할 수 있도록 방향에 값을 부여한 것이다. ***테크닉*** 
 
 ex) UP|RIGHT|LEFT = 1+2+8 = 11 = 1011(bit) = ㅗ모양
		(벽배치)	   		(코드)	  		  (모양) 
 0 1 0
 1 1 1
 0 0 0 일때 ㅗ모양
 
 미로그리기 함수들 
  CMaze::GetShape 주위의 벽배치에 따라 벽모양코드 리턴
  CMaze::DrawMaze GetShape이용하여 실제로 미로를 그린다 
  
  shape |= UP; 	// |= OR 연산자 .... 처음본다

*/

// 벽1 통로0 
int CMaze::GetShape(int x, int y){
	int shape = 0;
	if(m_arrayMaze[y][x] != 0){				// 벽이 있을때만
		if(y>0 && m_arrayMaze[y-1][x])					// 위쪽에 벽이 있나? 
			shape |= UP;
		if(y<MAZE_SIZE-1 && m_arrayMaze[y+1][x])		// 아랫쪽에 벽이 있나? 
			shape |= DOWN;
		if(x>0 && m_arrayMaze[y][x-1])					// 왼쪽에 벽이 있나? 
			shape |= LEFT;
		if(x<MAZE_SIZE-1 && m_arrayMaze[y][x+1])		// 오른쪽에 벽이 있나? 
			shape |= RIGHT;
	}
	return shape;	
} 
 
// ***예시코드들은 Windows MFC프로그래밍 코드들이기 때문에 윈도우 시스템변수들이 나옴
// 미로의 벽모양 그림을 그려주는 부분은 MFC강좌를 들으면 알 수 있는 부분
// https://master-hun.tistory.com/74    DC CDC 개념설명
 
bool CMaze::DrawMaze(){
	// assertion
	if(!m_pwndDraw)
		return false;
	// DC를 얻는다
	CDC *pdc = m_pwndDraw->GetDC();
	if(!pdc)
		return false;
	// 벽 이미지를 로드하여 메모리DC에 넣는다
	CDC dcMem;
	dcMem.CreateCompatibleDC(pdc);
	CBitmap bmpWall;
	CBitmap *pdmp0ld;
	bmpWall.LoadBitmap(IDB_WALL); // IDB_WALL은 16pix로 그려진 미로벽 이미지파일 
	pbmp0ld = dcMem.SelectObject(&bmpWall);
	// 미로를 그린다
	int i, j;
	for(j=0; j<MAZE_SIZE; j++){
		for(i=0; i<MAZE_SIZE; i++){
			int shape = GetShape(i, j); // 주변벽모양에 따라 내가 어떤모양이 되어야하는지 받는것 
			pdc->BitBlt(i*16, j*16, 16, 16, &dcMem, shape*16, 0, SRCC0PY);
			// BitBlt() : 한 Bitmap그림에서 다른 Bitmap그림으로 복사하는 함수 
		} 
	} 
	// 사용한 리소스들을 정리한다
	dcMem.SelectObject(pbmp0ld);
	bmpWall.DeleteObject();
	m_pwndDraw->ReleaseDC(pdc);
	m_pwndDraw->ReleaseDC(&dcMem);
	return false;
}

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

