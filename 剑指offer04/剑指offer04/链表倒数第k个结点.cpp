#include <iostream>
using namespace std;

typedef struct ListNode {
	ListNode* next;
	int value;
	ListNode(int a) {
		value = a;
		next = NULL;
	}
}ListNode;
ListNode* findk(ListNode* head, int k) {
	if (head == NULL) {
		return NULL;
	}
	ListNode* pnext = head;
	ListNode* ppre = head;
	for (int i = 0; i < k - 1; ++i) {
		if (pnext->next != NULL)
			pnext = pnext->next;
		else
			return NULL;
	}
	while (pnext->next != NULL) {
		pnext = pnext->next;
		ppre = ppre->next;
	}
	return ppre;
}
int main() {
	int length;
	while (cin >> length) {
		ListNode* phead = new ListNode(0);
		ListNode* p = phead;
		for (int i = 0; i < length; ++i) {
			int value;
			cin >> value;
			ListNode* node = new ListNode(value);
			p->next = node;
			p = p->next;
		}
		int k;
		cin >> k;
		if (k == 0) {
			cout << k << endl;
		}
		ListNode* pTmp = findk(phead, k);
		cout << pTmp->value << endl;
	}
}