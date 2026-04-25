Slip 26:- 
  
Ds)  2) 
#include<stdio.h> 
#include<stdlib.h> 
 
struct node 
{     int data;     struct node *left,*right; 
}; 
 
/* create BST */ struct node* create(struct node *T,int x) 
{ 
    struct node *nw; 
 
    if(T==NULL) 
    { 
        nw=(struct node*)malloc(sizeof(struct node));         nw->data=x;         nw->left=nw->right=NULL;         return nw; 
    } 
 
    if(x < T->data)         T->left=create(T->left,x);     else 
        T->right=create(T->right,x); 
 
    return T; 
} 
 
/* find minimum */ int findMin(struct node *T) 
{ 
    while(T->left!=NULL) 
        T=T->left; 
 
    return T->data; 
} 
 
/* find maximum */ int findMax(struct node *T) 
{ 
    while(T->right!=NULL) 
        T=T->right; 
 
    return T->data; 
} 
 
int main() 
{ 
    struct node *T=NULL; 
    int n,i,x; 
 
    printf("Enter number of nodes: ");     scanf("%d",&n); 
 
    for(i=0;i<n;i++) 
    { 
        printf("Enter value: ");         scanf("%d",&x); 
        T=create(T,x); 
    } 
 
    printf("Minimum value = %d\n",findMin(T));     printf("Maximum value = %d\n",findMax(T)); 
 
    return 0; 
} 
 
DBMS:- 
CREATE TABLE Item (     itemno INTEGER PRIMARY KEY,     itemname VARCHAR(20),     quantity INTEGER 
); 
CREATE TABLE Supplier (     supplierno INTEGER PRIMARY KEY,     supplier_name VARCHAR(20),     city VARCHAR(20) 
); 
 
CREATE TABLE Item_Supplier (     itemno INTEGER REFERENCES Item(itemno),     supplierno INTEGER REFERENCES Supplier(supplierno),     rate MONEY, 
    PRIMARY KEY(itemno, supplierno) 
); 
 
1B) 
CREATE OR REPLACE FUNCTION check_rate_difference() 
RETURNS TRIGGER 
AS $$ 
BEGIN 
 
    IF ABS(NEW.rate - OLD.rate) > 2000 THEN 
        RAISE EXCEPTION 'Rate difference cannot exceed Rs 2000'; 
    END IF; 
 
    RETURN NEW; 
 
END; 
$$ LANGUAGE plpgsql; 
 
CREATE TRIGGER trg_rate_update 
BEFORE UPDATE 
ON Item_Supplier 
FOR EACH ROW 
EXECUTE FUNCTION check_rate_difference(); 
 
 
2) 
CREATE OR REPLACE PROCEDURE subtract_three(a INT, b INT, c INT) 
LANGUAGE plpgsql 
AS $$ DECLARE 
    result INT; 
BEGIN 
 
    result := a - b - c; 
 
    RAISE NOTICE 'Result = %', result; 
 
END; 
$$; 
 
 
 
 
 
 
