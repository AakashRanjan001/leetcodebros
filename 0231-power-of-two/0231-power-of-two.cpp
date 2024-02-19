class Solution {
public:                              //method of recursion 
// we can even solve it by bit manipulation
    bool isPowerOfTwo(int n) {
         
         if(n==0){
             return false;
         }
        if(n==1 || (n%2==0 && isPowerOfTwo(n/2))){
            return true;
        }
return false;

    }
};