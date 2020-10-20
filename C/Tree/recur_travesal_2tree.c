#include <stdio.h>
/*
### 树的遍历
      F
     / \
    B   G
   / \   \
  A   D   I
     / \   \
    C   E   H

前序遍历 F-B-A-D-C-E-G-I-H
中序遍历 A-B-C-D-E-F-G-I-H
后续遍历 A-C-E-D-B-H-I-G-F
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){

    int *arr_left = NULL;
    int *arr_right = NULL;
    int result_left = 0;
    int result_right = 0;
    int result = 0;

    if(root == NULL){
        *returnSize = 0;
        return NULL;
    }

    arr_left = preorderTraversal(root->left, &result_left);

    arr_right = preorderTraversal(root->right, &result_right);

    *returnSize = result_left + 1 + result_right;

    int *arr = malloc(sizeof(int) * (*returnSize));

    arr[0] = root->val;   

    if(result_left != 0){
        memcpy(&arr[1], arr_left, result_left * sizeof(int));
        free(arr_left);
    }

    if(result_right != 0){
        memcpy(&arr[1 + result_left], arr_right, result_right* sizeof(int));
        free(arr_right);
    }

    return arr;
}

/* 中序遍历 */
int traversal_head()
{

}

/* 后续遍历 */
int traversal_head()
{

}