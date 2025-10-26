class Solution {
public:
    long long removeZeros(long long n) {
         string temp = to_string(n);
         string ans = "";
         for(long long i=0;i<temp.size();i++){
             if(temp[i]!='0'){
                 ans+=temp[i];
             }
         }
         long long val = stoll(ans);
         return val;
    }
};