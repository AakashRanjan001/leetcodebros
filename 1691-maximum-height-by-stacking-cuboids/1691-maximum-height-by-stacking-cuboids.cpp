class Solution {
public:
 bool check(vector<int>a , vector<int>b){
    if(b[0]<=a[0] && b[1]<=a[1] && b[2]<=a[2])return true;
    else
     return false;
 }
 int solveUsingTabSO(vector<vector<int>>& nums){
        int n = nums.size();
       vector<int>currRow(n+1 , 0);
       vector<int>nextRow(n+1 , 0);

          
          for(int curr = n-1;curr>=0;curr--){
            for(int prev = curr-1;prev>=-1 ; prev--){
              int include =0; 
              // hamesha yah amei chaneg hoyta hai dhyan rkahna 
              if(prev == -1 || check(nums[curr] , nums[prev])){
              include =  nums[curr][2] + nextRow[curr +1];// we have done curr as for validindex
            // hamne pehel LIS mei 1 + kiya tha lein hame yaha mei height plus karni hai 
             // height kiski karni hai curr ki phro
             }
  
         // excude 
            int exclude = 0 + nextRow[prev +1];
            int ans = max(include, exclude);
             currRow[prev +1] =ans;
   
            }
            //shifting 
            // yaha mai bhulta hu x
            nextRow = currRow; // upar ki taraf jaaa rrha na 
          }
        return currRow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        //step 1: sort the array in each row // taaki height sabse right side ko lele
        for(auto &it:cuboids){
             sort(it.begin(),it.end());
        }
       // step 2: sort the array on the basis of th width 
       sort(cuboids.begin(),cuboids.end());

       int ans = solveUsingTabSO(cuboids);
       return ans;


    }
};