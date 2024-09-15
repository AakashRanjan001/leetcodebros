class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
         set<int>st;
         vector<int>ans;
         for(int i=0;i<n;i++){
            if(st.find(nums[i])!=st.end()){
                ans.push_back(nums[i]);
            }
            else{
                st.insert(nums[i]);
            }
         } 
        
        return ans;
    }
};