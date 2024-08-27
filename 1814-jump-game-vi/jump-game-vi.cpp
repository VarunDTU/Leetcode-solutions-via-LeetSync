class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty())
                nums[i] = nums[dq.front()] + nums[i];
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
            
        }
        return nums.back();
    }
};