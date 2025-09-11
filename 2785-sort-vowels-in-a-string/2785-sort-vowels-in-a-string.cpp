class Solution {
public:
    string sortVowels(string s) {
        
        int n = s .size();
        vector<char>ans;
        for(int i=0;i<n;i++){
           if(s[i]=='a' ||s[i]=='e'||s[i]=='o'|| s[i]=='u' ||s[i]=='i' ||s[i]=='A' ||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
               ans.push_back(s[i]);
           }
        }
        sort(ans.begin(),ans.end());
        int j=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a' ||s[i]=='e'||s[i]=='o'|| s[i]=='u' ||s[i]=='i' ||s[i]=='A' ||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                s[i]=ans[j];
                j++;
            }
        }
        return s;
    }
};