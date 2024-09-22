class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        
    //     unordered_map<string,int>mpp;
    //     for(auto i: message){
    //         mpp[i]++;
    //     }
    //     for(auto i:bannedWords){
    //         mpp[i]++;
    //     }
    // int cnt =0;
    //     for(auto it:mpp){
    //         if(it.second>1){
    //             cnt++;
    //         }
    //     }
    //     if(cnt>=2)return true;
    //     return false;

    unordered_set<string>st;
    for(auto i:bannedWords){
        st.insert(i);
    }
    int cnt =0;
    for(auto i:message){
      if(st.find(i)!=st.end()){
          cnt++;
      }
    }
    if(cnt>=2)return true;
      return false;



    }
};