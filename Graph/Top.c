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

/* 关键路径算法 */
int *etv, *ltv; /* 事件最早发生时间etv数组，最晚发生时间ltv数组 */
int *stack2;    /* 存储拓扑序列的栈 */
int top2;       /* 存储stack2的指针 */

/* 拓扑排序，用于关键路径计算 */
Status ToplogicalSort(GraphAdjList GL)
{
    EdgeNode *e;
    int i, k, gettop;
    int top = 0;   /* 用于栈指针下表 */
    int count = 0; /* 用于统计输出顶点的个数 */
    int *stack;    /* 建栈，用于将入度为0的顶点入栈 */
    stack = (int *)malloc(GL->numVertexes * sizeof(int));
    for (i = 0; i < GL->numVertexes; i++)
    {
        if (0 == GL->adjList[i].in)
        {
            stack[++top] = i;
        }
    }
    // 优化改进 start
    top2 = 0;                                           /* 初始化为0 */
    etv = (int *)malloc(GL->numVertexes * sizeof(int)); /* 事件最早发生时间 */
    for (i = 0; i < GL->numVertexes; i++)
    {
        etv[i] = 0; /* 初始化为0 */
    }
    stack2 = (int *)malloc(GL->numVertexes * sizeof(int)); /* 初始化 */
    // 优化改进 end
    while (top != 0)
    {
        gettop = stack[top--];
        count++;
        // 优化改进 start
        stack2[++top2] = gettop; /* 将弹出的顶点序号压入拓扑序列的栈 */
        // 优化改进 end

        for (e = GL->adjList[gettop].firstedge; e; e = e->next)
        {
            k = e->adjvex;
            if (!(--GL->adjList[k].in))
            {
                stack[++top] = k;
            }
            // 优化改进 start
            if ((etv[gettop] + e->weight) > etv[k]) /* 计算求出各顶点事件最早发生的时间值 */
            {
                etv[k] = etv[gettop] + e->weight;
            }
            // 优化改进 end
        }
    }
    if (count < GL->numVertexes)
    {
        return ERROR;
    }
    else
    {
        return OK;
    }
}