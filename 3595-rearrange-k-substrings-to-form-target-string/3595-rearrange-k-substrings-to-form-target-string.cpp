class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        
        int n = s.size();
        int part = n/k;

        map<string,int>freq;
      
      for(int i=0;i<n;i+=part){
          string substr = s.substr(i,part); // i is the starting index and kitne  length ka chahiye woh hai part length ka 
          freq[substr]++;
      }
      for(int i=0;i<t.size();i+=part){
         string substr = t.substr(i,part);
          if(freq[substr] ==0)return false;
          freq[substr]--;
      }
      return true;
    }
};
