class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]++;
        int prefix=0;
        int ans=0;
        for(auto itr:nums){
             prefix=(prefix+itr%k+k)%k;
             ans+=mp[prefix];
             mp[prefix]++;

        }
        return ans;
    }
};