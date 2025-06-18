class NumArray {
public: 
    int n;
    vector<int>segtree;
    void buildsegtree(int i,int l,int r,vector<int>& nums){
        if(l == r){
             segtree[i] = nums[l];
             return;
        }
         
         int mid = l+(r-l)/2;
         buildsegtree(2*i+1,l,mid,nums);
         buildsegtree(2*i+2,mid+1,r,nums);

         segtree[i] = segtree[2*i+1] + segtree[2*i+2];
    }
    int Query(int left,int right,int i,int l,int r){
         if(l>right || r<left){
             return 0;
         }
         if(l>=left && r<=right){
             return segtree[i];
         }
         int mid = l+(r-l)/2;
         return Query(left,right,2*i+1,l,mid) + Query(left,right,2*i+2,mid+1,r);
    }
    NumArray(vector<int>& nums) {
         n = nums.size();
         segtree.resize(4*n);
         buildsegtree(0,0,n-1,nums);

    }
    
    int sumRange(int left, int right) {
         return Query(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */