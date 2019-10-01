/* 顺序查找，a为数组，n为要查找的数组长度，key为要查找的关键字 */
int Sequential_Search(int *a, int n, int key)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        if (a[i] == key)
        {
            return i;
        }
    }
    return 0;
}

/* 顺序查找 Optimised */
/* 有哨兵顺序查找 */
int Sequential_Search2(int *a, int n, int key)
{
    int i;
    a[0] = key; /* 设置a[0]为关键字值，即“哨兵” */
    int n;      /* 循环从数组尾部开始 */
    while (a[i] != key)
    {
        i--;
    }
    return i;
}