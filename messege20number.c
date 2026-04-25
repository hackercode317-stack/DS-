 
Slip 7:- 
  
Ds)  1) 
#include<stdio.h> 
#define MAX 10 
 
typedef struct {     int data[MAX]; 
    int top; 
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
{     int i,j,v,w; 
    int visited[10]={0};     int indegree[10]={0};    STACK s;    for(i=0;i<n;i++) 
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
        if(isempty(&s)) 
            break;         v=pop(&s);         for(w=0;w<n;w++) 
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
CREATE TABLE Branch ( br_id INTEGER PRIMARY KEY, br_name CHAR(30), 
br_city CHAR(10) 
); 
 
CREATE TABLE Customer ( cno INTEGER PRIMARY KEY, c_name CHAR(20), caddr CHAR(35), 
city CHAR(20) 
); 
CREATE TABLE Loan_application (     lno INTEGER PRIMARY KEY,     l_amt_required MONEY CHECK (l_amt_required > 0::money),     l_amt_approved MONEY,     l_date DATE 
); 
 
CREATE TABLE Ternary (     br_id INTEGER REFERENCES Branch(br_id),     cno INTEGER REFERENCES Customer(cno),     lno INTEGER REFERENCES Loan_application(lno), 
    PRIMARY KEY (br_id, cno, lno) 
); 
 
1B) 
CREATE OR REPLACE FUNCTION check_customer_number() 
RETURNS TRIGGER 
AS $$ 
BEGIN 
 
    IF NEW.cno <= 0 THEN 
        RAISE EXCEPTION 'Customer number must be greater than zero'; 
    END IF; 
 
    RETURN NEW; 
 
END; 
$$ LANGUAGE plpgsql; 
 
CREATE TRIGGER trg_check_customer 
BEFORE INSERT 
ON Customer 
FOR EACH ROW 
EXECUTE FUNCTION check_customer_number(); 
 
 
 
2) 
CREATE OR REPLACE PROCEDURE sum_first_20() 
LANGUAGE plpgsql 
AS $$ DECLARE 
    i INT := 1; 
    sum_val INT := 0; 
BEGIN 
 
    LOOP         sum_val := sum_val + i; 
        i := i + 1; 
 
        EXIT WHEN i > 20; 
    END LOOP; 
 
    RAISE NOTICE 'Sum of first 20 numbers = %', sum_val; 
 
END; 
$$; 
