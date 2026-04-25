 
Slip 9:- 
  
Ds)  1) 
#include<stdio.h> 
#define ts 10 
 
typedef struct node 
{ 
    int key,chain; 
}HT; 
 
/* Hash Function */ 
int hf(int key,int i) 
{ 
    return ((key%10+1)%10); 
} 
 
/* Initialize Hash Table */ void init(HT ht[ts]) 
{     int i; 
    for(i=0;i<ts;i++) 
    { 
        ht[i].key=-1;         ht[i].chain=-1; 
    } 
} 
 
/* Insert Key */ void insert(HT ht[ts],int key) 
{ 
    int index = hf(key,0); 
 
    if(ht[index].key==-1) 
    { 
        ht[index].key=key; 
        return; 
    }      int i;     for(i=0;i<ts;i++) 
    { 
        if(ht[i].key==-1) 
        { 
            ht[i].key=key; 
 
            int temp=index;             while(ht[temp].chain!=-1)                 temp=ht[temp].chain; 
 
            ht[temp].chain=i;             return; 
        } 
    } 
 
    printf("Hash table full\n"); 
} 
 
/* Search Key */ int search(HT ht[ts],int key) 
{ 
    int index=hf(key,0); 
 
    while(index!=-1) 
    { 
        if(ht[index].key==key)             return index; 
 
        index=ht[index].chain; 
    } 
 
    return -1; 
} 
 
/* Display Hash Table */ void showtable(HT ht[ts]) 
{     int i; 
    for(i=0;i<ts;i++)         printf("%d.[%d][%d]\n",i,ht[i].key,ht[i].chain); 
} 
 
/* Main Function */ int main() 
{ 
    HT ht[ts];     int key,ch; 
 
    init(ht); 
 
    printf("1.Insert\n2.Search\n3.Display\n4.Exit\n"); 
 
    while(1) 
    { 
        printf("Enter choice: ");         scanf("%d",&ch); 
 
        switch(ch) 
        {             case 1: 
                printf("Enter key: ");                 scanf("%d",&key);                 insert(ht,key);                 break; 
 
            case 2: 
                printf("Enter key: ");                 scanf("%d",&key); 
 
                int pos=search(ht,key); 
 
                if(pos==-1)                     printf("Key not found\n"); 
                else 
                    printf("Key found at index %d\n",pos); 
                 break; 
             case 3:                 showtable(ht);                 break; 
 
            case 4:                 return 0; 
 
            default: 
                printf("Invalid choice\n"); 
        } 
    } 
} 
 
DBMS:-  
CREATE TABLE STUDENT ( 
    sreg_no INT PRIMARY KEY,     name CHAR(30),     class CHAR(10) 
); 
 
CREATE TABLE COMPETITION (     c_no INT PRIMARY KEY,     name CHAR(20),     c_type CHAR(15) 
); 
 
CREATE TABLE STUDENT_COMPETITION (     sreg_no INT REFERENCES STUDENT(sreg_no),     c_no INT REFERENCES COMPETITION(c_no), 
    rank INT,     year INT,     prize INT, 
    PRIMARY KEY(sreg_no,c_no,year) 
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
CREATE OR REPLACE PROCEDURE divide_numbers(a INT, b INT) 
LANGUAGE plpgsql 
AS $$ DECLARE 
    result FLOAT; 
BEGIN 
 
    IF b = 0 THEN 
        RAISE EXCEPTION 'Division by zero is not allowed'; 
    END IF; 
 
    result := a / b; 
 
    RAISE NOTICE 'Result = %', result; 
 
END; 
$$; 
 
 
 
 
 
 
 
 
 
 
