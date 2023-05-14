//
//  binary_tree.cpp
//  BinaryTreeApp
//
//  Created by ljpc on 2018/5/3.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include "binary_tree.h"
#include <iostream>

BiTreeNode* BiTreeChangeStack(BiTreeNode* root)
// 实现二叉树左右子树的交换（栈实现）
// 参数：二叉树根节点root
// 返回：二叉树
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    stack<BiTreeNode*>s;
    BiTreeNode*temp=NULL,*node=root;
    if(root==NULL)return NULL;
    s.push(root);
    while(!s.empty()){
    	temp=node->left;
    	node->left=node->right;
    	node->right=temp;
    	if(node->right!=NULL){
    		s.push(node->right);
		}
		if(node->left!=NULL){
			node=node->left;
		}else{
			node=s.top();
        	s.pop();
		}
	}
	return node;
    /********** End **********/
}


void PostOrder(BiTreeNode* root)
// 二叉树的后序遍历
// 参数：二叉树根节点root
// 输出：二叉树的后序遍历，中间没有空格，末尾不换行。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if(root==NULL)return;
    if(root->left!=NULL){
    	PostOrder(root->left);
	}
	if(root->right!=NULL){
		PostOrder(root->right);
	}
	cout<<root->data;
    /********** End **********/
}
