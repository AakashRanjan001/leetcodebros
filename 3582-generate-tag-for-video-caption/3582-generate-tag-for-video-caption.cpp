class Solution {
public:
    string generateTag(string caption) {

        // MY WRONG SOLUTION !! 

        //  int n = caption.size();
        //  vector<string>words;
        //  string str = "";
        //  for(int i=0;i<n;i++){
        //      if(caption[i] == ' '){
        //          if(!str.empty()){
        //              words.push_back(str);
        //              str = "";
        //          }        
        //      }
        //      else{
        //          str+=caption[i];
        //      }
        //  }

        //  //for adding the last word
        //  if(!str.empty())words.push_back(str);

        //  for(int i=0;i<words.size();i++){
        //      if(words[i][0] >='A' && words[i][0]<='Z'){
        //          words[i][0] +=32;
        //          break;
        //      }
        //  }
        //  for(int i=1;i<words.size();i++){
        //      for(int j=0;j<words[i].size();j++){
        //          if(words[i][0]>='a' && words[i][0]<='z'){
        //              words[i][0]-=32;
        //          }
        //          else if(words[i][j]>='A' && words[i][j]<='Z'){
        //               words[i][j]+=32;
        //          }
        //      }
        //  }
        //   string ans = "#";
        // for (int i = 0; i < words.size(); i++) {
        //     ans+=words[i];
           
        // }
        //  if (ans.size() > 100) {
        //     ans = ans.substr(0, 100);
        // }
        //   return ans;

        int n = caption.size();
        string ans = "#";
        for(int i=0;i<n;i++){
             if(caption[i] == ' '){
                 continue;
             }
              if(i>0  && caption[i-1] == ' '){
                 if(islower(caption[i]))caption[i] = toupper(caption[i]);
             }
             else{
                 if(isupper(caption[i])) caption[i] = tolower(caption[i]);
             }
             ans+=caption[i];
        }
      if(ans.size()>=1)ans[1] = tolower(ans[1]);
      return ans.substr(0,100);
       

    }
};