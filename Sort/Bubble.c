#include "Basic.c";

/* basic */
void BubbleSort0(Sqlist *L)
{
    int i, j;
    for (i = 1; i < L->length; i++)
    {
        for (j = i + 1; j <= L->length; j++)
        {
            if (L->r[i] < L->r[j])
            {
                swap(L, i, j);
            }
        }
    }
}

/* optimise */
void BUbbleSort1(Sqlist *L)
{
    int i, j;
    Status flag = 1;
    for (i = 1; i < L->length && flag; i++)
    {
        flag = 0;
        for (j = L->length - 1; j >= i; j--)
        {
            if (L->r[j] > L->r[j + 1])
            {
                swap(L, j, j + 1);
                flag = 1;
            }
        }
    }
}