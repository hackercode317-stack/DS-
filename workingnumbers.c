//slip1
//Q1) Write a C program that accepts the vertices and edges of a graph and stores it as an adjacency 
//matrix. Display the adjacency matrix.
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
