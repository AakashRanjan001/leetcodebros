class Solution {
public:
    int xorOperation(int n, int start) {
vector<int>nums(1000);
        
int XOR = 0;
for(int i=0;i<n;i++){
  nums[i] = start  + 2*i;
  XOR = XOR^nums[i];
}
return XOR;

    }
};