class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int ans=0;
        for(auto itr:nums){
            int len=1;
            
            for(int i=1;s.find(itr-i)!=s.end();i++)s.erase(itr-i),len++;
            for(int i=1;s.find(itr+i)!=s.end();i++)s.erase(itr+i),len++;
            ans=max(len,ans);

        }
        return ans;

    }
};