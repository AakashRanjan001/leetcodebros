class Solution {
public:
    int minSteps(string s, string t) {
        
        map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            mpp[t[i]]--;
        }
        int count1 =0;
        for(auto it:mpp){
            if(it.second>0){
                count1 = count1 + it.second;
            }
        }
        map<char,int>spp;
            for(int i=0;i<t.size();i++){
            spp[t[i]]++;
        }
        for(int i=0;i<s.size();i++){
            spp[s[i]]--;
        }
           int count2 =0;
        for(auto im:spp){
            if(im.second>0){
                count2 = count2 + im.second;
            }
        }
        
    return count1 + count2;
    }
};