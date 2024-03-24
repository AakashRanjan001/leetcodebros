class Solution {
public:
    bool isSubstringPresent(string s) {
         int n = s.size();

         for(int i=0;i<n-1;i++){
            for(int j= n-1;j>0;j--){
                if(s[i]==s[j]){
                    if(s[i+1]==s[j-1])return true;
                    else{continue;}
                }
                else{continue;}
            }
         }
       return false;

    }
};