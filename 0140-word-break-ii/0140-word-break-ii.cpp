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
       //step 1 : crreat e a Dp araray , or unordered_map;
        unordered_map<int,vector<string>>dp; //harr ek i -->string(valid word)
    
     vector<string>solveUsingMem(string &s,unordered_map<string,bool>&dict , int i){
      if(i==s.size())return {""};
      vector<string>ans;
      string word;//s ke pehle character se tarverse karte rahenge 

      if(dp.find(i)!=dp.end())return dp[i];

      for( int j = i;j<s.size();++j){
           word.push_back(s[j]);
           //agar word nhi mila bass
           if(dict.find(word) == dict.end()){
               continue;
           }
          //agar word mil gya tab 
           auto right = solveUsingMem(s,dict,j+1); // right part mil gya 
           for(auto eachRightWord: right){
               string endPart;
               if(eachRightWord.size()>0 )endPart = " " + eachRightWord;
               ans.push_back(word + endPart); 
           }
      }
     return  dp[i] = ans;

    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool>dict; //for finding the wprd in the wordDict 
        for(auto word:wordDict){
             dict[word] = 1;
         }
        // return solveUsingRec(s,dict,0);
     
        return solveUsingMem(s,dict,0);
    }
};