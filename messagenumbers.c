Slip 19:- 
  
Ds)  1) 
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
 
struct node 
{ 
    char name[30];     char phone[15];     struct node *left,*right; 
}; 
 
/* create node in BST */ 
struct node* create(struct node *T, char name[], char phone[]) 
{ 
    struct node *nw; 
 
    if(T==NULL) 
    { 
        nw=(struct node*)malloc(sizeof(struct node));         strcpy(nw->name,name);         strcpy(nw->phone,phone);         nw->left=nw->right=NULL; 
        return nw; 
    } 
 
    if(strcmp(name,T->name) < 0)         T->left=create(T->left,name,phone); 
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
 
    if(strcmp(name,T->name)<0)         search(T->left,name); 
    else 
        search(T->right,name); 
} 
 
/* display phonebook */ void inorder(struct node *T) 
{ 
    if(T!=NULL) 
    { 
        inorder(T->left); 
        printf("%s : %s\n",T->name,T->phone);         inorder(T->right); 
    } 
} 
 
int main() 
{ 
    struct node *T=NULL; 
    int ch; 
    char name[30],phone[15]; 
 
    while(1) 
    { 
        printf("\n1.Add Contact"); 
        printf("\n2.Search Contact");         printf("\n3.Display Phonebook");         printf("\n4.Exit"); 
 
        printf("\nEnter choice: ");         scanf("%d",&ch); 
 
        switch(ch) 
        {             case 1: 
                printf("Enter name: ");                 scanf("%s",name); 
 
                printf("Enter phone: ");                 scanf("%s",phone); 
 
                T=create(T,name,phone); 
                break; 
 
            case 2: 
                printf("Enter name to search: ");                 scanf("%s",name);                 search(T,name);                 break; 
             case 3: 
                printf("\nPhonebook:\n"); 
                inorder(T);                 break; 
             case 4:                 return 0; 
 
            default: 
                printf("Invalid choice\n"); 
        } 
    } 
} 
DBMS:- 
CREATE TABLE Project (     pno INTEGER PRIMARY KEY,     pname CHAR(30) NOT NULL,     ptype CHAR(20),     duration INTEGER CHECK (duration > 0) 
); 
 
CREATE TABLE Employee (     eno INTEGER PRIMARY KEY,     ename CHAR(20),     qualification CHAR(15),     joining_date DATE 
); 
 
CREATE TABLE Project_Employee (     pno INTEGER REFERENCES Project(pno),     eno INTEGER REFERENCES Employee(eno),     start_date DATE, 
    no_of_hours_worked INTEGER, 
    PRIMARY KEY (pno, eno) 
); 
 
 
1A) 
CREATE OR REPLACE FUNCTION count_projects(emp_no INT) 
RETURNS INT 
LANGUAGE plpgsql 
AS $$ DECLARE 
    total INT; 
BEGIN 
 
    SELECT COUNT(*) 
    INTO total 
    FROM Project_Employee 
    WHERE eno = emp_no; 
 
    RETURN total; 
 
END; 
$$; 
2) 
CREATE OR REPLACE PROCEDURE min_max(a INT, b INT) 
LANGUAGE plpgsql 
AS $$ DECLARE 
    min_val INT;     max_val INT; 
BEGIN 
 
    IF a < b THEN         min_val := a;         max_val := b; 
    ELSE 
        min_val := b;         max_val := a; 
    END IF; 
 
    RAISE NOTICE 'Minimum = %', min_val; 
    RAISE NOTICE 'Maximum = %', max_val; 
 
END; 
$$; 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
