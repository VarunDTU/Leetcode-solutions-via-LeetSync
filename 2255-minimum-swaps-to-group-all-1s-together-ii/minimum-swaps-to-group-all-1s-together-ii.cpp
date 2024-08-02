class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k=accumulate(nums.begin(),nums.end(),0);
        int count=0;
        for(int i=0;i<k;i++)if(nums[i])count++;
        for(int i=k,sum=count;i<nums.size()+k;i++){
            if(nums[i-k]==1)sum--;
            if(nums[i%nums.size()]==1)sum++;
            count=max(count,sum);
        }
        return k-count;
    }
};