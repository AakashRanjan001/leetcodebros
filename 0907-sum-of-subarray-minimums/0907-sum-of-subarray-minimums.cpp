const int mod = 1e9 + 7;
 class Solution {
public:
    vector<int>findnse(vector<int>& arr){
        int n = arr.size();
         vector<int>nse(n);
         stack<int>st; // we are pushing indexes into the stack 

         for(int i=n-1;i>=0;i--){
              while(!st.empty() &&  arr[st.top()] >= arr[i]){
                 st.pop();
              }
              if(st.empty()){
                 nse[i] = n;
              }
              else{
                 nse[i] = st.top();
              }
              st.push(i);
         }
         return nse;
    }
    vector<int>findpsee(vector<int>& arr){
        int n = arr.size();
         vector<int>psee(n);
         stack<int>st;


         for(int i=0;i<n;i++){
             while(!st.empty() && arr[st.top()]>arr[i]){
                 st.pop();
             }
             psee[i] = st.empty() ? -1 : st.top();
             st.push(i);
         }
         return psee;
    }
    int sumSubarrayMins(vector<int>& arr) {
        // int n = arr.size();
        // int mini = INT_MAX;
        // long long sum =0;
        // for(int i=0;i<n;i++){
        //      mini = INT_MAX;
        //      for(int j=i;j<n;j++){
        //          mini =min(arr[j],mini);
        //          sum+=mini;
        //      }
        // }
        // return sum % 1000000007;

        //for optimisation
        //store the next smaller element 
        int n = arr.size();
        vector<int>nse = findnse(arr);
        vector<int>psee = findpsee(arr);

        int total = 0;
        for(int i=0;i<n;i++){
             int leftelements = i - psee[i];
             int rightelements = nse[i] - i;

             total = (total + (1LL * leftelements * rightelements * arr[i]))% mod;
        }
        return total;
    }
};