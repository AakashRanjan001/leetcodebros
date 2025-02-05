class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        //   if(s1 == s2)return true;
        //   if(s1.size()!=s2.size())return false;
        //   int n = s1.size();
        //   for(int i=0;i<s2.size();i++){
        //       swap(s2[i],s2[n-i-1]);
        //       if(s1 == s2)return true;
        //       break;
         
        //   }
        //   for(int i=0;i<n;i++){
        //       swap(s1[i],s1[n-i-1]);
        //       if(s1 == s2)return true;
        //       break;
      
        //   }
        //   return false;

        // sort(s1.begin(),s1.end());
        // sort(s2.begin(),s2.end());

        // if(s1 == s2)return true;
        // return false;

        if (s1 == s2) return true;  // Already equal
        
        vector<int> diff;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) diff.push_back(i);
            if (diff.size() > 2) return false;  
        }

        if (diff.size() != 2) return false;  // Must be exactly 2 mismatches
        
        
        return s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]];
    }
};