class Solution {
public:
    bool check(vector<int>& nums) {
        //binary searh ka question lag rha hai 
        int n = nums.size();
        vector<int>temp = nums;

        sort(temp.begin(),temp.end());

        vector<int>ans(2*n);
        for(int i=0;i<n;i++){
            ans[i] = nums[i];
        }
        for(int i=0;i<n;i++){
            ans[n+i] = nums[i];
        }
        // for(int i=0;i<ans.size();i++){
        //     cout<<ans[i]<<"";
        // }

        for (int i = 0; i < n; i++) {
            if (vector<int>(ans.begin() + i, ans.begin() + i + n) == temp) {
                return true;
            }
        }
     return false;

       
    }
};


