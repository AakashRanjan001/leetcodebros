class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        for(char ch ='a' ;ch<='z';ch++){
            int mnc =INT_MAX;
            for(string eachstr:words){
                int count =0;
                for(char c:eachstr){
                    if(c == ch)count++;
                }
                mnc = min(mnc , count);
            }
        
        for(int i=0;i<mnc;i++){
            ans.push_back(string(1,ch));
        }
        }
        return ans;

    }
};