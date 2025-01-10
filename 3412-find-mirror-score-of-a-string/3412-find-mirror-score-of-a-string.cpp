class Solution {
public:
    long long calculateScore(string s) {
        // i habe to use the most recentky used mirror
        long long score =0;
        unordered_map<char,vector<int>>mp;
        for(int i=0;i<s.size();i++){
            char mirror = (25-(s[i]-'a')) + 'a';
            if(mp.find(mirror)!=mp.end()){
                int index = mp[mirror].back();//sabse previous wala 
                score += i - index;
                mp[mirror].pop_back();
                // YAHA MERA GALTI THA < BHUL GYA TAH 
                if(mp[mirror].size() == 0){
                     mp.erase(mirror);
                }
            }
            else{
                mp[s[i]].push_back(i); // agar maanlo mai pehele char mei aaya aur uska mirror tab tak present nhi tha tab apon ko 
                // push karna hoga 
            }
        }
       return score;

    }
};