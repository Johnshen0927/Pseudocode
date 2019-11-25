#include "Basic.c"

/* 交换顺序表中子表的记录，使pivot的记录到位，并返回其所在的位置，且使得pivot前的记录不大于它，pivot后的记录不小于它 */
int Partition(Sqlist *L, int low, int high)
{
    int pivotkey;         /* pivot下标对应的数组值 */
    pivotkey = L->r[low]; /* 假设使用L表的第一个值作为pivotkey */
    while (low < high)    /* 当数组下标low＜high时 */
    {
        while (low < high && L->r[high] >= pivotkey) /* 如果下标 low<high 的同时 high的值 ＞= pivotkey，满足正常排序条件*/
        {
            high--; /* 下标high向左移动1位 */
        }
        swap(L, low, high);                         /* 不满足大>中的条件，将＜pivotkey的值交换到左端 */
        while (low < high && L->r[low] <= pivotkey) /* 如果下标 low<high 的同时 low的值 <= pivotkey ，满足正常排序条件*/
        {
            low++; /* 下标low向右移动1位 */
        }
        swap(L, low, high); /*不满足小<中的条件，将＞pivotkey的值交换到右端 */
    }
    return low; /* 返回pivot的位置 */
}

/* 对表进行排序 */
void QSort(Sqlist *L, int low, int high)
{
    int pivot;
    if (low < high)
    {
        pivot = Partition(L, low, high);/* 计算出pivot的位置 */
        QSort(L, low, pivot - 1);  /* 对表中pivot左端递归排序 */
        QSort(L, pivot + 1, high); /* 对表中pivot右端递归排序 */
    }
}

void QuickSort(Sqlist *L)
{
    QSort(L, 1, L->length);
}