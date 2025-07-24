class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         int n = nums.size();
         set<int>st;
         for(int i=0;i,n;i++){
             st.insert(nums[i]);
         }
         nums.erase(nums.begin(),nums.end());
         for(auto i :st){
             nums.push_back(i);
         }
         return nums.size();
          
       
    }
};