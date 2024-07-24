class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        int n = nums.size();
        vector<pair<int,int>>storepair;
        for(int i=0;i<n;i++){
            string number = to_string(nums[i]);
            string formed ="";

            for(int j=0;j<number.size();j++){
                formed = formed + to_string(mapping[number[j]-'0']);
            }
            int mappedval = stoi(formed);
            storepair.push_back({mappedval,i});


        }
        sort(storepair.begin(),storepair.end());
        vector<int>ans;
        for(auto pr:storepair){
          ans.push_back(nums[pr.second]);
        }
        return ans;

    }
};