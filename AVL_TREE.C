#include <stdio.h>
#include <stdlib.h>

struct node {
    int data, height;
    struct node *left, *right;
};

int max(int a, int b) {
    return a > b ? a : b;
}

int height(struct node *n) {
    return n == NULL ? 0 : n->height;
}

struct node* create(int data) {
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

struct node* rightRotate(struct node *y) {
    struct node *x = y->left;
    struct node *t = x->right;

    x->right = y;
    y->left = t;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct node* leftRotate(struct node *x) {
    struct node *y = x->right;
    struct node *t = y->left;

    y->left = x;
    x->right = t;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int balance(struct node *n) {
    return n == NULL ? 0 : height(n->left) - height(n->right);
}

struct node* insert(struct node *root, int
RESULT: 
The above mentioned program has been executed and verified successfully.
 data) {
    if (root == NULL)
        return create(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int b = balance(root);

    if (b > 1 && data < root->left->data)
        return rightRotate(root);

    if (b < -1 && data > root->right->data)
        return leftRotate(root);

    if (b > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (b < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct node *root = NULL;
    int n, i, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("Inorder traversal: ");
    inorder(root);

    return 0;
}