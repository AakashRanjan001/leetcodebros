class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
         
         //brute force 
        //  int n = queries.size();
        //  for(int i=0;i<n;i++){
        //      int s = queries[i][0];
        //      int e = queries[i][1];


        //     for(int j=s;j<=e;j++){
        //          if(nums[j]>0){
        //              nums[j]--;
        //          }
        //          else{
        //              continue;
        //          }
        //     }
        //  }
        //  bool f = true;
        //  for(int i=0;i<nums.size();i++){
        //      if(nums[i] != 0){
        //          f = false;
        //      }
        //  }
        //  if(f)return true;
        //  return false;

        //RANGE QUERY 
        // DIFFERENCE ARRAY TECHNIQUE

        int n = nums.size();

        //STEP1 : make the diffrence array using query;
         vector<int>diff(n,0);
         for(auto &q:queries){
             int s = q[0];
             int e = q[1];
             int x = 1;
              
             diff[s]+=x;
             if(e+1<n){
                 diff[e+1]-=x;
             } 
             
         }

         //step 2: find the cumulative sum on each index 
         int cumSum =0;
         vector<int>result(n, 0);
         for(int i=0;i<n;i++){
             cumSum+=diff[i];
             result[i] = cumSum;
         }
         // means harr ek index mei pata chalega in result array that these many operations are required for the above tranformation 

         for(int i=0;i<n;i++){
             if(result[i]<nums[i]){
                 return false;
             }
         }
         return true;

    }
};