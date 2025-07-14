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
        //        int n1 = nums1.size(),n2 = nums2.size();
        //        int n = n1+n2;
        //  int i=0,j=0;
        //  int cnt =0;
        //  int ind2 = n/2;
        //  int ind1 = n/2-1;
        //  int ind_el1 = -1,ind_el2 = -1;
        //  vector<int>arr;
        //  while(i<n1 && j<n2){
        //      if(nums1[i]<nums2[j]){
        //          if(cnt == ind2)ind_el2 = nums1[i];
        //          if(cnt == ind1)ind_el1 = nums1[i];
        //          cnt++;
        //          i++;
        //      }
        //      else{
        //          if(cnt == ind2)ind_el2 = nums2[j];
        //          if(cnt == ind1)ind_el1 = nums2[j];
        //          cnt++;
        //          j++;
                
        //      }
        //  }
        //  //rest of the elemnet s'
        //  while(i<n1){
        //       if(cnt == ind2)ind_el2 = nums1[i];
        //          if(cnt == ind1)ind_el1 = nums1[i];
        //          cnt++;
        //          i++;

        //  }
        //  while(j<n2){
        //       if(cnt == ind2)ind_el2 = nums2[j];
        //          if(cnt == ind1)ind_el1 = nums2[j];
        //          cnt++;
        //          j++;
        //  }
        //  if(n%2 == 1)return (double)ind_el2;
        //  else return (double)(ind_el1 + ind_el2)/2;



        // MOST OPTIMAL APPROACH 
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 > n2)return findMedianSortedArrays(nums2,nums1);
        // this is done to maintain that the nums1 array is always the smallest 
        int low = 0;
        int high = n1;
        int left = (n1 + n2 +1)/2;// no .of elements i require on the left side 
        int n = n1+n2;
        double median = -1;
        while(low<=high){
              int mid1 = low+(high-low)/2;
              int mid2 = left - mid1;

              //in case 
              int l1 = INT_MIN, l2 = INT_MIN;
              int r1 = INT_MAX, r2 = INT_MAX;
              if(mid1 < n1) r1  = nums1[mid1];
              if(mid2< n2)r2 = nums2[mid2];
              if(mid1-1 >=0)l1 = nums1[mid1-1];
              if(mid2-1>=0)l2 = nums2[mid2 -1];

              if(l1<=r2 && l2<=r1){
                 if(n%2 ==1){
                     median = (double)max(l1,l2);
                     break;
                 }
                 else{
                     median = (double)(max(l1,l2) + min(r1,r2))/2.0;
                     break;
                 }
              }
              else if(l1>r2)high = mid1-1;
              else low = mid1+1;
        }

           return median;
    }
};