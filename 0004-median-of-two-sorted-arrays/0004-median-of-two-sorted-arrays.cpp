class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         // BRUTE FORCE
        //  int n1 = nums1.size(),n2 = nums2.size();
        //  int i=0,j=0;
        //  vector<int>arr;
        //  while(i<n1 && j<n2){
        //      if(nums1[i]<nums2[j]){
        //          arr.push_back(nums1[i]);
        //          i++;
        //      }
        //      else{
        //          arr.push_back(nums2[j]);
        //          j++;
        //      }
        //  }
        //  //rest of the elemnet s'
        //  while(i<n1)arr.push_back(nums1[i++]);
        //  while(j<n2)arr.push_back(nums2[j++]);
        //  int n = n1 + n2;
        //  if(n%2 == 1)return (double)arr[n/2];
        //  else return (double)(arr[n/2] + arr[n/2-1])/2;



         // BETTER SOLOUTION FOR SPACE OPTIMISATION
               int n1 = nums1.size(),n2 = nums2.size();
               int n = n1+n2;
         int i=0,j=0;
         int cnt =0;
         int ind2 = n/2;
         int ind1 = n/2-1;
         int ind_el1 = -1,ind_el2 = -1;
         vector<int>arr;
         while(i<n1 && j<n2){
             if(nums1[i]<nums2[j]){
                 if(cnt == ind2)ind_el2 = nums1[i];
                 if(cnt == ind1)ind_el1 = nums1[i];
                 cnt++;
                 i++;
             }
             else{
                 if(cnt == ind2)ind_el2 = nums2[j];
                 if(cnt == ind1)ind_el1 = nums2[j];
                 cnt++;
                 j++;
                
             }
         }
         //rest of the elemnet s'
         while(i<n1){
              if(cnt == ind2)ind_el2 = nums1[i];
                 if(cnt == ind1)ind_el1 = nums1[i];
                 cnt++;
                 i++;

         }
         while(j<n2){
              if(cnt == ind2)ind_el2 = nums2[j];
                 if(cnt == ind1)ind_el1 = nums2[j];
                 cnt++;
                 j++;
         }
         if(n%2 == 1)return (double)ind_el2;
         else return (double)(ind_el1 + ind_el2)/2;


    }
};