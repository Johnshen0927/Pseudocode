#include "Basic.c"

void ShellSort(Sqlist *L)
{
    int i, j;
    int increament = L->length;
    do
    {
        increament = increament / 3 + 1; /* 计算增量序列，计算方法暂无最优*/
        for (i = increament + 1; i < L->length; i++)
        {
            if (L->r[i] < L->r[i - increament]) /* i为gap右，i-increament为gap左，若右小于左*/
            {                                   /* 需要将L->r[i]插入有序增量子表 */
                L->r[0] = L->r[i];              /* 暂存在L->r[0] */
                for (j = i - increament; j > 0 && L->r[0] < L->r[j]; j -= increament)
                {
                    L->r[j + increament] = L->r[j]; /* 记录后移,查找插入位置 */
                }
                L->r[j + increament] = L->r[0]; /* 插入 */
            }
        }
    } while (increament > 1);
}