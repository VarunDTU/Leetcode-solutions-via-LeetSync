class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(),start.end());
        long l=0,r=2000000000,n=start.size();

        while(l<=r){
            long m=l+(r-l)/2;
            long prev=start[0];
            bool can=true;
            for(int i=1;i<n;i++){
                long next=prev+m;
                if(next>start[i]+d){
                    can=false;
                    break;
                }
                else{
                    prev=max((int)next,start[i]);
                }
            }
            if(can)l=m+1;
            else r=m-1;
        }
        return l-1;
    }
};