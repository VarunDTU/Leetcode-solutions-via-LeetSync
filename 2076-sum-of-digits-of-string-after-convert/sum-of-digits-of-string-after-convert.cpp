class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        string x = "";
        for (auto itr : s)
            x += to_string(itr - 'a' + 1);

        for (int itr : x)
            sum += itr - '0';

        k--;

        while (k--) {

            int temp = 0;
            while (sum != 0) {
                //  temp*10;
                temp += sum % 10;
                sum /= 10;
            }
            sum = temp;
        }
        return sum;
    }
};