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
        int count =0;
        for(auto it:mpp){
            
            if(it.second>0){
                count= count + it.second;
            }
        }
        return count;
    }
};