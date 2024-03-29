class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       //basic observation is needed
       //difference ebetween the last and first element 

    int n = nums.size();
    int i=0;
    int j = n-1;
 int sum =0;
while(i<j){
sum+= nums[j]-nums[i];
}
return sum;
    }
};