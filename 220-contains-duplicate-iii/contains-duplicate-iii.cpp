class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff,
                                       int valueDiff) {
        multiset<int> s;
        int start = 0;
        for (int i = 0; i < nums.size(); i++) {
           
            if (i - start > indexDiff) {
                auto idx = s.find(nums[start]);
                s.erase(idx);
                start++;
            }

            auto bottom = s.lower_bound(nums[i]-valueDiff);
            if (bottom != s.end() && abs(*bottom - nums[i]) <= valueDiff)
                return true;

            s.insert(nums[i]);
        }
        return false;
    }
};