class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long s=0,score=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[s]){
                
                score+=(long long)(i-s)*nums[s];
                s=i;
            }
        }
       score+=(long long )(nums.size()-1-s)*nums[s];
        return score;
    }
};