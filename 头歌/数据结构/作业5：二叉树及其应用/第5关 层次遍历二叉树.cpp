//
//  binary_tree.cpp
//  BinaryTreeApp
//
//  Created by ljpc on 2018/5/3.
//  Copyright © 2018年 ljpc. All rights reserved.
//

#include "binary_tree.h"
#include <iostream>

void HierarchyOrder(BiTreeNode* root)
// 二叉树的层次遍历（队列实现）
// 参数：二叉树根节点root
// 输出：二叉树的层次遍历，中间没有空格，末尾不换行。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    queue<BiTreeNode*>q;
    q.push(root);
    if(root==NULL)return;
    while(!q.empty()){
    	BiTreeNode*node=q.front();
    	q.pop();
    	cout<<node->data;
    	if(node->left!=NULL){
    		q.push(node->left);
		}
		if(node->right!=NULL){
			q.push(node->right);
		}
	}
    /********** End **********/

}
