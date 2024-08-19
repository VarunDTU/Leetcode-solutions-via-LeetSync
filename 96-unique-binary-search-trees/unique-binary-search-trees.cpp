class Solution {
public:
    int numTrees(int n) {
       if(n<=1)return 1;
       int ans=0;
        for(int i=0;i<n;i++){
            ans+=numTrees(n-i-1)*numTrees(i);
        }
        return ans;
    }
};