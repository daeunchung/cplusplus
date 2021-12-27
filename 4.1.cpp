/*
4.1 
�迭�� �̸��� �迭�� ����� �޸��� ���θ� ����Ű�� ���(constant)�������̴�.
�ε��� ������[] : array[n] == *(array+n) 

4.3 �̷� ǥ���� �׸���
 1 �� 0 ��
 enum{ UP=1, RIGHT=2, DOWN=4, LEFT=8 };	�����ؼ� ����ġ�� �ڵ�� ����� ����
 		2^0		2^1		2^2		2^3
		 bit������ ��Ÿ�����ÿ� ��bit�� �ϳ��� ������ ���� �� �ֵ��� 
		 ���������� �ߺ��ؼ� ǥ���� �� �ֵ��� ���⿡ ���� �ο��� ���̴�. ***��ũ��*** 
 
 ex) UP|RIGHT|LEFT = 1+2+8 = 11 = 1011(bit) = �Ǹ��
		(����ġ)	   		(�ڵ�)	  		  (���) 
 0 1 0
 1 1 1
 0 0 0 �϶� �Ǹ��
 
 �̷α׸��� �Լ��� 
  CMaze::GetShape ������ ����ġ�� ���� ������ڵ� ����
  CMaze::DrawMaze GetShape�̿��Ͽ� ������ �̷θ� �׸��� 
  
  shape |= UP; 	// |= OR ������ .... ó������

*/

// ��1 ���0 
int CMaze::GetShape(int x, int y){
	int shape = 0;
	if(m_arrayMaze[y][x] != 0){				// ���� ��������
		if(y>0 && m_arrayMaze[y-1][x])					// ���ʿ� ���� �ֳ�? 
			shape |= UP;
		if(y<MAZE_SIZE-1 && m_arrayMaze[y+1][x])		// �Ʒ��ʿ� ���� �ֳ�? 
			shape |= DOWN;
		if(x>0 && m_arrayMaze[y][x-1])					// ���ʿ� ���� �ֳ�? 
			shape |= LEFT;
		if(x<MAZE_SIZE-1 && m_arrayMaze[y][x+1])		// �����ʿ� ���� �ֳ�? 
			shape |= RIGHT;
	}
	return shape;	
} 
 
// ***�����ڵ���� Windows MFC���α׷��� �ڵ���̱� ������ ������ �ý��ۺ������� ����
// �̷��� ����� �׸��� �׷��ִ� �κ��� MFC���¸� ������ �� �� �ִ� �κ�
// https://master-hun.tistory.com/74    DC CDC ���伳��
 
bool CMaze::DrawMaze(){
	// assertion
	if(!m_pwndDraw)
		return false;
	// DC�� ��´�
	CDC *pdc = m_pwndDraw->GetDC();
	if(!pdc)
		return false;
	// �� �̹����� �ε��Ͽ� �޸�DC�� �ִ´�
	CDC dcMem;
	dcMem.CreateCompatibleDC(pdc);
	CBitmap bmpWall;
	CBitmap *pdmp0ld;
	bmpWall.LoadBitmap(IDB_WALL); // IDB_WALL�� 16pix�� �׷��� �̷κ� �̹������� 
	pbmp0ld = dcMem.SelectObject(&bmpWall);
	// �̷θ� �׸���
	int i, j;
	for(j=0; j<MAZE_SIZE; j++){
		for(i=0; i<MAZE_SIZE; i++){
			int shape = GetShape(i, j); // �ֺ�����翡 ���� ���� ������ �Ǿ���ϴ��� �޴°� 
			pdc->BitBlt(i*16, j*16, 16, 16, &dcMem, shape*16, 0, SRCC0PY);
			// BitBlt() : �� Bitmap�׸����� �ٸ� Bitmap�׸����� �����ϴ� �Լ� 
		} 
	} 
	// ����� ���ҽ����� �����Ѵ�
	dcMem.SelectObject(pbmp0ld);
	bmpWall.DeleteObject();
	m_pwndDraw->ReleaseDC(pdc);
	m_pwndDraw->ReleaseDC(&dcMem);
	return false;
}

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

