#include <stdio.h>
#include <stdlib.h>
#define max 20
struct node
{
    char data;
    struct node *left;
    struct node *right;
};
struct node *stack[max];
struct node *createNode(int data)
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}
void inorder(struct node *root)
{
    int top = -1;
    struct node *cur = root;
    while (top > -1 || cur != NULL)

    {
        if (cur != NULL)

        {
            stack[++top] = cur;
            cur = cur->left;
        }
        else

        {
            cur = stack[top--];
            printf("%c ", cur->data);
            cur = cur->right;
        }
    }
}
void preorder(struct node *root)
{
    int top =
        -1;
    struct node *cur = root;
    stack[++top] = root;
    while (top > -1)

    {
        cur = stack[top--];
        printf("%c ", cur->data);
        if (cur->right != NULL)

        {
            stack[++top] = cur->right;
        }
        if (cur->left != NULL)

        {
            stack[++top] = cur->left;
        }
    }
}
void postorder(struct node *root)
{
    int top = -1;
    struct node *cur = root;
    do
    {
        while (cur != NULL)
        {
            if (cur->right != NULL)
            {
                stack[++top] = cur->right;
            }
            stack[++top] = cur;
            cur = cur->left;
        }
        cur = stack[top--];
        if (cur->right != NULL && stack[top] == cur->right)
        {
            --top;
            stack[++top] = cur;
            cur = cur->right;
        }
        else
        {
            printf("%c ", cur->data);
            cur = NULL;
        }
    } while (top != -1);
}
int main()
{
    struct node *root = createNode('A');
    root->left = createNode('B');
    root->right = createNode('C');
    root->left->left = createNode('D');
    root->left->right = createNode('E');
    /*
             D
           /  \
         B    C
        / \
      D     E

    */
    printf("Inorder traversal : ");
    inorder(root);
    printf("\nPreorder traversal : ");
    preorder(root);
    printf("\nPostorder traversal : ");
    postorder(root);
    return 0;
}
