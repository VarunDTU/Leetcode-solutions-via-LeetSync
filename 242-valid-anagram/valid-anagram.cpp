class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>s1(26,0),t1(26,0);
        for(auto itr:s)s1[itr-'a']++;
        for(auto itr:t)t1[itr-'a']++;

        return s1==t1;
    }
};