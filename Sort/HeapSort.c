#include "Basic.c"

void HeapAdjust(Sqlist *L, int s, int m) /* 构建从s....m的大顶堆 */
{
    int temp, j;
    temp = L->r[s];
    for (j = 2 * s; j <= m; j *= 2) /* 沿关键字较大的那个孩子结点向下筛选 */
    {
        if (j < m && L->r[j] < L->r[j + 1])
        {
            ++j; /* j为关键字中较大结点下标 */
        }
        if (temp >= L->r[j])
        {
            break; /* 应当插入到r[s]的位置上 */
        }
        L->r[s] = L->r[j];
        s = j;
    }
    L->r[s] = temp; /* 插入 */
}
void HeapSort(Sqlist *L)
{
    int i;
    for (i = L->length / 2; i > 0; i--) /* 循环数组来将其构建成大顶堆 */
    {
        HeapAdjust(L, i, L->length);
    }
    for (i = L->length; i > 1; i--)
    {
        swap(L, 1, i);           /* 交换堆顶和堆末的元素 */
        HeapAdjust(L, 1, i - 1); /* 重新构建长度-1的大顶堆 */
    }
}