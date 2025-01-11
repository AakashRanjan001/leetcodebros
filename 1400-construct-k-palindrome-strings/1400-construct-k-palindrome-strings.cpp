class Solution {
public:
    bool canConstruct(string s, int k) {
        //hint dekh ke samjh aaya 
        vector<int>hash(26,0);
        int n = s.size();
        int cnt =0;
        if(s.size()<k)return false;
        for(int i=0;i<n;i++){
            hash[s[i]-'a']++;
            if(hash[s[i]-'a'] % 2 ==0){
                cnt--;
            }
            else{
                cnt++;
            }
        }
      //  If the number of characters that have odd counts is > k then the minimum number of palindrome strings we can construct is > k and answer is false.
        if(cnt ==0 || cnt<=k){
            return true;
        }
        return false;
    }
};