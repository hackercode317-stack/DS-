 
Slip 6:- 
  
Ds)  2) 
#include<stdio.h> 
#include<stdlib.h> 
 
struct node 
{ 
    int data;     struct node *left,*right; }; 
 
/* Create BST */ struct node* create(struct node *T) 
{ 
    struct node *nw,*temp; 
    int n,i,x; 
 
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
 
/* Copy Tree */ struct node* copy(struct node *T) 
{ 
    struct node *nw; 
 
    if(T==NULL)         return NULL; 
 
    nw=(struct node*)malloc(sizeof(struct node)); nw->data=T->data; 
 
    nw->left=copy(T->left);     nw->right=copy(T->right); 
 
    return nw; 
} 
 
/* Compare Trees */ int compare(struct node *T1, struct node *T2) 
{ 
    if(T1==NULL && T2==NULL) 
        return 1; 
 
    if(T1!=NULL && T2!=NULL) 
    { 
        if(T1->data==T2->data &&            compare(T1->left,T2->left) &&            compare(T1->right,T2->right)) 
            return 1; 
    } 
 
    return 0; 
} 
 
/* Inorder Traversal */ void inorder(struct node *T) 
{ 
    if(T!=NULL) 
    { 
        inorder(T->left); 
        printf("%d ",T->data);         inorder(T->right); 
    } 
} 
 
int main() 
{ 
    struct node *T=NULL,*T2=NULL; 
 
    T=create(T);        // create original tree 
    T2=copy(T);         // copy tree 
 
    printf("\nOriginal Tree (Inorder): ");     inorder(T); 
 
    printf("\nCopied Tree (Inorder): ");     inorder(T2); 
 
    if(compare(T,T2))         printf("\nTrees are Equal\n"); 
    else         printf("\nTrees are NOT Equal\n"); 
 
    return 0; 
} 
 
 
DBMS:-  
CREATE TABLE BUS (     bus_no INT PRIMARY KEY,     capacity INT NOT NULL, depot_name VARCHAR(20) 
); 
 
CREATE TABLE ROUTE (     route_no INT PRIMARY KEY,     source CHAR(20),     destination CHAR(20),     no_of_stations INT 
); 
 
CREATE TABLE DRIVER (     driver_no INT PRIMARY KEY,     driver_name CHAR(20),     license_no INT UNIQUE,     address CHAR(20),     d_age INT,     salary FLOAT 
); 
-- BUS_ROUTE (Many buses belong to one route) CREATE TABLE BUS_ROUTE (     bus_no INT REFERENCES BUS(bus_no),     route_no INT REFERENCES ROUTE(route_no), 
    PRIMARY KEY(bus_no) 
); 
 
-- BUS_DRIVER (Many-to-Many) CREATE TABLE BUS_DRIVER (     bus_no INT REFERENCES BUS(bus_no),     driver_no INT REFERENCES DRIVER(driver_no),     duty_date DATE,     shift INT CHECK (shift IN (1,2)), 
PRIMARY KEY(bus_no, driver_no) 
);
 
 
1A) 
CREATE OR REPLACE FUNCTION get_driver_by_bus(b_no INT) 
RETURNS VOID 
LANGUAGE plpgsql 
AS $$ DECLARE 
    rec RECORD; 
BEGIN 
 
    FOR rec IN 
        SELECT d.driver_name 
        FROM DRIVER d 
        JOIN BUS_DRIVER bd ON d.driver_no = bd.driver_no 
        WHERE bd.bus_no = b_no 
    LOOP 
        RAISE NOTICE 'Driver Name: %', rec.driver_name; 
    END LOOP; 
 
END; 
$$; 
 
2) 
CREATE OR REPLACE PROCEDURE check_even_odd(n INT) 
LANGUAGE plpgsql 
AS $$ 
BEGIN 
 
IF n % 2 = 0 THEN 
        RAISE NOTICE 'Number is Even'; 
    ELSE 
        RAISE NOTICE 'Number is Odd'; 
    END IF; 
 
END; 
$$; 
 
 
