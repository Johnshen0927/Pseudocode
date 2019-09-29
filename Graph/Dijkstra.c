#define MAXVEX 9
#define INFINITY 65535

typedef int Patharc[MAXVEX];        /* 用来存储最短路径下标的数组 */
typedef int ShortPathTable[MAXVEX]; /* 用来存储到各点最短路径的权值和 */

/* Dijkstra算法，求有向网G的V_0顶点到其余顶点v最短路径P[v]以及带权长度D[v] */
/* P[v]的值为前驱顶点下标，D[v]表示v0到v的最短路径场长度和 */
void ShortestPath_Dijkstra(MGraph G, int v_0, Patharc *P, ShortPathTable *D)
{
    int v, w, k, min;
    int final[MAXVEX];                  /* final[w] = 1则表示求得顶点v_0至顶点v_w的最短路径 */
    for (v = 0; v < G.numVertexes; v++) /* 初始化数据 */
    {
        final[v] = 0;            /* 全部顶点初始化为位置最短路径状态 */
        (*D)[v] = G.arc[v_0][v]; /* 将与v_0点有连线的顶点加上权值 */
        (*P)[v] = 0;             /* 初始化路径数组P为0 */
    }
    (*D)[v_0] = 0;  /* v_0至v_0的路径长度为0 */
    final[v_0] = 1; /* V_0到v_0不需要求路径 */
    /* 开始主循环，每次求得v_0到某个v顶点的最短路径 */
    for (v = 1; v < G.numVertexes; v++)
    {
        min = INFINITY;                     /* 当前所知离v_0顶点的最近距离 */
        for (w = 0; w < G.numVertexes; w++) /* 寻找离v_0最近的顶点 */
        {
            if (!final[w] && (*D)[w < min])
            {
                k = w;
                min = (*D)[w]; /* w顶点离v_0顶点更近 */
            }
        }
        final[k] = 1; /* 将目前找到的最近的顶点置为1 */
        for (w = 0; w < G.numVertexes; w++)
        {
            /* 如果经过顶点的路径比现在这条路径的长度短的话 */
            if (!final[w] && (min + G.arc[k][w] < (*D)[w]))
            {
                /* 说明找到了更短路径,修改D[w]和P[w] */
                (*D)[w] = min + G.arc[k][w]; /* 修改当前路径长度 */
                (*P)[w] = k;
            }
        }
    }
}
