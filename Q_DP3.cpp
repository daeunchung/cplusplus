/*
 원래는 Top-Down방식(재귀, 순환알고리즘방식)말고 
 1차원배열, 2차원배열, python list등을 사용하는 
 Bottom-Up 방식을 Dynamic Programming 동적계획법이라고 부른다
 그래서 Top-Down을 DP가 아니라고 보는 이들도 많다
 그러나 Top-Down방식 수행시에 메모이제이션으로 배열에 저장하여 Cut Edge 하고
 재귀가 뻗어나가는 방식이 점화식과 유사하여 넓은 의미로 DP로 보는 것
 Bottom-Up이 진짜 DP이고, Top-Down은 넓은의미에서 DP이다. 
 
 도전과제 : 계단오르기 , 돌다리 건너기
 f(n) = f(n-1) + f(n-2)
*/
