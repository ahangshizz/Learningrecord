#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//定义一个结构体
//最大容量capacity   有效个数  size   指针   
typedef struct Damarray {
	int* p_array;
	int capacity;//容器容量
	int size;//当前有效元素
}Damarray;
//初始化
Damarray* Init_array();
//插入元素
void Pushback_array(Damarray* arr,int value);
//根据位置删除
void RemoveBypos_array(Damarray* arr,int pos);
//根据值删除
void RemoveByvalue_array(Damarray* arr, int value);
//查找
void Find_array(Damarray* arr, int value);
//打印数组
void Printf_array(Damarray* arr);
//释放动态数组的内存
void FreeSpace_array(Damarray* arr);
//清空数组
void Clear_array(Damarray* arr);
//获得动态数组的容量
void Capacity_array(Damarray* arr);
//获得动态数组当前元素个数
void Size_array(Damarray* arr);
//获取某个位置的当前元素
void At_array(Damarray* arr, int pos);