 
 
Slip 21:- 
  
Ds)  1) 
 
#include<stdio.h> 
#define MAX 10 
 
typedef struct {     int data[MAX];     int top; 
}STACK; 
 
void initStack(STACK *ps) {     ps->top = -1; 
} 
void push(STACK *ps, int num) 
{ 
    ps->top++;     ps->data[ps->top] = num; 
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
{     int m[10][10],n,i,j;   printf("Enter the number of vertices:");     scanf("%d",&n);     printf("Enter the adjacency matrix:\n");     for(i=0;i<n;i++) 
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
CREATE TABLE Hospital (     h_no INT PRIMARY KEY,     h_name VARCHAR(20),     city VARCHAR(10) 
); 
 
CREATE TABLE Doctor (     d_no INT PRIMARY KEY,     d_name VARCHAR(30),     specialization VARCHAR(35),     phone_no INT,     charges INT,     h_no INT REFERENCES Hospital(h_no) );
 
1B) 
CREATE OR REPLACE FUNCTION check_charges() 
RETURNS TRIGGER 
AS $$ 
BEGIN 
 
    IF NEW.charges < 0 THEN 
        RAISE EXCEPTION 'Charges cannot be negative'; 
    END IF; 
 
    RETURN NEW; 
 
END; 
$$ LANGUAGE plpgsql; 
 
CREATE TRIGGER trg_charges_check 
BEFORE INSERT OR UPDATE 
ON Doctor 
FOR EACH ROW 
EXECUTE FUNCTION check_charges(); 
 
 
2) 
CREATE OR REPLACE PROCEDURE sum_avg_n(n INT) 
LANGUAGE plpgsql 
AS $$ DECLARE 
    i INT := 1;     s INT := 0;     avg_val NUMERIC; 
BEGIN 
 
    WHILE i <= n LOOP 
        s := s + i;         i := i + 1; 
    END LOOP; 
 
    avg_val := s / n; 
 
    RAISE NOTICE 'Sum = %', s; 
    RAISE NOTICE 'Average = %', avg_val; 
 
END; 
$$; 
 
 
 
 
 
 
ww