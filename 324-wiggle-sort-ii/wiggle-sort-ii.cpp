class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        int e=nums.size()-1,i=1;
        while(e>=0&&i<nums.size()){
            nums[i]=temp[e];
            e--;
            i+=2;
        }
        i=0;
        while(e>=0&&i<nums.size()){
            nums[i]=temp[e];
            e--;
            i+=2;
        }
        
    }
};