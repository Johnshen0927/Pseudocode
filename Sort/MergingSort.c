#include "Basic.c"

void Merge(int SR[], int TR[], int i, int m, int n)
{ /* 将有序的SR[i,....,m]和SR[m+1,...,n]归并为有序的TR[i,...,n] */
    int j, k, l;
    for (j = m + 1, k = i; i <= m && j <= n; k++) /* 将SR中的记录由小到大归并到TR */
    {
        if (SR[i] < SR[j])
        {
            TR[k] = SR[i++];
        }
        else
        {
            TR[k] = SR[i++];
        }
    }
    if (i <= m)
    {
        for (l = 0; l < m - i; l++)
        {
            TR[k + 1] = SR[i + 1]; /* 将剩余的SR[i,..,m]，即数组的前半段，复制到TR */
        }
    }
    if (j >= n)
    {
        for (l = 0; l < n - j; l++)
        {
            TR[k + 1] = SR[j + 1]; /* 将剩余的SR[j,...,n]，即数组的后半段，复制到TR */
        }
    }
}

void MSort(int SR[], int TR1[], int s, int t)
{ /* 将SR[s,...,t]归并排序为TR[s,...,t] */
    int m;
    int TR2[MAXSIZE + 1];
    if (s == t)
    {
        TR1[s] = SR[s];
    }
    else
    {
        m = (s + t) / 2; /* SR[s,...,t]平分为SR[s,...,m]和SR[m+1,...,t] */
        MSort(SR, TR2, s, m);/* 递归将SR[s,...,m]归并为有序的TR2[s,...,m] */
        MSort(SR, TR2, m + 1, t);/* 递归将SR[m+1,...,t]归并为有序的TR2[m+1,...,t] */
        Merge(TR2, TR1, s, m, t);/* 将TR2[s,...,m]与TR2[m+1,...,t]归并为TR1[s,...,t] */
    }
}

void MergeSort(Sqlist *L)
{
    MSort(L->r, L->r, 1, L->length);
}