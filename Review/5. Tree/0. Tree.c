#include <stdio.h>
#include <stdlib.h>

/*
Basic Tree

*/
typedef int element;

typedef struct TreeNode {
    element data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

void preorder(TreeNode* head) {
    if (head == NULL) return;
    printf("[%d] ", head->data);
    preorder(head->left);
    preorder(head->right);
}

void inorder(TreeNode* head) {
    if (head == NULL) return;
    inorder(head->left);
    printf("[%d] ", head->data);
    inorder(head->right);
}

void postorder(TreeNode* head) {
    if (head == NULL) return;
    postorder(head->left);
    postorder(head->right);
    printf("[%d] ", head->data);
}

int main(void) {
    TreeNode n6 = { 6, NULL, NULL };
    TreeNode n5 = { 5, NULL, NULL };
    TreeNode n4 = { 4, NULL, NULL };
    TreeNode n3 = { 3, &n6, NULL };
    TreeNode n2 = { 2, &n4, &n5 };
    TreeNode n1 = { 1, &n2, &n3 };

    printf("\n\npreorder: ");
    preorder(&n1);
    printf("\n\ninorder: ");
    inorder(&n1);
    printf("\n\npostorder: ");
    postorder(&n1);
}
