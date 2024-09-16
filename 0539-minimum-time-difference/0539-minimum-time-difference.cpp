class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        vector<int>minutes;   
        for(int i=0;i<timePoints.size();i++){
            string curr = timePoints[i];
            
            int hours = stoi(curr.substr(0,2));  //first conversion of string part into int
            int minute = stoi(curr.substr(3,2)); //means hours yaha string ke form mei hai toh apon ko int  mei badalte hai by use of stoi function
            int totalminutes = hours*60 + minute;
            minutes.push_back(totalminutes);  // fir jo resulatnt array hota in minutes ke form mei usko pushback kar dete
            
        }
        sort(minutes.begin(),minutes.end());  //apon ko min time diff chahiye so linear ek elemnt ko select karke dusre elemnt mei traverse karme mei ti,me compelxity is O^n2
//But agar apon sort kar denge toh nlogn TC hoga which is less than 0n^2        
        int n = minutes.size();
        int mini = INT_MAX; 
        
        for(int i=0;i<n-1;i++){
            int diff = abs(minutes[i+1]-minutes[i]);
            mini = min(mini,diff);
        }
        int lastdiff=(minutes[0]+1440)-minutes[n-1];//something missing
        mini= min(mini ,lastdiff); // ye part hamesha bhul jaaat hu dhyan rakhna hoiga 
        
        return mini;
        
    }
};