class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int>mp;
        for(auto itr:arr)mp[(itr%k+k)%k]++;
        for(auto itr:arr){
            int remainder=(itr%k+k)%k;
            if(remainder==0){
                if(mp[remainder]%2!=0)return false;
            }
            else if(mp[remainder]!=mp[k-remainder])return false;
        }
        return  true;
    }
};