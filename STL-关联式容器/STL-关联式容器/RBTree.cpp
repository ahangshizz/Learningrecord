#include <iostream>
using namespace std;

enum Color{RED,BLACK};

template<class T>
struct RBTreeNode {

	RBTreeNode(const T& data=T(),Color color=RED)
		:p_Left(nullptr)
		,p_Right(nullptr)
		,p_Parent(nullptr)
		,_data(data)
		,_color(color)
	{}

	RBTreeNode<T>* p_Left;//左孩子结点
	RBTreeNode<T>* p_Right;//右孩子结点
	RBTreeNode<T>* p_Parent;//父结点
	T _data;//值域
	Color _color;//结点的颜色
};

template<class T>
class RBTree {
	typedef RBTreeNode<T> Node;
public:
	RBTree() {
		p_Head = new Node;
		p_Head->p_Left = p_Head;
		p_Head->p_Right = p_Head;
		p_Head->p_Parent = nullptr;
	}

	bool Insert(const T& data) {
		Node*& pRoot = GetRoot();
		//如果空树直接插入
		if (nullptr == pRoot) {
			pRoot == new Node(data, RED);
			pRoot->p_Parent = p_Head;
			p_Head->p_Left = pRoot;
			p_Head->p_Right = pRoot;
			return true;
		}

		//按照二叉搜索树插入方式
		Node* pCur = pRoot;
		Node* pParent = nullptr;
		while (pCur) {
			pParent = pCur;
			if (data < pCur->_data)
				pCur = pCur->p_Left;
			else if (data > pCur->_data)
				pCur = pCur->p_Right;
			else
				return false;
		}

		pCur = new Node(data);
		if (data < pParent->_data)
			pParent->p_Left = pCur;
		else
			pParent->p_Right = pCur;
		pCur->p_Parent = pParent;

		//检测是否满足RBTree的性质
		//不能有两个红色结点连接在一起
		while (pParent != p_Head && RED == pParent->_color) {
			Node* grandFather = pParent->p_Parent;
			if (pParent == grandFather->p_Left) {
				Node* Uncle = grandFather->p_Right;

				//情况一:叔叔结点存在且为红色
				if (Uncle&&Uncle->_color == RED) {
					pParent->_color = BLACK;
					Uncle->_color = BLACK;
					grandFather->_color = RED;
					pCur = grandFather;
					pParent = pCur->p_Parent;
				}
				else {
					//叔叔结点不存在||叔叔结点为黑色

				}
			}
		}

	}

	Node*& GetRoot() {
		return p_Head->p_Parent;
	}
private:
	Node* p_Head;
};

int main() {


	system("pause");
	return 0;
}