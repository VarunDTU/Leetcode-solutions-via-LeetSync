class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,pair<int,int>>mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end())mp[s[i]]={i,i};
            else mp[s[i]].second=i;
        }
        
        vector<pair<int,int>>in;
        
        for(auto itr:mp){
          // cout<<itr.first<<itr.second.first<<","<<itr.second.second<<endl;
            in.push_back(itr.second);
        }
        
        
        sort(in.begin(),in.end());
        vector<int>ans;
        int st=in[0].first,e=in[0].second;
        for(int i=1;i<in.size();i++){
            if(in[i].first<e){
                e=max(in[i].second,e);
            }
            else {
               
                ans.push_back(e-st+1);
                st=in[i].first;
                e=in[i].second;
            }
        }
        
        ans.push_back(e-st+1);
        
        return ans;
        
        
        
    }
};