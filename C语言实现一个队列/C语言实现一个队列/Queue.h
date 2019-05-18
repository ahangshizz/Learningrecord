#pragma once 
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>


typedef int QDataType;
typedef struct QNode
{
	struct QNode* _pNext;
	QDataType _data;
}QNode;

typedef struct Queue
{
	QNode* _front; // 指向队头元素
	QNode* _back; // 指向队尾元素
	int Q_size;//队列的有效元素
}Queue;

//队列的初始化
void QueueInit(Queue* q);
//入队列
void QueuePush(Queue* q, QDataType data);
//出队列
void QueuePop(Queue* q);
//返回对头元素
QDataType QueueFront(Queue* q);
//返回队尾元素
QDataType QueueBack(Queue* q);
//返回队列有效元素个数
int QueueSize(Queue* q);
//判断队列是否为空
int QueueEmpty(Queue* q);
//销毁队列
void QueueDestroy(Queue* q);