Slip 15:- 
  
Ds)  2) 
“Btree.h” 
#include<stdio.h> 
#include<stdlib.h> 
 
struct node 
{     int data;     struct node *left,*right; 
}; 
/* create first node */ struct node *create(struct node *root) 
{ 
    struct node *nw,*temp;     int n,i,num; 
 
    printf("Enter number of nodes: ");     scanf("%d",&n); 
 
    temp=root;     printf("Enter the nodes: "); 
 
    for(i=0;i<n;i++) 
    { 
        nw=(struct node *)malloc(sizeof(struct node));         nw->left=NULL;         nw->right=NULL;         scanf("%d",&num);         nw->data=num; 
 
        if(temp==NULL) 
        { 
            root=temp=nw; 
        } 
        else{             temp=root;             while(1) 
            { 
                if(nw->data <temp->data) 
                { 
                   if(temp->left == NULL) 
                    { 
                        temp->left=nw;                         break;                     }                     else{ 
                        temp=temp->left; 
                    }                 } 
                else{                     if(temp->right == NULL) 
                    { 
                        temp->right=nw; 
                        break;                     }                     else{ 
                        temp=temp->right; 
                    } 
                } 
            } 
        } 
    } 
    return root; 
} 
 
/* insert node */ struct node *insert(struct node *T, int x) 
{ 
struct node *nw,*temp; nw=(struct node*)malloc(sizeof(struct node)); nw->left=NULL; nw->right=NULL; 
nw->data=x; 
 
if(T==NULL)     T=nw; else 
    { 
        temp=T;         while(1) 
        { 
            if(x<temp->data) 
                { 
                    if(temp->left==NULL) 
                    { 
                        temp->left=nw;                         break;                     }                     else{ 
                        temp=temp->left; 
                    }                 } 
            else{                 if(temp->right==NULL) 
                { 
                    temp->right=nw; 
                    break;                 } 
                else{ 
                temp=temp->right; 
                } 
            } 
        } 
    } 
return T; 
} 
 
/* search node */ struct node* search(struct node *T,int key) 
{ 
    while(T!=NULL) 
    { 
        if(T->data==key) 
            return T; 
 
        if(key < T->data)             T=T->left;         else 
            T=T->right; 
    } 
 
    return NULL; 
} 
 
/* inorder traversal */ void inorder(struct node *T) 
{ 
    if(T!=NULL) 
    { 
        inorder(T->left);         printf("%d ",T->data);         inorder(T->right); 
    } 
}
 
/* preorder traversal */ void preorder(struct node *T) 
{ 
    if(T!=NULL) 
    { 
        printf("%d ",T->data);         preorder(T->left);         preorder(T->right); 
    } 
} 
 
/* postorder traversal */ void postorder(struct node *T) 
{ 
    if(T!=NULL) 
    { 
        postorder(T->left);         postorder(T->right);         printf("%d ",T->data); 
    } 
} 
 
Main.c 
 
#include<stdio.h> #include"btree.h" 
 
int main() 
{ 
    struct node *T=NULL,*temp;     int ch,x; 
 
    while(1) 
    { 
        printf("\n1.Create");         printf("\n2.Insert");         printf("\n3.Search");         printf("\n4.Inorder");         printf("\n5.Preorder");         printf("\n6.Postorder");         printf("\n7.Exit"); 
 
        printf("\nEnter choice: ");         scanf("%d",&ch); 
 
        switch(ch) 
        { 
            case 1:                 root=create(root); 
                break; 
             case 2: 
                printf("Enter value: ");                 scanf("%d",&x);                 T=insert(T,x);                 break; 
 
            case 3: 
                printf("Enter value to search: ");                 scanf("%d",&x);                 temp=search(T,x); 
 
                if(temp==NULL)                     printf("Element not found\n"); 
                else 
                    printf("Element found\n");                 break; 
 
            case 4: 
                printf("Inorder Traversal:\n"); 
                inorder(T);                 break; 
 
            case 5: 
                printf("Preorder Traversal:\n");                 preorder(T);                 break; 
             case 6: 
                printf("Postorder Traversal:\n");                 postorder(T);                 break; 
             case 7:                 return 0; 
 
            default: 
                printf("Invalid choice\n"); 
        } 
    } 
}
DBMS:-  
 
CREATE TABLE Area (     aname VARCHAR(20) PRIMARY KEY,     area_type VARCHAR(5) CHECK (area_type IN ('urban','rural')) 
); 
 
CREATE TABLE Person (     pnumber INTEGER PRIMARY KEY,     pname VARCHAR(20), 
    birthdate DATE,     income MONEY,     aname VARCHAR(20) REFERENCES Area(aname) 
); 
 
1B) 
 
CREATE OR REPLACE FUNCTION check_pnumber() 
RETURNS TRIGGER 
AS $$ 
BEGIN 
 
    IF NEW.pnumber < 0 THEN 
        RAISE EXCEPTION 'Invalid Number'; 
    END IF; 
 
    RETURN NEW; 
 
END; 
$$ LANGUAGE plpgsql; 
CREATE TRIGGER trg_person_check 
BEFORE INSERT 
ON Person 
FOR EACH ROW 
EXECUTE FUNCTION check_pnumber(); 
 
2) 
CREATE OR REPLACE PROCEDURE odd_numbers() 
LANGUAGE plpgsql 
AS $$ DECLARE 
    i INT := 1; 
BEGIN 
 
    WHILE i <= 100 LOOP 
        IF i % 2 <> 0 THEN 
            RAISE NOTICE '%', i; 
        END IF; 
 
        i := i + 1; 
    END LOOP; 
 
END; 
$$; 
 
 
 
 
 
 
