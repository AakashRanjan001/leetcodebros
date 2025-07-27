class Solution {
public:
    void sortColors(vector<int>& nums) {
         //priority Quwue
        //  int n = nums.size();
        //  priority_queue<int , vector<int>, greater<int>>pq;
        //  for(int i =0;i<n;i++){
        //      pq.push(nums[i]);
        //  }
        //  nums.clear();
        //  while(!pq.empty()){
        //      nums.push_back(pq.top());
        //      pq.pop();
        //  }
       

       int cnt_zero = 0,cnt_one = 0, cnt_two = 0;
        for(int i=0;i<nums.size();i++){
             if(nums[i]== 0)cnt_zero++;
             else if(nums[i] == 1)cnt_one++;
             else cnt_two++;
        }
        nums.clear();
        while(cnt_zero!=0){
             nums.push_back(0);
             cnt_zero--;
        }
        while(cnt_one!=0){
             nums.push_back(1);
             cnt_one--;
        }
        while(cnt_two!=0){
             nums.push_back(2);
             cnt_two--;
        }


    }
};