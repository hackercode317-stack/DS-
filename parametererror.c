//Q1) Write a C program to find the minimum and maximum values in a Binary Search Tree
//Slip2

#include<stdio.h>
#include<stdlib.h>

typedef struct BSTnode
{
    int data;
    struct BSTnode *left, *right;
} BSTnode;

// Insert function
BSTnode *insert(BSTnode *T, int x)
{
    BSTnode *nw, *temp;

    nw = (BSTnode *)malloc(sizeof(BSTnode));
    nw->data = x;
    nw->left = nw->right = NULL;

    if(T == NULL)
        return nw;

    temp = T;

    while(1)
    {
        if(x < temp->data)
        {
            if(temp->left == NULL)
            {
                temp->left = nw;
                break;
            }
            else
                temp = temp->left;
        }
        else
        {
            if(temp->right == NULL)
            {
                temp->right = nw;
                break;
            }
            else
                temp = temp->right;
        }
    }
    return T;
}

// Create BST
BSTnode *create()
{
    int i, n, x;
    BSTnode *root = NULL;

    printf("\nEnter how many nodes: ");
    scanf("%d", &n);

    printf("Enter tree values: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        root = insert(root, x);
    }

    return root;
}

// Find minimum
int min(BSTnode *T)
{
    BSTnode *temp = T;

    while(temp->left != NULL)
        temp = temp->left;

    return temp->data;
}

// Find maximum
int max(BSTnode *T)
{
    BSTnode *temp = T;

    while(temp->right != NULL)
        temp = temp->right;

    return temp->data;
}

// Main function
int main()
{
    BSTnode *root = NULL;

    root = create();

    if(root != NULL)
    {
        printf("\nMinimum value in BST: %d", min(root));
        printf("\nMaximum value in BST: %d", max(root));
    }

    return 0;
}

----------------------------------------------------- SLIP  - 2 ------------------------------------------------------------------ 
create table area2(aname varchar(20) primary key,area_type varchar(5)); 
create table person2(pno int primary key,pname varchar(20),birthdate date,income money,aname varchar(20),foreign key(aname) references area2(aname)); 
insert into area2 values ('nashik','urban'),('sinner','rural'),('pune','urban'); 
insert into person2 values (101,'amit','1998-05-12',25000,'nashik'),(102,'amit','1999-07-15',30000,'pune'),(103,'amit','2000-02-10',20000,'sinner'),(104,'pooja','1998
11-20',28000,'nashik'); 
create or replace function count_person(area_name varchar) returns int as $$ 
declare  
total int; 
begin 
select count(*) into total from person2 where aname=area_name; 
return total; 
end; 
$$ language plpgsql; 
select count_person('nashik'); 


Q2]  

create or replace procedure divide_num(a int,b int) language plpgsql as $$ 
declare 
result numeric; 
begin  
if b= 0 then 
raise exception 'Division by zero error'; 
end if; 
result := a/b; 
raise notice 'Division Result = %',result; 
end; 
$$; 
call divide_num(10,2); 
call divide_num(5,0);

