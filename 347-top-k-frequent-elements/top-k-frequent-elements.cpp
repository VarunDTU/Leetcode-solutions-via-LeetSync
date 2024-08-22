class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>>q;
        unordered_map<int,int>mp;
        for(auto itr:nums)mp[itr]++;

        for(auto itr:mp)q.push_back({itr.second,itr.first});
        sort(q.begin(),q.end(),greater<pair<int,int>>());
        vector<int>ans;
        int i=0;
        while(i<k){
            ans.push_back(q[i].second);
            i++;
        }
        return ans;


    }
};