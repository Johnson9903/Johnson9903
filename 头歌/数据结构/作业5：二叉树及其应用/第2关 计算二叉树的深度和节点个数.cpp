//
//  binary_tree.cpp


#include "binary_tree.h"

//创建新结点的工具函数
BiTreeNode* getNewNode(char e)
{
    BiTreeNode* p = (BiTreeNode*)malloc(sizeof(BiTreeNode));
    p->data = e;
    p->left = p->right = NULL;
    return p;
}

// 计算该二叉树的深度
// 参数：二叉树根节点root
// 返回：二叉树的深度
int GetTreeDepth(BiTreeNode* root)
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!root)return 0;
    if(!root->left && !root->right)return 1;
    int deep=0;
	int deepl = GetTreeDepth(root->left);
    if(deep<deepl)deep=deepl;
	int deepr = GetTreeDepth(root->right);
    if(deep<deepr)deep=deepr;
	return deep+1;
    /********** End **********/
}

// 计算该二叉树的总节点个数
// 参数：二叉树根节点root
// 返回：二叉树的总节点个数
int GetNodeNumber(BiTreeNode* root)
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (root == NULL)
        return 0;
    else
        return GetNodeNumber(root->left) + GetNodeNumber(root->right) +1;
    /********** End **********/
}

// 计算该二叉树的叶子节点个数
// 参数：二叉树根节点root
// 返回：二叉树的叶子节点个数
int GetLeafNodeNumber(BiTreeNode* root)
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(!root)return 0;
    if(!root->left && !root->right) return 1;
    int leaf = GetLeafNodeNumber(root->left);
    leaf += GetLeafNodeNumber(root->right);
    return leaf;
    /********** End **********/
}


