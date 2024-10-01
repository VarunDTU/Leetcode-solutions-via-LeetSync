class Solution {
bool helper(vector<int>& nums, vector<int>& c,int end){
        unordered_map<int,int>mp;
        for(int i=0;i<end;i++){
            mp[c[i]]=i;
        }
        if(mp.size()!=nums.size())return false;
        int power=0;
        for(int i=0;i<end;i++){
            if(i==mp[c[i]]){
                if(power>=nums[c[i]-1])power-=nums[c[i]-1];
                else return false;
            }else power++;
        }
        return true;
    }
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& c) {
        int n=nums.size(),m=c.size();
        int s=0,e=m+1;
        while(s<e){
            int mid=s+(e-s)/2;
            if(helper(nums,c,mid)){
                e=mid;
            }
            else s=mid+1;
        }
        return (e)==m+1?-1:e;
    }
};