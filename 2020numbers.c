Slip 17:-

Ds)  2) 
#include<stdio.h> 
#include<stdlib.h> 
 
struct node 
{ 
    int data;     struct node *left,*right; 
}; 
 
/* create node in BST */ struct node* create(struct node *T,int x) { 
    struct node *nw; 
 
    if(T==NULL) 
    { 
        nw=(struct node*)malloc(sizeof(struct node));         nw->data=x;         nw->left=nw->right=NULL; 
        return nw; 
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
CREATE TABLE STUDENT (     sreg_no INT PRIMARY KEY,     name CHAR(30), 
    class CHAR(10) 
); 
 
CREATE TABLE COMPETITION (     c_no INT PRIMARY KEY,     name CHAR(20),     c_type CHAR(15) 
); 
 
CREATE TABLE STUDENT_COMPETITION (     sreg_no INT REFERENCES STUDENT(sreg_no),     c_no INT REFERENCES COMPETITION(c_no), 
    rank INT,     year INT,     prize INT, 
    PRIMARY KEY(sreg_no, c_no, year) 
); 
 
1A) 
CREATE OR REPLACE FUNCTION comp_update_msg() 
RETURNS TRIGGER 
AS $$ 
BEGIN 
    RAISE NOTICE 'Competition record is being updated'; 
    RETURN NEW; 
END; 
$$ LANGUAGE plpgsql; 
 
CREATE TRIGGER trg_comp_update 
BEFORE UPDATE 
ON COMPETITION 
FOR EACH ROW 
EXECUTE FUNCTION comp_update_msg(); 
 
2) 
CREATE OR REPLACE PROCEDURE sum_50() 
LANGUAGE plpgsql 
AS $$ DECLARE 
    i INT := 1;     s INT := 0; 
BEGIN 
 
    LOOP 
        EXIT WHEN i > 50; 
 
        s := s + i;         i := i + 1; 
 
    END LOOP; 
 
    RAISE NOTICE 'Sum of first 50 numbers = %', s; 
 
END; 
$$; 
 
 
 
