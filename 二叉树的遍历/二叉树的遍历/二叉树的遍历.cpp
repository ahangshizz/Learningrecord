#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
	char ch;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* create() {
	TreeNode* root = new TreeNode;
	char ch;
	cin >> ch;
	if (ch == '#')
		return NULL;
	else {
		root->ch = ch;
		root->left = create();
		root->right = create();
	}
	return root;
}

//前序遍历
void PreOrder(TreeNode* root) {
	if (root == NULL)
		return;
	TreeNode* p = root;
	stack<TreeNode*> s;
	while (!s.empty() || p) {
		if (p) {
			cout << p->ch << " ";
			s.push(p);
			p = p->left;
		}
		else {
			p = s.top();
			s.pop();
			p = p->right;
		}
	}
	cout << endl;
}
void InOrder(TreeNode* root) {
	if (root == NULL)
		return;
	TreeNode* p = root;
	stack<TreeNode*> s;
	while (!s.empty() || p) {
		if (p) {
			s.push(p);
			p = p->left;
		}
		else {
			p = s.top();
			s.pop();
			cout << p->ch << " ";
			p = p->right;
		}
	}
	cout << endl;
}

void PosOrder(TreeNode* root) {
	if (root == NULL)
		return;
	stack<TreeNode*> s;
	TreeNode* p1, *p2;
	p1 = root;
	p2 = NULL;
	while (p1) {
		s.push(p1);
		p1 = p1->left;
	}
	//p1为空走到左子树的低端
	while (!s.empty()) {
		p1 = s.top();
		s.pop();
		if (p1->right == NULL || p1->right == p2) {
			cout << p1->ch << " ";
			p2 = p1;
		}
		else {
			s.push(p1);
			p1 = p1->right;
			while (p1) {
				s.push(p1);
				p1 = p1->left;
			}
		}
	}
	cout << endl;
}

void LevelTree(TreeNode* root) {
	if (root == NULL)
		return;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode* p = q.front();
		q.pop();
		cout << p->ch << " ";
		if (p->left)
			q.push(p->left);
		if (p->right)
			q.push(p->right);
	}
	cout << endl;
}
int main() {
	TreeNode* root = create();

	cout << "前序遍历" << endl;

	PreOrder(root);

	cout << "中序遍历" << endl;
	InOrder(root);

	cout << "后序遍历" << endl;

	PosOrder(root);
	cout << "层序遍历" << endl;
	LevelTree(root);
	//getchar();
	system("pause");
	return 0;
}