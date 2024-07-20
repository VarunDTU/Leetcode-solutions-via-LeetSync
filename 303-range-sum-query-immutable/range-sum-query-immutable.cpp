class NumArray {
public:
    vector<int>left={};

    NumArray(vector<int>& nums) {
        left.push_back(nums[0]);
       
        for(int i=1;i<nums.size();i++){
            left.push_back(nums[i]+left[i-1]);
           
        }
        

    }
    
    int sumRange(int l, int r) {
        return left[r]-(l==0?0:left[l-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */