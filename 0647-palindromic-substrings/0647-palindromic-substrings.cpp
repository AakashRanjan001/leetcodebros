class Solution {
public:
    int expandAroundindex(string s,int i,int j){
        int count =0;
        while(i>=0 && j<s.length() && s[i]==s[j]){
            count ++;
            i--;
            j++;
            
        }
        return count;
    }
    
    
    
    
    int countSubstrings(string s) {
        int count =0;
        int n = s.length();
        
        for(int i=0;i<n;i++){
            //odd index
            int oddkaindex = expandAroundindex(s , i ,i);
            count = count + oddkaindex;
        }
        for(int i=0;i<n;i++){
            int evenkaindex = expandAroundindex(s,i,i+1);
            count = count + evenkaindex;
        }
        return count ;
    }
};