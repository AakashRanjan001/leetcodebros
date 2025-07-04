class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        //base cas e
      if(k == 1)return 'a';
      
      int n = operations.size();
      long long len = 1;
      long long operType = -1;
      long long newK = -1;

      for(int i=0;i<n;i++){
         len*=2;
         if(len>=k){
             operType = operations[i];
             newK = k - len/2;
             break;

         }
      }

      char ch = kthCharacter(newK,operations);
      if(operType == 0){
         return ch;
      }
      else{
         if(ch == 'z')return 'a';
         return ch+1;
      }

    }
};