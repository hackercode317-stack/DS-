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



----------------------------------------------------- SLIP  - 10 ------------------------------------------------------------------ 
Q1]  
create table book10 (b_no int primary key,b_name varchar(20),pub_name varchar(20) not null,b_price float); 
create table author10(a_no int primary key,a_name varchar(20),qualification varchar(20),address varchar(15)); 
create table book_author10 (b_no int references book10(b_no),a_no int references author10(a_no)); 
insert into book10 values(1,'DBMS','pearson',900),(2,'java','McGraw',1200); 
insert into author10 values(101,'Korth','PhD','USA'),(102,'James','MCA','UK'); 
insert into book_author10 values(1,101),(2,102),(2,101); 
create or replace function dis_msg_of_prize() returns trigger as $$ 
begin 
if NEW.b_price > 1000 then 
raise notice 'Book Price is so High'; 
end if; 
return NEW; 
end;  
$$ language plpgsql; 
create trigger trg_book_insert 
after insert on book10 
for each row 
execute function dis_msg_of_prize(); 
insert into book10 values(4,'DS','pearson',1500); 
Q2]  
create or replace procedure even_num() language plpgsql as $$ 
declare 
i int := 2; 
begin 
while i <= 50 
loop  
raise notice '%',i; 
i := i + 2; 
end loop; 
end;  
$$