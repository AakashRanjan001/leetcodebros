class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int cnt_zero =0;
        int cnt_one = 0;
        int cnt_two =0;

        for(int i=0;i<n;i++){
             if(nums[i] == 0)cnt_zero++;
             else if(nums[i] == 1)cnt_one++;
             else cnt_two++;
        }
        nums.clear();
        while(cnt_zero--){
           nums.push_back(0);  
        }
        while(cnt_one--){
             nums.push_back(1);
        }
        while(cnt_two--){
             nums.push_back(2);
        }

    }
};