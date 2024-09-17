class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        vector<string>ans;
        unordered_map<string,int>mpp;
        string word = "";
        for(auto it:s1){
              if(it == ' '){
                //word complte ho gya hai
                mpp[word]++;
                word = "";
              }
              else{
                word+=it;
              }
        }
        mpp[word]++;
        word ="";

        for(auto i:s2){
              if(i == ' '){
                //word complte ho gya hai
                mpp[word]++;
                word = "";
              }
              else{
                word+=i;
              }
        }
        mpp[word]++;

      for(auto words:mpp){
        if(words.second ==1){
            ans.push_back(words.first);
        }
      }

      return ans;

    }
};