#include "SeqQueue.h"

//初始化
SeqQueue* InIt_SeqQueue() {
	SeqQueue* seq = (SeqQueue*)malloc(sizeof(SeqQueue));
	for (int i = 0; i < MAX_SIZE; ++i) {
		seq->data[i] = NULL;
	}
	seq->size = 0;
	return seq;
}
//入队
void Push_SeqQueue(SeqQueue* seq,void* data) {
	if (seq == NULL) {
		return;
	}
	if (data == NULL) {
		return;
	}
	if (seq->size == 1024) {
		return;
	}
	seq->data[seq->size] = data;
	seq->size++;
}
//出队
void Pop_SeqQueue(SeqQueue* seq) {
	if (seq == NULL) {
		return;
	}
	if (seq->size == 0) {
		return;
	}
	//移动元素
	for (int i = 0; i < seq->size - 1; ++i) {
		seq->data[i] = seq->data[i + 1];
	}
	seq->size--;
}
//返回队伍大小
int Size_SeqQueue(SeqQueue* seq) {
	return seq->size;
}
//返回对头元素;
void* Front_SeqQueue(SeqQueue* seq) {
	if (seq == NULL) {
		return NULL;
	}
	return seq->data[0];
}
//返回队尾元素
void* Back_SeqQueue(SeqQueue* seq) {
	if (seq == NULL) {
		return NULL;
	}
	if (seq->size == 0) {
		return NULL;
	}
	return seq->data[seq->size - 1];
}
//清空队列
void Clear_SeqQueue(SeqQueue* seq) {
	if (seq == NULL) {
		return;
	}
	//for (int i = 0; i < MAX_SIZE; ++i) {
	//	seq->data[i] = NULL;
	//}
	seq->size = 0;
}
//销毁队列
void Free_SeqQueue(SeqQueue* seq) {
	if (seq == NULL) {
		return;
	}
	free(seq);
	seq = NULL;
}