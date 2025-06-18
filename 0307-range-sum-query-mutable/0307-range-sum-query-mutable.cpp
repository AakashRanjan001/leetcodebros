class NumArray { // clearly it is a question of  segment tree 
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
    void updatesegtree(int index,int val,int i,int l,int r){

        if(l == r){
             segtree[i] = val;
             return;
        }
         int mid = l+(r-l)/2;

         if(index<=mid){ // matlab woh index left side mei present hai
             updatesegtree(index,val,2*i+1,l,mid);
         }
         if(index>mid){ // matlab woh right side mei present hai 
            updatesegtree(index,val,2*i+2,mid+1,r);
             
         }
         segtree[i] = segtree[2*i+1] + segtree[2*i+2];
    }
    int Querysegtree(int left,int right,int i,int l,int r){
         if(r<left || l>right){ // out of bounds
             return 0;
         }
         // within the range 
         if(l>=left && r<=right){
             return segtree[i];
         }
         int mid = l+(r-l)/2;
         //some are outside and some ar not 
         return Querysegtree(left,right,2*i+1,l,mid) + Querysegtree(left,right,2*i+2,mid+1,r);

    }
        
    NumArray(vector<int>& nums) {
          n = nums.size();
          segtree.resize(4*n);
          buildsegtree(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
         updatesegtree(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
         return Querysegtree(left,right , 0 , 0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */