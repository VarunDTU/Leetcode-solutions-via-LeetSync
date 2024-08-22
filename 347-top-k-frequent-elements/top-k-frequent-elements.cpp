class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>q;
        map<int,int>mp;
        for(auto itr:nums)mp[itr]++;

        for(auto itr:mp)q.push({itr.second,itr.first});

        vector<int>ans;
        while(ans.size()<k){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;


    }
};