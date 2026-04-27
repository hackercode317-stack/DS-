//1. Write a C program that accepts the vertices and edges of a graph.
//Create and display adjacency list also print indegree, outdegree and
//total degree of all vertex of graph.

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int vertex;
    struct node *next;
};

// Create adjacency list
int read_graph(struct node *adj_list[10], int n)
{
    int i, j, reply;
    struct node *temp, *nw;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(i == j)
                continue;

            printf("\nVertices %d and %d are adjacent? (1/0): ", i, j);
            scanf("%d", &reply);

            if(reply == 1)
            {
                nw = (struct node*)malloc(sizeof(struct node));
                nw->vertex = j;
                nw->next = NULL;

                if(adj_list[i] == NULL)
                {
                    adj_list[i] = nw;
                }
                else
                {
                    temp = adj_list[i];
                    while(temp->next != NULL)
                        temp = temp->next;

                    temp->next = nw;
                }
            }
        }
    }
    return 0;
}

// Display adjacency list
int dislist(struct node *adj_list[10], int n)
{
    struct node *temp;
    int i;

    for(i = 1; i <= n; i++)
    {
        printf("\nv[%d] -> ", i);
        temp = adj_list[i];

        while(temp)
        {
            printf("v[%d] -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL");
    }
    return 0;
}

// In-degree, Out-degree
int inout_degree(struct node *adj_list[10], int n)
{
    struct node *temp;
    int in_deg, out_deg, i, j;

    printf("\n\nVertex\tIn-Degree\tOut-Degree\tTotal");

    for(i = 1; i <= n; i++)
    {
        in_deg = out_deg = 0;

        // Out-degree
        temp = adj_list[i];
        while(temp)
        {
            out_deg++;
            temp = temp->next;
        }

        // In-degree (FIXED)
        for(j = 1; j <= n; j++)
        {
            temp = adj_list[j];
            while(temp)
            {
                if(temp->vertex == i)
                    in_deg++;
                temp = temp->next;
            }
        }

        printf("\nV[%d]\t%d\t\t%d\t\t%d",
               i, in_deg, out_deg, in_deg + out_deg);
    }
    return 0;
}

// Main
void main()
{
    struct node *adj_list[10];
    int n, i;

    printf("\nDirected Graph");
    printf("\nHow many vertices: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
        adj_list[i] = NULL;

    read_graph(adj_list, n);
    dislist(adj_list, n);
    inout_degree(adj_list, n);
}








Q1) Write a C program that accepts the vertices and edges of a graph 
and stores it as an adjacency matrix. Display the adjacency matrix

#include<stdio.h>
#include<stdlib.h>

struct node
{
 int vertex;
 struct node *next;
};

struct node *v[10];   // adjacency list

// Create adjacency matrix
void creamat(int m[10][10], int n)
{
 int i, j;

 for(i = 0; i < n; i++)
 {
     for(j = 0; j < n; j++)
     {
         m[i][j] = 0;

         if(i != j)
         {
             printf("\nIs there an edge between %d and %d (1/0): ", i+1, j+1);
             scanf("%d", &m[i][j]);
         }
     }
 }
}

// Display adjacency matrix
void dismat(int m[10][10], int n)
{
 int i, j;

 printf("\nAdjacency Matrix:\n");

 for(i = 0; i < n; i++)
 {
     for(j = 0; j < n; j++)
         printf("%4d", m[i][j]);

     printf("\n");
 }
}

// Create adjacency list from matrix
void crelist(int m[10][10], int n)
{
 int i, j;
 struct node *temp, *nw;

 for(i = 0; i < n; i++)
 {
     v[i] = NULL;

     for(j = 0; j < n; j++)
     {
         if(m[i][j] == 1)
         {
             nw = (struct node *)malloc(sizeof(struct node));
             nw->vertex = j + 1;
             nw->next = NULL;

             if(v[i] == NULL)
             {
                 v[i] = nw;
                 temp = nw;
             }
             else
             {
                 temp->next = nw;
                 temp = nw;
             }
         }
     }
 }
}

// Display adjacency list
void dislist(int n)
{
 struct node *temp;
 int i;

 printf("\nAdjacency List:\n");

 for(i = 0; i < n; i++)
 {
     printf("V[%d] -> ", i+1);
     temp = v[i];

     while(temp)
     {
         printf("%d -> ", temp->vertex);
         temp = temp->next;
     }
     printf("NULL\n");
 }
}

// Main function
int main()
{
 int m[10][10], n;

 printf("How many vertices: ");
 scanf("%d", &n);

 creamat(m, n);
 dismat(m, n);
 crelist(m, n);
 dislist(n);

 return 0;
}


 Q1) Write a program to sort n randomly generated elements using 
Heapsort method.

#include<stdio.h>
void heapsort(int arr[], int n);
void heapify(int arr[], int n, int i);
void swap(int *a, int *b);

int main()
{
    int arr[20], i, n;

    printf("\nEnter how many elements :- ");
    scanf("%d", &n);

    printf("\nEnter Array Elements : ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heapsort(arr, n);

    printf("\nSorted Elements are : ");
    for(i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    return 0;
}

// Swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function
void heapify(int arr[], int n, int i)
{
    int largest = i;          
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap sort
void heapsort(int arr[], int n)
{
    int i;

    // Build max heap
    for(i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements
    for(i = n - 1; i > 0; i--)   
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}


 Q1) Write a C program to find the height of the tree and check 
whether given tree is balanced or not.

#include<stdio.h>
#include<stdlib.h>

// Structure of Tree Node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Create new node
struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Find height of tree
int height(struct node* root)
{
    if(root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Check if tree is balanced
int isBalanced(struct node* root)
{
    if(root == NULL)
        return 1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int diff = leftHeight - rightHeight;
    if(diff < 0)
        diff = -diff;

    if(diff <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

    return 0;
}

// Main
int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Height of tree = %d\n", height(root));

    if(isBalanced(root))
        printf("Tree is Balanced\n");
    else
        printf("Tree is NOT Balanced\n");

    return 0;
}

Q1) Write a C program for the Implementation of Kruskal’s 
Minimum spanning tree algorithm

#include<stdio.h>
#include<stdlib.h>

int i, j, k, a, b, u, v, n, e = 1;
int min, mincost = 0, cost[9][9], parent[9];

int find(int);
int uni(int, int);

int main()
{
    printf("\nImplementation of Kruskal's Algorithm");
    printf("\nEnter number of vertices: ");
    scanf("%d", &n);

    // Initialize parent array
    for(i = 1; i <= n; i++)
        parent[i] = 0;

    printf("\nEnter cost adjacency matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            printf("Enter cost of %d to %d: ", i, j);
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = 999;   // no edge
        }
    }

    printf("\nEdges of Minimum Cost Spanning Tree:\n");

    while(e < n)
    {
        for(i = 1, min = 999; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(uni(u, v))
        {
            printf("Edge %d: (%d - %d) = %d\n", e++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 999;   // remove edge
    }

    printf("\nMinimum Cost = %d\n", mincost);

    return 0;
}

// Find function
int find(int i)
{
    while(parent[i])
        i = parent[i];
    return i;
}

// Union function
int uni(int i, int j)
{
    if(i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}


Q1) Write a C program for the Implementation of Prim’s Minimum 
spanning tree algorithm.

#include<stdio.h>

int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0}, min, mincost = 0, cost[10][10];

int main()
{
    printf("\nEnter number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter adjacency matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            printf("Enter cost of %d to %d: ", i, j);
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("\nAdjacency Matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            printf("%5d", cost[i][j]);
        printf("\n");
    }

    visited[1] = 1;   // start from vertex 1

    while(ne < n)
    {
        min = 999;

        for(i = 1; i <= n; i++)
        {
            if(visited[i])
            {
                for(j = 1; j <= n; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        visited[v] = 1;
        printf("\nEdge %d: (%d - %d) cost = %d", ne++, a, b, min);
        mincost += min;

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\n\nMINIMUM COST = %d\n", mincost);

    return 0;
}


 Q1) Write a C program for the implementation of Topological 
sorting.

#include<stdio.h>
#define MAX 50

typedef struct
{
    int data[MAX];
    int top;
} stack;

// Initialize stack
void initstack(stack *ps)
{
    ps->top = -1;   
}

// Push
void push(stack *ps, int num)
{
    ps->data[++ps->top] = num;
}

// Pop
int pop(stack *ps)
{
    return ps->data[ps->top--];
}

// Check empty
int isempty(stack *ps)
{
    return (ps->top == -1);
}

// Topological Sort
void topological_sort(int m[10][10], int n)
{
    int i, j, v, w;
    int visited[20] = {0};
    int indeg[10] = {0};
    stack ps;

    // Calculate indegree
    for(i = 0; i < n; i++)
    {
        indeg[i] = 0;   // important
        for(j = 0; j < n; j++)
        {
            indeg[i] += m[j][i];
        }
    }

    initstack(&ps);

    printf("\nTopological Order:\n");

    while(1)
    {
        for(v = 0; v < n; v++)
        {
            if(visited[v] == 0 && indeg[v] == 0)
            {
                visited[v] = 1;
                push(&ps, v);
                printf("v[%d] ", v + 1);
            }
        }

        if(isempty(&ps))
            break;

        v = pop(&ps);

        for(w = 0; w < n; w++)
        {
            if(m[v][w] == 1)
                indeg[w]--;
        }
    }
}

// Main
int main()
{
    int m[10][10], n, i, j;

    printf("\nHow many vertices: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j)
                m[i][j] = 0;
            else
            {
                printf("Edge between %d and %d (1/0): ", i+1, j+1);
                scanf("%d", &m[i][j]);
            }
        }
    }

    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%5d", m[i][j]);
        printf("\n");
    }

    topological_sort(m, n);

    return 0;
}



 Q1) Write a C program to find the minimum and maximum values 
in a Binary Search Tree.

#include<stdio.h>
#include<stdlib.h>

typedef struct BSTnode
{
    int data;
    struct BSTnode *left, *right;
} BSTnode;

// Insert function
BSTnode *insert(BSTnode *T, int x)
{
    BSTnode *nw, *temp;

    nw = (BSTnode *)malloc(sizeof(BSTnode));
    nw->data = x;
    nw->left = nw->right = NULL;

    if(T == NULL)
        return nw;

    temp = T;

    while(1)
    {
        if(x < temp->data)
        {
            if(temp->left == NULL)
            {
                temp->left = nw;
                break;
            }
            else
                temp = temp->left;
        }
        else
        {
            if(temp->right == NULL)
            {
                temp->right = nw;
                break;
            }
            else
                temp = temp->right;
        }
    }
    return T;
}

// Create BST
BSTnode *create()
{
    int i, n, x;
    BSTnode *root = NULL;

    printf("\nEnter how many nodes: ");
    scanf("%d", &n);

    printf("Enter tree values: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        root = insert(root, x);
    }

    return root;
}

// Find minimum
int min(BSTnode *T)
{
    BSTnode *temp = T;

    while(temp->left != NULL)
        temp = temp->left;

    return temp->data;
}

// Find maximum
int max(BSTnode *T)
{
    BSTnode *temp = T;

    while(temp->right != NULL)
        temp = temp->right;

    return temp->data;
}

// Main function
int main()
{
    BSTnode *root = NULL;

    root = create();

    if(root != NULL)
    {
        printf("\nMinimum value in BST: %d", min(root));
        printf("\nMaximum value in BST: %d", max(root));
    }

    return 0;
}


 Write a C program to maintain a phonebook using Binary Search 
Tree by name where each node contains contact name and phone 
number

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char name[50];
    char phone[15];
    struct node *left, *right;
} node;

// Create node
node* createNode(char name[], char phone[])
{
    node* newnode = (node*)malloc(sizeof(node));
    strcpy(newnode->name, name);
    strcpy(newnode->phone, phone);
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Insert BST
node* insert(node* root, char name[], char phone[])
{
    if(root == NULL)
        return createNode(name, phone);

    if(strcmp(name, root->name) < 0)
        root->left = insert(root->left, name, phone);

    else if(strcmp(name, root->name) > 0)
        root->right = insert(root->right, name, phone);

    else
        printf("\nContact already exists!");

    return root;
}

// Search
void search(node* root, char name[])
{
    if(root == NULL)
    {
        printf("\nContact not found!");
        return;
    }

    int cmp = strcmp(name, root->name);

    if(cmp == 0)
    {
        printf("\nContact Found!");
        printf("\nName  : %s", root->name);
        printf("\nPhone : %s", root->phone);
        return;
    }

    if(cmp < 0)
        search(root->left, name);
    else
        search(root->right, name);
}

// Display (Inorder)
void display(node* root)
{
    if(root != NULL)
    {
        display(root->left);
        printf("\nName: %s\tPhone: %s", root->name, root->phone);
        display(root->right);
    }
}

// Main
int main()
{
    node* root = NULL;
    int choice;
    char name[50], phone[15];

    while(1)
    {
        printf("\n\n--- PHONEBOOK MENU ---");
        printf("\n1. Insert Contact");
        printf("\n2. Search Contact");
        printf("\n3. Display Contacts");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter Name: ");
                scanf("%49s", name);
                printf("Enter Phone: ");
                scanf("%14s", phone);
                root = insert(root, name, phone);
                break;

            case 2:
                printf("\nEnter Name to Search: ");
                scanf("%49s", name);
                search(root, name);
                break;

            case 3:
                printf("\nPhonebook Contacts:");
                display(root);
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}




Q1)  Menu Driven Program :- Create, Insert, Search, Inorder, Preorder, 
Postorder, Count Node, Count Leaf. 

#include<stdio.h>
#include<stdlib.h>

typedef struct BSTnode
{
    int data;
    struct BSTnode *left, *right;
} BSTnode;

// Create BST
BSTnode *create();
BSTnode *insert(BSTnode *, int);
BSTnode *search(BSTnode *, int);
void inorder(BSTnode *);
void preorder(BSTnode *);
void postorder(BSTnode *);
int count(BSTnode *);
int countLeaf(BSTnode *);

// Create
BSTnode *create()
{
    int i, n, x;
    BSTnode *root = NULL;

    printf("\nEnter how many nodes: ");
    scanf("%d", &n);

    printf("\nEnter tree values: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        root = insert(root, x);
    }
    return root;
}

// Insert
BSTnode *insert(BSTnode *T, int x)
{
    BSTnode *nw, *temp;

    nw = (BSTnode *)malloc(sizeof(BSTnode));
    nw->data = x;
    nw->left = nw->right = NULL;

    if(T == NULL)
        return nw;

    temp = T;

    while(1)
    {
        if(x < temp->data)
        {
            if(temp->left == NULL)
            {
                temp->left = nw;
                break;
            }
            temp = temp->left;
        }
        else
        {
            if(temp->right == NULL)
            {
                temp->right = nw;
                break;
            }
            temp = temp->right;
        }
    }
    return T;
}

// Search
BSTnode *search(BSTnode *root, int x)
{
    while(root != NULL)
    {
        if(x == root->data)
            return root;

        if(x < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

// Inorder
void inorder(BSTnode *T)
{
    if(T != NULL)
    {
        inorder(T->left);
        printf("%d ", T->data);
        inorder(T->right);
    }
}

// Preorder
void preorder(BSTnode *T)
{
    if(T != NULL)
    {
        printf("%d ", T->data);
        preorder(T->left);
        preorder(T->right);
    }
}

// Postorder
void postorder(BSTnode *T)
{
    if(T != NULL)
    {
        postorder(T->left);
        postorder(T->right);
        printf("%d ", T->data);
    }
}

// Count nodes
int count(BSTnode *T)
{
    if(T == NULL)
        return 0;

    return 1 + count(T->left) + count(T->right);
}

// Count leaf nodes
int countLeaf(BSTnode *T)
{
    if(T == NULL)
        return 0;

    if(T->left == NULL && T->right == NULL)
        return 1;

    return countLeaf(T->left) + countLeaf(T->right);
}

// Main
int main()
{
    BSTnode *root = NULL, *p;
    int x, op;

    do
    {
        printf("\n\n1.Create");
        printf("\n2.Insert");
        printf("\n3.Search");
        printf("\n4.Inorder");
        printf("\n5.Preorder");
        printf("\n6.Postorder");
        printf("\n7.Count Nodes");
        printf("\n8.Count Leaf Nodes");
        printf("\n9.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                root = create();
                break;
            case 2:
                printf("\nEnter value: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;
            case 3:
                printf("\nEnter key: ");
                scanf("%d", &x);
                p = search(root, x);
                if(p == NULL)
                    printf("\nNOT FOUND");
                else
                    printf("\nFOUND");
                break;
            case 4:
                inorder(root);
                break;
            case 5:
                preorder(root);
                break;
            case 6:
                postorder(root);
                break;
            case 7:
                printf("\nTotal nodes = %d", count(root));
                break;
            case 8:
                printf("\nLeaf nodes = %d", countLeaf(root));
                break;
        }

    } while(op != 9);

    return 0;
}