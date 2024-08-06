class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(auto itr:word){
            freq[itr-'a']++;
        }
        map<int,int,greater<int>>mp;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                mp[freq[i]]++;
            }

        }



        int ans=0,l=8,count=1;
        for(auto &itr:mp){
            if(itr.second<=l){
                ans+=(itr.first)*(itr.second)*count;
                l-=itr.second;
            }
            else{
                int c=itr.second;
                
                while(c>=l){
                ans+=(itr.first)*(l)*count;
                c-=l;
                count++;
                l=8;
                //cout<<ans;
                }
                ans+=(itr.first)*(c)*count;
                l-=c;
            }

        }
        return ans;






    }
};