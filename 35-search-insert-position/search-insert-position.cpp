class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1;


        while(s>=0&&e<nums.size()&&s<=e){
            int mid=s+(e-s)/2;
            
            if(nums[mid]==target)return mid;
            if((mid-1<0||nums[mid-1]<target)&&(nums[mid]>=target))return mid;
            if(nums[mid]>target)e--;
            else s++;
        }
        return nums[0]>target?0:nums.back()<target?nums.size():-1;

    }
};