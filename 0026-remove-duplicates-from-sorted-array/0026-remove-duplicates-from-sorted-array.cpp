class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       set<int>st;
       int n = nums.size();
       for(int i=0;i<n;i++){
        st.insert(nums[i]);
       }
       nums.erase(nums.begin(),nums.end());
       for(auto it: st){
           nums.push_back(it);
       }
       return nums.size();
    }
};