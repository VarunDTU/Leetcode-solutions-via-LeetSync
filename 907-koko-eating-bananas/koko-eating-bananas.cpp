class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long s=1,e=*max_element(piles.begin(),piles.end());
        while(s<=e){
            long long mid=s+(e-s)/2,total=0;
            for(auto itr:piles){
               total+=(itr+mid-1)/mid;
            }
               if(total>h){
                s=mid+1;
                continue;
               }else{
                e=mid-1;
               }


        }
        return s;
    }
};



//
//
//