
//选择排序—简单选择排序（Simple Selection Sort）
//基本思想：
//在要排序的一组数中，选出最小（或者最大）的一个数与第1个位置的数交换；
//然后在剩下的数当中再找最小（或者最大）的与第2个位置的数交换，依次类推，
//直到第n - 1个元素（倒数第二个数）和第n个元素（最后一个数）比较为止。

#include <iostream>
using namespace std;

void print(int a[], int n, int i) {
	cout << "第" << i + 1 << "趟 : ";
	for (int j = 0; j < 8; j++) {
		cout << a[j] << "  ";
	}
	cout << endl;
}
/**
 * 数组的最小值
 *
 * @return int 数组的键值
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
 * 选择排序
 *
 */
void selectSort(int a[], int n) {
	int key, tmp;
	for (int i = 0; i < n; ++i) {
		key = SelectMinKey(a, n, i);           //选择最小的元素  
		if (key != i) {
			tmp = a[i];  a[i] = a[key]; a[key] = tmp; //最小元素与第i位置元素互换  
		}
		print(a, n, i);
	}
}
int main() {
	int a[8] = { 3,1,5,7,2,4,9,6 };
	cout << "初始值：";
	for (int j = 0; j < 8; j++) {
		cout << a[j] << "  ";
	}
	cout << endl << endl;
	selectSort(a, 8);
	print(a, 8, 8);
}