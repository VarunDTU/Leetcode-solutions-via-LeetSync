class NumArray {
public:
    vector<int>arr;
    NumArray(vector<int>& nums) {
        arr.resize(nums.size(),0);
        arr[0]=nums[0];
        for(int i=1;i<nums.size();i++)arr[i]=nums[i]+arr[i-1];
    }
    
    void update(int index, int val) {
        int temp=index==0?arr[index]:arr[index]-arr[index-1];
        for(int i=index;i<arr.size();i++){
            arr[i]-=temp;
            arr[i]+=val;
        }
        

    }
    
    int sumRange(int left, int right) {
        return arr[right]-(left==0?0:arr[left-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */