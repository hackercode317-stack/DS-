Slip 2:- 
  
Ds)  1) 
#include<stdio.h> 
#include<stdlib.h> 
 
struct node 
{ 
    int data;     struct node *left,*right; 
}; 
 
/* Create BST */ 
struct node* create(struct node *root) 
{     int n,i,x; 
    struct node *nw,*temp; 
 
    printf("Enter number of nodes: ");     scanf("%d",&n); 
 
    for(i=0;i<n;i++) 
    { 
        printf("Enter value: ");         scanf("%d",&x); 
 
        nw=(struct node*)malloc(sizeof(struct node));         nw->data=x;         nw->left=nw->right=NULL; 
 
        if(root==NULL)             root=nw; 
        else 
        { 
            temp=root; 
 
            while(1) 
            { 
                if(x < temp->data) 
                { 
                    if(temp->left==NULL) 
                    { 
                        temp->left=nw;                         break; 
                    } 
                    temp=temp->left; 
                }                 else 
                { 
                    if(temp->right==NULL) 
                    { 
                        temp->right=nw; 
                        break; 
                    } 
                    temp=temp->right; 
                } 
            } 
        } 
    } 
 
    return root; 
} 
 
/* Find Minimum */ int findMin(struct node *root) 
{ 
    while(root->left!=NULL)         root=root->left; 
 
    return root->data; 
} 
 
/* Find Maximum */ int findMax(struct node *root) 
{
while(root->right!=NULL) 
        root=root->right; 
 
    return root->data; 
} 
 
int main() 
{ 
    struct node *root=NULL; 
 
    root=create(root); 
 
    printf("Minimum value = %d\n",findMin(root));     printf("Maximum value = %d\n",findMax(root)); 
 
    return 0; 
} 
 
DBMS:-  
CREATE TABLE Area (     aname VARCHAR(20) PRIMARY KEY,     area_type VARCHAR(5) CHECK (area_type IN ('urban','rural')) 
); 
 
CREATE TABLE Person (     pno INTEGER PRIMARY KEY,     pname VARCHAR(20), 
    birthdate DATE,     income MONEY,     aname VARCHAR(20) REFERENCES Area(aname) 
);
1A) 
CREATE OR REPLACE FUNCTION count_persons(area_name VARCHAR) 
RETURNS INTEGER 
LANGUAGE plpgsql 
AS $$ DECLARE 
    total_persons INTEGER; 
BEGIN 
 
    SELECT COUNT(*) INTO total_persons 
    FROM Person 
    WHERE aname = area_name; 
 
    RETURN total_persons; 
 
END; 
$$; 
 
2) 
CREATE OR REPLACE PROCEDURE divide_numbers(a NUMERIC, b NUMERIC) LANGUAGE plpgsql  
AS $$ DECLARE 
    result NUMERIC; 
BEGIN 
 
    IF b = 0 THEN 
        RAISE EXCEPTION 'Error: Division by zero is not allowed'; 
    END IF; 
 
    result := a / b; 
RAISE NOTICE 'Division Result = %', result; 
 
END; 
$$; 
 
 
 
 
 
 
 
