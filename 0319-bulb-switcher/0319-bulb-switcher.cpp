class Solution {
public:
    // bool perfectsquare(int n){
    //      long long sr = sqrt(n);
    //      if(sr*sr == n)return true;
    //      return false;
    // }
    int bulbSwitch(int n) {
        //approch 1 : count the number of perfect squares from 1 to n , then that is the answer 
        //  int cnt =0;
        //  for(int i=1;i<=n;i++){
        //      if(perfectsquare(i)){
        //          cnt++;
        //      }
        //  }
        //  return cnt;

        // approach 2 : by just returning the sqrt(n)
        return sqrt(n);
    }
};