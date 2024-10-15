class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>cans(n,1);
        for(int i=0;i<n-1;i++){
            if(ratings[i]<ratings[i+1])cans[i+1]=cans[i]+1;
        }
        for(int i=n-1;i>0;i--){
            if(ratings[i]<ratings[i-1])cans[i-1]=max(cans[i]+1,cans[i-1]);
        }
        int ans=0;
        for(auto itr:cans)ans+=itr;
        return ans;
    }
};