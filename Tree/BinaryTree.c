/* 二叉树的二叉链表结点结构定义 */
typedef int TElemType; /* 树节点的数据类型，目前暂定位整型 */
typedef struct BiTNode /* 结点结构 */
{
    TElemType data;                 /* 结点数据 */
    struct BiTNode *lchild, *rchild /* 左右孩子指针 */
} BiTNode, *BiTree;

/* 二叉树前序遍历递归算法 */
void PreOrderTraverse(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    printf("%c", T->data);       /* 显示结点数据，也可使用其他对结点的操作来代替打印 */
    PreOrderTraverse(T->lchild); /* 先遍历左子树 */
    PreOrderTraverse(T->rchild); /* 再遍历右子树 */
}

/* 二叉树中序遍历递归算法 */
void InOrderTraverse(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    InOrderTraverse(T->lchild); /* 先中序遍历左子树 */
    printf("%c", T->data);      /* 后打印 */
    InOrderTraverse(T->rchild); /* 最后中序遍历右子树 */
}

/* 二叉树后序遍历递归算法 */
void PostOrderTraverse(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    PostOrderTraverse(T->lchild); /* 先遍历左子树 */
    PostOrderTraverse(T->rchild); /* 再遍历右子树 */
    printf("%c", T->data);        /* 最后打印 */
}

/* 按前序输入二叉树中结点的值（一个字符） */
/* #表示空树，构造二叉链表表示二叉树T */
void CreateBiTree(BiTree *T)
{
    TElemType ch;
    scanf("%c", &ch);
    if (ch == '#')
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTree)mlloc(sizeof(BiTNode));
        if (!*T)
        {
            exit(OVERFLOW);
        }
        (*T)->data = ch;             /* 生成根结点 */
        CreateBiTree(&(*T)->lchild); /* 构造左子树 */
        CreateBiTree(&(*T)->rchild); /* 构造右子树 */
    }
}

/* 二叉树的二叉线索存储结构定义 */
typedef enum
{
    Link,
    Thread
} PointerTag;            /* link == 0 表示指向左右孩子指针，Thread == 1 表示指向前驱或后继的线索 */
typedef struct BiThrNode /* 二叉线索存储结点结构 */
{
    TElemType data;                    /* 结点数据 */
    struct BiThrNode *lchild, *rchild; /* 左右孩子指针 */
    PointerTag LTag;
    PointerTag RTag; /* 左右标志 */
} BiThrNode, *BiThrTree;

/* 中序遍历的线索化递归函数 */
BiThrTree pre; /* 全局变量，始终指向刚刚访问过的结点 */
/* 中序遍历进行中序线索化 */
void InThreading(BiThrTree p)
{
    if (p)
    {
        InThreading(p->lchild);
        if (!p->lchild)
        {
            p->LTag = Thread;
            p->lchild = pre;
        }
        if (!pre->rchild)
        {
            pre->RTag = Thread; /*  */
            pre->rchild = p;    /* 前驱右孩子指针指向后继（当前节点P） */
        }
        pre = p;                /* 保持pre指向p的前驱 */
        InThreading(p->rchild); /* 递归右子树线索化 */
    }
}