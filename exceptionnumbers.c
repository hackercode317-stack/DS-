Slip 18:- 
  
Ds)  2) 
#include<stdio.h> 
 
void cremat(int m[10][10], int n) 
{     int i,j; 
 
    for(i=0;i<n;i++) 
    { 
        for(j=0;j<n;j++) 
        {             m[i][j]=0;             if(i!=j) 
            { 
                printf("\nIs the edge present between %d & %d (1/0): ",i+1,j+1); 
                scanf("%d",&m[i][j]); 
            } 
        } 
    } 
} 
 
void dismat(int m[10][10], int n) 
{     int i,j; 
 
    printf("\nThe Adjacency matrix is:\n"); 
 
    for(i=0;i<n;i++) 
    { 
        for(j=0;j<n;j++) 
        { 
            printf("%d ",m[i][j]); 
        } 
        printf("\n"); 
    } 
} 
 
int main() 
{ 
    int m[10][10], n; 
 
    printf("Enter the number of vertices: ");     scanf("%d",&n);
 
    cremat(m,n);     dismat(m,n); 
 
    return 0; 
} 
 
 
DBMS:-  
CREATE TABLE Item (     itemno INTEGER PRIMARY KEY,     itemname VARCHAR(20) 
); 
 
CREATE TABLE Supplier (     supplier_no INTEGER PRIMARY KEY,     supplier_name VARCHAR(20),     city VARCHAR(20) 
); 
 
CREATE TABLE Item_Supplier (     itemno INTEGER REFERENCES Item(itemno),     supplier_no INTEGER REFERENCES Supplier(supplier_no),     rate MONEY,     quantity INTEGER, 
    PRIMARY KEY(itemno, supplier_no) 
); 
 
1B) 
CREATE OR REPLACE FUNCTION check_rate() 
RETURNS TRIGGER
AS $$ 
BEGIN 
 
    IF NEW.rate < 50 THEN 
        RAISE EXCEPTION 'Rate must be greater than or equal to 50'; 
    END IF; 
 
    RETURN NEW; 
 
END; 
$$ LANGUAGE plpgsql; 
 
CREATE TRIGGER trg_check_rate 
BEFORE INSERT OR UPDATE 
ON Item_Supplier 
FOR EACH ROW 
EXECUTE FUNCTION check_rate(); 
 
 
2) 
CREATE OR REPLACE PROCEDURE max_three(a INT, b INT, c INT) 
LANGUAGE plpgsql 
AS $$ DECLARE 
    max_val INT; 
BEGIN 
 
    max_val := a; 
 
    IF b > max_val THEN         max_val := b;
    END IF; 
 
    IF c > max_val THEN 
        max_val := c; 
    END IF; 
 
    RAISE NOTICE 'Maximum number is %', max_val; 
 
END; 
$$; 
