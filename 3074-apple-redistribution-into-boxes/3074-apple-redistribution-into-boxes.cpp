class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
         int n = apple.size();
         int m = capacity.size();
          
         sort(capacity.rbegin(),capacity.rend());
         int sum =0;
         for(auto i: apple){
             sum+=i;
         }
         int box =0;
         for(int i=0;i<m;i++){
             sum = sum - capacity[i];
             box++;
             if(sum<=0)break;
         }
         return box;
    }
};