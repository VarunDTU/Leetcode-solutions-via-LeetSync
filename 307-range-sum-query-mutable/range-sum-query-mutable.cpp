class NumArray {
public:
    vector<int> arr;
    int n;
    void build(vector<int>& nums, int index, int left, int right) {

        if (left == right) {
            arr[index] = nums[left];
            return;
        }
        int mid = left + (right - left) / 2;
        build(nums, 2 * index + 1, left, mid);
        build(nums, 2 * index + 2, mid + 1, right);
        arr[index] = arr[2 * index + 1] + arr[2 * index + 2];
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        arr.resize(4 * n + 1);
        build(nums, 0, 0, n - 1);
    }

    int updatearr(int i, int left, int right, int index, int val) {
        if (left == index && left == right) {
            return arr[i] = val;
        }
        if (left > index || right < index)
            return arr[i];
        int mid = left + (right - left) / 2;
        return arr[i] = updatearr(2 * i + 1, left, mid, index, val) +
                        updatearr(2 * i + 2, mid + 1, right, index, val);
    }
    void update(int index, int val) { updatearr(0, 0, n - 1, index, val); }
    int sumR(int left, int right, int index, int l, int r) {
        if (left >= l && right <= r)
            return arr[index];
        if (left > r || right < l)
            return 0;
        int mid = left + (right - left) / 2;
        int x = sumR(left, mid, 2 * index + 1, l, r),
            y = sumR(mid + 1, right, 2 * index + 2, l, r);
        return x + y;
    }
    int sumRange(int left, int right) { return sumR(0, n - 1, 0, left, right); }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */