Q1) Write a C program for the Implementation of Prim’s Minimum 
spanning tree algorithm.

#include<stdio.h>

int a, b, u, v, n, i, j, ne = 1;
int visited[10] = {0}, min, mincost = 0, cost[10][10];

int main()
{
    printf("\nEnter number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter adjacency matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            printf("Enter cost of %d to %d: ", i, j);
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("\nAdjacency Matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            printf("%5d", cost[i][j]);
        printf("\n");
    }

    visited[1] = 1;   // start from vertex 1

    while(ne < n)
    {
        min = 999;

        for(i = 1; i <= n; i++)
        {
            if(visited[i])
            {
                for(j = 1; j <= n; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        visited[v] = 1;
        printf("\nEdge %d: (%d - %d) cost = %d", ne++, a, b, min);
        mincost += min;

        cost[a][b] = cost[b][a] = 999;
    }

    printf("\n\nMINIMUM COST = %d\n", mincost);

    return 0;
}


----------------------------------------------------- SLIP  - 05 ------------------------------------------------------------------ 
Q1]  
create table stude5(sreg_no int primary key,s_name varchar(30),s_class varchar(10)); 
create table compe5(c_no int primary key,c_name varchar(20),c_type varchar(15)); 
create table stud_comp5(sreg_no int,c_no int,rank int,year int,primary key(sreg_no,c_no),foreign key(sreg_no) references stude5(sreg_no),foreign key(c_no) 
references compe5(c_no)); 
insert into stude5 values(1,'amit','SYBSC'),(2,'priya','SYBSC'),(3,'rohit','FYBSC'); 
insert into compe5 values(101,'cricket','sport'),(102,'quiz','academic'),(103,'chess','sport'); 
insert into stud_comp5 values(1,101,1,2023),(2,102,2,2023),(3,103,1,2024),(1,102,3,2024); 
create or replace function comp_update_msg() returns trigger as $$ 
begin 
raise notice 'Competition record is being updated'; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_comp_update 
before update on compe5 
for each row 
execute function comp_update_msg(); 
update compe5 set c_name = 'football' where c_no = 103; 
select * from compe5; 
Q2]  
create or replace procedure find_min(a int,b int, c int) language plpgsql as $$ 
declare  
min_val int := a; 
begin  
if b  < min_val then  
min_val := b; 
end if; 
if c < min_val then 
min_val := c; 
end if; 
raise notice ' Minimum number :- %',min_val; 
end ; 
$$; 
call find_min(10,1,4); 
create or replace procedure find_max(a int,b int,c int) language plpgsql as $$ 
declare  
max_val int := a; 
begin  
if b>max_val then  
max_val := b; 
end if; 
if c>max_val then  
max_val := c; 
end if; 
raise notice ' Maximum number :- %',max_val; 
end ; 
$$; 
call find_max(4,30,33);