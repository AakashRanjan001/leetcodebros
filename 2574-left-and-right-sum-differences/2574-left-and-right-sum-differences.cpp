class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        
        int n = nums.size();
vector<int>leftSum;
vector<int>rightSum;

int sum =0;
        for(int i=0;i<n;i++){
           leftSum.push_back(sum);
           sum +=nums[i]; 
        }

sum =0;
for(int i=n-1;i>=0;i--){
    rightSum.push_back(sum);
    sum +=nums[i];
}
reverse(rightSum.begin(),rightSum.end());

vector<int>ans;
for(int i=0;i<n;i++){
int diff = abs(leftSum[i] - rightSum[i]);
ans.push_back(diff);
}
return ans;

    }
};