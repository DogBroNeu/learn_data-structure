#include <stdlib.h>
#include<stdio.h>
#include <string.h>

// /二叉树节点
typedef struct BINARYNODE
{
    char ch;
    struct BINARYNODE *lchild;//左节点
    struct BINARYNODE *rchild;//右节点
}BinaryNode;

//递归遍历
void Recursion(BinaryNode* root)
{
    if(root == NULL) return;

    // 再遍历做左子树
    Recursion(root->lchild);
    
    //再遍历右子树
    Recursion(root->rchild);
    //先访问根节点
    printf("%c",root->ch);
}

void CreateBinaryTree()
{
    //创建节点
    BinaryNode node1 = {'A' , NULL, NULL};
    BinaryNode node2 = {'B' , NULL, NULL};
    BinaryNode node3 = {'C' , NULL, NULL};
    BinaryNode node4 = {'D' , NULL, NULL};
    BinaryNode node5 = {'E' , NULL, NULL};
    BinaryNode node6 = {'F' , NULL, NULL};
    BinaryNode node7 = {'G' , NULL, NULL};
    BinaryNode node8 = {'H' , NULL, NULL};
    //建立节点关系
    node1.lchild = &node2;
    node1.rchild = &node6;
    node2.rchild = &node3;
    node3.lchild = &node4;
    node3.rchild = &node5;
    node6.rchild = &node7;
    node7.lchild = &node8;

    Recursion(&node1);
}



/*          A
           / \
          B   F
           \   \
            C   G
           / \  /
          D   E H
*/
int main()
{
    CreateBinaryTree();
    return 0 ;
}