class Solution {
public:
    void buildsegtree(int i , int l ,int r, int segmentree[], vector<int> &heights){
          if(l == r){
             segmentree[i] = l;// store the index 
             return;
          }

          int mid = l + (r-l)/2;
          buildsegtree(2*i+1,l,mid,segmentree,heights);
          buildsegtree(2*i+2,mid+1,r,segmentree, heights);
          
          //store the index of the maxElment 
          int leftIndex = segmentree[2*i+1];
          int rightIndex = segmentree[2*i+2];

          if(heights[leftIndex] > heights[rightIndex]){
              segmentree[i] = leftIndex;
          }
          else{
             segmentree[i] = rightIndex;
          }
    }
    int *constructST(vector<int> &heights , int n){
         int *segmentree = new int[4*n];
         buildsegtree(0 ,0 , n-1,segmentree,heights);
         return segmentree;
    }
    int querySegment(int start,int end,int i,int l,int r,int st[], vector<int> &heights){
         if(l>end || r<start){ // out of bounds
             return -1; // invalid index
         }
         if(l>=start && r<=end){
             // entirely andar hai 
             return st[i]; // index dega maxekemnt ka
         }
         int mid = l+(r-l)/2;
         int  leftIndex= querySegment(start,end,2*i+1,l,mid,st,heights);
         int rightIndex = querySegment(start,end,2*i+2,mid+1,r,st,heights);

         if(leftIndex == -1)return rightIndex;
         if(rightIndex == -1)return leftIndex;

         return (heights[leftIndex]>=heights[rightIndex])? leftIndex : rightIndex;

    }

    int RMIQ(int st[], vector<int>&heights , int n , int start, int end){
         // this returns the maximum elemnet ka index in the range[a,b] in heights Array;
         return querySegment(start,end,0,0,n-1,st,heights);

    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
         
        int *segmentTree = constructST(heights,n);
         vector<int>res;
         for(auto &query:queries){
             int max_idx = max(query[0],query[1]);
             int min_idx = min(query[0],query[1]);

             if(max_idx == min_idx){ // alice and bob are present in the same location
                 res.push_back(min_idx); // can also be max_idx
                 continue;
             }
             else if(heights[max_idx] > heights[min_idx]){ 
                 res.push_back(max_idx);
                 continue;
             }

    
                int l = max_idx +1 ;
                int r = n-1;
                int result_idx = INT_MAX;

                while(l<=r){
                     int mid = l+(r-l)/2;
                     int idx = RMIQ(segmentTree,heights,n,l,mid);// returns the max elementka index  from [l,mid] range 

                     if(heights[idx]>max(heights[max_idx],heights[min_idx])){
                         result_idx = min(result_idx,idx);
                         r = mid-1;
                     }
                     else{
                         l = mid+1;
                     }
                }
                 
             
             if(result_idx == INT_MAX)res.push_back(-1);
             else{ res.push_back(result_idx);}
         }
return res;
        
    }
};