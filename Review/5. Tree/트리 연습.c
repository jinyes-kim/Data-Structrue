#include <stdio.h>
#include <stdlib.h>

/*
basic 코드와 다른점은 순회에서 끝 처리 방법
*/


typedef int element;

typedef struct treeNode {
    element data;
    struct treeNode* left;
    struct treeNode* right;
} treeNode;


//ADT
void preorder(treeNode* root);
void inorder(treeNode* root);
void postorder(treeNode* root);


void preorder(treeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(treeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(treeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main(void) {
    treeNode n7 = {7, NULL, NULL };
    treeNode n6 = {6, NULL, NULL};
    treeNode n5 = {5, NULL, NULL};
    treeNode n4 = {4, NULL, NULL};
    treeNode n3 = {3, &n6, &n7};
    treeNode n2 = {2, &n4, &n5};
    treeNode n1 = {1, &n2, &n3};

    postorder(&n1);
    printf("\n");
    inorder(&n1);
    printf("\n");
    preorder(&n1);
    printf("\n");
    return 0;
}
