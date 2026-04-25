Slip 20:- 
  
Ds)  1) 
#include<stdio.h> 
#include<stdlib.h> 
 
#define MAX 10 
 
struct node 
{ 
    int vertex;     struct node *next; 
}; 
 
void recdfs(struct node *adj[MAX], int v) 
{ 
    struct node *temp;     static int visit[MAX]={0}; 
 
    visit[v]=1;     printf("\tV[%d]",v+1); 
 
    temp=adj[v]; 
 
    while(temp!=NULL) 
    { 
        if(visit[temp->vertex]==0)             recdfs(adj,temp->vertex); 
 
        temp=temp->next; 
    } 
} 
 
int main() 
{ 
    struct node *adj[MAX], *nw, *temp; 
    int n,i,j,reply; 
 
    printf("Enter the number of vertices: ");     scanf("%d",&n); 
 
    for(i=0;i<n;i++)         adj[i]=NULL; 
 
    for(i=0;i<n;i++) 
    { 
        for(j=0;j<n;j++) 
        {             if(i!=j) 
            { 
                printf("\nIs the edge present between %d & %d (1/0): ",i+1,j+1);                 scanf("%d",&reply); 
 
                if(reply==1) 
                { 
                    nw=(struct node*)malloc(sizeof(struct node));                     nw->vertex=j;                     nw->next=NULL; 
 
                    if(adj[i]==NULL)                         adj[i]=nw;                     else 
                    {                         temp=adj[i]; 
                        while(temp->next!=NULL)                             temp=temp->next; 
 
                        temp->next=nw; 
                    } 
                } 
            } 
        } 
    } 
 
    printf("\nDFS Traversal:\n");     recdfs(adj,0); 
 
    return 0; 
} 
 
DBMS:- 
CREATE TABLE Department (     dno INTEGER PRIMARY KEY,     dname VARCHAR(20),     city VARCHAR(20) 
); 
 
CREATE TABLE Employee (     eno INTEGER PRIMARY KEY,     ename VARCHAR(20),     salary MONEY, 
    dno INTEGER REFERENCES Department(dno) 
); 
 
1B) 
CREATE OR REPLACE FUNCTION check_salary() 
RETURNS TRIGGER 
AS $$ 
BEGIN 
 
    IF NEW.salary < 0 THEN 
        RAISE EXCEPTION 'Salary cannot be negative'; 
    END IF; 
 
    RETURN NEW; 
 
END; 
$$ LANGUAGE plpgsql; 
 
CREATE TRIGGER trg_salary_check 
BEFORE INSERT OR UPDATE 
ON Employee 
FOR EACH ROW 
EXECUTE FUNCTION check_salary(); 
 
2) 
CREATE OR REPLACE PROCEDURE multiply_num(a INT, b INT) 
LANGUAGE plpgsql 
AS $$ DECLARE 
    result INT; 
BEGIN 
 
    result := a * b; 
 
    RAISE NOTICE 'Multiplication = %', result; 
 
END; 
$$; 
 
 
 
 
 
 
 
 
 
 
