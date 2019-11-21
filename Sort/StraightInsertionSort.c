/* 对顺序表L做直接插入排序 */
#include "Basic.c";

void InsertSort(Sqlist *L){
    int i,j;
    for ( i = 2; i < L->length; i++)/* 第一个值作为有序序列，从后面的值开始循环 */
    {
       if(L->r[i]<L->r[i-1]){/* 将L->r[i]插入有序序列中 */
           L->r[0] = L->r[i];/* 设置哨兵 */
           for ( j = i-1; L->r[j]>L->r[0]; j--)
           {
                   L->r[j+1] = L->r[j];/* 记录后移 */
           }
            L->r[j+1] = L->r[0];/* 将值插到正确的位置 */
       }
    }
}