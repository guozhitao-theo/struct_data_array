#include <stdio.h>

// ���� bool
typedef enum {
	false = 0,
	true
} bool;

// ����ṹ��
typedef struct Arr {
	int * pBase; // �洢�����һ��Ԫ�صĵ�ַ
	int len; // �洢����ĳ���
	int cnt; // �������Чֵ�ĸ���
} ARR, * PARR;

// ����ķ���
void init_arr(); // ����ĳ�ʼ������
bool append_arr(); // ����׷��Ԫ��
bool insert_arr(); // �������Ԫ��
bool delete_arr(); // ����ɾ��Ԫ��
int get_arr(); // �����ȡԪ��
bool isEmpty_arr(); // �ж������Ƿ�Ϊ��
bool isFull_arr(); // �ж������Ƿ��Ѿ���
void sort_arr(); // ��������
void show_arr(); // ��������ÿ��Ԫ��
void inversion(); // ���鵹��
int main(void)
{
	printf("hello word");
	return 0;
}