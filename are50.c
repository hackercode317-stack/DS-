Slip 27:- 
  
Ds)  2) 
#include<stdio.h> 
 
int a,b,u,v,n,i,j,e=1; int visited[10]={0},min,mincost=0,cost[10][10]; 
 
void main() 
{ 
    printf("Enter the number of vertices:");     scanf("%d",&n);    printf("Enter the cost adjacency matrix:\n");    for(i=1;i<=n;i++) 
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
                       min=cost[i][j];                        a=u=i;                        b=v=j; 
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
CREATE TABLE Student (     rollno INTEGER PRIMARY KEY,     name VARCHAR(30),     class VARCHAR(10) 
); 
 
CREATE TABLE Subject (     scode VARCHAR(10) PRIMARY KEY,     subject_name VARCHAR(20) 
); 
 
CREATE TABLE Student_Subject (     rollno INTEGER REFERENCES Student(rollno),     scode VARCHAR(10) REFERENCES Subject(scode),     marks_scored INTEGER, 
    PRIMARY KEY(rollno, scode) 
);
 
 
1B) 
CREATE OR REPLACE FUNCTION check_marks() 
RETURNS TRIGGER 
AS $$ 
BEGIN 
 
    IF NEW.marks_scored < 0 THEN 
        RAISE EXCEPTION 'Marks cannot be negative'; 
    END IF; 
 
    RETURN NEW; 
 
END; 
$$ LANGUAGE plpgsql; 
 
CREATE TRIGGER trg_marks_check 
BEFORE INSERT OR UPDATE 
ON Student_Subject 
FOR EACH ROW 
EXECUTE FUNCTION check_marks(); 
 
 
 
2) 
CREATE OR REPLACE PROCEDURE even_numbers() 
LANGUAGE plpgsql 
AS $$ 
DECLARE 
    i INT := 2; 
BEGIN 
 
    WHILE i <= 50 LOOP         RAISE NOTICE '%', i; 
        i := i + 2; 
    END LOOP; 
 
END; 
$$; 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
