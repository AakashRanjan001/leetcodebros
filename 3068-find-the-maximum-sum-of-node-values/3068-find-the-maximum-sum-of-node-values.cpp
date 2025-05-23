class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        
        // vector<int>temp = nums;
        // int n = nums.size();
        
        // for(int i=0;i<n;i++){
        //      int Xor = nums[i]^k;
        //      if(Xor > nums[i]){
        //          temp[i] = Xor;
        //      }
        // }
        // int sum =0;
        // for(int i=0;i<temp.size();i++){
        //      sum+=temp[i];
        // }
        // return sum;

        vector<int>temp = nums;
        for(auto i:edges){
             int u = i[0];
             int v = i[1];
             
            int Xor_u = nums[u]^k;
            if(Xor_u > nums[u]){
                temp[u] = Xor_u;
            }
            int Xor_v = nums[v]^k;
            if(Xor_v > nums[v]){
                 temp[v] = Xor_v;
            }
            
           
        }
        int sum =0;
        for(int i=0;i<temp.size();i++){
             sum+=temp[i];
        }
        return sum;

    }
};