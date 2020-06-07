#include <stdio.h>
#include <stdlib.h>

// binary search tree

typedef int element;

typedef struct TreeNode {
    element data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;


// ADT
TreeNode* search(TreeNode* root, element key);
TreeNode* new_node(element key);
TreeNode* insert_node(TreeNode* root, element key);
TreeNode* get_min_node(TreeNode* root);
TreeNode* delete_node(TreeNode* root);
TreeNode* construct_Tree(element key);

TreeNode* search(TreeNode* root, element key) {
    if (root == NULL) return;

    if (root->data == key) return root;
    else if (key < root->data) {
        search(root->left, key);
    }
    else {
        search(root->right, key);
    }
}

TreeNode* new_node(element key) {
    TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
    tmp->data = key;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

TreeNode* insert_node(TreeNode* root, element key) {
    if (root == NULL) return new_node(key);
    else if (key < root->data) {
        root->left = insert_node(root->left, key);
    }
    else {
        root->right = insert_node(root->right, key);
    }
    return root;
}

TreeNode* get_min_node(TreeNode* root) {
    TreeNode* tmp = root;
    while (tmp->left != NULL) {
        tmp = tmp->left;
    }
    return tmp;
}

TreeNode* delete_node(TreeNode* root, element key) {
    if (root == NULL) return root;
    if (key < root->data) {
        root->left = delete_node(root->left, key);
    }
    else if (root->data < key){
        root->right = delete_node(root->right, key);
    }
    // root == key 
    else {
        if (root->right == NULL) {
            TreeNode* tmp = root->left;
            free(root);
            return tmp;
        }
        else if (root->left == NULL) {
            TreeNode* tmp = root->right;
            free(root);
            return tmp;
        }
        else {
            TreeNode* tmp = get_min_node(root->right);
            root->data = tmp->data;
            root->right = delete_node(root->right, tmp->data);
            return root;
        }
    }
    return root;
}

void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(TreeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

TreeNode* construct_Tree(int n) {
    int count = 0;
    TreeNode* head = NULL;
    while (count < n) {
        element key;
        printf("=> ");
        scanf_s("%d", &key, 2);
        head = insert_node(head, key);
        count++;
    }
    return head;
}


int main(void) {
    TreeNode* head = construct_Tree(5);
    inorder(head);
    printf("\n");
    postorder(head);

    head = delete_node(head, 5);
    head = delete_node(head, 4);
    printf("\n");
    inorder(head);
    printf("\n");
    postorder(head);


    return 0;
}
