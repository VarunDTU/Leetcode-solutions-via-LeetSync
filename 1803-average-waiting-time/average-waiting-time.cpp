class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double total = 0;
        int current_time = 0;
        for (auto itr : customers) {
            current_time = max(current_time, itr[0]) + itr[1];
            total += current_time - itr[0];
        }
        return (double)total / (customers.size());
    }
};