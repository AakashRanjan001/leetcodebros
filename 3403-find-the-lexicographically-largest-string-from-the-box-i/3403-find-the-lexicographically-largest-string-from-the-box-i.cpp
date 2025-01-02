class Solution {
public:
    string answerString(string word, int numFriends) {
        
        int n =  word.size();
        if(numFriends == 1)return word;
        string res = "";
        int len = n - numFriends +1 ;
        for(int i=0;i<len;i++){
             string str = word.substr(i,len);
             res = max(res,str);
        }
        return res;
    }
};