class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        int n = nums.size();
        map<int,int>mp;
        
        for(int i :nums){
            mp[i]++;
        }
        vector<priority_queue<int>>freq(101);
        for(auto &i:mp){
            freq[i.second].push(i.first);
        }
        vector<int>ans;
        for(auto &i:freq){
            while(!i.empty()){
                for(int j=0;j<mp[i.top()];j++){
                ans.push_back(i.top());
            
            }
            i.pop();
            }
        }
        return ans;

    }
};