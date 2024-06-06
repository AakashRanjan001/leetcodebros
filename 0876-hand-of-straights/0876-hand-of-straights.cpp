class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gz) {
        int n = hand.size();
        if(n % gz)return false;
        sort(hand.begin(), hand.end());
        map <int,int> mp;
        for(int i : hand)mp[i]++;
        for(int num : hand){
            if(mp[num] == 0)continue;
            int cnt = mp[num];
            for(int j = 0; j < gz; j++){
                if(mp[num+j] >= cnt){
                    mp[num+j] -= cnt;
                }
                else return false;
            }
        }
        return true;
    }
};
