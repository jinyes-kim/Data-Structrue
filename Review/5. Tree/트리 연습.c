#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct tree {
    element data;
    struct tree* left;
    struct tree* right;
} tree;

//ADT
tree* insert_node(tree* root, element item);
tree* delete_node(tree* root, element item);
tree* get_min_node(tree* root);
tree* new_node(element item);
void preorder(tree* root);

tree* construct_node(int n);

tree* new_node(element item) {
    tree* tmp = (tree*)malloc(sizeof(tree));
    tmp->data = item;
    tmp->right = tmp->left = NULL;
    return tmp;
}

tree* insert_node(tree* root, element item) {
    if (root == NULL) return new_node(item);

    if (root->data < item) {
        root->right = insert_node(root->right, item);
    }
    else if (root->data > item) {
        root->left = insert_node(root->left, item);
    }
    return root;
}

tree* get_min_node(tree* root) {
    tree* tmp = root;
    while (tmp->left != NULL) {
        tmp = tmp->left;
    }
    return tmp;
}

tree* delete_node(tree* root, element item) {
    if (root == NULL) return;

    if (root->data < item) {
        root->right = delete_node(root->right, item);
    }
    else if (root->data > item) {
        root->left = delete_node(root->left, item);
    }
    else {
        if (root->left == NULL) {
            tree* tmp = root->right;
            free(root);
            return tmp;
        }
        else if (root->right == NULL) {
            tree* tmp = root->left;
            free(root);
            return tmp;
        }
        else {
            tree* tmp = get_min_node(root->right);
            root->data = tmp->data;
            root->right = delete_node(root->right, tmp->data);
        }
    }
    return root;
}

void preorder(tree* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

tree* construct_node(int n) {
    int count = 0;
    int input;
    tree* tmp = NULL;
    for (; count < n; count++) {
        printf("삽입 노드: ");
        scanf_s("%d", &input);
        tmp = insert_node(tmp, input);
    }
    return tmp;
}


int main(void) {
    tree* root = construct_node(6);

    preorder(root);
    printf("\n");

    root = delete_node(root, 4);
    root = delete_node(root, 5);
    root = delete_node(root, 1);

    preorder(root);

    return 0;
}
