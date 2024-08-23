class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size())
            return addBinary(b, a);
        string ans = "";
        int n = a.size();
        int carry = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i = 0; i < n; i++) {
            int n1 = i < a.size() ? a[i] - '0' : 0;
            int n2 = i < b.size() ? b[i] - '0' : 0;
            carry += n1 + n2;
            if (carry == 3) {
                ans += '1';
                carry = 1;
            } else if (carry == 2) {
                ans += '0';
                carry = 1;
            } else if (carry == 1) {
                ans += '1';
                carry--;
            } else {
                ans += '0';
            }
        }

        if (carry == 1)
            ans += '1';

        reverse(ans.begin(), ans.end());
        return ans;
    }
};