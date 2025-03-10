class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2,
                                 int k) {

        // first i have to store the values of j which are less than i
        //  this is my Brute force approach
        //  long long n = nums1.size();
        //  long long sum =0;
        //  vector<long long>ans;

        // for(int i=0;i<n;i++){
        //     vector<long long>temp;
        //     sum =0;
        //     for(int j=0;j<n;j++){
        //         if(nums1[j]<nums1[i]){
        //            temp.push_back(j);
        //         }
        //     }
        //     priority_queue<int>pq;
        //     for(int k=0;k<temp.size();k++){
        //         pq.push(nums2[temp[k]]);
        //     }
        //     int temp_k = k;

        //     while(temp_k-- && !pq.empty()){
        //         sum+=pq.top();
        //         pq.pop();
        //     }
        //     ans.push_back(sum);

        // }
        //   return ans;

        int n = nums1.size();
        vector<array<int, 3>> elements(n);
        for (int i = 0; i < n; i++) {
            elements[i] = {nums1[i], nums2[i], i};
        }

        sort(elements.begin(), elements.end());
        vector<long long> res(n);

        // minheap
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && elements[i-1][0] == elements[i][0]){
                res[elements[i][2]] = res[elements[i-1][2]];
            }
            else{
                res[elements[i][2]] = sum;
            }

            pq.push(elements[i][1]);
            sum+=elements[i][1];

            if(pq.size()>k){
                 sum-=pq.top();
                 pq.pop();
            }
        }
        return res;
    }
};
