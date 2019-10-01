/* 折半查找 */
/* 查找一个有序数组中的指定值 */
int Binary_Search(int *a, int n, int key)
{
    int low, high, mid;
    low = 1;  /* 定义最低下标为记录首位 */
    high = n; /* 定义最高下标为记录末位 */
    while (low <= high)
    {
        mid = (low + high) / 2; /* 折半算法 */
        // mid = low + (high - low) * (key -a[low])/(a[high] - a[low]); /* 插值算法 */
        
        if (key < a[mid]) /* 若查找值比中值小 */
        {
            high = mid - 1; /* 最高值调整为中位值-1 */
        }
        else if (key > a[mid]) /* 若大 */
        {
            low = mid + 1; /* 最小值调整为中位值+1 */
        }
        else
        {
            return mid; /* 若相等，则mid为查找位置 */
        }
    }
    return 0;
}