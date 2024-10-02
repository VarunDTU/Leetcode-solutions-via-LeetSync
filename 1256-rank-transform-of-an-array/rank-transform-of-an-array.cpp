class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int,int>>nums;
        for(int i=0;i<arr.size();i++)nums.push_back({arr[i],i});
        sort(nums.begin(),nums.end());
        int count=1;
        for(int i=0;i<nums.size();i++){
            if(i!=0&&nums[i-1].first!=nums[i].first)count++;

            arr[nums[i].second]=count;
      
        }
        
        return arr;
    }
};