// class Solution {  // this is my wrong approach
// public:
//    int countfreq(vector<int>& subbarr, int x){
//          map<int,int>m;
//          for(int i=0;i<subbarr.size();i++){
//               m[subbarr[i]]++;
//          }
//          int ans;
//          if(mp.size()<x){
//              ans = accumulate(subbarr.begin(),subbarr.end(),0);
//          }
//          int maxi = INT_MIN;
//          for(auto i:m){
//              if(i.second>maxi){
//                  maxi = i.second;
//              }
//          }
//          bool f= false;
//          for(auto it:mp){
//              if(it.second == maxi){
//                  ans+=(it.first)*(it.second);
//                  x--;
//                  if(x==0){
//                      f = true;
//                      break;
//                  }
//             }    
//          }
//          while(!f && x--){
//               maxi--;

//               for(auto it:mp){
//                  if(it.second == maxi){
                    
//                  }
//               }
//          }

//    }
//     vector<int> findXSum(vector<int>& nums, int k, int x) {
//          int n = nums.size();
//          vector<int>ans;
//          for(int i=0;i<n;i++){
//              for(int j=i;j<n;j++){
//                   if(j-i+1 == k){
//                       int sum = countfreq(nums,x);
//                       ans.push_back(sum);
//                   }

//              }
//          }
//        return ans;
//     }
// };
class Solution {
public:
   int countfreq(vector<int>& subarr, int x){
       int n = subarr.size();
       map<int,int>mp;
       for(auto i:subarr){
         mp[i]++;
       }
       vector<pair<int,int>>freq;
       for(auto it:mp){
          freq.push_back({it.second,it.first});
       }
       sort(freq.rbegin(),freq.rend());

       int ans =0;
       for(int i=0;i<x && i<freq.size();i++){
           ans+=(freq[i].first)*(freq[i].second);
       }
       return ans;
   }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
         long long n = nums.size();
         vector<int>ans;
         for(int i=0;i+k<=n;i++){
             vector<int>subarr(nums.begin()+i, nums.begin()+i+k);
             int sum = countfreq(subarr,x);
             ans.push_back(sum);
         }
         return ans;
    }
};