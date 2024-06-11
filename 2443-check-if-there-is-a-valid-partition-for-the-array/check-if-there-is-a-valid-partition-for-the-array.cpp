class Solution {
public:
    bool helper(vector<int>&nums,int i,vector<int>&t){
        if(i>=nums.size())return true;
        if(t[i]!=-1)return t[i];
        if(i+1<nums.size()&&nums[i]==nums[i+1]){
            if(helper(nums,i+2,t))return t[i]= true;
            if(i+2<nums.size()&&nums[i]==nums[i+2]){
                if(helper(nums,i+3,t))return t[i]= true;
            }
        }
        if(i+2<nums.size()&&nums[i]==nums[i+1]-1&&nums[i+1]==nums[i+2]-1)if(helper(nums,i+3,t))return t[i]= true;
        return t[i]=false;

    } 
    bool validPartition(vector<int>& nums) {
        vector<int>t(nums.size(),-1);

        return helper(nums,0,t);
    }
};