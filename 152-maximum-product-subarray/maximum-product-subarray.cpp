class Solution {
    
public:
    int maxProduct(vector<int>& nums) {
        int pmax=nums[0],pmin=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            
            int temp=max({pmin*nums[i],pmax*nums[i],nums[i]});
            pmin=min({pmin*nums[i],pmax*nums[i],nums[i]});
            pmax=temp;
            ans=max(pmax,ans);
        }
        return ans;
    }
};