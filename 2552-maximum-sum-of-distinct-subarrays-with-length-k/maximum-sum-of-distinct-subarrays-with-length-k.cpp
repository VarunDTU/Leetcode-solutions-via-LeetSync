class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>s;
        long long sum=0;
        for(int i=0;i<k;i++)s[nums[i]]++,sum+=nums[i];
        long long ans=0;
        if(s.size()==k)ans=sum;

        for(auto i=k;i<nums.size();i++){
            sum-=nums[i-k];
            sum+=nums[i];
            s[nums[i]]++;
            if(s[nums[i-k]]==1)s.erase(nums[i-k]);
            else s[nums[i-k]]--;
            if(s.size()==k)ans=max(sum,ans);
        }
        return ans;

    }
};  