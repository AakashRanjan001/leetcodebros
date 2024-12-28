class Solution {
public:
    vector<string>solveUsingRec(string &s,unordered_map<string,bool>&dict , int i){
      if(i==s.size())return {""};
      vector<string>ans;
      string word;//s ke pehle character se tarverse karte rahenge 

      for( int j = i;j<s.size();++j){
           word.push_back(s[j]);
           //agar word nhi mila bass
           if(dict.find(word) == dict.end()){
               continue;
           }
          //agar word mil gya tab 
           auto right = solveUsingRec(s,dict,j+1); // right part mil gya 
           for(auto eachRightWord: right){
               string endPart;
               if(eachRightWord.size()>0 )endPart = " " + eachRightWord;
               ans.push_back(word + endPart); 
           }
      }
     return ans;

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>dict; //for finding the wprd in the wordDict 
        for(auto word:wordDict){
             dict[word] = 1;
        }
        return solveUsingRec(s,dict,0);
    }
};