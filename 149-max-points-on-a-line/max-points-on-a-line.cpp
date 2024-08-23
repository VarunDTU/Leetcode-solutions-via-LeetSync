class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res=0;
        for(int i=0;i<points.size();i++){
            unordered_map<double,int>mp;
            for(int j=i+1;j<points.size();j++){
                if(points[i][0]==points[j][0]){
                    mp[1e5]++;
                    continue;
                }
                double slope=(double)((double)(points[i][1]-points[j][1])/(double)(points[i][0]-points[j][0]));
                mp[slope]++;                
            }
            for(auto itr:mp){
                res=max(res,itr.second);
            }
        }
        return res+1;
    }
};