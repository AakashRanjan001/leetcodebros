class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int length=0;       
        bool flag = false;    //apon ko spaces ignore karne ke liye bool data type ka use karna padega
        for(int i=n-1;i>=0;i--){
          if(s[i]==' ' && flag==false)continue;
          if(s[i]!=' ')length++; flag = true;
          if(s[i]==' '&& flag==true)break;
               
        }
        return length;
    }
};