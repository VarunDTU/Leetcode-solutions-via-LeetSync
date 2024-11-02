class Solution {
    int mod=1e9 +7;
public:
    int lengthAfterTransformations(string s, int t) {
        int dic[26]={0};
        for(auto itr:s)dic[itr-'a']++;
        int len=s.size();
        for(int i=0;i<t;i++){
            len=(len+dic[25])%mod;
            int z=dic[25];
            for(int j=25;j>0;j--){
                dic[j]=dic[j-1];
            }
            dic[0]=z;
            dic[1]=(dic[1]+z)%mod;
        }
        return len;
    }
};