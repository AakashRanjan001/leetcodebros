class Solution {
public:
    bool isPalindrome(int x) {
  long long reversed =0;
  
  long long number=x;
  


  while(x>0){
      int digit =x%10;
       reversed = (reversed *10)+ digit;
      x =x/10;
  }

  if(reversed == number){
      return true;
  }
  return false;
  








    }
    
};