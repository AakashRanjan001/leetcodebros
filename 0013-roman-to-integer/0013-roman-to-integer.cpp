class Solution {
public:
    int romanToInt(string s) {
      map<char,int>mpp;
      mpp.insert({'I',1});
      mpp.insert({'V',5});
      mpp.insert({'X',10});
      mpp.insert({'L',50});
      mpp.insert({'C',100});
      mpp.insert({'D',500});
      mpp.insert({'M',1000});

    int sum =0;

    for(int i=0;i<s.size();i++){
        if(mpp[s[i]]>=mpp[s[i+1]])
        sum+=mpp[s[i]];
        else{
            sum-=mpp[s[i]];
        }
    }
return sum;
        
    }
};