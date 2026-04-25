Slip 5:- 
   
Ds) 1 ) 
#include<stdio.h> 
#include<stdlib.h> 
 
#define MAX 20 
 
struct node 
{
    int data;     struct node *left,*right; 
}; 
 
typedef struct 
{ 
    struct node *data[MAX]; 
    int front,rear; 
}queue; 
 
/* Queue Functions */ 
 
void initq(queue *q) 
{ 
    q->front = q->rear = -1; 
} 
 
void addq(queue *q, struct node *n) 
{ 
    q->data[++q->rear] = n; 
} 
 
struct node* delq(queue *q) 
{ 
    return q->data[++q->front]; 
} 
 
int isempty(queue *q) 
{ 
    return (q->front == q->rear); 
}
 
/* Create BST */ 
 
struct node* create(struct node *root) 
{ 
    struct node *nw,*temp; 
    int n,i,x; 
 
    printf("Enter number of nodes: ");     scanf("%d",&n); 
 
    for(i=0;i<n;i++) 
    { 
        scanf("%d",&x); 
 
        nw=(struct node*)malloc(sizeof(struct node));         nw->data=x;         nw->left=nw->right=NULL; 
 
        if(root==NULL)             root=nw;         else 
        { 
            temp=root; 
 
            while(1) 
            { 
                if(x < temp->data) 
                { 
                    if(temp->left==NULL) 
                    { 
                        temp->left=nw; 
                        break; 
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
 
/* Level Order Traversal */ 
 
void levelorder(struct node *root) 
{ 
    queue q; 
    struct node *temp,*marker=NULL;     int level=0,count=0,total_levels=0; 
 
    initq(&q); 
 
    addq(&q,root);     addq(&q,marker); 
 
    printf("\nLevel %d : ",level); 
 
    while(!isempty(&q)) 
    { 
        temp=delq(&q); 
 
        if(temp==marker) 
        { 
            printf("\nCount of nodes at level %d = %d\n",level,count); 
 
            count=0;             level++;             total_levels++; 
 
            if(!isempty(&q)) 
            { 
                addq(&q,marker);                 printf("\nLevel %d : ",level); 
            }         }         else 
        { 
            printf("%d ",temp->data); 
            count++; 
 
            if(temp->left)                 addq(&q,temp->left);             if(temp->right)                 addq(&q,temp->right); 
        } 
    } 
 
    printf("\nTotal Levels in Tree = %d\n",total_levels); 
} 
 
int main() 
{ 
    struct node *root=NULL; 
 
    root=create(root); 
 
    levelorder(root); 
 
    return 0; 
} 
 
DBMS:-  
CREATE TABLE Student (     sreg_no INT PRIMARY KEY,     s_name VARCHAR(20),     s_class CHAR(10) 
); 
 
CREATE TABLE Competition (     c_no INT PRIMARY KEY,     c_name VARCHAR(20),     c_type CHAR(10) NOT NULL CHECK (c_type IN ('sport','academic')) 
); 
 
CREATE TABLE Student_Competition (     sreg_no INT REFERENCES Student(sreg_no),     c_no INT REFERENCES Competition(c_no), 
    rank INT,     year INT, 
    PRIMARY KEY (sreg_no, c_no, year) 
); 
 
1B) 
CREATE OR REPLACE FUNCTION competition_update_msg() 
RETURNS TRIGGER 
AS $$ 
BEGIN 
    RAISE NOTICE 'Competition record is being updated'; 
    RETURN NEW; 
END; 
$$ LANGUAGE plpgsql; 
 
CREATE TRIGGER trg_comp_update 
BEFORE UPDATE 
ON Competition 
FOR EACH ROW 
EXECUTE FUNCTION competition_update_msg(); 
 
 
2) 
CREATE OR REPLACE PROCEDURE find_min_max_three(a INT, b INT, c INT) 
LANGUAGE plpgsql 
AS $$ 
DECLARE 
    max_val INT;     min_val INT; 
BEGIN 
 
    max_val := GREATEST(a,b,c);     min_val := LEAST(a,b,c); 
 
    RAISE NOTICE 'Maximum = %', max_val; 
    RAISE NOTICE 'Minimum = %', min_val; 
 
END; 
$$; 
 
 
 
 
 
 
 
 
 
Slip 5:- 
   
Ds) 1 ) 
#include<stdio.h> 
#include<stdlib.h> 
 
#define MAX 20 
 
struct node 
{
    int data;     struct node *left,*right; 
}; 
 
typedef struct 
{ 
    struct node *data[MAX]; 
    int front,rear; 
}queue; 
 
/* Queue Functions */ 
 
void initq(queue *q) 
{ 
    q->front = q->rear = -1; 
} 
 
void addq(queue *q, struct node *n) 
{ 
    q->data[++q->rear] = n; 
} 
 
struct node* delq(queue *q) 
{ 
    return q->data[++q->front]; 
} 
 
int isempty(queue *q) 
{ 
    return (q->front == q->rear); 
}
 
/* Create BST */ 
 
struct node* create(struct node *root) 
{ 
    struct node *nw,*temp; 
    int n,i,x; 
 
    printf("Enter number of nodes: ");     scanf("%d",&n); 
 
    for(i=0;i<n;i++) 
    { 
        scanf("%d",&x); 
 
        nw=(struct node*)malloc(sizeof(struct node));         nw->data=x;         nw->left=nw->right=NULL; 
 
        if(root==NULL)             root=nw;         else 
        { 
            temp=root; 
 
            while(1) 
            { 
                if(x < temp->data) 
                { 
                    if(temp->left==NULL) 
                    { 
                        temp->left=nw; 
                        break; 
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
 
/* Level Order Traversal */ 
 
void levelorder(struct node *root) 
{ 
    queue q; 
    struct node *temp,*marker=NULL;     int level=0,count=0,total_levels=0; 
 
    initq(&q); 
 
    addq(&q,root);     addq(&q,marker); 
 
    printf("\nLevel %d : ",level); 
 
    while(!isempty(&q)) 
    { 
        temp=delq(&q); 
 
        if(temp==marker) 
        { 
            printf("\nCount of nodes at level %d = %d\n",level,count); 
 
            count=0;             level++;             total_levels++; 
 
            if(!isempty(&q)) 
            { 
                addq(&q,marker);                 printf("\nLevel %d : ",level); 
            }         }         else 
        { 
            printf("%d ",temp->data); 
            count++; 
 
            if(temp->left)                 addq(&q,temp->left);             if(temp->right)                 addq(&q,temp->right); 
        } 
    } 
 
    printf("\nTotal Levels in Tree = %d\n",total_levels); 
} 
 
int main() 
{ 
    struct node *root=NULL; 
 
    root=create(root); 
 
    levelorder(root); 
 
    return 0; 
} 
 
DBMS:-  
CREATE TABLE Student (     sreg_no INT PRIMARY KEY,     s_name VARCHAR(20),     s_class CHAR(10) 
); 
 
CREATE TABLE Competition (     c_no INT PRIMARY KEY,     c_name VARCHAR(20),     c_type CHAR(10) NOT NULL CHECK (c_type IN ('sport','academic')) 
); 
 
CREATE TABLE Student_Competition (     sreg_no INT REFERENCES Student(sreg_no),     c_no INT REFERENCES Competition(c_no), 
    rank INT,     year INT, 
    PRIMARY KEY (sreg_no, c_no, year) 
); 
 
1B) 
CREATE OR REPLACE FUNCTION competition_update_msg() 
RETURNS TRIGGER 
AS $$ 
BEGIN 
    RAISE NOTICE 'Competition record is being updated'; 
    RETURN NEW; 
END; 
$$ LANGUAGE plpgsql; 
 
CREATE TRIGGER trg_comp_update 
BEFORE UPDATE 
ON Competition 
FOR EACH ROW 
EXECUTE FUNCTION competition_update_msg(); 
 
 
2) 
CREATE OR REPLACE PROCEDURE find_min_max_three(a INT, b INT, c INT) 
LANGUAGE plpgsql 
AS $$ 
DECLARE 
    max_val INT;     min_val INT; 
BEGIN 
 
    max_val := GREATEST(a,b,c);     min_val := LEAST(a,b,c); 
 
    RAISE NOTICE 'Maximum = %', max_val; 
    RAISE NOTICE 'Minimum = %', min_val; 
 
END; 
$$; 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
