class Solution {
public:
     int solveUsingRec(vector<int>& nums,int start , int end){
        // base case
        if(start == end)return nums[start];
        
        //diff-> p1 - p2
        //p1 --> nums[start] pick kiya , bakki recursion p2-->ka laayega 
        int diffbystart = nums[start] -solveUsingRec(nums, start+1,end);
        int diffbyend = nums[end] - solveUsingRec(nums,start,end -1);

        //agar meko player 1 ko jeetnaa hai toh meko diiff maximise karna hoga 
        int ans = max(diffbystart,diffbyend);
        return ans;
     }
    bool predictTheWinner(vector<int>& nums) {
        //start = 0 , end = nums.size()-1
        int ans = solveUsingRec(nums,0,nums.size()-1);
        return ans>=0;

    }
};