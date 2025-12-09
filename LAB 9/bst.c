#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createnode(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node *root, int value) {
    if (root == NULL)
        return createnode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void inorder(struct node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void display(struct node *root) {
    printf("Elements (inorder): ");
    inorder(root);
    printf("\n");
}

int main() {
    struct node *root = NULL;
    int choice, value;

    while (1) {
        printf("\n1. insert into BST\n");
        printf("2. inorder traversal\n");
        printf("3. preorder traversal\n");
        printf("4. postorder traversal\n");
        printf("5. display BST\n");
        printf("6. exit\n");
        printf("enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                display(root);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
