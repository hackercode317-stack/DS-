Slip 4:- 
  
Ds) 2 ) 
#include<stdio.h> 
#include<stdlib.h> 
 
#define MAX 10 
 
struct node 
{ 
    int vertex;     struct node *next; 
}; 
 
struct node *adj[MAX]; int visited[MAX]; 
 
void dfs(int v) 
{ 
    struct node *temp; 
 
    visited[v] = 1;     printf("\tV[%d]", v+1); 
 
    temp = adj[v]; 
 
    while(temp != NULL) 
    { 
        if(visited[temp->vertex] == 0)             dfs(temp->vertex); 
 
        temp = temp->next; 
    } 
} 
 
int main() 
{ 
    struct node *nw, *temp; 
    int n,i,j,reply; 
 
    printf("Enter number of vertices: ");     scanf("%d",&n); 
 
    for(i=0;i<n;i++) 
    { 
        adj[i]=NULL;         visited[i]=0; 
    } 
 
    for(i=0;i<n;i++) 
    { 
        for(j=0;j<n;j++) 
        {             if(i!=j) 
            { 
                printf("\nIs edge present between %d & %d (1/0): ",i+1,j+1);                 scanf("%d",&reply); 
 
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
 
    printf("\nDFS Traversal:\n");     dfs(0); 
 
    return 0; 
} 
DBMS:-  
CREATE TABLE Movies (     m_name VARCHAR(25) PRIMARY KEY,     release_year INTEGER,     budget MONEY 
); 
 
CREATE TABLE Actor (     a_name CHAR(30) PRIMARY KEY, 
    role CHAR(30),     charges MONEY,     a_address VARCHAR(30) 
); 
 
CREATE TABLE Producer (     producer_id INTEGER PRIMARY KEY,     name CHAR(30),     p_address VARCHAR(30) 
); 
 
CREATE TABLE Movie_Actor (     m_name VARCHAR(25) REFERENCES Movies(m_name),     a_name CHAR(30) REFERENCES Actor(a_name),     PRIMARY KEY(m_name, a_name) 
); 
 
CREATE TABLE Movie_Producer (     m_name VARCHAR(25) REFERENCES Movies(m_name),     producer_id INTEGER REFERENCES Producer(producer_id), 
    PRIMARY KEY(m_name, producer_id) 
); 
 
1B) 
CREATE OR REPLACE FUNCTION check_movie_budget() 
RETURNS TRIGGER 
AS $$ 
BEGIN 
 
    IF NEW.budget < 5000000 THEN 
        RAISE EXCEPTION 'Budget must be at least 50 lakh'; 
    END IF; 
 
    RETURN NEW; 
 
END; 
$$ LANGUAGE plpgsql; 
 
CREATE TRIGGER trg_check_budget 
BEFORE INSERT 
ON Movies 
FOR EACH ROW 
EXECUTE FUNCTION check_movie_budget(); 
 
2) 
CREATE OR REPLACE PROCEDURE check_number(n INT) 
LANGUAGE plpgsql 
AS $$ 
BEGIN 
 
    IF n > 0 THEN 
        RAISE NOTICE 'Number is Positive'; 
 
    ELSIF n < 0 THEN 
        RAISE NOTICE 'Number is Negative'; 
 
    ELSE 
        RAISE NOTICE 'Number is Zero'; 
    END IF; 
 
END; 
$$; 
 
