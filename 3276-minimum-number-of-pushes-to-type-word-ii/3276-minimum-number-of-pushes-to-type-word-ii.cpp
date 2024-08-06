
class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        for(auto ch:word){
            mp[ch]++;  //for storing the frequency
        }
        vector<int>V;
        for(auto c:mp){
            V.push_back(c.second);
        }
        sort(V.begin(),V.end(),greater<int>());
        int count=0;
        int ans=0;
        for(auto h:V){
            count++;
            if(count<=8){
                ans+=1*h;
            }
            else if(count<=16){
                ans+=2*h;
            }
            else if(count<=24){
                ans+=3*h;
            }
            else{
                ans+=4*h;
            }
        }
        return ans;
    }
};