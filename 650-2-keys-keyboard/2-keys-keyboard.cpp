class Solution {
    int helper(int n,int l ,int i){
        if(i>n)return 1e9;
        if(i==n)return 1;
        return min(2+helper(n,i,i+i),1+helper(n,l,i+l));
    }
public:
    int minSteps(int n) {
        if(n<=1)return 0;
        return helper(n,1,1);
    }
};