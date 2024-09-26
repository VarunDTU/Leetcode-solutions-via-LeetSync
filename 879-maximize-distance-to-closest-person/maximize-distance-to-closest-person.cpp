class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
    
        int s=0,e=0;
        int ans=0;
        for(int i=0;i<seats.size();i++){
            s=i;
            while(i<seats.size()&&seats[i]==0){
                i++;   
            }
            if(s==0||i==seats.size())ans=max(ans,abs(i-s));
            else ans=max(ans,((i-s+1)/2));
        }
        return ans;
    }
};