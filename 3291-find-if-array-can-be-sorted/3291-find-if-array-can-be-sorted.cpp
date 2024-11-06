// class Solution {
// public:
//    void convertToBinary(int nums[i]){
//       string binary = "";

//       if(nums[i] ==0){
//         binary ="0";
//       }

//       else{
//         while(nums[i]>0){
//              binary+= if(nums[i]%2 ==0 ) ? "0" : "1";
//              nums[i] = nums[i]/2;
//         }
//       }
//       reverse(binary.begin(),binary.end());
//    }

   
//     bool canSortArray(vector<int>& nums) {
//         int n = nums.size();
    
//         for(int i=0;i<n;i++){
//             convertToBinary(nums[i]);
//         }
//         int cnt_1 = 0;
//         vector<int>setbits;
//       for(int i=0;i<binary.size();i++){
//           if(binary[i] == '1'){
//             cnt_1++;
//           }

//       }

//       for(int i=0;i<n;i++){
//         if()
//       }




//     }
// };



class Solution {
private:
    int getsetbit(int num){
        int count = 0;
        while(num){
            count++;
            num = num & (num-1);
        }
        return count;
    }
public:
    bool canSortArray(vector<int>& nums) {
        for(int i = 0; i<nums.size() ; i++){
            for(int j = 0; j<nums.size()-1; j++){
                if(nums[j] > nums[j+1]){
                    if(getsetbit(nums[j]) != getsetbit(nums[j+1])){
                        return false;
                    }
                    swap(nums[j], nums[j+1]);
                }
            }
        }

        return true;


        
    }
};