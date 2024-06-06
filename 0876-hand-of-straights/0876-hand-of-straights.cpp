class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        map<int,int>mp;
         for(auto i: hand){
        mp[i]++;
    }
  if(n%groupSize!=0)return false;
   for(auto [h,freq]:mp){
    if(freq==0)continue;
    while(freq--){
        for(int j=h;j<h+groupSize;j++){
            if(mp[j]==0)return false;
            mp[j]--;
        }
    }

 }
 return true;

    }
};