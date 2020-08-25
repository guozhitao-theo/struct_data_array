#include <stdio.h>

// 定义 bool
typedef enum {
	false = 0,
	true
} bool;

// 定义结构体
typedef struct Arr {
	int * pBase; // 存储数组第一个元素的地址
	int len; // 存储数组的长度
	int cnt; // 数组的有效值的个数
} ARR, * PARR;

// 数组的方法
void init_arr(); // 数组的初始化方法
bool append_arr(); // 数组追加元素
bool insert_arr(); // 数组插入元素
bool delete_arr(); // 数组删除元素
int get_arr(); // 数组获取元素
bool isEmpty_arr(); // 判断数组是否为空
bool isFull_arr(); // 判断数组是否已经满
void sort_arr(); // 数组排序
void show_arr(); // 输出数组的每个元素
void inversion(); // 数组倒置
int main(void)
{
	printf("hello word");
	return 0;
}