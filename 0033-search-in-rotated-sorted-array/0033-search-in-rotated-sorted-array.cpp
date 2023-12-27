class Solution {
public:
    
int findpivot(vector<int>arr){
  int s =0;                               //WEEK 4 CONNECT
  int e = arr.size()-1;                   // NO DUPLICATE ELEMENT
                                            //SHOULD BE ROTATED SORTED ARRAY
  int mid = s + (e-s)/2;

  for(;s<=e;){
      
      if(s==e){
          return s;// agar single element rha tab
      }
    if(mid +1<=arr.size()-1 && arr[mid]>arr[mid+1]){   // agar arr[mid] ka value 10 hai toh uske baad 2 hi aayega so woh hi hai pivot element
      return mid;
    }
    else if(mid -1>=0 && arr[mid-1]>arr[mid]){   // agar arr[mid] ka value 2 hai toh uske pehle 10 hi aayega so woh hi hai pivot element
      return mid-1;
    }
     else if(arr[s]>arr[mid]){ //agar mid line b mei hai toh woh pakka start se chote honge 
        e = mid -1;
    }
    else {
      s = mid +1;
    }
    mid = s + (e-s)/2;
  }
  return -1;
}
    
    
    
    
    
    
    
   int binarysearch(vector<int>arr,int s,int e,int target){
       int mid = s + (e-s)/2;
       for(;s<=e;){
       if(arr[mid]==target){
           return mid;
       }
       else if ( arr[mid]<target){
           s = mid +1;
       }
       else{
           e = mid -1;
       }
       mid = s + (e-s)/2;
       
   } 
    return -1;
    
   }    
    
    int search(vector<int>& nums, int target) {
        int pivotindex = findpivot(nums);
        int ans =0;
        if(target>=nums[0] &&target<=nums[pivotindex]){
              ans = binarysearch(nums,0,pivotindex,target);
            return ans;
        }
        else {
              ans =  binarysearch(nums,pivotindex+1,nums.size()-1,target);
        return ans;
        }
        
    }
};