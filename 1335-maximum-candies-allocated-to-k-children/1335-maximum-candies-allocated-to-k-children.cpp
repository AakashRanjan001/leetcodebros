class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        
     int n = candies.size();
     sort(candies.begin(),candies.end());
     long long sum =0;
     for(int i=0;i<n;i++){
         sum+=candies[i];
         if(sum<k){
            return 0;
         }
     }
    return candies[0];

    }
};