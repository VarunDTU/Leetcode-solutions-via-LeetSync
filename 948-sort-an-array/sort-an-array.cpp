class Solution {
    void merge(vector<int>&nums,int start,int mid,int end){
            vector<int>finalarr(end-start+1);
            int first=start,second=mid+1;
            int ptr=0;
            while(first<=mid&&second<=end){
                if(nums[first]<nums[second]){
                    finalarr[ptr]=nums[first];
                    first++;
                }
                else{
                    finalarr[ptr]=nums[second];
                    second++;
                }
                ptr++;
            }
            while(first<=mid){
                finalarr[ptr]=nums[first];
                first++;
                ptr++;
            }
            while(second<=end){
                finalarr[ptr]=nums[second];
                second++;
                ptr++;
            }

        for(int i=0;i<finalarr.size();i++){
            nums[i+start]=finalarr[i];
        }
        


    }
    void mergeSort(vector<int>&nums,int start,int end){
        if(start>=end)return ;
        int mid=start+(end-start)/2;
        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        merge(nums,start,mid,end);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};