class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        
        string temp ="";
        for(int i=0;i<words.size();i++){
            temp+=words[i];
            cout<<temp<<endl;
             if(temp == s){
            return true;
        }
        }
            return false;
        
    }
};