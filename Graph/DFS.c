/* Adjacency Matrix */
typedef int Boolean;  /* 定义布尔类型 */
Boolean visited[MAX]; /* 访问标志数组 */
/* 邻接矩阵深度优先递归算法 */
void DFS(MGraph G, int i)
{
    int j;
    visited[i] = TRUE;
    printf("%c", G.vexs[i]); /* 打印顶点 */
    for (j = 0; j < G.numVertexes; j++)
    {
        if (G.arc[i][j] == 1 && !visited[j])
        {
            DFS(G, j); /* 对访问的邻接顶点递归调用 */
        }
    }
}

/* 邻接矩阵的深度遍历操作 */
void DFSTraverse(MGraph G)
{
    int i;
    for (i = 0; i < G.numVertexes; i++)
    {
        visited[i] = FALSE; /* 初始化所有顶点为未访问状态 */
    }
    for (i = 0; i < G.numVertexes; i++)
    {
        if (!visited[i]) /* 对未访问过的顶点调用DFS，若是连通图，只会执行一次 */
        {
            DFS(G, i);
        }
    }
}

/* Adjacency List */
void DFS(GraphAdjList GL, int i)
{
    EdgeNode *p;
    visited[i] = TRUE;
    printf("%c", GL->adjList[i].data); /* 打印顶点 */
    p = GL->adjList[i].firstedge;
    while (p)
    {
        if (!visited[p->adjvex])
        {
            DFS(GL, p->adjvex); /* 对访问的邻接顶点递归调用 */
        }
        p = p->next;
    }
}

/* 邻接表深度遍历操作 */
void DFSTraverse(GraphAdjList GL)
{
    int i;
    for (i = 0; i < GL->numVertexes; i++)
    {
        visited[i] = FALSE; /* 初始化所有顶点为未访问状态 */
    }
    for (i = 0; i < GL->numVertexes; i++)
    {
        if (!visited[i]) /* 对未访问过的顶点调用DFS，若是连通图，只会执行一次 */
        {
            DFS(GL, i);
        }
    }
}