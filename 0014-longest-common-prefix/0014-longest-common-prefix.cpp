class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string temp ="";
        
        for(int i=0;i<strs[0].size();i++){
             char ch = strs[0][i];
             bool match = true;

             for(int j =1;j<n;j++){
                 if(ch!=strs[j][i]){
                     match = false;
                     break;
                 }
             }
             if(match == false){
                 break;
             }
             else{
                temp+=ch;
                  
             }
        }
        return temp;
    }
};