#define MAXVEX 9 /* 定义一个最大顶点数，举例为9 */
typedef int Pathmatrix[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

/* Floyd 算法，求网图 G 中各顶点 V 到其余顶点 W 最短路径 P[V][W] 以及带权长度D[V][W] */
void ShortestPathTable_Floyd(MGraph G, Pathmatrix *P, ShortestPathTable *D)
{
    int v, w, k;
    for (v = 0; v < G.numVertexes; ++v)
    { /* 初始化D和P */
        for (w = 0; w < G.numVertexes; ++w)
        {
            (*D)[v][w] = G.matrix[v][w]; /* D[V][W]值为对应点之间的权值 */
            (*P)[v][w] = w;              /* 初始化P */
        }
    }

    for (k = 0; k < G.numVertexes; ++k)
    {
        for (v = 0; v < G.numVertexes; ++v)
        {
            for (w = 0; w < G.numVertexes; ++w)
            {
                if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w]) /* 如果以K为中继点，经过K的路径比原来两点间更短 */
                {
                    (*D)[v][w] = (*D)[v][k] + (*D)[k][w]; /* 将原来两点间的权值设为更小的一个,更改权值 */
                    (*P)[v][w] = (*P)[v][k];              /* 路径设置经过下标为k的顶点，更改顶点 */
                }
            }
        }
    }
}