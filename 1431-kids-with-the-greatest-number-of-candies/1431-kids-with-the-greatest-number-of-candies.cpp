class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool>ans;
        int largest = candies[0];
        for(int i=0;i<n;i++){
            if(candies[i]>largest){
                largest = candies[i];
            }
        }
        for(int i=0;i<n;i++){
            candies[i]=candies[i]+extraCandies;
            if(candies[i]>=largest){
                ans.push_back(true);
            }
            else{
            ans.push_back(false);
            }
        }
        return ans;
    }
};