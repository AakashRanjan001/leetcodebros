class Solution {
public:
    long long sumAndMultiply(int n) {
         string temp = to_string(n);
         string ans ="";
         long long sum =0;
         for(long long i=0;i<temp.size();i++){
             if((temp[i] - '0') != 0){
                  ans.push_back(temp[i]);
                  sum+=(temp[i]- '0');
             }
         }
         long long num = stoll(ans);
         return num*sum*1LL;

    }
};