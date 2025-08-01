class Solution {
public:
    int ncr(int n, int r){
         long long res = 1;
         for(int i=0;i<r;i++){
             res = res*(n-i);
             res = res/(i+1);
         }
         return res;
    }
    vector<int> getRow(int n) {
         //hame woh element nikqalna jao 

         //naive approach 
         vector<int>ans;
         for(int c =0;c<=n;c++){
               int element = ncr(n,c);
               ans.push_back(element);
         }
         return ans;
    }
};