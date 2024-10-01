class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& s, int time) {
   
        vector<int>start(s.size(),0),end(s.size(),0);
        for(int i=1;i<s.size();i++){
            if(s[i-1]>=s[i])start[i]=start[i-1]+1;
            else start[i]=0;
        }

        for(int i=s.size()-2;i>=0;i--){
            if(s[i+1]>=s[i])end[i]=end[i+1]+1;
            else end[i]=0;
        }

        vector<int>ans;
        int size=start.size();
        for(int i=time;i<size-time;i++){
         
            if(start[i]>=time&&end[i]>=time)ans.push_back(i);
        }
        return  ans;
    }
};