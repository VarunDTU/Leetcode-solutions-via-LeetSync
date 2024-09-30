class Solution {
public:
    int minNumberOfFrogs(string croak) {
        map<char,int>cr;
        cr['c']=0;
        cr['r']=1;
        cr['o']=2;
        cr['a']=3;
        cr['k']=4;
        map<int,int>mp;
        int ans=0;
        for(int i=0;i<5;i++)mp[i]=0;
        for(auto itr:croak){
            
            int curr=cr[itr];
            if(itr=='c'){mp[curr]++;if(mp[4]!=0)mp[4]--;}
            else if(mp[curr-1]==0)return -1;
            else {mp[curr-1]--;mp[curr]++;}
            if(curr!=4)ans=max(mp[curr],ans);
        }

        for(auto itr:mp){
           if(itr.first!=4&&itr.second!=0)return -1;
        }

        return mp[4];
        
    }
};