-- # Write your MySQL query statement below
--  -- logic :
--      -- we will first seperate the forst caharcter and remianing characters here 
--      -- then we will first caharacter --> uppercase and remianing chaaracters --> lowercase 
--      -- then we  will concatenate both of them 

--      SELECT user_id, CONCAT(UPPER(LEFT(name,1)), LOWER(RIGHT(name,LENGTH(name)-1))) AS name
--         -- LEFT is the kind of loop starting from left aur hame pata hai pehla hi caharacter hai isi kaaran 1 daal diya 
--         -- RIGHt wle case mei right se traverse karega but kitne chaarcter chahiye woh nhi pata isi kaarana we use LENGTH function jo length batayega aur -1 isislye kiya 

--     -- example ALICE -- > length = 5 and LENGTH(name )- 1 meanns 5 -1 = 4 matlab ye right se 4 characters chalega 
--      FROM Users
--      ORDER BY user_id;


--      -- we can even use 
--      # Write your MySQL query statement below
-- SELECT user_id,CONCAT(UPPER(SUBSTR(name,1,1)),LOWER(SUBSTR(name,2,length(name)))) AS name
-- FROM Users ORDER BY user_id;
-- # SUBSTR(string_name , start_index ,end_index)

# second method 
SELECT user_id, concat(upper(LEFT(name, 1)), lower(RIGHT(name, length(name)-1))) as name
FROM users
ORDER BY user_id;
#RIGHT(name_of_string, no_of_charachters) 
