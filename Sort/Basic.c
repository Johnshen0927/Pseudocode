#define MAXSIZE 10 /* 用于排序数组个数的最大值，可根据需要修改 */
typedef int Status;

typedef struct
{
    int r[MAXSIZE + 1]; /* 用于储存要排序数组 r[0]作为哨兵或临时变量 */
    int length;         /* 用于记录顺序表的长度 */
} Sqlist;

/* 用于交换两相邻数字值 */
void swap(Sqlist *L, int i, int j)
{
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}
