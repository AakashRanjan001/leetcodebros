class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
       // pehle string ko padd kar lete hai if the size is not divisible by k

          int n = s.size();
       while(s.size()%k!=0){
          s+=fill;
       }
    
       vector<string>ans;
       for(int i=0;i<n;i+=k){
          ans.push_back(s.substr(i,k));
       }
        return ans;
    }
};