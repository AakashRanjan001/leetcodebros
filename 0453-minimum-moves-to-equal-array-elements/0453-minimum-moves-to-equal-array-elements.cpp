class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int moves =0;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            moves+= nums[i]-nums[0];
        }
       return moves;

    }
};