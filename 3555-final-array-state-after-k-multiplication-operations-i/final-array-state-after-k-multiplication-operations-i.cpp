class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(int i=0;i<nums.size();i++)q.push({nums[i],i});

            pair<int,int>temp;
        while(k--){temp=q.top();
            q.pop();
            temp.first*=multiplier;
            q.push(temp);
        } 
        while(!q.empty()){
            nums[q.top().second]=q.top().first;
            q.pop();
        }
        return nums;  
    }
};