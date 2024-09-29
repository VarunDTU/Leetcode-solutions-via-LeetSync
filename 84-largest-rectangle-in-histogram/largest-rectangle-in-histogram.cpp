class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nsr(n);
        stack<int> s;
         for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[i]<=heights[s.top()]){
                s.pop();
            }
            if(s.empty()) nsr[i]=n;
            else nsr[i]=s.top();
            s.push(i);
        }
        while(!s.empty())s.pop();
         int ans=0;
        for(int i=0;i<n;i++){
            while(!s.empty() && heights[i]<=heights[s.top()]){
                s.pop();
            }
            if(s.empty()) nsr[i]-=-1;
            else nsr[i]-=s.top();
            ans=max(ans,(nsr[i]-1)*heights[i]);
            s.push(i);
        }
       
        
        return ans;
    }
};