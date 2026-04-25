Slip 13:- 
  
Ds)  2) 
#include<stdio.h> 
#include<stdlib.h> 
 
#define MAX 10 
 
struct node 
{     int vertex;     struct node *next; 
}; 
 
void create_graph(struct node *adj[MAX], int n) 
{     int i,j,reply; 
    struct node *nw,*temp; 
 
    for(i=0;i<n;i++) 
    { 
        for(j=0;j<n;j++) 
        {             if(i!=j) 
            { 
                printf("\nIs edge present between %d & %d (1/0): ",i+1,j+1);                 scanf("%d",&reply); 
 
                if(reply==1) 
                { 
                    nw=(struct node*)malloc(sizeof(struct node)); 
                    nw->vertex=j;                     nw->next=NULL; 
 
                    if(adj[i]==NULL)                         adj[i]=nw;                     else 
                    { 
                        temp=adj[i];                         while(temp->next!=NULL)                             temp=temp->next;                         temp->next=nw; 
                    } 
                } 
            } 
        } 
    } 
} 
 
void display_graph(struct node *adj[MAX], int n) 
{     int i; 
    struct node *temp; 
 
    printf("\nAdjacency List:\n"); 
 
    for(i=0;i<n;i++) 
    { 
        printf("V[%d] -> ",i+1); 
 
        temp=adj[i]; 
 
        while(temp!=NULL) 
        { 
            printf("V[%d] ",temp->vertex+1);             temp=temp->next; 
        } 
 
        printf("\n"); 
    } 
} 
 
void indegree_outdegree(struct node *adj[MAX], int n) 
{ 
    int indeg[MAX]={0}, outdeg[MAX]={0}; 
    int i; 
    struct node *temp; 
 
    for(i=0;i<n;i++) 
    { 
        temp=adj[i]; 
 
        while(temp!=NULL) 
        { 
            outdeg[i]++;             indeg[temp->vertex]++;             temp=temp->next; 
        } 
    } 
 
    printf("\nVertex\tIndegree\tOutdegree\tTotal Degree\n"); 
 
    for(i=0;i<n;i++) 
    { 
        printf("V[%d]\t%d\t\t%d\t\t%d\n",         i+1, indeg[i], outdeg[i], indeg[i]+outdeg[i]); 
    } 
} 
 
int main() 
{ 
    struct node *adj[MAX]; 
    int n,i; 
 
    printf("Enter number of vertices: ");     scanf("%d",&n); 
 
    for(i=0;i<n;i++)         adj[i]=NULL; 
 
    create_graph(adj,n);     display_graph(adj,n);     indegree_outdegree(adj,n); 
 
    return 0; 
} 
 
DBMS:-  
CREATE TABLE BUS (     bus_no INT PRIMARY KEY,     capacity INT NOT NULL,     depot_name VARCHAR(20) 
); 
 
CREATE TABLE ROUTE (     route_no INT PRIMARY KEY,     source CHAR(20),     destination CHAR(20),     no_of_stations INT 
); 
 
CREATE TABLE DRIVER (     driver_no INT PRIMARY KEY,     driver_name CHAR(20),     license_no INT UNIQUE,     address CHAR(20),     d_age INT,     salary FLOAT 
); 
 
CREATE TABLE BUS_ROUTE (     bus_no INT REFERENCES BUS(bus_no),     route_no INT REFERENCES ROUTE(route_no), 
    PRIMARY KEY(bus_no) 
); 
 
CREATE TABLE BUS_DRIVER (     bus_no INT REFERENCES BUS(bus_no),     driver_no INT REFERENCES DRIVER(driver_no),     duty_date DATE,     shift INT CHECK (shift IN (1,2)), 
    PRIMARY KEY(bus_no, driver_no, duty_date) 
); 
 
1A) 
 
CREATE OR REPLACE FUNCTION check_driver_age() 
RETURNS TRIGGER 
AS $$ 
BEGIN 
 
    IF NEW.d_age < 18 OR NEW.d_age > 50 THEN 
        RAISE EXCEPTION 'Invalid entry'; 
    END IF; 
 
    RETURN NEW; 
 
END; 
$$ LANGUAGE plpgsql; 
 
CREATE TRIGGER trg_driver_age 
BEFORE INSERT 
ON DRIVER 
FOR EACH ROW 
EXECUTE FUNCTION check_driver_age(); 
 
2) 
CREATE OR REPLACE PROCEDURE check_range(num INT, m INT, n INT) 
LANGUAGE plpgsql 
AS $$ 
BEGIN 
 
    IF num BETWEEN m AND n THEN 
        RAISE NOTICE 'Number % is within the range', num; 
    ELSE 
        RAISE NOTICE 'Number % is outside the range', num; 
    END IF; 
 
END; 
$$; 
 
 
 
 
 
