#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the binary search tree
void insert(struct Node **root, int data)
{
    if (*root == NULL)
    {
        *root = createNode(data);
    }
    else
    {
        if (data < (*root)->data)
        {
            insert(&(*root)->left, data);
        }
        else
        {
            insert(&(*root)->right, data);
        }
    }
}

// Function to search
bool search(struct Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == data)
    {
        return true;
    }
    if (data < root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

// Function to find the minimum node
struct Node *findMin(struct Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL)
    {
        return root;
    }
    return findMin(root->left);
}

// Function to find the maximum node
struct Node *findMax(struct Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->right == NULL)
    {
        return root;
    }
    return findMax(root->right);
}

// Function to perform inorder tree traversal
void inorder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    struct Node *root = NULL;
    insert(&root, 15);
    insert(&root, 30);
    insert(&root, 22);
    insert(&root, 14);
    insert(&root, 70);
    insert(&root, 62);
    insert(&root, 18);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    int n = 14;
    if (search(root, n))
    {
        printf("%d is found!\n", n);
    }
    else
    {
        printf("Not Found: %d\n", n);
    }

    printf("Minimum: %d\n", findMin(root)->data);
    printf("Miaximum: %d\n", findMax(root)->data);
    return 0;
}
