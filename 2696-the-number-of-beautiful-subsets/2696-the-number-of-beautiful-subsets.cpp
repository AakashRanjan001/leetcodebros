class Solution {
public:
    int ans=0;
    bool check(vector<int>&temp, int k){
        if(temp.empty())  return false;
        if(temp.size()==1)  return true;
        for(int i=0;i<temp.size();i++){
            for(int j=i+1;j<temp.size();j++){
                if(abs(temp[j]-temp[i])==k)
                    return false;
            }
        }
        return true;
    }
    int solve(vector<int>&nums, int k, int i, vector<int>&temp){
        if(i==nums.size()){
            if(check(temp,k)){
                return 1;
            }
            return 0;
        }
        temp.push_back(nums[i]);
        int val1=solve(nums,k,i+1,temp);
        temp.pop_back();
        int val2=solve(nums,k,i+1,temp);

        return val1+val2;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> temp;
        return solve(nums,k,0,temp);
    }
};
