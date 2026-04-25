Slip 11:- 
  
Ds)  1) 
#include<stdio.h> 
#include<stdlib.h> 
 
struct node 
{ 
    int data;     struct node *left,*right; 
}; 
 
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
                        temp->right=nw; 
                        break; 
                    } 
                    temp=temp->right; 
                } 
            } 
        } 
    } 
 
    return T; 
} 
 
/* YOUR FUNCTION (UNCHANGED) */ int countNode(struct node *T) 
{ 
static int cnt=0; struct node *temp=T; 
 
if(temp!=NULL) 
{ 
cnt++; countNode(temp->left); countNode(temp->right); 
} 
return cnt; 
} 
 
/* YOUR FUNCTION (UNCHANGED) */ int leafNode(struct node *T) 
{ 
static int lcnt=0; 
struct node *temp=T; if(temp == NULL) return 0; 
 
if(temp!=NULL) 
{ 
if((temp->left==NULL)&&(temp->right==NULL)) 
lcnt++; leafNode(temp->left); leafNode(temp->right); 
} 
return lcnt; 
} 
 
int main() 
{ 
struct node *T=NULL; 
 
T=create(T); 
 
printf("Total nodes = %d\n",countNode(T)); printf("Total leaf nodes = %d\n",leafNode(T)); 
 
return 0; 
} 
 
DBMS:-  
CREATE TABLE Student (     rollno INT PRIMARY KEY,     s_name VARCHAR(30),     class VARCHAR(10) 
); 
CREATE TABLE Subject (     scode INT PRIMARY KEY,     subject_name VARCHAR(30) 
); 
CREATE TABLE Student_Subject (     rollno INT REFERENCES Student(rollno),     scode INT REFERENCES Subject(scode), 
    marks INT, 
    PRIMARY KEY(rollno, scode) 
); 
 
1B) 
CREATE OR REPLACE FUNCTION student_delete_msg() 
RETURNS TRIGGER 
AS $$ 
BEGIN 
    RAISE NOTICE 'Student record is being deleted'; 
    RETURN OLD; 
END; 
$$ LANGUAGE plpgsql; 
 
CREATE TRIGGER trg_student_delete 
BEFORE DELETE 
ON Student 
FOR EACH ROW 
EXECUTE FUNCTION student_delete_msg(); 
 
2) 
CREATE OR REPLACE PROCEDURE sum_avg_n(n INT) 
LANGUAGE plpgsql 
AS $$ DECLARE 
    i INT := 1; 
    sum_val INT := 0;     avg_val FLOAT; 
BEGIN 
 
    WHILE i <= n LOOP         sum_val := sum_val + i; 
        i := i + 1; 
    END LOOP; 
 
    avg_val := sum_val / n; 
 
    RAISE NOTICE 'Sum = %', sum_val; 
    RAISE NOTICE 'Average = %', avg_val; 
 
END; 
$$; 
