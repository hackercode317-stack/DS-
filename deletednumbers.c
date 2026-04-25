Slip 29:- 
  
Ds)  1) 
#include<stdio.h> 
 
void swap(int *a, int *b) 
{ 
    int temp = *a;     *a = *b; 
    *b = temp; 
} 
 
void heapify(int arr[], int n, int i) 
{    int largest = i;     int left = 2 * i + 1;      int right = 2 * i + 2;  
 
    if (left < n && arr[left] > arr[largest]) 
        largest = left; 
 
    if (right < n && arr[right] > arr[largest])         largest = right; 
 
    if (largest != i) {         swap(&arr[i], &arr[largest]);         heapify(arr, n, largest); 
    } 
} 
 
void heapSort(int arr[], int n) 
{     for (int i = n / 2 - 1; i >= 0; i--)         heapify(arr, n, i); 
 
    for (int i = n - 1; i >= 0; i--) { 
        swap(&arr[0], &arr[i]);         heapify(arr, i, 0); 
    } 
} 
 
int main() 
{ 
    int arr[20], n, i;     printf("Enter number of elements: ");    scanf("%d", &n);    printf("Enter %d elements: ", n); 
    for (i = 0; i < n; i++)         scanf("%d", &arr[i]);     heapSort(arr, n);     printf("Sorted array: ");     for (i = 0; i < n; i++)         printf(" %d ", arr[i]);     return 0; 
} 
 
DBMS:- 
CREATE TABLE Area (     aid INT PRIMARY KEY,     aname VARCHAR(20),     area_type VARCHAR(5) CHECK (area_type IN ('urban','rural')) 
); 
 
CREATE TABLE Person (     pno INT PRIMARY KEY,     pname VARCHAR(20), 
    birthdate DATE,     income MONEY,     aid INT REFERENCES Area(aid) 
); 
 
1B) 
 
CREATE OR REPLACE FUNCTION person_delete_msg() 
RETURNS TRIGGER 
AS $$ 
BEGIN 
    RAISE NOTICE 'Person record is being deleted'; 
 
    RETURN OLD; 
 
END; 
$$ LANGUAGE plpgsql; 
 
CREATE TRIGGER trg_person_delete 
BEFORE DELETE 
ON Person 
FOR EACH ROW 
EXECUTE FUNCTION person_delete_msg(); 
 
 
 
2) 
 
CREATE OR REPLACE PROCEDURE subtract_three(a INT, b INT, c INT) 
LANGUAGE plpgsql 
AS $$ DECLARE 
    result INT; 
BEGIN 
 
    result := a - b - c; 
 
    RAISE NOTICE 'Result = %', result; 
 
END; 
$$; 
