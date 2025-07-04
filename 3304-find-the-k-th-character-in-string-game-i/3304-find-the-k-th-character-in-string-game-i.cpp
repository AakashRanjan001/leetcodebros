class Solution {
public:
    char kthCharacter(int k) {

        // TIME COMPLEXITY ---> O(K)
        //   string res = "a";
        //   while(res.length()<k){
        //      int n = res.length();
        //      for(int i=0;i<n;i++){
        //          char ch = res[i] == 'z'?'a' : res[i]+1;
        //          res.push_back(ch);
        //      }
        //   }
        //   return res[k-1];

        // BETTER SOLUTION 
        int shift = __builtin_popcount(k-1);
        return 'a'+shift;

    }
};