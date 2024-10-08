class Solution {
public:
    int minSwaps(string s) {

        int n = s.size();
        int swap = 0, power = 0, j = n - 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == '[')
                power++;
            else
                power--;

            if (power < 0) {
                while (i < j && s[j] != '[')
                    j--;
                char ch=s[j];
                s[j]=s[i];
                s[i]=ch;
                swap++;
                power = 1;
            }
        }

        return swap;
    }
};