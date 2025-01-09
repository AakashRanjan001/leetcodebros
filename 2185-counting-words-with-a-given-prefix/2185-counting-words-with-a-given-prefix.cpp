class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int n = words.size();
        int cnt =0;
        for(int i=0;i<n;i++){
            auto substring = words[i].substr(0,pref.size());
            if( substring == pref){
                cnt++;
            }
        }
        return cnt;
    }
};