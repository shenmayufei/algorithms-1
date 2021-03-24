// 快速排序 - 递归版本

#include <stdio.h>  // for printf

void Swap(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

// 分割函数，选取第一个为基准元素
// 把 start 到 end 内的元素，小于基准元素的放在左边，大于的放在右边
// 返回基准值的右边界位置，也是 <= 基准值的个数
int Partition(int a[], int start, int end) {
    int k = a[start];
    int left = start;
    int right = end;
    int i = start;

    while (i <= right) {
        if (a[i] < k) {
            Swap(a, i, left);
            left++;
            i++;
        } else if (a[i] > k) {
            Swap(a, i, right);
            right--;
        } else {
            i++;
        }
    }
    return i;
}

// 快速排序 - 递归实现
void QuickSort(int a[], int start, int end) {
    if (start >= end) return;
    int p = Partition(a, start, end);
    QuickSort(a, start, p - 1);
    QuickSort(a, p, end);
}

int main(void) {
    int n = 9;
    int a[] = {4, 1, 3, 9, 7, 2, 6, 8, 5};
    QuickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
}
