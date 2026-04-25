Slip 28:- 
  
Ds)  2) 
#include<stdio.h> 
 
int a,b,u,v,n,i,j,e=1; 
int visited[10]={0},min,mincost=0,cost[10][10]; 
 
void main() 
{ 
    printf("Enter the number of vertices:");     scanf("%d",&n);     printf("Enter the cost adjacency matrix:\n");     for(i=1;i<=n;i++) 
    { 
        for(j=1;j<=n;j++) 
        { 
           scanf("%d",&cost[i][j]); 
            if(cost[i][j]==0)                 cost[i][j]=999; 
        } 
    } 
    printf("\nCost matrix is:\n ");     for(i=1;i<=n;i++) 
    { 
        for(j=1;j<=n;j++) 
        { 
            printf("%d\t",cost[i][j]); 
        } 
        printf("\n"); 
    } 
 
    visited[1]=1;     while(e<n) 
    { 
        for(i=1,min=999;i<=n;i++) 
        { 
            for(j=1;j<=n;j++) 
            { 
                if(cost[i][j]<min) 
                { 
                    if(visited[i]!=0) 
                    { 
                        min=cost[i][j];                         a=u=i;                         b=v=j; 
                    } 
               } 
           } 
        } 
        if(visited[u]==0 || visited[v]==0) 
        { 
            printf("\nEdge %d:(%d->%d) cost:%d",e++,a,b,min);             mincost+=min;             visited[b]=1; 
        } 
        cost[a][b]=cost[b][a]=999; 
    } 
    printf("\nMinimum cost=%d\n",mincost); 
} 
 
DBMS:- 
CREATE TABLE Company (     name VARCHAR(30) PRIMARY KEY,     address VARCHAR(50),     city VARCHAR(20),     share_value MONEY 
); 
 
CREATE TABLE Person (     pname VARCHAR(30) PRIMARY KEY,     pcity VARCHAR(20) 
); 
 
CREATE TABLE Company_Person (     name VARCHAR(30) REFERENCES Company(name),     pname VARCHAR(30) REFERENCES Person(pname),     no_of_shares INTEGER, 
    PRIMARY KEY(name, pname) 
);
 
1B) 
CREATE OR REPLACE FUNCTION company_delete_msg() 
RETURNS TRIGGER 
AS $$ 
BEGIN 
 
    RAISE NOTICE 'Company record is being deleted'; 
 
    RETURN OLD; 
 
END; 
$$ LANGUAGE plpgsql; 
 
CREATE TRIGGER trg_company_delete 
BEFORE DELETE 
ON Company 
FOR EACH ROW 
EXECUTE FUNCTION company_delete_msg(); 
 
 
 
2) 
CREATE OR REPLACE PROCEDURE divide_numbers(a INT, b INT) 
LANGUAGE plpgsql 
AS $$ DECLARE 
    result NUMERIC; 
BEGIN 
    IF b = 0 THEN 
        RAISE EXCEPTION 'Division by zero is not allowed'; 
    END IF; 
 
    result := a / b; 
 
    RAISE NOTICE 'Result = %', result; 
 
END; 
$$; 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
w