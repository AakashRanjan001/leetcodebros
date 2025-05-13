// #define MOD 1000000009
// class Solution {
// public:
//     int lengthAfterTransformations(string s, int t) {
         
    //      int n = s.size();
    //  while(t--){ 
    //      string temp = "";   
    //      for(int i=0;i<n;i++){
    //          char ch = s[i];

    //          if(ch>='a' && ch<='y'){
    //               temp+= (char)(ch + 1);
                 
    //          }
    //          else if(ch == 'z'){
    //              temp+="ab";            
                 
    //          }
    //      }
    //      s = temp;
    //  }
    //  return s.size() % MOD;


//      vector<int>mp(26,0);
//      for(int i=0;i<s.size();i++){
//          mp[s[i]-'a']++;
//      }

//      for(int cnt =1 ;cnt<=t;cnt++){
         
//           vector<int>temp(26,0);
//           for(int i=0;i<26;i++){
//               char ch = i + 'a';
//               int freq = mp[i];

//               if(ch!='z'){
//                  temp[(ch + 1 )- 'a'] = (temp[(ch + 1) - 'a'] + freq)% MOD;
//               }
//               else{
//                  temp[0] = (temp[0]+ freq) % MOD;
//                  temp[1] =  (temp[1]+ freq)%MOD;
//               }
//           }
//           mp = temp; // after one transformation convert the current map to its previosu map
//      }
//       long long ans = 0;
//        for(int i=0;i<mp.size();i++){
//           ans  = (ans + mp[i]) % MOD;
//        }
//      return ans ;
//     }
// };

class Solution {
public:
    int lengthAfterTransformations(string s, int t) 
    {
        int n = s.size();
        long ans = 0, mod = 1e9 + 7;

        vector<long> count(130);
        for(auto &ch : s) count[ch] += 1;

        while(t--)
        {
            vector<long> temp(130);
            for(auto ch = 'z'; ch >= 'a'; ch--)
            {
                if(ch == 'z') temp['a'] = count[ch], temp['b'] = count[ch];
                else temp[ch + 1] += count[ch];
                temp[ch] %= mod;
            }
            count = temp;
        }

        for(auto ch = 'z'; ch >= 'a'; ch--)
            ans += (count[ch] % mod);

        return ans % mod;
    }
};