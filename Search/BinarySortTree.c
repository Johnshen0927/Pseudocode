#include <stdio.h>
/* 二叉树的二叉链表节点结构定义 */
typedef struct BiTNode /* 结点结构 */
{
    int data;                        /* 结点数据 */
    struct BiTNode *lchild, *rchild; /* 左右孩子指针 */
} BiTNode, *BiTree;

typedef int Status;
/* Serach */
/* 递归查找二叉排序树T中是否存在key */
/* 指针f指向T的双亲，其初始调用值为NULL */
/* 若查找成功，则指针p指向该数据元素，并返回TRUE(1) */
/* 否则指针p指向查找路径上访问的最后一个结点并返回FALSE(0) */

Status SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
    if (!T) /* 树不存在 */
    {
        *p = f;
        return 0;
    }
    else if (key == T->data) /* 查找成功 */
    {
        *p = T;
        return 1;
    }
    else if (key < T->data)
    {
        return SearchBST(T->lchild, key, T, p); /* 往左子树继续查找 */
    }
    else
    {
        return SearchBST(T->rchild, key, T, p); /* 往右子树查找 */
    }
}

/* insert */
/* 当二叉排序树T中不存在关键字等于key的数据元素时 */
/* 插入key并返回TRUE(1)，否则返回FALSE(0) */
Status InsertBST(BiTree *T, int key)
{
    BiTree p, s;
    if (!SearchBST(*T, key, NULL, &p)) /* 判断条件，当数组中不存在将要插入的key时，执行以下代码 */
    {                                  /* 在查找函数中earchBST，查找不成功的情况下返回查找路径上的最后一个结点 */
        s = (BiTree)malloc(sizeof(BiTNode));
        s->data = key;
        s->lchild = s->rchild = NULL;
        if (!p)
        {
            *T = s; /* 插入s为新的根节点 */
        }
        else if (key < p->data)
        {
            p->lchild = s; /* 插入s为左孩子 */
        }
        else
        {
            p->rchild = s; /* 插入s为右孩子 */
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

/* delete */

/* 找到需要删除的节点p的直接前驱（或直接后继）s，用s来替换结点p，然后再删除结点s */
Status Delete(BiTree *p)
{
    BiTree q, s;
    if ((*p)->rchild == NULL) /* 右子树为空，则只需要重接它的左子树 */
    {
        q = *p;
        *p = (*p)->lchild;
        free(q);
    }
    else if ((*p)->lchild == NULL) /* 左子树为空，则只需要重接它的右子树 */
    {
        q = *p;
        *p = (*p)->rchild;
        free(q);
    }
    else /* 左右子树都不空 */
    {
        q = *p;
        s = (*p)->lchild;
        while (s->rchild) /* 转左，然后向右到尽头（找到待删结点的前驱） */
        {
            q = s;
            s = s->rchild;
        }
        (*p)->data = s->data; /* s指向被删节点的直接前驱 */
        if (q != *p)
        {
            q->rchild = s->rchild; /* 重接q的右子树 */
        }
        else
        {
            q->lchild = s->lchild; /* 重接q的左子树 */
        }
        free(s);
    }
    return 1;
}

/* 若二叉排序树T中存在关键字等于key的数据元素，则删除该数据元素结点，并返回TRUE(1)，否则返回FALSE(0) */
Status DeleteBST(BiTree *T, int key)
{
    if (!*T)
    { /* 不存在关键字等于key的数据元素 */
        return 0;
    }
    else
    {
        if (key == (*T)->data)
        { /* 找到关键字等于key的数据元素 */
            return Delete(T);
        }
        else if (key < (*T)->data)
        {
            return DeleteBST(&(*T)->lchild, key);
        }
        else
        {
            return DeleteBST(&(*T)->rchild, key);
        }
    }
}