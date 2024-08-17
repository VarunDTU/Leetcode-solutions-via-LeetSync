class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 1 2  s=1 , e=2      
        // 1 3  1<e e=min(3,e)=2 vount++; ; else s=1,e=3 ;
        // 2 3  
        // 3 4

        sort(intervals.begin(),intervals.end());

        int s=intervals[0][0],e=intervals[0][1];
        int n=intervals.size();
        int count=0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<e){
                e=min(intervals[i][1],e);
                count++;
            }
            else{
                s=intervals[i][0];
                e=intervals[i][1];
            }
        }
        return count;


    }
};