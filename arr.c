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
void init_arr(PARR pArr, int len); // 数组的初始化方法 参数为PARR 类型变量首地址， len为数组的长度
bool append_arr(PARR pArr, int val); // 数组追加元素
bool insert_arr(PARR pArr, int pos, int val); // 数组插入元素 参数为数组首地址， 需要插入的位置 必须大于0；插入的值
bool delete_arr(PARR pArr, int pos, int * pVal); // 数组删除元素
int get_arr(PARR pArr, int index); // 数组 通过 下标 获取元素
bool isEmpty_arr(PARR pArr); // 判断数组是否为空
bool isFull_arr(PARR pArr); // 判断数组是否已经满
void sort_arr(PARR pArr); // 数组排序 升序
void show_arr(PARR pArr); // 输出数组的每个元素
void inversion(PARR pArr); // 数组倒置 

int main(void)
{
	ARR arr; // 定义变量 arr为ARR类型
	int val; // 定义删除 的元素的值
	init_arr(&arr, 6); // 传地址 比较方便可直接更改其值，并且仅传首地址即可，如果直接传 arr 则 需要传的数据比较多，形参赋值之后 在函数调用结束 内存被回收，无法改变原来的值
	show_arr(&arr);
	isFull_arr(&arr);
	append_arr(&arr, 100);
	append_arr(&arr, 102);
	append_arr(&arr, 13);
	append_arr(&arr, 14);
	insert_arr(&arr, 5, 99);
	printf("------------------------\n");
	if (delete_arr(&arr, 4, &val))
	{
		printf("你删除的元素为：%d\n", val);
	}
	if (get_arr(&arr, 6)) 
	{
		printf("根据下标获取的元素为%d\n", get_arr(&arr, 6));
	}
	printf("------------------------\n");
	show_arr(&arr);
	printf("------------------------\n");
	sort_arr(&arr);
	show_arr(&arr);
	printf("---------倒序之后-------------\n");
	inversion(&arr);
	show_arr(&arr);
	return 0;
}

void init_arr(PARR pArr, int len)
{
	pArr->pBase = (int*)malloc(sizeof(int) * len); // 动态分配内存 长度类int 类型所占字节 * 数组的长度，并将返回值强制转换成 存存 int 类型的地址
	if (NULL == pArr->pBase) // 内存分配失败 （内存已经满了或者其他情况导致分配失败）
	{
		printf("动态内存分配失败");
		exit(-1); // 终止程序
	}
	else 
	{
		pArr->len = len; // 内存分配成功之后 初始化 数组长度
		pArr->cnt = 0; // 初始化数组有效值 个数
	}
	return;
}

void inversion(PARR pArr) // 一个从小到大，一个从大到小 。互换内容
{
	int i = 0;
	int j = pArr->cnt - 1;
	while (i < j) {
		int t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		++i;
		--j;
	}
	return;

}

void sort_arr(PARR pArr)
{
	int i, j, t;
	for (i = 0; i < pArr->cnt; i++)
	{
		for (j = i + 1; j < pArr->cnt; j++)
		{
			if (pArr->pBase[i] > pArr->pBase[j]) // 选择排序 ，将最大的数字放在最后面
			{
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}
	}
	return;
}
int get_arr(PARR pArr, int index) 
{
	if (index < 0 || index > pArr->cnt) {
		printf("下标超出范围\n");
		return false;
	}
	else
	{
		return pArr->pBase[index];
	}
	return;
}

bool delete_arr(PARR pArr, int pos, int * pVal)
{
	if (isEmpty_arr(pArr)) 
	{
		return false;
	}
	if (pos < 0 || pos > pArr->cnt + 1)
	{
		return false;
	}
	*pVal = pArr->pBase[pos - 1]; // 先将值取出来
	for (int i = pos; i < pArr->len; i++) // 后面每个元素向前移动
	{
		pArr->pBase[i - 1] = pArr->pBase[i];
	}
	return true;
}

bool insert_arr(PARR pArr, int pos, int val)
{
	if (isFull_arr(pArr)) 
	{
		return false;
	}
	if (pos < 1 || pos > pArr->cnt+1) {
		printf("插入的位置超出数组范围\n");
		return false;
	}
	for (int i = pArr->cnt; i > pos - 1; --i) // 遍历 从最后一个开始 直到 pos位置 的元素 向后面移动 
	{
		pArr->pBase[i + 1] = pArr->pBase[i]; // 向右移动
	}
	pArr->pBase[pos - 1] = val; // 在 插入位置的 插入元素
	return true;
}

bool append_arr(PARR pArr, int val) 
{
	if (isFull_arr(pArr)) // 判断元素是否为满
	{
		return false;
	}
	else
	{
		pArr->pBase[pArr->cnt] = val; // 将有效个数作为下标 追加值
		(pArr->cnt)++; // 追加之后下标 +1
	}
	return true;
}

void show_arr(PARR pArr) // 遍历展示数组
{
	if (isEmpty_arr(pArr)) 
	{
		printf("数组为空\n");
	}
	else
	{
		for (int i = 0; i < pArr->cnt; i++) // 遍历 有效数组
		{
			printf("%d\n", pArr->pBase[i]); // pBase 存放数组第一个元素地址
		}

	}
	return;
}

bool isFull_arr(PARR pArr) // 判断数组是否 满
{
	if (pArr->cnt == pArr->len - 1) {
		return true;
	}
	else
	{
		return false;
	}
}

bool isEmpty_arr(PARR pArr) // 判断数组是否为空
{
	if (0 == pArr->cnt) { // 当数组的有效长度为 0 的时候数组为空
		return true;
	}
	else
	{
		return false;
	}
}