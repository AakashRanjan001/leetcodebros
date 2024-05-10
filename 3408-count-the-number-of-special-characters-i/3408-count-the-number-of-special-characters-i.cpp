class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,bool>mpp;
        int cnt =0;
        
        for(int i=0;i<word.size();i++){
            if(word[i]>=97 && word[i]<=122 && mpp[word[i]]!=true){
                mpp[word[i]]=true;
                
                char c1 = word[i];
                char c2 = toupper(c1);
                for(auto j:word){
                    if(j==c2){
                        cnt++;
                        break;
                    }
                }

            }
        }
        return cnt;
    }
};