typedef struct EdgeNode
{
    int adjvex;
    int weight;
    struct EdgeNode *next;
} EdgeNode;

typedef struct VertexNode
{
    int in;
    int data;
    EdgeNode *firstedge;
} VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numVertexes, numEdges;
} graphAdjList, *GraphAdjList;

typedef int Status;

/* 拓扑排序，若GL无回路，则输出拓扑排序序列并返回OK，若有回路，则返回ERROR */
Status ToplogicalSort(GraphAdList GL)
{
    EdgeNode *e;
    int i, k, gettop;
    int top = 0;   /* 用于栈指针下标 */
    int count = 0; /* 用于统计输出顶点的个数 */
    int *stack;    /* 建栈存储入度为0的顶点 */
    stack = (int *)malloc(GL->numVertexes * sizeof(int));
    for (i = 0; i < GL->numVertexes; i++)
    {
        if (GL->adjList[i].in = 0)
        {
            stack[++top] = i; /* 将入度为0的顶点入栈 */
        }
    }
    while (top != 0)
    {
        gettop = stack[top--];                    /* 出栈 */
        printf("%d->", GL->adjList[gettop].data); /* 打印此顶点 */
        count++;                                  /* 统计输出顶点数 */
        for (e = GL->adjList[gettop].firstedge; e; e = e->next)
        { /* 对此顶点弧表遍历 */
            k = e->adjvex;
            if (!(--GL->adjList[k].in)) /* 将K号顶点邻接点的入度减1 */
            {
                stack[++top] = k; /* 若为0则入栈，以便于下次循环输出 */
            }
        }
    }
    if (count < GL->numVertexes) /* 如果count小于定点数，则说明存在环 */
    {
        return ERROR;
    }
    else
    {
        return OK;
    }
}