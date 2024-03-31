class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int emptybottles = numBottles;
        while(emptybottles>=numExchange){
            ans+=1; // 1 full bottle milega
            emptybottles-=numExchange;//numexchange ke corresponding ek full bottle milega
            emptybottles++;//1 full bottle peene ke baad end mei laga denge khali bottles ke saath toh khalli bottles bhi ek badh gya
            numExchange++; // har ek iteration mei numexcahneg ek badh rha hai


        }
        return ans;
    }
};