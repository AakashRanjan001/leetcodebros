class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
         int n = operations.size();
         int sum =0;
         for(auto it:operations){
             if(it == "--X" || it == "X--"){
                 sum-=1;
             }
             else{
                 sum+=1;
             }
         }
         return sum;
    }
};