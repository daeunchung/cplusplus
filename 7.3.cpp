#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

/* 7.3
 BinaryTree Skeleton
	Tree Traversal : Tree자료구조는 비선형구조여서 전체노드를 방문하는 방법이 필요
	Stack기반 : Pre-order, Post-order, In-order
	Queue기반 : Level-order
*/

template <class TYPE> 
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	void RemoveAll();
protected:
	struct Node {
		TYPE data;
		Node* pLeft;
		Node* pRight;
	};
	Node* m_pNodeHead;
	Node* m_pNodeTail;
	void RemoveSubtree(Node *pNode);
	void PreOrderTraverse(Node * pNode);
	void InOrderTraverse(Node * pNode);
	void PostOrderTraverse(Node * pNode);

};

template<class TYPE>
BinaryTree<TYPE>::BinaryTree()
{
	m_pNodeHead = new Node;
	m_pNodeTail = new Node;

	m_pNodeHead->pLeft = m_pNodeTail
	m_pNodeHead->pRight = m_pNodeTail;

	m_pNodeTail->pLeft = m_pNodeTail
	m_pNodeTail->pRight = m_pNodeTail;
}

template<class TYPE>
BinaryTree<TYPE>::~BinaryTree()
{
	RemoveAll;
	if (m_pNodeHead) delete m_pNodeHead;
	if (m_pNodeTail) delete m_pNodeTail;
}

// Post-Order Traverse를 이용하여 모든 노드 삭제. 부모노드는 자식에 대한 정보를 가지고 있기 때문에 가장 나중에 삭제되어야 함
template<class TYPE>
void BinaryTree<TYPE>::RemoveAll()
{
	RemoveSubtree(m_pNodeHead->pLeft);
	m_pNodeHead->pLeft = m_pNodeTail;
}


template<class TYPE>
void BinaryTree<TYPE>::RemoveSubtree(Node * pNode)
{
	if (pNode != m_pNodeTail) {
		RemoveSubtree(pNode->pLeft);
		RemoveSubtree(pNode->pRight);
		delete pNode;	// Visit대신 delete
	}
}

template<class TYPE>
void BinaryTree<TYPE>::PreOrderTraverse(Node *pNode)
{
	if (pNode != m_pNodeTail) {
		Visit(pNode);
		PreOrderTraverse(pNode->pLeft);
		PreOrderTraverse(pNode->pRight);
	}
}

template<class TYPE>
void BinaryTree<TYPE>::InOrderTraverse(Node *pNode)
{
	if (pNode != m_pNodeTail) {
		InOrderTraverse(pNode->pLeft);
		Visit(pNode);
		InOrderTraverse(pNode->pRight);
	}
}

template<class TYPE>
void BinaryTree<TYPE>::PostOrderTraverse(Node *pNode)
{
	if (pNode != m_pNodeTail) {
		PostOrderTraverse(pNode->pLeft);
		PostOrderTraverse(pNode->pRight);
		Visit(pNode);
	}
}

/* 7.4
   Pre-order Traversal : Stack 버전
	일반적으로 stack을 사용하여 non-recursive방식으로 바꿀 수 있다.
	Post-Order, In-Order는 다소 복잡함!

   Level-Order Traversal : Queue 사용
	가장 직관적인 순회. 위에서 아래로, 좌에서 우로 진행
*/
template<class TYPE>
void BinaryTree<TYPE>::PreOrderTraverse_Stack(Node *pNode)
{
	ListStack<Node*> stack;
	stack.push(pNode);
	while (!stack.IsEmpty())
	{
		pNode = stack.Pop();
		if (pNode != m_pNodeTail)
		{
			Visit(pNode);
			stack.Push(pNode->pRight);
			stack.Push(pNode->pLeft);
		}
	}
}

template<class TYPE>
void BinaryTree<TYPE>::LevelOrderTraverse(Node *pNode)
{
	ListQueue<Node*> queue;
	queue.Put(pNode);
	while (!queue.IsEmpty())
	{
		pNode = queue.Get();
		if (pNode != m_pNodeTail)
		{
			Visit(pNode);
			queue.Put(pNode->pLeft);
			queue.Put(pNode->pRight);
		}
	}
}

/* 7.5
수식트리 Parse Tree
수식을 연산순서에 따라 트리로 구성
Root에 Operator연산자, Child에 Operand피연산자 배치
모든 Operator는 Non-Terminal, Operand는 Terminal Node

((A+B)*(C-D))/E+(F*G)
수식트리를 In-Order Traverse하면 Infix Notation
수식트리를 Pre-Order Traverse하면 Prefix Notation
수식트리를 Post-Order Traverse하면 Postfix Notation

후위표기에서 수식트리 구성 Postfix Notation
알고리즘
1. Operand는 Node를 만들어 Stack에 Push
2. Operand는 Node를 생성하여
1. Stack에서 Pop한 노드를 오른쪽자식으로 하고
2. Stack에서 또 Pop한 노드를 왼쪽자식으로 하고
3. Operator Node를 Stack에 Pop
3. Stack에 마지막으로 남은 노드가 Root 이다

A B + C D - * E / F G * +
연산자 만나기 전까지 스택에 넣고 연산자 만나면 스택에서 꺼내서 오른쪽놓고 또 꺼내서 왼쪽 놓고 연산후에 스택에 넣고....
*/


/*
7.6 수식트리의 구현
ParseTree Skeleton
*/

class ParseTree : public BinaryTree<string>
{
public:
	void BuildParseTree(const string& strPostfix);
	bool IsOperator(char c) {
		return (c == '+' || c == '-' || c == '*' || c == '/');
	}
	void PreOrderTraverse(Node *pNode = 0);
	void PostOrderTraverse(Node *pNode = 0);
	void InOrderTraverse(Node *pNode = 0);
	void LevelOrderTraverse(Node *pNode = 0);
	void Visit(Node *pNode);
};

void ParseTree::BuildParseTree(const string& strPostfix)
{
	Node *pNode;
	int i = 0;
	ListStack<Node*> NodeStack;
	RemoveAll();

	while (strPostfix[i] == ' ') i++;	// 공백 문자는 무시
}

void ParseTree::PreOrderTraverse(Node * pNode)
{
}

void ParseTree::PostOrderTraverse(Node * pNode)
{
}

void ParseTree::InOrderTraverse(Node * pNode)
{
}

/* 7.5
수식트리 Parse Tree
수식을 연산순서에 따라 트리로 구성
Root에 Operator연산자, Child에 Operand피연산자 배치
모든 Operator는 Non-Terminal, Operand는 Terminal Node

((A+B)*(C-D))/E+(F*G)
수식트리를 In-Order Traverse하면 Infix Notation
수식트리를 Pre-Order Traverse하면 Prefix Notation
수식트리를 Post-Order Traverse하면 Postfix Notation

후위표기에서 수식트리 구성 Postfix Notation
알고리즘
1. Operand는 Node를 만들어 Stack에 Push
2. Operand는 Node를 생성하여
1. Stack에서 Pop한 노드를 오른쪽자식으로 하고
2. Stack에서 또 Pop한 노드를 왼쪽자식으로 하고
3. Operator Node를 Stack에 Pop
3. Stack에 마지막으로 남은 노드가 Root 이다

A B + C D - * E / F G * +
연산자 만나기 전까지 스택에 넣고 연산자 만나면 스택에서 꺼내서 오른쪽놓고 또 꺼내서 왼쪽 놓고 연산후에 스택에 넣고
*/