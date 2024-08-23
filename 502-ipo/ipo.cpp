class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q1;
        priority_queue<pair<int,int>>q2;
        for(int i=0;i<profits.size();i++)q1.push({capital[i],profits[i]});

        for(int i=0;i<k;i++){
        
            while(!q1.empty()&&q1.top().first<=w){
              
                q2.push({q1.top().second,q1.top().first});
                q1.pop();
            }
            
            if(q2.empty())break;

            w+=q2.top().first;
            q2.pop();
        }
        return w;


    }
};