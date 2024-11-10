
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        vector<int> b(32,0);//this bits array
        int temp=0;
        int l = 0;
        int r = 0;

        while(r<n){
            temp = temp | nums[r];
            
            for(int i =0;i<32;i++){
                if(nums[r] & (1<<i)){
                    b[i]++;
                }
            }

            if(temp>=k){
                //cout<<r<<l<<ans << " ddfa" ; this for debuging purpose
                ans = min(ans,r-l+1);
            }

            while(l<r && temp>=k){
                for(int i =0;i<32;i++){
                    if(nums[l] & (1<<i)){
                        b[i]--;
                    }
                }  
                int recentnew=0;
                for(int i =0;i<32;i++){
                    if(b[i]>0){
                        recentnew += 1<<i;
                    }
                }  
                l++;
                temp = recentnew;
                if(temp>=k){
                    ans = min(ans,r-l+1);
                }
            }
            r++;
        }
        return ans==INT_MAX?-1:ans;
    }
};