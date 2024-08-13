class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //if(intervals.size()<=0)return intervals;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int s=intervals[0][0],e=intervals[0][1];
        for(int i=0;i<intervals.size();i++){
            if(e>=intervals[i][0]){
                e=max(intervals[i][1],e);
                s=min(intervals[i][0],s);
            }
            else{
                ans.push_back({s,e});
                s=intervals[i][0];
                e=intervals[i][1];
            }
        }
        ans.push_back({s,e});
        return ans;
    }
};