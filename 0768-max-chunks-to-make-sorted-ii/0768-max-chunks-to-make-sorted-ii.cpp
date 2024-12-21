class Solution {
public:
const int MOD = 1e9 +7;
    int maxChunksToSorted(vector<int>& arr) {
         int n = arr.size();
         vector<int>temp = arr;
         sort(temp.begin(),temp.end());

         int prefixSum =0;
         int tempPrefixSum =0;
         int cnt =0;
         for(int i=0;i<n;i++){
            prefixSum+=arr[i];
            tempPrefixSum+=temp[i];

            if(prefixSum == tempPrefixSum){
                 cnt++;
            }

         }
         return cnt %MOD;
    }
};