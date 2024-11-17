class Solution {
public:
    int shortestSubarray(vector<int>& num, int k) {
        deque<long> de;
        vector<long> nums;
        for (auto itr : num)
            nums.push_back(itr);
        int ans = nums.size() + 1;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0)
                nums[i] += nums[i - 1];
            if (nums[i] >= k)
                ans = min(ans, i + 1);
            while (de.size() > 0 && nums[i] - nums[de.front()] >= k)
                ans = min(ans, (int)i - (int)de.front()), de.pop_front();
            while (de.size() > 0 && nums[i] <= nums[de.back()])
                de.pop_back();
            de.push_back(i);
        }
        return ans == nums.size() + 1 ? -1 : ans;
    }
};