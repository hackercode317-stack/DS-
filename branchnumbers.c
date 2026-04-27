
 Q1) Write a C program for the implementation of Topological 
sorting.

#include<stdio.h>
#define MAX 50

typedef struct
{
    int data[MAX];
    int top;
} stack;

// Initialize stack
void initstack(stack *ps)
{
    ps->top = -1;   
}

// Push
void push(stack *ps, int num)
{
    ps->data[++ps->top] = num;
}

// Pop
int pop(stack *ps)
{
    return ps->data[ps->top--];
}

// Check empty
int isempty(stack *ps)
{
    return (ps->top == -1);
}

// Topological Sort
void topological_sort(int m[10][10], int n)
{
    int i, j, v, w;
    int visited[20] = {0};
    int indeg[10] = {0};
    stack ps;

    // Calculate indegree
    for(i = 0; i < n; i++)
    {
        indeg[i] = 0;   // important
        for(j = 0; j < n; j++)
        {
            indeg[i] += m[j][i];
        }
    }

    initstack(&ps);

    printf("\nTopological Order:\n");

    while(1)
    {
        for(v = 0; v < n; v++)
        {
            if(visited[v] == 0 && indeg[v] == 0)
            {
                visited[v] = 1;
                push(&ps, v);
                printf("v[%d] ", v + 1);
            }
        }

        if(isempty(&ps))
            break;

        v = pop(&ps);

        for(w = 0; w < n; w++)
        {
            if(m[v][w] == 1)
                indeg[w]--;
        }
    }
}

// Main
int main()
{
    int m[10][10], n, i, j;

    printf("\nHow many vertices: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j)
                m[i][j] = 0;
            else
            {
                printf("Edge between %d and %d (1/0): ", i+1, j+1);
                scanf("%d", &m[i][j]);
            }
        }
    }

    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            printf("%5d", m[i][j]);
        printf("\n");
    }

    topological_sort(m, n);

    return 0;
}



----------------------------------------------------- SLIP  - 07 ------------------------------------------------------------------ 
Q1]  
create table branch7(br_id int primary key,br_name varchar(20),br_city varchar(20)); 
create table cust7(cno int primary key,c_name varchar(10),caddre varchar(20),city varchar(15)); 
create table loan_app7(lno int primary key,l_amt_required money,l_amt_approved money,l_date date); 
create table ternary7(br_id int,cno int,lno int,primary key(br_id,cno,lno),foreign key(br_id) references branch7(br_id),foreign key(cno) references cust7(cno),foreign 
key(lno) references loan_app7(lno)); 
insert into branch7 values(1,'SBI','nashik'),(2,'BOI','pune'),(3,'HDFC','pune'); 
insert into cust7 values(101,'amit','nashik road','nashik'),(102,'riya','college road','nashik'),(103,'neha','fc road','pune'); 
insert into loan_app7 values(201,50000,45000,'10-01-2024'),(202,45000,30000,'11-05-2023'); 
insert into ternary7 values(1,101,201),(2,103,202),(3,103,201),(2,101,201); 

create or replace function check_cust_no() returns trigger as $$ 
begin 
if NEW.cno<=0 then raise notice 'INVALID CUSTOMER NUMBER'; 
return null; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_customer 
before  insert on cust7 
for each row 
execute function check_cust_no(); 
insert into cust7 values(0,'priya','pavan ngr','nsk'); 

Q2]  

create or replace procedure sum_20_num() language plpgsql as $$ 
declare  
i int := 1; 
total int = 0; 
begin 
loop 
exit when i > 20; 
total := total + i; 
i := i + 1; 
end loop; 
raise notice 'Sum of first 20 numbers :- %',total; 
end; 
$$; 
call sum_20_num(); 