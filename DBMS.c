----------------------------------------------------- SLIP  - 1 ------------------------------------------------------------------ 
 
create table pro1(pno int primary key,pname varchar(30) not null,ptype varchar(20),duration int, check(duration > 0)); 
create table emp1(eno int primary key,ename varchar(20),qualification varchar(15),joinig_date date); 
create table pro_emp1(pno int,eno int,start_date date,no_of_hours_worked int,foreign key(pno) references pro1(pno),foreign key(eno) references emp1(eno)); 
insert into pro1 values(1,'Library System','software',6),(2,'banking app','software',8),(3,'website developement','web',4); 
select * from pro1; 
insert into emp1 values(101,'amit','Bsc','2022-06-10'),(102,'neha','Msc','2021-08-15'),(103,'rahul','Bca','2023-01-05'); 
select * from emp1; 
insert into pro_emp1 values(1,101,'2024-01-10',120),(2,101,'2024-02-05',90),(3,101,'2024-03-01',110),(1,103,'2024-02-15',80); 
select * from pro_emp1;

 ------------------- Trigger -----------------------------------  
create or replace function check_duration() returns trigger as $$ 
begin 
if NEW.duration <=0 then 
raise exception 'Duration must be greater then zero'; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 

create trigger duration_check 
before insert on pro1 
for each row 
execute function check_duration(); 
insert into pro1 values(4,'test','software',0); ---------------------- Q2 ------------------------------------------- 
create or replace procedure arithmetic_op(a int,b int,c int) language plpgsql as $$ 
begin 
raise notice 'Addition = %',a+b+c; 
raise notice 'Subtraction = %',a-b-c; 
raise notice 'Multiplication = %',a*b*c; 
end; 
$$; 
call arithmetic_op(5,3,2); 

----------------------------------------------------- SLIP  - 2 ------------------------------------------------------------------ 
Q1):- 

create table area2(aname varchar(20) primary key,area_type varchar(5)); 
create table person2(pno int primary key,pname varchar(20),birthdate date,income money,aname varchar(20),foreign key(aname) references area2(aname)); 
insert into area2 values ('nashik','urban'),('sinner','rural'),('pune','urban'); 
insert into person2 values (101,'amit','1998-05-12',25000,'nashik'),(102,'amit','1999-07-15',30000,'pune'),(103,'amit','2000-02-10',20000,'sinner'),(104,'pooja','1998
11-20',28000,'nashik'); 

create or replace function count_person(area_name varchar) returns int as $$ 
declare  
total int; 
begin 
select count(*) into total from person2 where aname=area_name; 
return total; 
end; 
$$ language plpgsql; 
select count_person('nashik'); 
Q2]  

create or replace procedure divide_num(a int,b int) language plpgsql as $$ 
declare 
result numeric; 
begin  
if b= 0 then 
raise exception 'Division by zero error'; 
end if; 
result := a/b; 
raise notice 'Division Result = %',result; 
end; 
$$; 
call divide_num(10,2); 
call divide_num(5,0); 

----------------------------------------------------- SLIP  - 3 ------------------------------------------------------------------ 
Q1]  
create table stud3(s_no int primary key,s_name varchar(20) not null,address varchar(30),class varchar(10)); 
create table tea3(t_no int primary key,t_name varchar(20) not null,qualification varchar(15),experience int); 
create table stud_tea3(s_no int,t_no int,subject varchar(15),marks_scored int,check (marks_scored > 0),primary key(s_no,t_no),foreign key(t_no) references 
tea3(t_no)); 
insert into stud3 values(1,'amit','nashik','SYBSC'),(2,'priya','pune','SYBSC'),(3,'rohit','mumbai','FYBSC'); 
insert into tea3 values(101,'patil','MSC',10),(102,'sharma','MCA',8); 
insert into stud_tea3 values(1,101,'RDBMS',80),(2,101,'RDBMS',75),(3,102,'JAVA',70); 

create or replace function student_insert_msg() returns trigger as $$ 
begin 
if NEW.s_no<=0 then raise notice 'Invalid Number'; 
return NULL; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_student_insert 
before insert on stud3  
for each row 
execute function student_insert_msg(); 
insert into stud3 values(-1,'tejal','nashik','SYBSC'); 
Q2]  
create or replace procedure find_min_max(a int,b int) language plpgsql as $$ 
begin 
if a > b then 
raise notice 'Maximum Number :- % ',a; 
raise notice 'Minimum Number :- % ',b; 
else 
raise notice 'Maximum Number :- % ',b; 
raise notice 'Minimum Number :- % ',a; 
end if; 
end; 
$$; 
call find_min_max(2,10); 


----------------------------------------------------- SLIP  - 4------------------------------------------------------------------ 
Q1]  
create table movies4(m_name varchar(20) primary key,release_yr int,budget money); 
create table actor4(a_name varchar(30) primary key ,role varchar(20),charges money,a_address varchar(30)); 
create table producer4(producer_id int primary key, name varchar(20),p_address varchar(30)); 
create table movies_actor4(m_name varchar(20),a_name varchar(30),primary key(m_name,a_name),foreign key(m_name) references movies4(m_name),foreign 
key(a_name) references actor4(a_name)); 
create table movies_producer4(m_name varchar(20),producer_id int,primary key(m_name,producer_id),foreign key(m_name) references movies4(m_name),foreign 
key(producer_id) references producer4(producer_id)); 
insert into movies4 values('RRR',2022,70000000),('Bahubali',2017,60000000),('KGF',2018,55000000); 
insert into actor4 values('Ram Charan','Hero',2000000,'Hyderabad'),('Prabhas','Hero',2500000,'Chennai'),('Yash','Hero',2200000,'Banglore'); 
insert into producer4 values(1,'Raju','Mumbai'),(2,'Karan','Delhi'); 
insert into movies_actor4 values('RRR','Ram Charan'),('Bahubali','Prabhas'),('KGF','Yash'),('RRR','Prabhas'); 
insert into movies_producer4 values('RRR',1),('Bahubali',2),('KGF',1);
 
create or replace function check_movie_budget() returns trigger as $$ 
begin 
if NEW.budget < 5000000 ::money then raise notice 'Budget should be minimum 50 lakh'; 
return null; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_movie_budget 
before insert on movies4 
for each row 
execute function check_movie_budget(); 
insert into movies4 values('DDLJ',2007,4500000); 
insert into movies4 values('DDLJ',2007,5500000);
 
Q2] 
create or replace procedure check_num(n int) language plpgsql as $$ 
begin 
if n>0 then raise notice 'Number is positive'; 
elsif n<0 then raise notice 'number is negative'; 
else raise notice 'number is zero'; 
end if; 
end; 
$$; 
call check_num(5);

----------------------------------------------------- SLIP  - 05 ------------------------------------------------------------------ 
Q1]  
create table stude5(sreg_no int primary key,s_name varchar(30),s_class varchar(10)); 
create table compe5(c_no int primary key,c_name varchar(20),c_type varchar(15)); 
create table stud_comp5(sreg_no int,c_no int,rank int,year int,primary key(sreg_no,c_no),foreign key(sreg_no) references stude5(sreg_no),foreign key(c_no) 
references compe5(c_no)); 
insert into stude5 values(1,'amit','SYBSC'),(2,'priya','SYBSC'),(3,'rohit','FYBSC'); 
insert into compe5 values(101,'cricket','sport'),(102,'quiz','academic'),(103,'chess','sport'); 
insert into stud_comp5 values(1,101,1,2023),(2,102,2,2023),(3,103,1,2024),(1,102,3,2024); 
create or replace function comp_update_msg() returns trigger as $$ 
begin 
raise notice 'Competition record is being updated'; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_comp_update 
before update on compe5 
for each row 
execute function comp_update_msg(); 
update compe5 set c_name = 'football' where c_no = 103; 
select * from compe5;
 
Q2]  
create or replace procedure find_min(a int,b int, c int) language plpgsql as $$ 
declare  
min_val int := a; 
begin  
if b  < min_val then  
min_val := b; 
end if; 
if c < min_val then 
min_val := c; 
end if; 
raise notice ' Minimum number :- %',min_val; 
end ; 
$$; 
call find_min(10,1,4); 

create or replace procedure find_max(a int,b int,c int) language plpgsql as $$ 
declare  
max_val int := a; 
begin  
if b>max_val then  
max_val := b; 
end if; 
if c>max_val then  
max_val := c; 
end if; 
raise notice ' Maximum number :- %',max_val; 
end ; 
$$; 
call find_max(4,30,33);



----------------------------------------------------- SLIP  - 06 ------------------------------------------------------------------ 
Q1]  
create table route6(route_no int primary key,source varchar(20),dest varchar(20),no_of_stations int); 
create table bus6(bus_no int primary key,capacity int,depot_name varchar(20),route_no int,foreign key(route_no) references route6(route_no)); 
create table driver6(driver_no int primary key,d_name varchar(20),license_no int,address varchar(15),d_age int,salary float); 
create table bus_driver6(bus_no int,driver_no int,date_of_duty date,shift int check(shift in(1,2)),primary key(bus_no,driver_no),foreign key(bus_no) references 
bus6(bus_no),foreign key(driver_no) references driver6(driver_no)); 
insert into route6 values(1,'nashik','pune',10),(2,'pune','mumbai',12); 
insert into bus6 values(101,50,'nashik',1),(102,40,'pune',2),(103,45,'mumbai',1); 
insert into driver6 values(201,'amit',111,'nashik',45,20000),(202,'rohit',222,'pune',55,22000),(203,'suresh',333,'mumbai',48,21000); 
insert into bus_driver6 values(101,201,'10-jan-2024',1),(102,202,'11-jan-2024',2),(103,203,'12-jan-2024',1); 
create or replace function driver_of_bus(v_bus int) returns void as $$ 
declare 
dname varchar(20); 
cur1 cursor for 
select d_name from driver6 d join bus_driver6 bd on d.driver_no = bd.driver_no where bd.bus_no=v_bus; 
begin 
open cur1; 
loop 
fetch cur1 into dname; 
exit when not found; 
raise notice 'Driver name %',dname; 
end loop; 
close cur1; 
end; 
$$ language plpgsql; 
select driver_of_bus(102); 
select * from bus6; 
select * from driver6; 
Q2]  
create or replace procedure even_odd(a int) language plpgsql as $$ 
begin 
if a % 2 = 0 then  
raise notice 'Number is EVEN'; 
else 
raise notice 'Number is ODD'; 
end if; 
end; 
$$; 
call even_odd(225);


 ----------------------------------------------------- SLIP  - 07 ------------------------------------------------------------------ 
Q1]  
create table branch7(br_id int primary key,br_name varchar(20),br_city varchar(20)); 
create table cust7(cno int primary key,c_name varchar(10),caddre varchar(20),city varchar(15)); 
create table loan_app7(lno int primary key,l_amt_required money,l_amt_approved money,l_date date); 
create table ternary7(br_id int,cno int,lno int,primary key(br_id,cno,lno),foreign key(br_id) references branch7(br_id),foreign key(cno) references cust7(cno),foreign 
key(lno) references loan_app7(lno)); 
insert into branch7 values(1,'SBI','nashik'),(2,'BOI','pune'),(3,'HDFC','pune'); 
insert into cust7 values(101,'amit','nashik road','nashik'),(102,'riya','college road','nashik'),(103,'neha','fc road','pune'); 
insert into loan_app7 values(201,50000,45000,'10-01-2024'),(202,45000,30000,'11-05-2023'); 
insert into ternary7 values(1,101,201),(2,103,202),(3,103,201),(2,101,201); 
create or replace function check_cust_no() returns trigger as $$ 
begin 
if NEW.cno<=0 then raise notice 'INVALID CUSTOMER NUMBER'; 
return null; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_customer 
before  insert on cust7 
for each row 
execute function check_cust_no(); 
insert into cust7 values(0,'priya','pavan ngr','nsk'); 
Q2]  
create or replace procedure sum_20_num() language plpgsql as $$ 
declare  
i int := 1; 
total int = 0; 
begin 
loop 
exit when i > 20; 
total := total + i; 
i := i + 1; 
end loop; 
raise notice 'Sum of first 20 numbers :- %',total; 
end; 
$$; 
call sum_20_num(); 



----------------------------------------------------- SLIP  - 08 ------------------------------------------------------------------ 
Q1]  
create table train8(train_no int primary key,train_name varchar(50),depart_time time,arrival_time time,source_stn varchar(20),dest_stn 
varchar(20),no_of_res_bogies int,bogie_capacity int); 
create table pass8(pass_id int primary key,pass_name varchar(15),address varchar(20),age int,gender varchar(15)); 
create table ticket(train_no int,pass_id int,ticket_no int,bogie_no int,no_of_berths int,tdate date,ticket_amt decimal(7,2),status char,primary 
key(train_no,pass_id),foreign key(train_no) references train8(train_no),foreign key(pass_id) references pass8(pass_id)); 
insert into train8 values(1,'rajdhani','10:00','18:00','mumbai','delhi',5,72),(2,'express','09:00','16:00','pune','nagpur',4,70); 
insert into pass8 values(101,'amit','nashik',25,'M'),(102,'sneha','pune',20,'F'); 
insert into ticket values(1,101,1001,2,1,'10-02-2024',2000,'C'),(2,102,1002,1,2,'12-05-2024',2200,'W'); 
create or replace function age_check() returns trigger as $$ 
begin 
if NEW.age>5 then raise notice 'Age above 5 will be charged full fare'; 
return null; 
end if; 
return NEW; 
end ; 
$$ language plpgsql; 
create trigger trg_pass_age 
before insert on pass8  
for each row 
execute function age_check(); 
insert into pass8 values(103,'riya','pune',10,'F'); 
insert into pass8 values(104,'rohan','mumbai',2,'M'); 
Q2]  
create or replace procedure add_2_num(a int, b int) language plpgsql as $$ 
begin 
raise notice 'Addition of % and % is:- %',a,b,a+b; 
end; 
$$; 
call add_2_num(5,4); 


----------------------------------------------------- SLIP  - 10 ------------------------------------------------------------------ 
Q1]  
create table book10 (b_no int primary key,b_name varchar(20),pub_name varchar(20) not null,b_price float); 
create table author10(a_no int primary key,a_name varchar(20),qualification varchar(20),address varchar(15)); 
create table book_author10 (b_no int references book10(b_no),a_no int references author10(a_no)); 
insert into book10 values(1,'DBMS','pearson',900),(2,'java','McGraw',1200); 
insert into author10 values(101,'Korth','PhD','USA'),(102,'James','MCA','UK'); 
insert into book_author10 values(1,101),(2,102),(2,101); 
create or replace function dis_msg_of_prize() returns trigger as $$ 
begin 
if NEW.b_price > 1000 then 
raise notice 'Book Price is so High'; 
end if; 
return NEW; 
end;  
$$ language plpgsql; 
create trigger trg_book_insert 
after insert on book10 
for each row 
execute function dis_msg_of_prize(); 
insert into book10 values(4,'DS','pearson',1500); 
Q2]  
create or replace procedure even_num() language plpgsql as $$ 
declare 
i int := 2; 
begin 
while i <= 50 
loop  
raise notice '%',i; 
i := i + 2; 
end loop; 
end;  
$$;




 ----------------------------------------------------- SLIP  - 11 ------------------------------------------------------------------ 
Q1]  
create table stud11(rollno int primary key,s_name varchar(20),class varchar(20)); 
create table sub11(scode int primary key,sub_name varchar(15)); 
create table stud_sub11(rollno int references stud11(rollno),scode int references sub11(scode),marks int); 
insert into stud11 values(1,'amit','SY'),(2,'riya','TY'),(3,'neha','FY'); 
insert into sub11 values(101,'DS'),(102,'DBMS'); 
insert into stud_sub11 values(1,101,75),(2,102,80),(3,101,50); 
create or replace function del_stud_rec() returns trigger as $$ 
begin 
raise notice 'Student record is being deleted'; 
return old; 
end; 
$$ language plpgsql; 
create trigger trg_del_stud_rec 
before delete on stud11 
for each row 
execute function del_stud_rec(); 
delete from stud11 where rollno = 1; 
Q2]  
create or replace procedure sum_avg(n int) language plpgsql as $$ 
declare  
i int := 1; 
total int := 0; 
avge float; 
begin 
while i <= n loop 
total :=  total + i; 
i := i + 1; 
end loop; 
avge := total/n; 
raise notice ' Sum = % and Average = %',total,avge; 
end; 
$$; 
call sum_avg(10);



 ----------------------------------------------------- SLIP  - 12 ------------------------------------------------------------------ 
Q2]  
create or replace procedure cnt_odd ( m int , n int) language plpgsql as $$ 
declare  
i int; 
cnt int := 0; 
begin 
for i in m..n loop 
if i % 2 <> 0 then 
cnt := cnt + 1; 
end if; 
end loop; 
raise notice ' Total odd numbers :- %',cnt; 
end; 
$$; 
call cnt_odd(10,50);



 ----------------------------------------------------- SLIP  - 13 ------------------------------------------------------------------ 
Q1]  
create table route13(route_no int primary key,source varchar(20),dest varchar(20),no_of_stations int); 
create table bus13(bus_no int primary key,capacity int,depot_name varchar(20),route_no int,foreign key(route_no) references route6(route_no)); 
create table driver13(driver_no int primary key,d_name varchar(20),license_no int,address varchar(15),d_age int,salary float); 
create table bus_driver13(bus_no int,driver_no int,date_of_duty date,shift int check(shift in(1,2)),primary key(bus_no,driver_no),foreign key(bus_no) references 
bus6(bus_no),foreign key(driver_no) references driver6(driver_no)); 
insert into route13 values(1,'nashik','pune',10),(2,'pune','mumbai',12); 
insert into bus13 values(101,50,'nashik',1),(102,40,'pune',2),(103,45,'mumbai',1); 
insert into driver13 values(201,'amit',111,'nashik',45,20000),(202,'rohit',222,'pune',55,22000),(203,'suresh',333,'mumbai',48,21000); 
insert into bus_driver13 values(101,201,'10-jan-2024',1),(102,202,'11-jan-2024',2),(103,203,'12-jan-2024',1); 
create or replace function chk_age() returns trigger as $$ 
begin 
if NEW.d_age < 18 or NEW.d_age > 50 then 
raise exception ' Invalid Entry'; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_chk_age 
before insert on  driver13 
for each row 
execute function chk_age(); 
insert into driver13 values(205,'kunal',444,'pune',55,25000); 
Q2]  
create or replace function search_in_range (num int, m int , n int) returns varchar language plpgsql as $$ 
begin  
if num between m and n then 
raise notice 'Number is in the range'; 
else 
raise notice 'Number is not int the range '; 
end if; 
end; 
$$; 
select search_in_range(110,1,20);




 ------------------------------------------------------- SLIP  - 14 ------------------------------------------------------------------ 
Q2]  
create or replace function number_in_words(n int) returns text language plpgsql as $$ 
declare 
temp int := n; 
digit int; 
result text := ''; 
begin 
if n = 0 then 
return 'zero'; 
end if; 
while temp > 0 loop 
digit := temp % 10; 
case digit  
when 0 then result := ' zero' || result; 
when 1 then result := 'one' || result; 
when 2 then result := 'two' || result; 
when 3 then result := 'three' || result; 
when 4 then result := 'four' || result; 
when 5 then result := 'five' || result; 
when 6 then result := 'six' || result; 
when 7 then result := 'seven' || result; 
when 8 then result := 'eight' || result; 
when 9 then result := 'nine' || result; 
end case; 
temp := temp / 10; 
end loop; 
return trim(result); 
end ; 
$$; 
select number_in_words(789);


 ----------------------------------------------------- SLIP  - 15 ------------------------------------------------------------------ 
Q1]  
create table area15(aname varchar(20) primary key,area_type varchar(5) check (area_type in ('urban','rural'))); 
create table person15(pno int primary key,pname varchar(20),birthdate date,income money,aname varchar(20),foreign key(aname) references area2(aname)); 
insert into area15 values ('nashik','urban'),('sinner','rural'),('pune','urban'); 
insert into person15 values (101,'amit','1998-05-12',25000,'nashik'),(102,'amit','1999-07-15',30000,'pune'),(103,'amit','2000-02
10',20000,'sinner'),(104,'pooja','1998-11-20',28000,'nashik'); 
create or replace function chk_pno_neg() returns trigger as $$ 
begin 
if NEW.pno < 0 then 
raise exception 'Invalid Number'; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_chk_pno_neg 
before insert on person15 
for each row 
execute function chk_pno_neg(); 
insert into person15 values (-104,'rahul','1995-01-12',30000,'nashik'); 
Q2]  
create or replace procedure odd_numbers() language plpgsql as $$ 
declare 
i int := 1; 
begin 
while i<=100 loop 
if i%2 <> 0 then 
raise notice '%',i; 
end if; 
i := i+1; 
end loop; 
end; 
$$; 
call odd_numbers();



 ----------------------------------------------------- SLIP  - 18 ------------------------------------------------------------------ 
Q1]  
create table item18(itemno int primary key,itemname varchar(20)); 
create table supplier18(supplier_no int primary key,supplier_name varchar(20), city varchar(15)); 
create table item_supplier_18(itemno int references item18(itemno),supplier_no int references supplier18(supplier_no),rate int,quantity int); 
insert into item18 values(1,'biscuits'),(2,'soap'),(3,'washing powder'); 
insert into supplier18 values(101,'amit traders','nashik'),(102,'neha suppliers','pune'); 
insert into item_supplier18 values(1,101,600,100),(2,102,500,50),(3,102,1000,250); 
create or replace function chk_rate_dismsg() returns trigger as $$ 
begin 
if NEW.rate < 50 then 
raise exception 'Rate should not be less than 50'; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_chk_rate_msg18 
before insert or update on item_supplier_18 
for each row 
execute function chk_rate_dismsg(); 
insert into item_supplier_18 values(2,101,45,100); 




----------------------------------------------------- SLIP  - 20 ------------------------------------------------------------------ 
Q1]  
create table dept20 (dno int primary key,dname varchar(15),city varchar(10)); 
create table emp20 (eno int primary key, ename varchar(20),salary int,dno int references dept20(dno)); 
insert into dept20 values(1,'sales','nashik'),(2,'HR','pune'); 
insert into emp20 values(101,'amit',20000,1),(102,'neha',35000,1),(103,'rahul',80000,2); 
create or replace function sal_chk() returns trigger as $$ 
begin  
if NEW.salary <= 0 then 
raise exception 'Salary Should Not be ZERO'; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_sal_chk 
before insert or update on emp20 
for each row 
execute function sal_chk(); 
insert into emp20 values(104,'priya',-225,2);



 ----------------------------------------------------- SLIP  - 21 ------------------------------------------------------------------ 
Q1]  
create table hos21(h_no int primary key,h_name varchar(20),city varchar(15)); 
create table doc21(d_no int primary key,d_name varchar(20),specialization varchar(20),phone_no int, charges int,h_no int references hos21(h_no)); 
insert into hos21 values(1,'lilavati hospital','mumbai'),(2,'samarth hospital','nashik'); 
insert into doc21 values(101,'dr.patil','dentist',0563448,2000,1),(102,'dr.sharma','cardiologist',8485464,1800,2); 
create or replace function chk_charges() returns trigger as $$ 
begin 
if NEW.charges < 0 then  
raise exception ' charges must be greater than zero'; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_chk_charges 
before insert or update on doc21 
for each row 
execute function chk_charges(); 
insert into doc21 values(101,'dr.patil','dentist',0889448,-200,1); 





----------------------------------------------------- SLIP  - 23 ------------------------------------------------------------------ 
Q1]  
create table car23(c_no int primary key,owner varchar(20),model varchar(20),colour varchar(20)); 
create table driver23(driver_no int primary key,driver_name varchar(10),license_no int,d_age int,salary float); 
create table car_driver23(c_no int references car23(c_no), driver_no int references driver23(driver_no)); 
insert into car23 values(1,'amit','swift','white'),(2,'neha','i20','black'); 
insert into driver23 values(101,'rahul',111,23,15000),(102,'suresh',222,20,10000); 
insert into car_driver23 values(1,101),(2,102),(2,101); 
create or replace function chk_driver_age() returns trigger as $$ 
begin 
if NEW.d_age < 21 then 
raise exception 'driver age must be greater than 21'; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_chk_driver_age 
before insert or update on driver23 
for each row 
execute function chk_driver_age(); 
insert into driver23 values(103,'rahul',333,19,15000); 
insert into driver23 values(104,'rohit',444,25,15000);



 ----------------------------------------------------- SLIP  - 24 ------------------------------------------------------------------ 
Q1]  
create table dept24 (dno int primary key,dname varchar(15),city varchar(10)); 
create table emp24 (eno int primary key, ename varchar(20),salary int,dno int references dept24(dno)); 
insert into dept24 values(1,'sales','nashik'),(2,'HR','pune'); 
insert into emp24 values(101,'amit',20000,1),(102,'neha',35000,1),(103,'rahul',80000,2); 
create or replace function insert_emp() returns trigger as $$ 
begin 
raise notice ' Employee Record in Successfully Inserted.'; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_insert_emp 
after insert on emp24 
for each row 
execute function insert_emp(); 
insert into emp24 values(104,'rohit',26000,1); 
Q2]  
create or replace procedure even_num_20() language plpgsql as $$ 
declare 
i int := 2; 
cnt int := 0; 
begin 
while  i <= 20 
loop  
raise notice '%',i; 
i := i + 2; 
end loop; 
end;  
$$; 
call even_num_20();




 ----------------------------------------------------- SLIP  - 25 ------------------------------------------------------------------ 
Q1]  
create table cust25(cno int primary key,cname varchar(20),city varchar(10)); 
create table acc25(a_no int primary key,a_type varchar(15),opening_date date,balance money,cno int references cust25(cno)); 
insert into cust25 values(1,'amit','nashik'),(2,'neha','mumbai'),(3,'payal','pune'); 
insert into acc25 values(101,'saving','2024-04-11',45000,1),(102,'current','2024-06-12',30000,2); 
create or replace function prevent_delete() returns trigger as $$ 
begin  
if OLD.a_type = 'saving ' then 
raise exception 'Deletion of Saving Account is not Allowed.'; 
end if; 
return OLD; 
end; 
$$ language plpgsql; 
create trigger trg_prevent_delete 
before delete on acc25 
for each row 
execute function prevent_delete(); 
delete from acc25 where a_type = 'saving'; 
select * from acc25; 
create or replace procedure pune_cust() language plpgsql as $$ 
declare  
rec record; 
begin 
for rec in select * from cust25 where city ='pune' 
loop  
raise notice 'Customer No :- % , Name :- %',rec.cno,rec.cname; 
end loop; 
end; 
$$; 
call pune_cust();





 ----------------------------------------------------- SLIP  - 26 ------------------------------------------------------------------ 
Q1]  
create table item26(itemno int primary key,itemname varchar(20),quantity int); 
create table supplier26(supplier_no int primary key,supplier_name varchar(20), city varchar(15)); 
create table item_supplier_26(itemno int references item18(itemno),supplier_no int references supplier18(supplier_no),rate int); 
insert into item26 values(1,'biscuits',100),(2,'soap',50),(3,'washing powder',250); 
insert into supplier26 values(101,'amit traders','nashik'),(102,'neha suppliers','pune'); 
insert into item_supplier_26 values(1,101,600),(2,102,500),(3,102,1000); 
create or replace function chk_rate() returns trigger as $$ 
begin  
if abs(NEW.rate - OLD.rate ) > 2000 then 
raise exception ' rate difference cannot exceed Rs.2000'; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_chk_rate 
before update on item_supplier_26 
for each row 
execute function chk_rate(); 
update item_supplier_26  
set rate = 5000 
where itemno = 1; 
-



---------------------------------------------------- SLIP  - 27 ------------------------------------------------------------------ 
Q1]  
create table stud27(rollno int primary key,s_name varchar(20),class varchar(20)); 
create table sub27(scode int primary key,sub_name varchar(15)); 
create table stud_sub27(rollno int references stud11(rollno),scode int references sub11(scode),marks int); 
insert into stud27 values(1,'amit','SY'),(2,'riya','TY'),(3,'neha','FY'); 
insert into sub27 values(101,'DS'),(102,'DBMS'); 
insert into stud_sub27 values(1,101,75),(2,102,80),(3,101,50); 
create or replace function chk_marks() returns trigger as $$ 
begin 
if NEW.marks < 0 then 
raise exception 'Marks Cannot be Negative'; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_chk_marks 
before insert or update on stud_sub27 
for each row 
execute function chk_marks(); 
insert into stud_sub27 values(2,101,-70); 



----------------------------------------------------- SLIP  - 28 ------------------------------------------------------------------ 
Q1]  
create table comp28(name varchar(20) primary key,address varchar(25),city varchar(20),share_value money); 
create table person28 (pname varchar(20) primary key,pcity varchar(20)); 
create table comp_person28(name varchar(20) references comp28(name),pname varchar(20) references person28(pname),no_of_shares int); 
insert into comp28 values('TCS','mumbai road','mumbai',1000),('Infosys','hinjewadi','pune',1200); 
insert into person28 values('amit','nashik'),('sneha','pune'); 
insert into comp_person28 values('TCS','amit',50),('Infosys','sneha',30),('TCS','sneha',20); 
create or replace function del_record() returns trigger as $$ 
begin 
raise notice 'Company Record is Deleted Successfully'; 
return OLD; 
end; 
$$ language plpgsql; 
create trigger trg_del_record 
before delete on comp28 
for each row 
execute function del_record(); 
select * from comp28; 
delete from comp28 where name = 'TCS';



 ----------------------------------------------------- SLIP  - 29 ------------------------------------------------------------------ 
Q1]  
create table area29(aid int primary key,aname varchar(20),area_type varchar(5) check (area_type in ('urban','rural'))); 
create table person29(pno int primary key,pname varchar(20),birthdate date,income money,aid int,foreign key(aid) references area29(aid)); 
insert into area29 values (1,'nashik','urban'),(2,'sinner','rural'),(3,'pune','urban'); 
insert into person29 values (101,'amit','1998-05-12',25000,1),(102,'amit','1999-07-15',30000,2),(103,'amit','2000-02-10',20000,3),(104,'pooja','1998-11
20',28000,1); 
create or replace function del_record() returns trigger as $$ 
begin 
raise notice 'Person Record is Deleted Successfully'; 
return OLD; 
end; 
$$ language plpgsql; 
create trigger trg_del_record 
before delete on person29 
for each row 
execute function del_record(); 
select * from person29; 
delete from person29 where pno = 101;

 ----------------------------------------------------- SLIP  - 30 ------------------------------------------------------------------ 
Q1]  
create table stud30(rollno int primary key,sname varchar(20),sclass varchar(10)); 
create table tea30(t_no int primary key,tname varchar(20),experience int); 
create table stud_sub30(rollno int references stud30(rollno),t_no int references tea30(t_no),subject varchar(15)); 
insert into stud30 values(1,'amit','FY'),(2,'neha','SY'),(3,'rohit','TY'); 
insert into tea30 values(101,'yogesh chavan',10),(102,'madhuri patil',5); 
insert into stud_sub30 values(1,101,'DS'),(2,102,'DBMS'),(3,101,'Maths'); 
create or replace function chk_roll_no() returns trigger as $$ 
begin 
if NEW.rollno <= 0 then 
raise exception 'Invalid Roll Number'; 
end if; 
return NEW; 
end; 
$$ language plpgsql; 
create trigger trg_chk_roll_no 
before insert on stud30 
for each row 
execute function chk_roll_no(); 
select * from stud30; 
insert into stud30 values(-20,'megha','FY');

