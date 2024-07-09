class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double total = 0, current_time = 0;
        for (auto itr : customers) {
            total += current_time >= itr[0] ? current_time + itr[1] - itr[0]
                                            : itr[1];

            current_time = current_time >= itr[0] ? current_time + itr[1]
                                                  : itr[0] + itr[1];
        }
        double avg = 0;
        avg = (double)total / (customers.size());
        return avg;
    }
};