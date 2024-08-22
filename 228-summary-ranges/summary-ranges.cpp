class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0)return {};
        vector<string>ans;
        int start=-1,end=-1;

        for(int i=0;i<=nums.size();i++){
            if(i<nums.size()&&start==-1){
                start=i;
                end=i;
                continue;
            }
            if(i<nums.size()&&nums[i-1]+1==nums[i]){
                end=i;
                continue;
            }
            string temp="";
            if(start!=end){
                temp+=(to_string(nums[start])+"->"+to_string(nums[end]));
            }
            else{
                temp+=to_string(nums[start]);
            }
            ans.push_back(temp);
            start=i;
            end=i;
        }
        return ans;
    }
};