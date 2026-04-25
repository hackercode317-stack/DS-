Slip 23:- 
  
Ds)  2) 
#include<stdio.h> 
#define MAX 10 
 
typedef struct {     int data[MAX];     int top; 
}STACK; 
 
void initStack(STACK *ps) {     ps->top = -1; 
} 
 
void push(STACK *ps, int num) 
{ 
    ps->top++; 
ps->data[ps->top] = num; 
}
 
int pop(STACK *ps) 
{ 
    return (ps->data[ps->top--]); 
} 
 
int isempty(STACK *ps) 
{ 
    return (ps->top == -1); 
} 
 
int isfull(STACK *ps) 
{ 
    return (ps->top == MAX - 1); 
} 
 
void topologicalSort(int m[10][10], int n) 
{     int i,j,v,w;     int visited[10]={0};     int indegree[10]={0};     STACK s;     for(i=0;i<n;i++) 
    { 
        for(j=0;j<n;j++) 
        { 
            indegree[i] += m[j][i]; 
        } 
    } 
initStack(&s); 
    while(1) 
    { 
        for(v=0;v<n;v++) 
        { 
            if((visited[v]==0) && (indegree[v]==0)) 
            {    
                visited[v]=1;                 push(&s,v);                 printf("v[%d]\t",v+1); 
            } 
        } 
        if(isempty(&s))             break; 
        v=pop(&s);         for(w=0;w<n;w++) 
        { 
            if(m[v][w]==1)                 indegree[w]= indegree[w]-1; 
        } 
    } 
} 
 
int main() 
{ 
    int m[10][10],n,i,j;     printf("Enter the number of vertices:");     scanf("%d",&n);     printf("Enter the adjacency matrix:\n");     for(i=0;i<n;i++) 
{ 
       for(j=0;j<n;j++) 
        { 
            scanf("%d",&m[i][j]); 
        } 
    } 
    printf("Topological order of the vertices:\n");     topologicalSort(m,n); 
 
    return 0; 
} 
 
DBMS:- 
CREATE TABLE Car (     c_no INT PRIMARY KEY,     owner VARCHAR(20),     model VARCHAR(10),     color VARCHAR(10) 
); 
 
CREATE TABLE Driver (     driver_no INT PRIMARY KEY,     driver_name VARCHAR(20),     license_no INT,     d_age INT,     salary FLOAT 
); 
 
CREATE TABLE Car_Driver (     c_no INT REFERENCES Car(c_no),     driver_no INT REFERENCES Driver(driver_no),     PRIMARY KEY (c_no, driver_no) 
); 
 
1B) 
CREATE OR REPLACE FUNCTION check_driver_age() 
RETURNS TRIGGER 
AS $$ 
BEGIN 
 
    IF NEW.d_age < 21 THEN 
        RAISE EXCEPTION 'Driver age must be at least 21'; 
    END IF; 
 
    RETURN NEW; 
 
END; 
$$ LANGUAGE plpgsql; 
 
CREATE TRIGGER trg_driver_age 
BEFORE INSERT OR UPDATE 
ON Driver 
FOR EACH ROW 
EXECUTE FUNCTION check_driver_age(); 
 
 
 
2) 
 
CREATE OR REPLACE PROCEDURE sum_100() 
LANGUAGE plpgsql 
AS $$ 
DECLARE 
    i INT := 1;     s INT := 0; 
BEGIN 
 
    LOOP 
        EXIT WHEN i > 100; 
 
        s := s + i;         i := i + 1; 
 
    END LOOP; 
 
    RAISE NOTICE 'Sum of first 100 numbers = %', s; 
 
END; 
$$; 
 
 
 
 
 
 
