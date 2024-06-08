class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>>num_pair;
        for(int i=0;i<nums.size();i++)num_pair.push_back({nums[i],i});
        sort(num_pair.begin(),num_pair.end());
        vector<int>ans(nums.size());
        int i=0;
        vector<int>ind,num;
        while(i<=num_pair.size()){
            if(i<num_pair.size()&&(num.size()==0||abs(num.back()-num_pair[i].first)<=limit)){
                ind.push_back(num_pair[i].second);
                num.push_back(num_pair[i].first);
                
            }
            else{
                sort(ind.begin(),ind.end());
                for(int i=0;i<ind.size();i++){
                    ans[ind[i]]=num[i];
                }
                ind.clear();
                num.clear();
                if(i<num_pair.size())i--;

            }
            i++;

        }
        return ans;
    }
};