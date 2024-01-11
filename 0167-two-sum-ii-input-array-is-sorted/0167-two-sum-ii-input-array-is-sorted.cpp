class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        map<int,int>mpp;
        for(int i=0;i<numbers.size();i++){
            int a = numbers[i];
            int extra = target - a;
            
            if(mpp.find(extra)!=mpp.end()){
                return {mpp[extra]+1,i+1};
            }
            mpp[a]=i;
        }
   
        return{-1,-1};
    }
};