class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    //     int n = nums1.size();  //it is a Brute Force Approach
    //     int m = nums2.size();
    //    vector<int>temp;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //              temp.push_back(nums1[i]^nums2[j]);
    //         }
    //     }
    //     int XOR =0;
    //     for(int i=0;i<temp.size();i++){
    //         XOR = XOR^temp[i];
    //     }
    //     return XOR;

    int n = nums1.size();
    int m = nums2.size();
    int XOR =0;
   
    if(n%2 ==0 && m%2 ==0){
        return 0;
    }
  
    else if(n%2 ==0 && m%2!=0){
         for(int i=0;i<n;i++){
            XOR= XOR^nums1[i];
         }
     
    }
    else{
        for(int i=0;i<m;i++){
            XOR = XOR^nums2[i];
        }
    }
    return XOR;
 

    }
};