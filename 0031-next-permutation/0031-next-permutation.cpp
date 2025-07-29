// class Solution {
// public:
//     void func(vector<int> &temp, vector<bool>&hash , vector<int> &ds , set<vector<int>>& ans){
//          if(ds.size() == temp.size()){
//              ans.insert(ds);
//              return;
//          }

//          for(int i=0;i<temp.size();i++){
//              if(hash[i] ==0){
//                  ds.push_back(temp[i]);
//                  hash[i] = 1;
//                  func(temp,hash,ds,ans);
//                  //while returning 
//                  ds.pop_back();
//                  hash[i] = 0;
//              }
//          }
//     }
    
//     void nextPermutation(vector<int>& nums) {
//          // store all the permutations in a array and thens sort it lexicographically and then give the next inde x
         
//          vector<int>temp = nums;
//          int n = nums.size();
//          vector<bool>hash(n,0);
//          vector<int>ds;
//          set<vector<int>>ans;
//          func(temp,hash,ds,ans);
       
//        vector<vector<int>>newAns(ans.begin(),ans.end());


//          for(int i = 0; i < newAns.size(); i++) {
//              if(newAns[i] == nums) {
//                  if(i == newAns.size() - 1)
//                      nums = newAns[0];
//                  else
//                      nums = newAns[i + 1];
//                  return;
//              }
//          }

//     }
// };

// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//          int n = nums.size();
//          vector<int>temp = nums;
//          set<vector<int>>perms;

//          sort(temp.begin(),temp.end());
//          perms.insert(temp); // pehle permutation ko insert karo 

//          while(next_permutation(temp.begin(),temp.end())){
//              perms.insert(temp);
//          }

//           vector<vector<int>> allPerms(perms.begin(), perms.end());


//         for(int i = 0; i < allPerms.size(); ++i) {
//             if(allPerms[i] == nums) {
//                 if(i + 1 < allPerms.size())
//                     nums = allPerms[i + 1];
//                 else
//                     nums = allPerms[0];  // wrap around
//                 return;
//             }
//         }

//     }
// };
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n = nums.size();
         int ind = -1;
         //dip nikalna hai
         for(int i=n-2;i>=0;i--){
             if(nums[i]<nums[i+1]){
                 ind = i;
                 break;
             }
         }

         // edge case 
         if(ind == -1){ // jab last wala perms hoga 
            reverse(nums.begin(),nums.end()); 
            return;
         }

         // replace the element with the greater element in the right side 
         for(int i=n-1;i>=0;i--){
             if(nums[i]>nums[ind]){
                 swap(nums[i],nums[ind]);
                 break;
             }
         }
         reverse(nums.begin() + ind +1, nums.end());

    }
};