/*
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;

struct node *Create(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

void Insert(int x)
{
    printf("\nInserting %d", x);
    struct node *newnode = Create(x);

    if (newnode != NULL)
    {
        if (root == NULL)
        {
            root = newnode;
            return;
        }

        struct node *temp = root;
        struct node *previous = NULL;

        while (temp != NULL)
        {
            previous = temp;
            if (x > temp->data)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }

        if (x > previous->data)
        {
            previous->right = newnode;
        }
        else
        {
            previous->left = newnode;
        }
    }
}

void Inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

void Preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(3);
    Insert(8);
    Insert(5);
    Insert(9);
    Insert(10);
    Insert(13);
    Insert(11);

    printf("\n");

    printf("\nInorder Traversal:\n");
    Inorder(root);
    printf("\n");

    printf("\nPreorder Traversal:\n");
    Preorder(root);
    printf("\n");

    printf("\nPostorder Traversal:\n");
    Postorder(root);
    printf("\n");

    printf("\nDevanshu Gupta 21BCE0597");
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

// structure of a node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// globally initialized root pointer
struct node *root = NULL;

// creates a new node
struct node *create_node(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("\nMemory for new node can't be allocated");
        return NULL;
    }

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// finds the node with the smallest value in BST
struct node *smallest_node(struct node *root)
{
    struct node *curr = root;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

// finds the node with the largest value in BST
struct node *largest_node(struct node *root)
{
    struct node *curr = root;
    while (curr != NULL && curr->right != NULL)
    {
        curr = curr->right;
    }
    return curr;
}

// inserts the data in the BST
void insert(int data)
{
    struct node *new_node = create_node(data);

    if (new_node != NULL)
    {
        // if the root is empty then make a new node as the root node
        if (root == NULL)
        {
            root = new_node;
            printf("\n* node having data %d was inserted\n", data);
            return;
        }

        struct node *temp = root;
        struct node *prev = NULL;

        // traverse through the BST to get the correct position for insertion
        while (temp != NULL)
        {
            prev = temp;
            if (data > temp->data)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }

        // found the last node where the new node should insert
        if (data > prev->data)
        {
            prev->right = new_node;
        }
        else
        {
            prev->left = new_node;
        }

        printf("\n* node having data %d was inserted\n", data);
    }
}

// deletes the given key node from the BST
struct node *delete (struct node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->data)
    {
        root->left = delete (root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delete (root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = smallest_node(root->right);
        root->data = temp->data;
        root->right = delete (root->right, temp->data);
    }
    return root;
}

// search the given key node in BST
int search(int key)
{
    struct node *temp = root;

    while (temp != NULL)
    {
        if (key == temp->data)
        {
            return 1;
        }
        else if (key > temp->data)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    return 0;
}

// inorder traversal of the BST
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// preorder traversal of the BST
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// postorder travsersal of the BST
void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// getting data from the user
int get_data()
{
    int data;
    printf("\nEnter Data: ");
    scanf("%d", &data);
    return data;
}

// getting kth minimum node
// Function to find k'th smallest element in BST
// Here count denotes the number of nodes processed so far
int count = 0;
struct node *kthSmallest(struct node *root, int k)
{
    // base case
    if (root == NULL)
        return NULL;

    // search in left subtree
    struct node *leftTree = kthSmallest(root->left, k);

    // if k'th smallest is found in left subtree, return it
    if (leftTree != NULL)
        return leftTree;

    // if current element is k'th smallest, return it
    count++;
    if (count == k)
        return root;

    // else search in right subtree
    return kthSmallest(root->right, k);
}

int main()
{
    int userChoice;
    int userActive = 'Y';
    int data;
    struct node *result = NULL;
    struct node *kthsmall;

    while (userActive == 'Y' || userActive == 'y')
    {
        printf("\n\n------- Binary Search Tree ------\n");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Get Largest Node Data");
        printf("\n5. Get Smallest Node data");
        printf("\n\n-- Traversals --");
        printf("\n\n6. Inorder ");
        printf("\n7. Post Order ");
        printf("\n8. Pre Oder ");
        printf("\n9. Exit");

        printf("\n\nEnter Your Choice: ");
        scanf("%d", &userChoice);
        printf("\n");

        switch (userChoice)
        {
        case 1:
            data = get_data();
            insert(data);
            break;

        case 2:
            data = get_data();
            root = delete (root, data);
            break;

        case 3:
            data = get_data();
            if (search(data) == 1)
            {
                printf("\nData was found!\n");
            }
            else
            {
                printf("\nData was not found!\n");
            }
            break;

        case 4:
            result = largest_node(root);
            if (result != NULL)
            {
                printf("\nLargest Data: %d\n", result->data);
            }
            break;

        case 5:
            result = smallest_node(root);
            if (result != NULL)
            {
                printf("\nSmallest Data: %d\n", result->data);
            }
            break;

        case 6:
            inorder(root);
            break;

        case 7:
            postorder(root);
            break;

        case 8:
            preorder(root);
            break;

        case 9:
            printf("\n\nProgram was terminated\n");
            break;
        case 10:
            kthsmall = kthSmallest(root,3);
            printf("%d", kthsmall->data);
            break;

        default:
            printf("\n\tInvalid Choice\n");
            break;
        }

        printf("\n__________\nDo you want to continue? ");
        fflush(stdin);
        scanf(" %c", &userActive);
    }

    return 0;
}
