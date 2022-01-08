///*
//https://m.blog.naver.com/PostView.naver?blogId=ndb796&logNo=221282210534&navType=by
//여러 개의 데이터가 연속적으로 존재할 때 특정하나 범위의 데이터의 합을 구하는 방법
//수열의 구간합 구할때 가장 빠르고 간단
//
//                              66(1)
//                30(2)                          36(3)
//         13(4)          17(5)            24(6)         12(7)
//    10(8)   3(9)   12(10)   5(11)    14(12)  10(13)  7(14)  5(15)
// 1(16)9(17)      8(20)4(21)       5(24)9(25)      3(28)4(29)
//
//구간 합 트리에 한해서는 인덱스 번호가 1부터 시작. 자식 노드가 2n, 2n+1 로 가도록.
//데이터의 개수가 N개일때 N보다 큰 가장 가까운 제곱수를 구한 뒤에 그것의 2배까지 미리 배열의 크기를 확보해놓아야함
//e.g) 데이터 12개 -> 16*2 (32) 공간확보 필요
//구간 합 트리는 반복적으로 보다 재귀적으로 구현하는 것이 간단하다
//*/
//
//
//// 1. 구간합투리 생성하기   start :시작인덱스, end:끝인덱스
//int init(int start, int end, int node)
//{
//    if (start == end) return tree[node] = a[start];
//    int mid = (start + end) / 2;
//    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
//}
//
//// 2. 구간 합을 구하는 함수 만들기   start,end:시작(1),끝(29) / left,right:구간 합을 구하고자 하는범위
//int sum(int start, int end, int node, int left, int right)
//{
//    if (left > end || right < start) return 0;
//    if(left )
//}
//
//// 3. 특정 원소의 값을 수정하는 함수 만들기 (밑에 하나 수정하면 위에 부분합 줄줄이 수정)
//
