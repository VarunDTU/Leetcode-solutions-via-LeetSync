class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4)return 0;
        int i=nums.size()-1;
        sort(nums.begin(),nums.end());
        return min({nums[i-3]-nums[0],nums[i]-nums[3],nums[i-1]-nums[2],nums[i-2]-nums[1]});
    }
};