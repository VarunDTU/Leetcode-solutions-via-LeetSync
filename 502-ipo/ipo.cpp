class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> q1;
        priority_queue<pair<int,int>>q2;
        for(int i=0;i<profits.size();i++)q1.push_back({capital[i],profits[i]});
        sort(q1.begin(),q1.end());
        int j=0;
        for(int i=0;i<k;i++){
        
            while(j<q1.size()&&q1[j].first<=w){
               
                q2.push({q1[j].second,q1[j].first});
                j++;
            }
            
            if(q2.empty())break;

            w+=q2.top().first;
            q2.pop();
        }
        return w;


    }
};