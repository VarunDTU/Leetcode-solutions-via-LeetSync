class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int>st,end;
        for(auto itr:intervals){
            st.push_back(itr[0]);
            end.push_back(itr[1]);
        }
        sort(st.begin(),st.end());
        sort(end.begin(),end.end());
        int endi=0,ans=0;
        for(auto itr:st){
            if(itr>end[endi]){
                endi++;
                
            }
            else ans++;
        }
        return ans;
    }
};