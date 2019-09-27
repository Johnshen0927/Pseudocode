/* Adjacency Matrix */
void BFSTraverse(MGraph G)
{
    int i, j;
    Queue Q;
    for (i = 0; i < G.numVertexes; i++)
    {
        visited[i] = FALSE;
        InitQueue(&Q);                      /* 初始化辅助队列 */
        for (i = 0; i < G.numVertexes; i++) /* 对每个顶点做循环 */
        {
            if (!visited[i])
            {                             /* 如果该顶点未访问过 */
                visited[i] = TRUE;        /* 设置顶点状态为已访问 */
                printf("%c", G, vexs[i]); /* 打印顶点 */
                EnQueue(&Q, &i);          /* 将此顶点加入队列 */
                while (!QueueEmpty(Q))    /* 若当前队列不为空 */
                {
                    DeQueue(&Q, &i); /* 将队列中元素pop出队列，赋值给i */
                    for (j = 0; j < G.numVertexes; j++)
                    {
                        /* 判断其他顶点与当前顶点之间，既存在边，又未被访问过 */
                        if (G.arc[i][j] == 1 && !visited[j])
                        {
                            visited[j] = TRUE;       /* 将此顶点标记为已访问 */
                            printf("%c", G.vexs[j]); /* 打印顶点 */
                            EnQueue(&Q, j);          /* 将此顶点加入队列 */
                        }
                    }
                }
            }
        }
    }
}

/* Adjacency List */
void BFSTraverse(GraphAdjList Gl)
{
    int i;
    EdgeNode *p;
    Queue Q;
    for (i = 0; i < GL->numVertexes; i++)
    {
        visited[i] = FALSE;
    }
    InitQueue(&Q);
    for (i = 0; i < GL->numVertexes; i++)
    {
        if (!visited[i])
        {
            visited[i] = TRUE;
            printf("%C", GL->adjList[i].data); /* 打印顶点 */
            EnQueue(&Q, i);
            while (!QueueEmpty(Q))
            {
                DeQueue(&Q, &i);
                p = GL->adjList[i].firstedge; /* 找到当前顶点边表链表头指针 */
                while (p)
                {
                    if (!visited[p->adjvex]) /* 若此顶点未被访问过 */
                    {
                        visited[p->adjvex] = TRUE;
                        printf("%c", GL->adjList[p->adjvex].data);
                        EnQueue(&Q, p->adjvex); /* 将此顶点加入队列 */
                    }
                    p = p -> next; /* 指针指向下一个邻接点 */
                }
            }
        }
    }
}