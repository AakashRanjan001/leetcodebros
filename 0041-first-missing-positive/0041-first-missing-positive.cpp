class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        

        for(int i=0;i<n;i++){ 
           if(nums[i]<=0){
            nums[i]=n+1;
           }

        }

        for(int i=0;i<n;i++){
            int x = abs(nums[i]);
            if(x>n)continue;
            if(nums[x-1]<0)continue;
            nums[x-1]*=-1;
        }
         for(int i=1;i<=n;i++){
             if(nums[i-1]>0)return i;
         }

        return n+1;
    }
};