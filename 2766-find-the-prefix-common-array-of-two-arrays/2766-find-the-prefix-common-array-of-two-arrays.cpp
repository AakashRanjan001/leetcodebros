class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

      vector<int>ans;
      vector<int>hash(A.size()+1,0);
      int cnt =0; // cnt is the unique no.of elements in both the array 
      for(int i=0;i<A.size();i++){
          hash[A[i]]++; // dono mei cnt daala phir dekha ki dono mei se cnt kaund ahpga 
          hash[B[i]]++;

          if(hash[A[i]] == 2)cnt++; // matlab pakka common elemnet hai
          if(hash[B[i]] == 2 && A[i]!=B[i])cnt++;// taaki dubaara count na ho skae 
        ans.push_back(cnt);
          
      }
       return ans;
    }
};