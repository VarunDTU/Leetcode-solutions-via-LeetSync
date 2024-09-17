class Solution {
public:
    int helper(vector<int> &nums,int i,vector<int> &t){
        if(i>=nums.size())return 0;
        if(t[i]!=-1)return t[i];
        return t[i]= max(helper(nums,i+1,t),nums[i]+helper(nums,i+2,t));
    }
    int rob(vector<int>& nums) {
        vector<int>t(nums.size(),-1);
        return helper(nums,0,t);
    }
};