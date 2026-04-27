
 Q1) Write a program to sort n randomly generated elements using 
Heapsort method.

#include<stdio.h>
void heapsort(int arr[], int n);
void heapify(int arr[], int n, int i);
void swap(int *a, int *b);

int main()
{
    int arr[20], i, n;

    printf("\nEnter how many elements :- ");
    scanf("%d", &n);

    printf("\nEnter Array Elements : ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heapsort(arr, n);

    printf("\nSorted Elements are : ");
    for(i = 0; i < n; i++)
        printf("%d\t", arr[i]);

    return 0;
}

// Swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function
void heapify(int arr[], int n, int i)
{
    int largest = i;          
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap sort
void heapsort(int arr[], int n)
{
    int i;

    // Build max heap
    for(i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements
    for(i = n - 1; i > 0; i--)   
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}


Q1]  
create table train8(train_no int primary key,train_name varchar(50),depart_time time,arrival_time time,source_stn varchar(20),dest_stn 
varchar(20),no_of_res_bogies int,bogie_capacity int); 
create table pass8(pass_id int primary key,pass_name varchar(15),address varchar(20),age int,gender varchar(15)); 
create table ticket(train_no int,pass_id int,ticket_no int,bogie_no int,no_of_berths int,tdate date,ticket_amt decimal(7,2),status char,primary 
key(train_no,pass_id),foreign key(train_no) references train8(train_no),foreign key(pass_id) references pass8(pass_id)); 
insert into train8 values(1,'rajdhani','10:00','18:00','mumbai','delhi',5,72),(2,'express','09:00','16:00','pune','nagpur',4,70); 
insert into pass8 values(101,'amit','nashik',25,'M'),(102,'sneha','pune',20,'F'); 
insert into ticket values(1,101,1001,2,1,'10-02-2024',2000,'C'),(2,102,1002,1,2,'12-05-2024',2200,'W'); 

create or replace function age_check() returns trigger as $$ 
begin 
if NEW.age>5 then raise notice 'Age above 5 will be charged full fare'; 
return null; 
end if; 
return NEW; 
end ; 
$$ language plpgsql; 

create trigger trg_pass_age 
before insert on pass8  
for each row 
execute function age_check(); 
insert into pass8 values(103,'riya','pune',10,'F'); 
insert into pass8 values(104,'rohan','mumbai',2,'M'); 

Q2]  

create or replace procedure add_2_num(a int, b int) language plpgsql as $$ 
begin 
raise notice 'Addition of % and % is:- %',a,b,a+b; 
end; 
$$; 
call add_2_num(5,4);