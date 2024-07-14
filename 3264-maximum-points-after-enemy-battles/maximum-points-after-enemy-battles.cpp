class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        int mini=INT_MAX;
        long long sum=currentEnergy;
        for(auto itr:enemyEnergies){
            mini=min(itr,mini);
            sum+=itr;
        }
        if(mini>currentEnergy)return 0;
        return (sum-mini)/mini;
    }
};