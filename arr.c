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
void init_arr(PARR pArr, int len); // ����ĳ�ʼ������ ����ΪPARR ���ͱ����׵�ַ�� lenΪ����ĳ���
bool append_arr(PARR pArr, int val); // ����׷��Ԫ��
bool insert_arr(PARR pArr, int pos, int val); // �������Ԫ�� ����Ϊ�����׵�ַ�� ��Ҫ�����λ�� �������0�������ֵ
bool delete_arr(PARR pArr, int pos, int * pVal); // ����ɾ��Ԫ��
int get_arr(PARR pArr, int index); // ���� ͨ�� �±� ��ȡԪ��
bool isEmpty_arr(PARR pArr); // �ж������Ƿ�Ϊ��
bool isFull_arr(PARR pArr); // �ж������Ƿ��Ѿ���
void sort_arr(PARR pArr); // �������� ����
void show_arr(PARR pArr); // ��������ÿ��Ԫ��
void inversion(PARR pArr); // ���鵹�� 

int main(void)
{
	ARR arr; // ������� arrΪARR����
	int val; // ����ɾ�� ��Ԫ�ص�ֵ
	init_arr(&arr, 6); // ����ַ �ȽϷ����ֱ�Ӹ�����ֵ�����ҽ����׵�ַ���ɣ����ֱ�Ӵ� arr �� ��Ҫ�������ݱȽ϶࣬�βθ�ֵ֮�� �ں������ý��� �ڴ汻���գ��޷��ı�ԭ����ֵ
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
		printf("��ɾ����Ԫ��Ϊ��%d\n", val);
	}
	if (get_arr(&arr, 6)) 
	{
		printf("�����±��ȡ��Ԫ��Ϊ%d\n", get_arr(&arr, 6));
	}
	printf("------------------------\n");
	show_arr(&arr);
	printf("------------------------\n");
	sort_arr(&arr);
	show_arr(&arr);
	printf("---------����֮��-------------\n");
	inversion(&arr);
	show_arr(&arr);
	return 0;
}

void init_arr(PARR pArr, int len)
{
	pArr->pBase = (int*)malloc(sizeof(int) * len); // ��̬�����ڴ� ������int ������ռ�ֽ� * ����ĳ��ȣ���������ֵǿ��ת���� ��� int ���͵ĵ�ַ
	if (NULL == pArr->pBase) // �ڴ����ʧ�� ���ڴ��Ѿ����˻�������������·���ʧ�ܣ�
	{
		printf("��̬�ڴ����ʧ��");
		exit(-1); // ��ֹ����
	}
	else 
	{
		pArr->len = len; // �ڴ����ɹ�֮�� ��ʼ�� ���鳤��
		pArr->cnt = 0; // ��ʼ��������Чֵ ����
	}
	return;
}

void inversion(PARR pArr) // һ����С����һ���Ӵ�С ����������
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
			if (pArr->pBase[i] > pArr->pBase[j]) // ѡ������ �����������ַ��������
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
		printf("�±곬����Χ\n");
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
	*pVal = pArr->pBase[pos - 1]; // �Ƚ�ֵȡ����
	for (int i = pos; i < pArr->len; i++) // ����ÿ��Ԫ����ǰ�ƶ�
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
		printf("�����λ�ó������鷶Χ\n");
		return false;
	}
	for (int i = pArr->cnt; i > pos - 1; --i) // ���� �����һ����ʼ ֱ�� posλ�� ��Ԫ�� ������ƶ� 
	{
		pArr->pBase[i + 1] = pArr->pBase[i]; // �����ƶ�
	}
	pArr->pBase[pos - 1] = val; // �� ����λ�õ� ����Ԫ��
	return true;
}

bool append_arr(PARR pArr, int val) 
{
	if (isFull_arr(pArr)) // �ж�Ԫ���Ƿ�Ϊ��
	{
		return false;
	}
	else
	{
		pArr->pBase[pArr->cnt] = val; // ����Ч������Ϊ�±� ׷��ֵ
		(pArr->cnt)++; // ׷��֮���±� +1
	}
	return true;
}

void show_arr(PARR pArr) // ����չʾ����
{
	if (isEmpty_arr(pArr)) 
	{
		printf("����Ϊ��\n");
	}
	else
	{
		for (int i = 0; i < pArr->cnt; i++) // ���� ��Ч����
		{
			printf("%d\n", pArr->pBase[i]); // pBase ��������һ��Ԫ�ص�ַ
		}

	}
	return;
}

bool isFull_arr(PARR pArr) // �ж������Ƿ� ��
{
	if (pArr->cnt == pArr->len - 1) {
		return true;
	}
	else
	{
		return false;
	}
}

bool isEmpty_arr(PARR pArr) // �ж������Ƿ�Ϊ��
{
	if (0 == pArr->cnt) { // ���������Ч����Ϊ 0 ��ʱ������Ϊ��
		return true;
	}
	else
	{
		return false;
	}
}