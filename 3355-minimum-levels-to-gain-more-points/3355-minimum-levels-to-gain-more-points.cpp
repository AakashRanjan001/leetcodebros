class Solution {
public:
    int minimumLevels(vector<int>& p) {
      int n = p.size();         //ARYAN MITTAL KA VIDEO DEKH LENA
      int sum =0;

      for(int i=0;i<n;i++){
          if(p[i]==1)sum+=1; //agar p[i] 1 mila toh apon add kar denge 1
          else if(p[i]==0)sum-=1; // agar p[i]=0 mila toh uske jagah apon -1 add kar denge       
      }  

      int prefix_sum=0;  
      for(int i=0;i<n-1;i++){  //n-1 tak isisliye liye kyunki ek level at least chodna hai bob ke liye
          if(p[i]==1)prefix_sum+=1;
          else{prefix_sum-=1;}
          
          int rem_sum = sum - prefix_sum;
          if(prefix_sum>rem_sum)return i+1; //i+1 isislye kiye kunki level toh 1 se shuru hota hai aur agar by cahnve i =0 ke liye satisfy ho gya toh ek jyada hoga
      }
      return -1;
    }
};