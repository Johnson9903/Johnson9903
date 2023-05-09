//
//  binary_tree.cpp
//  BinaryTreeApp
//
//  Created by ljpc on 2018/5/3.
//  Copyright © 2018年 ljpc. All rights reserved.
//
#include<iostream>
#include "binary_tree.h"
using namespace std;

BiTreeNode* CreatBiTree(char* s, int &i, int len)
// 利用先序遍历创建二叉树
// 参数：先序遍历字符串s，字符串初始下标i=0，字符串长度len。
// 返回：二叉树
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    BiTreeNode* root;
    root = new BiTreeNode;
    if(i<len)
    {
    root->data = s[i++];
    if(root->data!='#')
    {
    root->left = CreatBiTree(s, i, len);
    root->right = CreatBiTree(s, i, len);
    }
    }
    return root;
    /********** End **********/
}

void InOrder(BiTreeNode* root)
// 二叉树的中序遍历
// 参数：二叉树根节点root
// 输出：中间没有空格，末尾不换行。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(root->left!=NULL)
    {
        InOrder(root->left);
    }
    if(root->data!='#')
    {
        cout<<root->data;
    }
    if(root->right!=NULL)
    {
        InOrder(root->right);
    }
    /********** End **********/

}
