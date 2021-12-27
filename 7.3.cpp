#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

/* 7.3
 BinaryTree Skeleton
	Tree Traversal : Tree�ڷᱸ���� ������������ ��ü��带 �湮�ϴ� ����� �ʿ�
	Stack��� : Pre-order, Post-order, In-order
	Queue��� : Level-order
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

// Post-Order Traverse�� �̿��Ͽ� ��� ��� ����. �θ���� �ڽĿ� ���� ������ ������ �ֱ� ������ ���� ���߿� �����Ǿ�� ��
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
		delete pNode;	// Visit��� delete
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
   Pre-order Traversal : Stack ����
	�Ϲ������� stack�� ����Ͽ� non-recursive������� �ٲ� �� �ִ�.
	Post-Order, In-Order�� �ټ� ������!

   Level-Order Traversal : Queue ���
	���� �������� ��ȸ. ������ �Ʒ���, �¿��� ��� ����
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
����Ʈ�� Parse Tree
������ ��������� ���� Ʈ���� ����
Root�� Operator������, Child�� Operand�ǿ����� ��ġ
��� Operator�� Non-Terminal, Operand�� Terminal Node

((A+B)*(C-D))/E+(F*G)
����Ʈ���� In-Order Traverse�ϸ� Infix Notation
����Ʈ���� Pre-Order Traverse�ϸ� Prefix Notation
����Ʈ���� Post-Order Traverse�ϸ� Postfix Notation

����ǥ�⿡�� ����Ʈ�� ���� Postfix Notation
�˰���
1. Operand�� Node�� ����� Stack�� Push
2. Operand�� Node�� �����Ͽ�
1. Stack���� Pop�� ��带 �������ڽ����� �ϰ�
2. Stack���� �� Pop�� ��带 �����ڽ����� �ϰ�
3. Operator Node�� Stack�� Pop
3. Stack�� ���������� ���� ��尡 Root �̴�

A B + C D - * E / F G * +
������ ������ ������ ���ÿ� �ְ� ������ ������ ���ÿ��� ������ �����ʳ��� �� ������ ���� ���� �����Ŀ� ���ÿ� �ְ�....
*/


/*
7.6 ����Ʈ���� ����
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

	while (strPostfix[i] == ' ') i++;	// ���� ���ڴ� ����
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
����Ʈ�� Parse Tree
������ ��������� ���� Ʈ���� ����
Root�� Operator������, Child�� Operand�ǿ����� ��ġ
��� Operator�� Non-Terminal, Operand�� Terminal Node

((A+B)*(C-D))/E+(F*G)
����Ʈ���� In-Order Traverse�ϸ� Infix Notation
����Ʈ���� Pre-Order Traverse�ϸ� Prefix Notation
����Ʈ���� Post-Order Traverse�ϸ� Postfix Notation

����ǥ�⿡�� ����Ʈ�� ���� Postfix Notation
�˰���
1. Operand�� Node�� ����� Stack�� Push
2. Operand�� Node�� �����Ͽ�
1. Stack���� Pop�� ��带 �������ڽ����� �ϰ�
2. Stack���� �� Pop�� ��带 �����ڽ����� �ϰ�
3. Operator Node�� Stack�� Pop
3. Stack�� ���������� ���� ��尡 Root �̴�

A B + C D - * E / F G * +
������ ������ ������ ���ÿ� �ְ� ������ ������ ���ÿ��� ������ �����ʳ��� �� ������ ���� ���� �����Ŀ� ���ÿ� �ְ�
*/