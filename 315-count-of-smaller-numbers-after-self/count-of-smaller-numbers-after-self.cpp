class Solution {
    void merge(vector<pair<int, int>>& nums, vector<int>& ans, int& start,
               int mid, int end) {
        vector<pair<int,int>> finalarr(end - start + 1);
        int first = start, second = mid + 1;
        int ptr = 0;
        while (first <= mid && second <= end) {
            if (nums[first].first <= nums[second].first) {
                finalarr[ptr] = nums[second];
                second++;
            } else {
                ans[nums[first].second] += end - second + 1;
                finalarr[ptr] = nums[first];
                first++;
            }
            ptr++;
        }
        while (first <= mid) {
            finalarr[ptr] = nums[first];
            first++;
            ptr++;
        }
        while (second <= end) {
            finalarr[ptr] = nums[second];
            second++;
            ptr++;
        }

        for (int i = start; i <= end; i++) {
            nums[i] = finalarr[i-start];
        }
    }
    void mergeSort(vector<pair<int, int>>& nums, vector<int>& ans, int start,
                   int end) {
        if (start >= end)
            return;
        int mid = start + (end - start) / 2;
        mergeSort(nums, ans, start, mid);
        mergeSort(nums, ans, mid + 1, end);
        merge(nums, ans, start, mid, end);
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> newNum;
        for (int i = 0; i < nums.size(); i++) {
            newNum.push_back({nums[i], i});
        }
        vector<int> ans(nums.size(), 0);
       
        mergeSort(newNum, ans, 0, nums.size() - 1);
        return ans;
    }
};