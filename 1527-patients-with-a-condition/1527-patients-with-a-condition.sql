# Write your MySQL query statement below
-- we use the LIKE keyword jo ki where keyword kw saath lagaya jaata hai aur ye koi column mei pattern pakadne ke liye kaam aata hai 
 -- hame DIAB1 ko doondhna hai toh apon LIKE opertaor ko use karte hai 

 SELECT* 
 FROM 
 Patients 
 WHERE 
  conditions LIKE ('DIAB1%') OR conditions LIKE ('% DIAB1%');
  -- matlab % ka matlab hai apon jitne chahahe cahharcters laga sakte hai 
  -- % ka matlab hai ki DIAB1 ke pehle apon jitne chahe characters laga sakte hai 
-- % _ DIAB1%  ka matlab apon space ke pehle jitne characters sur DIAB1 ke baad jitne characters laga skate hai 