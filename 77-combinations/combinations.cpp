class Solution {
    void helper(vector<vector<int>>&ans,int &n,int i,int k,vector<int>temp){
            if(n-k<0)return ;
            if(k==0){
                ans.push_back(temp);
                return;
            }

            for(int j=i;j<=n;j++){
                temp.push_back(j);
                helper(ans,n,j+1,k-1,temp);
                temp.pop_back();
            }
            return ;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        helper(ans,n,1,k,{});
        return ans;
    }
};