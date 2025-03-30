class Solution {
public:
    int partitionString(string s) {
          
          vector<string>ans;
          int n = s.size();

          int j=0;
          int cnt =1;
           string temp;
          while(j<n){
              if(temp.find(s[j])==string:: npos || temp.empty()){
                 temp.push_back(s[j]);
                 j++;
              }
              else{
                 cnt++;
                 temp.clear();
                 temp.push_back(s[j]);
                 j++; 
              }
          }
         return cnt;

    }
};