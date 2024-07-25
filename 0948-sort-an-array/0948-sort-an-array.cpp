class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        priority_queue<int ,vector<int>, greater<int>>minH;
        //minH is the minimum heap 
        for(int i=0;i<n;i++){
            minH.push(nums[i]);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
             ans.push_back(minH.top());
             minH.pop();
        }
        return ans;
    }
};