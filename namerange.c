Slip 12:- 
 
Ds)  2) 
#include<stdio.h> 
#include<stdlib.h> 
 
struct node 
{ 
    int vertex;     struct node *next; 
}; 
 
int visited[10]; 
 
/* read graph */ int read_graph(struct node *adj_list[10], int n) 
{     int i,j,reply; 
    struct node *temp,*nw; 
 
    for(i=1;i<=n;i++) 
    { 
        for(j=1;j<=n;j++) 
        {             if(i==j)                 continue; 
 
            printf("Is there edge between %d and %d: ",i,j);             scanf("%d",&reply); 
 
            if(reply==1) 
            { 
                nw=(struct node*)malloc(sizeof(struct node));                 nw->vertex=j;                 nw->next=NULL; 
 
                if(adj_list[i]==NULL)                     adj_list[i]=nw; 
                else 
                { 
                    temp=adj_list[i]; 
                    while(temp->next!=NULL)                         temp=temp->next;                     temp->next=nw; 
                } 
            } 
        } 
    } 
 
    return 0; 
} 
 
/* DFS */ void dfs(struct node *adj_list[10], int v) 
{ 
    struct node *temp; 
 
    visited[v]=1;     printf("%d ",v); 
 
    temp=adj_list[v]; 
 
    while(temp!=NULL) 
    { 
        if(visited[temp->vertex]==0)             dfs(adj_list,temp->vertex); 
 
        temp=temp->next; 
    } 
} 
 
int main() 
{ 
    struct node *adj_list[10]; 
    int n,i,start; 
 
    printf("Enter number of vertices: ");     scanf("%d",&n); 
 
    for(i=1;i<=n;i++) 
    { 
        adj_list[i]=NULL;         visited[i]=0; 
    } 
 
    read_graph(adj_list,n); 
 
    printf("Enter starting vertex: ");     scanf("%d",&start); 
 
    printf("DFS Traversal:\n");     dfs(adj_list,start); 
 
    return 0; 
} 
DBMS:-  
 
CREATE TABLE PROJECT (     pno INTEGER PRIMARY KEY,     p_name CHAR(30),     ptype CHAR(20),     duration INTEGER 
); 
CREATE TABLE EMPLOYEE (     eno INTEGER PRIMARY KEY,     e_name CHAR(20),     qualification CHAR(15),     joindate DATE 
); 
 
CREATE TABLE EMPLOYEE (     eno INTEGER PRIMARY KEY,     e_name CHAR(20),     qualification CHAR(15),     joindate DATE 
); 
 
1A) 
CREATE OR REPLACE FUNCTION check_project_duration() 
RETURNS TRIGGER 
AS $$ 
BEGIN 
 
    IF NEW.duration <= 0 THEN 
        RAISE EXCEPTION 'Duration must be greater than zero'; 
    END IF; 
 
    RETURN NEW; 
 
END; 
$$ LANGUAGE plpgsql; 
 
CREATE TRIGGER trg_check_duration 
BEFORE INSERT 
ON PROJECT 
FOR EACH ROW 
EXECUTE FUNCTION check_project_duration(); 
 
2) 
CREATE OR REPLACE PROCEDURE count_odd(m INT, n INT) 
LANGUAGE plpgsql 
AS $$ DECLARE 
    i INT; 
    cnt INT := 0; 
BEGIN 
 
    FOR i IN m..n LOOP         IF i % 2 <> 0 THEN 
            cnt := cnt + 1; 
        END IF; 
    END LOOP; 
 
    RAISE NOTICE 'Total odd numbers between % and % = %', m, n, cnt; 
 
END; 
$$; 
 
 
 
 
 
 
 
