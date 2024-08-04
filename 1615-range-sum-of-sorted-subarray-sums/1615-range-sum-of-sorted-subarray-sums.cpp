
#define mod 1000000007;
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        
        vector<int>ans;

        long long temp =0;
        for(int i=0;i<n;i++){
            temp =0;
            for(int j=i;j<n;j++){
                (temp+=nums[j]) % mod;
                ans.push_back(temp);
            }
        }
        sort(ans.begin(),ans.end());
        long long val =0;
        for(int i=left-1 ;i<=right-1;i++){
            (val+=ans[i]) % mod;
        }
        return val;
    }
};