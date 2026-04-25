Slip 24:- 
  
Ds)  2) 
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
 
struct node 
{ 
    char name[30];     char phone[15];     struct node *left,*right; 
}; 
 
/* create node in BST */ struct node* create(struct node *T,char name[],char phone[]) { 
    struct node *nw; 
 
    if(T==NULL) 
    { 
        nw=(struct node*)malloc(sizeof(struct node));         strcpy(nw->name,name);         strcpy(nw->phone,phone);         nw->left=nw->right=NULL;         return nw; 
    } 
 
    if(strcmp(name,T->name)<0)         T->left=create(T->left,name,phone); 
    else 
        T->right=create(T->right,name,phone); 
 
    return T; 
} 
 
/* search contact */ void search(struct node *T,char name[]) 
{ 
    if(T==NULL) 
    { 
        printf("Contact not found\n"); 
        return; 
    } 
 
    if(strcmp(name,T->name)==0) 
    { 
        printf("Name: %s\nPhone: %s\n",T->name,T->phone); 
        return; 
    } 
 
    if(strcmp(name,T->name)<0) 
        search(T->left,name);     else 
        search(T->right,name); 
} 
 
/* display phonebook */ void inorder(struct node *T) 
{ 
    if(T!=NULL) 
    { 
        inorder(T->left);         printf("%s : %s\n",T->name,T->phone); 
        inorder(T->right); 
    } 
} 
 
int main() 
{ 
    struct node *T=NULL; 
    int ch; 
    char name[30],phone[15]; 
 
    while(1) 
    { 
        printf("\n1.Add Contact");         printf("\n2.Search Contact");         printf("\n3.Display Phonebook"); 
        printf("\n4.Exit"); 
 
        printf("\nEnter choice: ");         scanf("%d",&ch); 
 
        switch(ch) 
        { 
            case 1: 
                printf("Enter name: ");                 scanf("%s",name); 
 
                printf("Enter phone number: ");                 scanf("%s",phone); 
 
                T=create(T,name,phone); 
                break; 
             case 2: 
                printf("Enter name to search: ");                 scanf("%s",name);                 search(T,name); 
                break; 
 
            case 3: 
                printf("\nPhonebook:\n"); 
                inorder(T);                 break; 
 
            case 4:                 return 0;             default: 
                printf("Invalid choice\n"); 
        } 
    } 
} 
 
DBMS:- 
CREATE TABLE Department (     dno INTEGER PRIMARY KEY,     dname VARCHAR(20),     city VARCHAR(20) 
); 
 
CREATE TABLE Employee (     eno INTEGER PRIMARY KEY,     ename VARCHAR(20),     salary MONEY,     dno INTEGER REFERENCES Department(dno) 
); 
 
1B) 
CREATE OR REPLACE FUNCTION emp_insert_msg() 
RETURNS TRIGGER 
AS $$ 
BEGIN 
    RAISE NOTICE 'Employee record inserted successfully'; 
    RETURN NEW; 
END; 
$$ LANGUAGE plpgsql; 
 
CREATE TRIGGER trg_emp_insert 
AFTER INSERT 
ON Employee 
FOR EACH ROW 
EXECUTE FUNCTION emp_insert_msg(); 
 
2) 
CREATE OR REPLACE PROCEDURE even_numbers() 
LANGUAGE plpgsql 
AS $$ DECLARE 
    i INT := 2; 
    count INT := 0; 
BEGIN 
 
    WHILE count < 20 LOOP 
        RAISE NOTICE '%', i; 
        i := i + 2; 
        count := count + 1; 
    END LOOP; 
 
END; 
$$; 
 
 
