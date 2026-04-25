Slip 30:- 
  
Ds)  1) 
#include<stdio.h> 
 
int i,j,a,b,u,v,n,e=1; int min,mincost=0,cost[10][10],parent[10]; 
int find(int); int uni(int,int); 
 
int main() 
{ 
    printf("\nThe edge of maximum cost spanning tree are:\n");     while(e<n) 
    { 
        for(i=1,min=999;i<=n;i++) 
        { 
            for(j=1;j<=n;j++) 
            { 
                if(cost[i][j]<min) 
                { 
                    min=cost[i][j];                     a=u=i;                     b=v=j; 
                } 
            } 
        } 
        u=find(u);         v=find(v);         if(uni(u,v)) 
        { 
            printf("\nEdge %d:(%d->%d) cost:%d",e++,a,b,min);             mincost+=min; 
        } 
        cost[a][b]=cost[b][a]=999; 
    } 
    printf("\nMinimum cost=%d\n",mincost); 
 
    return 0; 
} 
 
int find(int i) 
{ 
    while(parent[i])         i=parent[i];     return i; 
} 
 
int uni(int i,int j) 
{     if(i!=j) 
    { 
        parent[j]=i;         return 1; 
    } 
    return 0; 
} 
 
 
DBMS:- 
CREATE TABLE Student ( 
    Roll_No INT PRIMARY KEY, 
    Sname VARCHAR(20), 
    Sclass CHAR(10) 
); 
 
CREATE TABLE Teacher ( 
    T_No INT PRIMARY KEY, 
    Tname CHAR(20), 
    Experience INT 
); 
 
CREATE TABLE Student_Teacher ( 
    Roll_No INT REFERENCES Student(Roll_No), 
    T_No INT REFERENCES Teacher(T_No), 
    Subject VARCHAR(20), 
    PRIMARY KEY(Roll_No, T_No) 
); 
1A) 
CREATE OR REPLACE FUNCTION count_teachers() 
RETURNS INT 
LANGUAGE plpgsql 
AS $$ DECLARE 
    total INT; 
BEGIN 
 
    SELECT COUNT(*) 
    INTO total 
    FROM Teacher 
    WHERE Experience > 10; 
 
    RETURN total; 
 
END; 
$$; 
 
 
2) 
CREATE OR REPLACE PROCEDURE sum_avg_n(n INT) 
LANGUAGE plpgsql 
AS $$ DECLARE 
    i INT := 1;     s INT := 0; 
    avg_val NUMERIC; 
BEGIN 
 
    WHILE i <= n LOOP 
        s := s + i;         i := i + 1; 
    END LOOP; 
 
    avg_val := s / n; 
 
    RAISE NOTICE 'Sum = %', s; 
    RAISE NOTICE 'Average = %', avg_val; 
 
END; 
$$; 
 

