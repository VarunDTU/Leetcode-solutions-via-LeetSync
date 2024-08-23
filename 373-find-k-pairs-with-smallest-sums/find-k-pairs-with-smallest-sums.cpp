class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,vector<int>>>q;

        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(q.size()<k){
                q.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});

                }
                else if(q.top().first>nums1[i]+nums2[j]){
                    q.pop();
                    q.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
                }
                else break;
            }
        }

        vector<vector<int>>ans;
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }

        return ans;

    }
};