 typedef long long ll;
class Solution {
public:
   
    vector<int> findEvenNumbers(vector<int>& digits) {
          
          int n = digits.size();
          set<ll>st;
       
          for(int i=0;i<n;i++){
             if(digits[i] == 0)continue;
             for(int j=0;j<n;j++){
                 if(i==j)continue;
                 for(int k=0;k<n;k++){
                     if(i == k || j == k)continue;
                     if(digits[k]%2 == 0){
                          ll temp = 100*digits[i] + 10*digits[j] + 1*digits[k];
                          st.insert(temp);
                     }
                 }
             }
          }
        vector<int>ans(st.begin(),st.end());
     return ans;

    }
};