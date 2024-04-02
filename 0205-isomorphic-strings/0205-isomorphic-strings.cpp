class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size(),m=t.size();
        if(n!=m) return false;
        map<char,vector<int>>m1,m2;
        for(int i=0;i<n;i++){
            m1[s[i]].push_back(i);
            m2[t[i]].push_back(i);
        }

        for(int i=0;i<n;i++){
            if(m1[s[i]]!=m2[t[i]]) return false;
            
        }
         
         return true;
    }
};
