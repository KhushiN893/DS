#include <stdio.h>
#include <stdlib.h>
struct tree
{
    char val;
    struct tree *left;
    struct tree *right;
};

typedef struct tree TreeNode;
TreeNode *newTree(char data)
{
    // Allocate memory for new node
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));

    // Assign data to this node val
    root->val = data;
    // Initialize left and right children as NULL
    root->left = NULL;
    root->right = NULL;
    return (root);
}

void inOrder(TreeNode *root)
{
    // base case
    if (root == NULL)
        return;
    // traverse left sub tree first
    inOrder(root->left);
    // traverse current node secondly
    printf("%c ", root->val);
    // traverse right sub tree finally
    inOrder(root->right);
}
void preOrder(TreeNode *root)
{
    // base case
    if (root == NULL)
        return;
    // traverse current node secondly
    printf("%c ", root->val);
    // traverse left sub tree first
    preOrder(root->left);
    // traverse right sub tree finally
    preOrder(root->right);
}
void postOrder(TreeNode *root)
{
    // base case
    if (root == NULL)
        return;
    // traverse left sub tree first
    postOrder(root->left);
    // traverse right sub tree finally
    postOrder(root->right);
    // traverse current node secondly
    printf("%c ", root->val);
}

int main()
{
    // building the tree

    TreeNode *root = newTree('A');
    root->left = newTree('B');
    root->right = newTree('C');
    root->left->left = newTree('D');
    root->left->right = newTree('E');

    /*
              7
            /  \
          1     9
         / \      \
       0     3      10

     */
    printf("Inorder traversal :");
    inOrder(root);
    printf("\nPreorder traversal : ");
    preOrder(root);
    printf("\nPostorder traversal : ");
    postOrder(root);

    return 0;
}
