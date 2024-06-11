class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>freq;
        for(auto it:arr1){
            freq[it]++;
        }
        vector<int>ans;
        for(auto i:arr2){
            while(freq[i]--){
                ans.push_back(i);
            }
        }

        //for remainning ekements which are not present in arr2
        for(auto& [it,f]:freq){
            while(f>0 && f--){
                  ans.push_back(it);
            }
        }
        return ans;
    }
};