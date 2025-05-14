#define MOD 1000000009
class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
         
         vector<int>freq(26,0);
         for(auto i:s){ 
            freq[i - 'a']++;
         }
         //now after the transformation 
         for(int cnt =1;cnt<=t;cnt++){
              vector<int>temp(26,0);
             for(int i=0;i<freq.size();i++){
                 char ch = i + 'a';
                 int number = freq[i];
                 

                 if(ch!='z' && nums[ch-'a'] == 1){
                      temp[ch-'a' + 1] = (temp[ch-'a'+1] + number) % MOD;
                 }
                 else if(nums[ch-'a']>1){
                       for(int j=1;j<=nums[ch-'a'];j++){
                            temp[(ch-'a'+j)%26] = (temp[(ch-'a'+j)%26] + number)%MOD;
                            
                       }
                 }
             }
               freq = (temp);

         }

         long long ans = 0;
         for(int i=0;i<freq.size();i++){
             ans+=freq[i];
         }
         return ans;
    }
};