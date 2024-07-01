class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int s=0,e=0;
        while(e<arr.size()){
            if(arr[e]%2==1){
                if(e-s+1==3)return true;
                e++;
            }
            else{
                s=e+1;
                e++;
            }
        }
        return false;
    }
};