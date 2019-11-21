#include "Basic.c";

/* 对顺序表L做简单选择排序 */
void SelectionSort(Sqlist *L)
{
    int i, j, min;
    for (i = 1; i < L->length; i++)
    {
        min = i;                            /* 将当前下标定义为最小下标 */
        for (j = i + 1; j < L->length; j++) /* 循环min后面的数据 */
        {
            if (L->r[min] > L->r[j]) /* 若当前值比min小 */
            {
                min = j; /* 将当前值得下标作为新的min */
            }
        }
        if (i != min) /* 退出内循环后，若min值发生变化，不为初始得i值*/
        {
            swap(L, i, min); /* 交换l->r[i]和L->r[min]的值 */
        }
    }
}