#include "Queue.h"

QNode* BuyQNode(QDataType data) {
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->_data = data;
	newNode->_pNext = NULL;
	return newNode;
}
//队列的初始化
void QueueInit(Queue* q) {
	if (q == NULL) {
		return;
	}
	q->_front = NULL;
	q->_back = NULL;
	q->Q_size = 0;
}
//入队列
void QueuePush(Queue* q, QDataType data) {
	if (q == NULL) {
		return;
	}
	QNode* newnode=BuyQNode(data);

	if(q->_front==NULL&&q->_back==NULL) {
		q->_front = newnode;
		q->_back = newnode;
	}
	q->_back->_pNext = newnode;
	q->_back = newnode;
	q->Q_size++;
}
//出队列
void QueuePop(Queue* q) {
	if (q == NULL) {
		return;
	}
	if (q->_front == NULL) {
		printf("队列为空\n");
		return;
	}
	//保存第一个元素
	QNode* pCur = q->_front;
	//把队列的头往后移动
	q->_front = q->_front->_pNext;
	//释放已经出队列的结点
	free(pCur);
	--q->Q_size;
}
//返回对头元素
QDataType QueueFront(Queue* q) {
	if (q == NULL) {
		return	0;
	}
	if (q->_front == NULL) {
		printf("队列为空\n");
		return 0;
	}
	return q->_front->_data;
}
//返回队尾元素
QDataType QueueBack(Queue* q) {
	if (q == NULL) {
		return 0;
	}
	return q->_back->_data;
}
//返回队列有效元素个数
int QueueSize(Queue* q) {
	if (q == NULL) {
		return 0;
	}
	return q->Q_size;
}
//判断队列是否为空
int QueueEmpty(Queue* q) {
	if (q == NULL) {
		return 0;
	}
	if (q->_front == NULL) {
		return 0;
	}
	return 1;
}
//销毁队列
void QueueDestroy(Queue* q) {
	if (q == NULL) {
		return;
	}
	for (int i = 0; i < q->Q_size; ++i) {
		QNode* pCur = q->_front;
		q->_front = pCur->_pNext;
		free(pCur);
		pCur = NULL;
	}
}