class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        int n = gifts.size();
        sort(gifts.rbegin(),gifts.rend());
    
        while(k--){
            
            gifts[0] = floor(sqrt(gifts[0]));

            sort(gifts.rbegin(),gifts.rend());
        }
        long long sum =0;
        for(int i=0;i<n;i++){
            sum+=gifts[i];
        }
        return sum;
    }
};