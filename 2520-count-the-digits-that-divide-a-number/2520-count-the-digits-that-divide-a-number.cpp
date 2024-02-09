class Solution {
public:
    int countDigits(int num) {
  int count =0;  
      int temp = num;
while(num>0){
int digits = num%10;



 

if(temp%digits==0){
    count++;
}
num = num/10;
}
return count;
    }
};