class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        pair<int,int>count1={-1,0},count2={-1,0};
        for(auto itr:nums){
            if(itr==count1.first)count1.second++;
            else if(itr==count2.first)count2.second++;
            else if(count1.second<=0)count1={itr,1};
            else if(count2.second<=0)count2={itr,1};
            else count1.second--,count2.second--;
        }
        cout<<count1.first<<count1.second;
        cout<<count2.first<<count2.second;
        count1.second=0;
        count2.second=0;
        for(auto itr:nums){
            if(itr==count1.first)count1.second++;
            else if(itr==count2.first)count2.second++;
        }
        vector<int>ans;
        if(3*count1.second>nums.size())ans.push_back(count1.first);
        if(3*count2.second>nums.size())ans.push_back(count2.first);
        return ans;
    }
};