class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        int ans=0;
        for(auto itr:nums)mp[itr]++;
        for(auto itr:mp){
            if(itr.second<2)return -1;
            if(itr.second%3==0)ans+=(itr.second/3);
            else if(itr.second%3==1)ans+=(itr.second/3)+1;
            else if(itr.second%3==2)ans+=(itr.second+1)/3;  
        }
        return ans;
    }
};