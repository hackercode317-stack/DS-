Slip 16:- 
  
Ds)  1) 
#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 
 
/* swap function */ void swap(int *a,int *b) 
{ 
    int temp=*a;     *a=*b; 
    *b=temp; 
}
/* heapify function */ void heapify(int arr[],int n,int i) 
{ 
    int largest=i;     int left=2*i+1;     int right=2*i+2; 
 
    if(left<n && arr[left]>arr[largest]) 
        largest=left; 
 
    if(right<n && arr[right]>arr[largest])         largest=right; 
 
    if(largest!=i) 
    { 
        swap(&arr[i],&arr[largest]);         heapify(arr,n,largest); 
    } 
} 
 
/* heap sort */ void heapsort(int arr[],int n) 
{     int i; 
 
    for(i=n/2-1;i>=0;i--)         heapify(arr,n,i); 
 
    for(i=n-1;i>=0;i--) 
    { 
        swap(&arr[0],&arr[i]);         heapify(arr,i,0); 
    } 
} 
 
int main() 
{     int n,i,arr[50]; 
 
    printf("Enter number of elements: ");     scanf("%d",&n); 
 
    srand(time(NULL)); 
 
    printf("Random numbers:\n"); 
 
    for(i=0;i<n;i++) 
    { 
        arr[i]=rand()%100;         printf("%d ",arr[i]); 
    } 
 
    heapsort(arr,n); 
 
    printf("\nSorted elements:\n"); 
 
    for(i=0;i<n;i++)         printf("%d ",arr[i]); 
 
    return 0; 
}
DBMS:-  
CREATE TABLE Student (     rollno INTEGER PRIMARY KEY,     name VARCHAR(30),     address VARCHAR(50),     class VARCHAR(10) 
); 
 
CREATE TABLE Subject (     scode VARCHAR(10) PRIMARY KEY,     subject_name VARCHAR(20) 
); 
 
CREATE TABLE Student_Subject (     rollno INTEGER REFERENCES Student(rollno),     scode VARCHAR(10) REFERENCES Subject(scode),     marks_scored INTEGER, 
    PRIMARY KEY(rollno, scode) 
); 
 
1A) 
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
CREATE OR REPLACE PROCEDURE check_number(n INTEGER) 
LANGUAGE plpgsql 
AS $$ 
BEGIN 
 
    IF n > 0 THEN 
        RAISE NOTICE 'Number is Positive'; 
    ELSIF n < 0 THEN 
        RAISE NOTICE 'Number is Negative'; 
    ELSE 
        RAISE NOTICE 'Number is Zero'; 
    END IF; 
 
END; 
$$; 
 
 
 
 
