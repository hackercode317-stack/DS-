Slip 22:- 
  
Ds)  2) 
#include<stdio.h> 
 
void cremat(int m[10][10], int n) 
{     int i,j; 
 
    for(i=0;i<n;i++) 
    { 
        for(j=0;j<n;j++) 
        { 
            m[i][j]=0; 
             if(i!=j) 
            { 
                printf("\nIs the edge present between %d & %d (1/0): ",i+1,j+1);                 scanf("%d",&m[i][j]); 
            } 
        } 
    } 
} 
 
void dismat(int m[10][10], int n) 
{     int i,j; 
 
    printf("\nAdjacency Matrix:\n"); 
 
    for(i=0;i<n;i++) 
    { 
        for(j=0;j<n;j++)             printf("%d ",m[i][j]); 
 
        printf("\n"); 
    } 
} 
 
int main() 
{ 
    int m[10][10], n; 
 
    printf("Enter number of vertices: ");     scanf("%d",&n); 
 
    cremat(m,n);     dismat(m,n); 
 
    return 0; 
} 
 
DBMS:- 
CREATE TABLE Project (     pno INTEGER PRIMARY KEY,     pname CHAR(30) NOT NULL,     ptype CHAR(20),     duration INTEGER CHECK (duration > 0) 
); 
 
CREATE TABLE Employee (     eno INTEGER PRIMARY KEY,     ename CHAR(20),     qualification CHAR(15),     joining_date DATE 
); 
 
CREATE TABLE Project_Employee (     pno INTEGER REFERENCES Project(pno),     eno INTEGER REFERENCES Employee(eno), 
    start_date DATE,     no_of_hours_worked INTEGER, 
    PRIMARY KEY(pno, eno) 
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
CREATE OR REPLACE PROCEDURE check_range(num INT, m INT, n INT) 
LANGUAGE plpgsql 
AS $$ 
BEGIN 
    IF num BETWEEN m AND n THEN 
        RAISE NOTICE 'Number is within the range'; 
    ELSE 
        RAISE NOTICE 'Number is outside the range'; 
    END IF; 
END; 
$$; 
