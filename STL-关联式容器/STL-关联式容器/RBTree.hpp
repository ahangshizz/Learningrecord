#pragma once
#include <iostream>
using namespace std;


enum COLOR{RED, BLACK};


template<class T>
struct RBTreeNode
{
	RBTreeNode(const T& data = T(), COLOR color = RED)
	: _pLeft(nullptr)
	, _pRight(nullptr)
	, _pParent(nullptr)
	, _data(data)
	, _color(color=RED)
	{}

	RBTreeNode<T>* _pLeft;
	RBTreeNode<T>* _pRight;
	RBTreeNode<T>* _pParent;
	T _data;
	COLOR _color;
};

template<class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
	{
		_pHead = new Node;
		_pHead->_pParent = nullptr;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
	}

	bool Insert(const T& data)
	{
		// 先按照二叉搜索树的方式插入新节点
		Node*& pRoot = GetRoot();
		if (nullptr == pRoot)
		{
			pRoot = new Node(data, BLACK);
			pRoot->_pParent = _pHead;
			_pHead->_pLeft = pRoot;
			_pHead->_pRight = pRoot;
			return true;
		}

		// 按照二叉搜索树的规则找待插入节点在红黑树中的位置
		Node* pCur = pRoot;
		Node* pParent = nullptr;
		while (pCur)
		{
			pParent = pCur;
			if (data < pCur->_data)
				pCur = pCur->_pLeft;
			else if (data > pCur->_data)
				pCur = pCur->_pRight;
			else
				return false;
		}

		// 插入新节点
		pCur = new Node(data);
		if (data < pParent->_data)
			pParent->_pLeft = pCur;
		else
			pParent->_pRight = pCur;

		pCur->_pParent = pParent;

		// 检测是否满足红黑树的性质---检测性质3--不能有连在一起的红色节点
		// pParent节点的颜色是红色
		while (pParent != _pHead && RED == pParent->_color)
		{
			Node* grandFather = pParent->_pParent;
			if (pParent == grandFather->_pLeft)
			{
				Node* uncle = grandFather->_pRight;
				// 情况一：叔叔节点存在且红
				if (uncle && RED == uncle->_color)
				{
					pParent->_color = BLACK;
					uncle->_color = BLACK;
					grandFather->_color = RED;

					pCur = grandFather;
					pParent = pCur->_pParent;
				}
				else
				{
					// 叔叔节点不存在 || 叔叔节点存在&&黑色
					// 情况三：
					if (pCur == pParent->_pRight)
					{
						RotateL(pParent);
						swap(pParent, pCur);
					}

					// 情况二
					pParent->_color = BLACK;
					grandFather->_color = RED;
					RotateR(grandFather);
				}
			}
			else
			{
				Node* uncle = grandFather->_pLeft;
				if (uncle && RED == uncle->_color)
				{
					pParent->_color = BLACK;
					uncle->_color = BLACK;
					grandFather->_color = RED;

					pCur = grandFather;
					pParent = pCur->_pParent;
				}
				else
				{
					if (pCur == pParent->_pLeft)
					{
						RotateR(pParent);
						swap(pParent, pCur);
					}

					pParent->_color = BLACK;
					grandFather->_color = RED;
					RotateL(grandFather);
				}
			}
		}

		pRoot->_color = BLACK;
		_pHead->_pLeft = LeftMost();
		_pHead->_pRight = RightMost();
		return true;
	}

	void InOrder()
	{
		_InOrder(GetRoot());
	}

	bool IsValidRBTree()
	{
		Node* pRoot = GetRoot();
		if (nullptr == pRoot)
			return true;

		if (pRoot->_color != BLACK)
		{
			cout << "违反性质2：根节点不是黑色" << endl;
			return false;
		}

		// 获取一条路径中黑色节点的个数
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur)
		{
			if (pCur->_color == BLACK)
				blackCount++;

			pCur = pCur->_pLeft;
		}

		size_t pathCount = 0;
		return _IsValidRBTree(pRoot, blackCount, pathCount);
	}

private:
	bool _IsValidRBTree(Node* pRoot, size_t blackCount, size_t pathCount)
	{
		if (nullptr == pRoot)
			return true;

		if (BLACK == pRoot->_color)
		    ++pathCount;

		// 验证性质3
		Node* pParent = pRoot->_pParent;
		if (pParent != _pHead && RED == pParent->_color && RED == pRoot->_color)
		{
			cout << "违反性质三：存在连在一起的红色节点" << endl;
			return false;
		}

		if (nullptr == pRoot->_pLeft && nullptr == pRoot->_pRight)
		{
			// 验证性质4
			if (blackCount != pathCount)
			{
				cout << "违反性质4：路径中黑色节点个数不相同" << endl;
				return false;
			}
		}

		return _IsValidRBTree(pRoot->_pLeft, blackCount, pathCount) &&
			   _IsValidRBTree(pRoot->_pRight, blackCount, pathCount);
	}

	void _InOrder(Node* pRoot)
	{
		if (pRoot)
		{
			_InOrder(pRoot->_pLeft);
			cout << pRoot->_data << " ";
			_InOrder(pRoot->_pRight);
		}
	}

	Node*& GetRoot()
	{
		return _pHead->_pParent;
	}

	Node* LeftMost()
	{
		Node* pCur = GetRoot();
		if (nullptr == pCur)
			return _pHead;

		while (pCur->_pLeft)
			pCur = pCur->_pLeft;

		return pCur;
	}

	Node* RightMost()
	{
		Node* pCur = GetRoot();
		if (nullptr == pCur)
			return _pHead;

		while (pCur->_pRight)
			pCur = pCur->_pRight;

		return pCur;
	}

	void RotateL(Node* pParent)
	{
		Node* pSubR = pParent->_pRight;
		Node* pSubRL = pSubR->_pLeft;

		pParent->_pRight = pSubRL;
		if (pSubRL)
			pSubRL->_pParent = pParent;

		pSubR->_pLeft = pParent;
		Node* pPParent = pParent->_pParent;
		pParent->_pParent = pSubR;
		pSubR->_pParent = pPParent;

		if (pPParent == _pHead)
		{
			_pHead->_pParent = pSubR;
		}
		else
		{
			if (pPParent->_pLeft == pParent)
				pPParent->_pLeft = pSubR;
			else
				pPParent->_pRight = pSubR;
		}
	}

	void RotateR(Node* pParent)
	{
		Node* pSubL = pParent->_pLeft;
		Node* pSubLR = pSubL->_pRight;

		pParent->_pLeft = pSubLR;
		if (pSubLR)
			pSubLR->_pParent = pParent;

		pSubL->_pRight = pParent;
		Node* pPParent = pParent->_pParent;
		pSubL->_pParent = pPParent;
		pParent->_pParent = pSubL;

		if (pPParent == _pHead)
		{
			_pHead->_pParent = pSubL;
		}
		else
		{
			if (pPParent->_pLeft == pParent)
				pPParent->_pLeft = pSubL;
			else
				pPParent->_pRight = pSubL;
		}
	}

private:
	Node* _pHead;
};

void TestRBTree()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };

	RBTree<int> t;
	for (auto e : a)
		t.Insert(e);

	t.InOrder();
	if (t.IsValidRBTree())
	{
		cout << "t is valid rbtree" << endl;
	}
	else
	{
		cout << "t is invalid rbtree" << endl;
	}
}