class Solution {
public:
    string lexSmallest(string s) {
        // int n = s.size();  // this was my solution but i have to make it the bvest 
        // int mini = s[n-1] - 'a';
        // int index = n-1;
        // for(int i=n-2;i>=0;i--){
        //      if(s[i]- 'a' <= mini){
        //          mini = s[i]- 'a';
        //          index = i;
        //      }
          
        // }
        // reverse(s.begin(), s.begin()+index+1);
        // return s;

        //  int n = s.size();
        //  string pref = s;
        //  int minipref = s[n-1]-'a';
        //  int prefindex = n-1;
        //  for(int i=n-2;i>=0;i--){
        //      if(s[i]-'a'<=minipref){
        //          minipref = s[i] -'a';
        //          prefindex = i;
        //      }else{
        //         break;
        //      }
        //  }
        //  reverse(pref.begin(), pref.begin() + prefindex+1);

        //   int suffindex = 0;
        //   string suff = s;
        //  int minisuff = s[0]-'a';
        //  for(int i=1;i<n;i++){
        //      if(s[i]-'a'<=minisuff){
        //          minisuff = s[i]-'a';
        //          suffindex = i;
        //      }
        //      else{
        //          break;
        //      }
        //  }
        //  reverse(suff.begin()+ suffindex, suff.end());
        //  return min(pref,suff);
     int n = s.length();
        string res = s;

        for(int k = 0; k < n; ++k) {
            string a = s;
            reverse(begin(a), begin(a) + k);

            string b = s;
            reverse(begin(b) + k, end(b));

            res = min({res, a, b});
        }
        
        return res;
 
         
    }
};


