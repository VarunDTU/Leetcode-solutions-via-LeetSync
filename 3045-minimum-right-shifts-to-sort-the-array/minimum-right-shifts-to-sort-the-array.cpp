class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int minIdx = 0;

        for (int i = 0; i < nums.size(); i++)
            if (nums[minIdx] > nums[i])
                minIdx = i;

        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[(i+minIdx)%n]>nums[(i+minIdx+1)%n])return -1;
        }
        return minIdx==0?0:(n-minIdx);

    }
};