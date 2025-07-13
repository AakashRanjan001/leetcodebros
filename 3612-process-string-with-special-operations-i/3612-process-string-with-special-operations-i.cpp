class Solution {
public:
    string processStr(string s) {
          size_t n = s.size();
          string temp = "";
          for(int i=0;i<n;i++){
             char ch = s[i];

             if(ch>='a' && ch<='z'){
                  temp = temp + ch;
             }
             else if(ch == '*'){
                 temp.pop_back();
             }
             else if(ch == '#'){
                 temp = temp + temp;

             }
             else if(ch == '%'){
                 reverse(temp.begin(),temp.end());
             }
          }
          return temp;
    }
};