#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TreeNode {
    element data;
    struct TreeNode* left;
    struct TreeNode* right;

} TreeNode;

//ADT
TreeNode* search(TreeNode* root, element key);
TreeNode* insert_node(TreeNode* root, element key);
TreeNode* delete_node(TreeNode* root, element key);
TreeNode* get_min_node(TreeNode* root);
TreeNode* new_node(element key);
TreeNode* construct_Tree(int n);
void inorder(TreeNode* root);

TreeNode* search(TreeNode* root, element key) {
    if (root == NULL) return NULL;
    if (key < root->data) {
        search(root->left, key);
    }
    else if (root->data < key) {
        search(root->right, key);
    }
    else {
        return root;
    }
}
//
TreeNode* new_node(element key) {
    TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
    tmp->data = key;
    tmp->left = tmp->right = NULL;
    return tmp;
}


TreeNode* insert_node(TreeNode* root, element key) {
    
    if (root == NULL) return new_node(key);
    if (key < root->data) {
        root->left = insert_node(root->left, key);
    }
    else if (root->data < key) {
        root->right = insert_node(root->right, key);
    }
    return root;
}
//


//
TreeNode* get_min_node(TreeNode* root) {
    TreeNode* tmp = root;
    while (tmp->left != NULL) {
        tmp = tmp->left;
    }
    return tmp;
}



TreeNode* delete_node(TreeNode* root, element key) {
    if (root == NULL) return NULL;

    if (key < root->data) {
        root->left = delete_node(root->left, key);
    }
    else if (root->data < key) {
        root->right = delete_node(root->right, key);
    }
    // root->data == key
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
//



TreeNode* construct_Tree(int n) {
    int count = 0;
    TreeNode* head = NULL;
    while (count < n) {
        int tmp;
        printf("=> ");
        scanf_s("%d", &tmp, 2);
        head = insert_node(head, tmp);
        count++;
    }
    return head;
}

void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(void) {
    TreeNode* head = construct_Tree(5);
    inorder(head);
    printf("\n");

    TreeNode* tmp = search(head, 3);
    printf("\n%d\n", tmp->data);

    head = delete_node(head, 5);
    head = delete_node(head, 2);
    inorder(head);
    return 0;
}
