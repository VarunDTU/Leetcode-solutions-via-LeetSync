class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        // [1,3,4,2,6,8]
        // 1 2 3    4  6 8

        map<int,int>mp;
        vector<int>ans;
        for(auto itr:changed)mp[itr]++;

        for(auto itr:mp){
            int first=itr.first;
            int second=itr.second;  
            if(first==0&&second%2)return {};
                else if(first==0)second/=2;
            if(second>0&&(mp.find((first)*2)==mp.end()||second>mp[(first)*2]))return  {};
            if(second>0&&second<=mp[(first)*2]){
                mp[(first)*2]-=second;
                while((second)--){
                    ans.push_back(itr.first);
                }
            }
            
        }
        return ans;


    }
};