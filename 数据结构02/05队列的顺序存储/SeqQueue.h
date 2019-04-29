#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1024
typedef struct SeqQueue {
	void* data[MAX_SIZE];
	int size;
}SeqQueue;

//初始化
SeqQueue* InIt_SeqQueue();
//入队
void Push_SeqQueue(SeqQueue* seq,void* data);
//出队
void Pop_SeqQueue(SeqQueue* seq);
//返回队伍大小
int Size_SeqQueue(SeqQueue* seq);
//返回对头元素;
void* Front_SeqQueue(SeqQueue* seq);
//返回队尾元素
void* Back_SeqQueue(SeqQueue* seq);
//清空队列
void Clear_SeqQueue(SeqQueue* seq);
//销毁队列
void Free_SeqQueue(SeqQueue* seq); 