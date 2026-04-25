Slip 10:- 
  
Ds)  2) 
#include<stdio.h> 
#include<stdlib.h> 
 
struct node 
{     int data;     struct node *left,*right; }; 
 
/* Create BST */ struct node* create(struct node *T) 
{     int n,i,x; 
    struct node *nw,*temp; 
 
    printf("Enter number of nodes: ");     scanf("%d",&n); 
 
    for(i=0;i<n;i++) 
    { 
        printf("Enter value: ");         scanf("%d",&x); 
 
        nw=(struct node*)malloc(sizeof(struct node));         nw->data=x;         nw->left=nw->right=NULL; 
 
        if(T==NULL)             T=nw;         else 
        { 
            temp=T; 
 
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
                        temp->right=nw;                         break; 
                    } 
                    temp=temp->right; 
                } 
            } 
        } 
    } 
 
    return T; 
} 
 
/* Find Minimum */ int findMin(struct node *T) 
{ 
    while(T->left != NULL) 
        T = T->left; 
 
    return T->data; 
} 
 
/* Find Maximum */ int findMax(struct node *T) 
{ 
    while(T->right != NULL) 
        T = T->right; 
 
    return T->data; 
} 
 
int main() 
{ 
    struct node *T=NULL; 
 
    T=create(T); 
 
    printf("Minimum value = %d\n",findMin(T));     printf("Maximum value = %d\n",findMax(T)); 
 
    return 0; 
} 
DBMS:-  
CREATE TABLE Book (     b_no INT PRIMARY KEY,     b_name VARCHAR(20),     pub_name VARCHAR(10) NOT NULL,     b_price FLOAT 
); 
 
CREATE TABLE Author (     a_no INT PRIMARY KEY,     a_name VARCHAR(20),     qualification VARCHAR(15),     address VARCHAR(15) 
); 
 
 
CREATE TABLE Book_Author (     b_no INT REFERENCES Book(b_no),     a_no INT REFERENCES Author(a_no), 
    PRIMARY KEY (b_no,a_no) 
); 
 
1B) 
CREATE OR REPLACE FUNCTION check_book_price() 
RETURNS TRIGGER 
AS $$ 
BEGIN 
 
    IF NEW.b_price > 1000 THEN 
        RAISE NOTICE 'Price is so high'; 
    END IF; 
 
    RETURN NEW; 
 
END; 
$$ LANGUAGE plpgsql; 
 
CREATE TRIGGER trg_book_price 
AFTER INSERT 
ON Book 
FOR EACH ROW 
EXECUTE FUNCTION check_book_price(); 
 
2) 
CREATE OR REPLACE PROCEDURE show_even_numbers() 
LANGUAGE plpgsql 
AS $$ DECLARE 
    i INT := 2; 
BEGIN 
 
    WHILE i <= 50 LOOP         RAISE NOTICE '%', i; 
        i := i + 2; 
    END LOOP; 
 
END; 
$$; 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
