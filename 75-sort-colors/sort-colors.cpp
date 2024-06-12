class Solution {
public:
    void sortColors(vector<int>& nums) {
        int mp[3]={0};
        for(int itr:nums)mp[itr]++;
        int n=0;
        for(int i=0;i<3;i++){
            while(mp[i]>0){
                nums[n]=i;
                n++;
                mp[i]--;
            }

        }
       
    }
};