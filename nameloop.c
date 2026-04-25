Slip 14:- 
  
Ds)  1) 
#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
 
struct node 
{ 
    char name[30];     char phone[15];     struct node *left,*right; 
}; 
 
/* Insert contact */ struct node* insert(struct node *T, char name[], char phone[]) 
{ 
    struct node *nw,*temp,*parent; 
 
    nw=(struct node*)malloc(sizeof(struct node));     strcpy(nw->name,name);     strcpy(nw->phone,phone);     nw->left=nw->right=NULL; 
 
    if(T==NULL)         return nw; 
 
    temp=T; 
 
    while(temp!=NULL) 
    { 
        parent=temp; 
 
        if(strcmp(name,temp->name)<0)             temp=temp->left; 
        else 
            temp=temp->right; 
    } 
 
    if(strcmp(name,parent->name)<0) 
        parent->left=nw;     else         parent->right=nw; 
 
    return T; 
} 
 
/* Search contact */ void search(struct node *T,char name[]) 
{ 
    while(T!=NULL) 
    { 
        if(strcmp(name,T->name)==0) 
        { 
            printf("Name: %s\nPhone: %s\n",T->name,T->phone); 
            return; 
        } 
 
        if(strcmp(name,T->name)<0) 
            T=T->left;         else 
            T=T->right; 
    } 
 
    printf("Contact not found\n"); 
} 
 
/* Display phonebook */ void inorder(struct node *T) 
{ 
    if(T!=NULL) 
    { 
        inorder(T->left); 
        printf("%s : %s\n",T->name,T->phone); 
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
        printf("\n1.Insert Contact");         printf("\n2.Search Contact");         printf("\n3.Display Phonebook");         printf("\n4.Exit"); 
 
        printf("\nEnter choice: ");         scanf("%d",&ch); 
 
        switch(ch) 
        {             case 1: 
                printf("Enter name: ");                 scanf("%s",name); 
 
                printf("Enter phone number: ");                 scanf("%s",phone); 
 
                T=insert(T,name,phone); 
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
CREATE TABLE PROJECT (     pno INTEGER PRIMARY KEY,     p_name CHAR(30),     ptype CHAR(20),     duration INTEGER 
); 
 
CREATE TABLE EMPLOYEE ( 
    eno INTEGER PRIMARY KEY,     e_name CHAR(20),     qualification CHAR(15),     joindate DATE 
); 
CREATE TABLE PROJECT_EMPLOYEE (     pno INTEGER REFERENCES PROJECT(pno),     eno INTEGER REFERENCES EMPLOYEE(eno), 
    start_date DATE,     no_of_hours_worked INTEGER, 
    PRIMARY KEY(pno, eno) 
); 
 
1A) 
CREATE OR REPLACE FUNCTION check_duration() 
RETURNS TRIGGER 
AS $$ 
BEGIN 
    IF NEW.duration <= 0 THEN 
        RAISE EXCEPTION 'Duration must be greater than zero'; 
    END IF; 
 
    RETURN NEW; 
END; 
$$ LANGUAGE plpgsql; 
 
CREATE TRIGGER trg_duration 
BEFORE INSERT 
ON PROJECT 
FOR EACH ROW 
EXECUTE FUNCTION check_duration(); 
2) 
CREATE OR REPLACE PROCEDURE num_word(n INT) 
LANGUAGE plpgsql 
AS $$ DECLARE 
    digit INT; 
BEGIN 
 
    WHILE n > 0 LOOP 
        digit := n % 10; 
 
        CASE digit 
            WHEN 0 THEN RAISE NOTICE 'ZERO'; 
            WHEN 1 THEN RAISE NOTICE 'ONE'; 
            WHEN 2 THEN RAISE NOTICE 'TWO'; 
            WHEN 3 THEN RAISE NOTICE 'THREE'; 
            WHEN 4 THEN RAISE NOTICE 'FOUR'; 
            WHEN 5 THEN RAISE NOTICE 'FIVE'; 
            WHEN 6 THEN RAISE NOTICE 'SIX'; 
            WHEN 7 THEN RAISE NOTICE 'SEVEN'; 
            WHEN 8 THEN RAISE NOTICE 'EIGHT'; 
            WHEN 9 THEN RAISE NOTICE 'NINE'; 
        END CASE; 
 
        n := n / 10; 
    END LOOP; 
 
END; 
$$; 
 
