 
Slip 8:- 
  
 
Ds)  2) 
#include<stdio.h> 
 
int main() 
{ 
    int n, e, i, j; 
    int adj[10][10];     int v1, v2; 
 
    printf("Enter number of vertices: ");     scanf("%d",&n); 
 
    printf("Enter number of edges: ");     scanf("%d",&e); 
 
    /* Initialize matrix with 0 */     for(i=0;i<n;i++) 
    { 
        for(j=0;j<n;j++) 
        { 
            adj[i][j]=0; 
        } 
    } 
 
    /* Accept edges */     printf("Enter edges (vertex1 vertex2):\n");     for(i=0;i<e;i++) 
    { 
        scanf("%d%d",&v1,&v2); 
 
        adj[v1][v2]=1;         adj[v2][v1]=1;   // for undirected graph 
    } 
 
    /* Display adjacency matrix */     printf("\nAdjacency Matrix:\n");     for(i=0;i<n;i++) 
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
CREATE TABLE TRAIN (     train_no INT PRIMARY KEY,     train_name VARCHAR(20),     depart_time TIME,     arrival_time TIME,     source_stn VARCHAR(20),     dest_stn VARCHAR(20),     no_of_res_bogies INT,     bogie_capacity INT 
); 
 
CREATE TABLE PASSENGER (     passenger_id INT PRIMARY KEY,     passenger_name VARCHAR(20),     address VARCHAR(30), 
    age INT,     gender CHAR(1) ); 
CREATE TABLE TICKET (     train_no INT REFERENCES TRAIN(train_no),     passenger_id INT REFERENCES PASSENGER(passenger_id), 
    ticket_no INT,     bogie_no INT,     no_of_berths INT,     tdate DATE,     ticket_amt DECIMAL(7,2),     status CHAR(1) CHECK (status IN ('W','C')), 
    PRIMARY KEY(train_no, passenger_id, ticket_no) 
); 
 
1B) 
CREATE OR REPLACE FUNCTION passenger_age_check() 
RETURNS TRIGGER 
AS $$ 
BEGIN 
    IF NEW.age > 5 THEN 
        RAISE NOTICE 'Age above 5 will be charged full fare'; 
    END IF; 
 
    RETURN NEW; 
END; 
$$ LANGUAGE plpgsql; 
 
CREATE TRIGGER trg_passenger_age 
AFTER INSERT 
ON PASSENGER 
FOR EACH ROW 
EXECUTE FUNCTION passenger_age_check(); 
2) 
CREATE OR REPLACE PROCEDURE add_numbers(a INT, b INT) 
LANGUAGE plpgsql 
AS $$ DECLARE 
    result INT; 
BEGIN 
 
    result := a + b; 
 
    RAISE NOTICE 'Addition = %', result; 
 
END; 
$$; 
 
 
 
