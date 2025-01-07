class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
      
      vector<string>ans;
        sort(words.begin(),words.end(),[](string a,string b){
            return a.size()<b.size();
        });
      for(int i=0;i<n;i++){
         for(int j=i+1;j<n;j++){
             if( i!=j && words[j].find(words[i])!=string::npos){
                 ans.push_back(words[i]);
                 break;
                }
         }
      }
   
      
      return ans;

    }
};