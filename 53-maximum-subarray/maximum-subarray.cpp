class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        int ans=-1e9,currentsum=0;
        for(auto itr:nums){
            currentsum+=itr;
            if(currentsum>ans){
                ans=currentsum;
            }
            if(currentsum<0){
                currentsum=0;
            }

        }
        return ans;
    }
};