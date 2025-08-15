class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //  int n = nums.size();
        //  set<vector<int>>st;
        //  set<int>hash;
        //  for(int i=0;i<n;i++){
        //     hash.clear();
        //      for(int j=i+1;j<n;j++){
        //          int third = 0 -(nums[i] + nums[j]);
                  
        //           if(hash.find(third)!=hash.end()){
        //                vector<int>temp({nums[i] , nums[j] , third});
        //                sort(temp.begin(), temp.end());
        //                st.insert(temp);
        //           }
        //      hash.insert(nums[j]);       
        //      }
        //  }
        //  vector<vector<int>>ans(st.begin(),st.end());
        //   return ans;

         
         int n = nums.size();
         sort(nums.begin(),nums.end());
         vector<vector<int>>ans;

         for(int i=0;i<n;i++){
             if(i>0 && nums[i] == nums[i-1])continue;

             int j = i+1;
             int k = n-1;

             while(j<k){
                 int sum = nums[i] + nums[j]  + nums[k];
                 if(sum<0){
                     j++;
                 }
                 else if( sum>0){
                     k--;
                 }
                 else{
                     ans.push_back({nums[i],nums[j],nums[k]});
                     j++;
                     k--;

                     while(j<k && nums[j] == nums[j-1])j++;
                     while(j<k && nums[k] == nums[k+1])k--;
                 }
             }
         }
         return ans;
    }
};