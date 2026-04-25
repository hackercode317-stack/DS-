Ds)  2) 
#include<stdio.h> 
 
int main() 
{     int n,i,j; 
    int adj[10][10]; 
 
    printf("Enter number of vertices: ");     scanf("%d",&n); 
 
    /* Initialize matrix with 0 */     for(i=0;i<n;i++) 
    { 
        for(j=0;j<n;j++) 
        {             adj[i][j]=0; 
        } 
    } 
 
    /* Accept edges */     for(i=0;i<n;i++) 
    { 
        for(j=0;j<n;j++) 
        {             if(i!=j) 
            { 
                printf("Is there an edge between %d and %d (1/0): ",i+1,j+1);                 scanf("%d",&adj[i][j]); 
            } 
        } 
    } 
 
    /* Display adjacency matrix */     printf("\nAdjacency Matrix:\n"); 
 
    for(i=0;i<n;i++) 
    { 
        for(j=0;j<n;j++) 
        { 
            printf("%d ",adj[i][j]); 
        } 
        printf("\n"); 
    } 
 
    return 0; 
} 
 
DBMS:-  
CREATE TABLE Project (     pno INTEGER PRIMARY KEY,     pname CHAR(30) NOT NULL,     ptype CHAR(20),     duration INTEGER CHECK (duration > 0) 
); 
 
CREATE TABLE Employee (     eno INTEGER PRIMARY KEY,     ename CHAR(20),     qualification CHAR(15),     joining_date DATE 
); 
 
CREATE TABLE Project_Employee (     pno INTEGER REFERENCES Project(pno),     eno INTEGER REFERENCES Employee(eno),     start_date DATE, 
    no_of_hours_worked INTEGER, 
    PRIMARY KEY (pno, eno) 
); 
 
1A) 
CREATE OR REPLACE FUNCTION count_projects(emp_no INT) RETURNS INTEGER LANGUAGE plpgsql AS $$ DECLARE 
    proj_count INTEGER; 
BEGIN 
 
    SELECT COUNT(*) INTO proj_count 
    FROM Project_Employee 
    WHERE eno = emp_no; 
 
    RETURN proj_count; 
 
END; 
$$; 
 
2) 
CREATE OR REPLACE PROCEDURE calc_numbers(a INT, b INT, c INT) LANGUAGE plpgsql AS $$ DECLARE 
    sum_val INT;     sub_val INT;     mul_val INT; 
BEGIN 
 
    sum_val := a + b + c;     sub_val := a - b - c;     mul_val := a * b * c; 
 
    RAISE NOTICE 'Addition = %', sum_val; 
    RAISE NOTICE 'Subtraction = %', sub_val; 
    RAISE NOTICE 'Multiplication = %', mul_val; 
 
END; 
$$; 
 
 
