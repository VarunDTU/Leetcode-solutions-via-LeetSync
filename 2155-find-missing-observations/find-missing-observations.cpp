class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int req_sum = mean * (n + rolls.size());
        req_sum -= sum;
        vector<int> t(n, 0);
        int m = req_sum / n;
        if (m > 6||req_sum<0||m==0)
            return {};
        
        if (m != 0) {
            for (int i = 0; i < n; i++)
                t[i] = m;
        }

        for (int i = 0; i < req_sum % n; i++) {
            t[i]++;
            if (t[i] > 6)
                return {};
        }
        return t;
    }
};