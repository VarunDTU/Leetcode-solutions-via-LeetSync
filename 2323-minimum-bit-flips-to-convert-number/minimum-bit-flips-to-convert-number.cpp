class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x= start^goal;
        int ans=0;
        for(int i=0;i<32;i++){
            ans+=(x>>i)&1;
        }
        return ans;
    }
};