//ѡ�����򡪼�ѡ������Simple Selection Sort��
//����˼�룺
//��Ҫ�����һ�����У�ѡ����С��������󣩵�һ�������1��λ�õ���������
//Ȼ����ʣ�µ�������������С��������󣩵����2��λ�õ����������������ƣ�
//ֱ����n - 1��Ԫ�أ������ڶ��������͵�n��Ԫ�أ����һ�������Ƚ�Ϊֹ��

#include <iostream>
using namespace std;

void print(int a[], int n, int i) {
	cout << "��" << i + 1 << "�� : ";
	for (int j = 0; j < 8; j++) {
		cout << a[j] << "  ";
	}
	cout << endl;
}
/**
 * �������Сֵ
 *
 * @return int ����ļ�ֵ
 */
int SelectMinKey(int a[], int n, int i)
{
	int k = i;
	for (int j = i + 1; j < n; ++j) {
		if (a[k] > a[j]) k = j;
	}
	return k;
}

/**
 * ѡ������
 *
 */
void selectSort(int a[], int n) {
	int key, tmp;
	for (int i = 0; i < n; ++i) {
		key = SelectMinKey(a, n, i);           //ѡ����С��Ԫ��  
		if (key != i) {
			tmp = a[i];  a[i] = a[key]; a[key] = tmp; //��СԪ�����iλ��Ԫ�ػ���  
		}
		print(a, n, i);
	}
}
int main() {
	int a[8] = { 3,1,5,7,2,4,9,6 };
	cout << "��ʼֵ��";
	for (int j = 0; j < 8; j++) {
		cout << a[j] << "  ";
	}
	cout << endl << endl;
	selectSort(a, 8);
	print(a, 8, 8);
}