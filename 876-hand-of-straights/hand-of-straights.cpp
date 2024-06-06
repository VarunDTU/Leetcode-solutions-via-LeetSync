class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;
        for (int itr : hand)
            mp[itr]++;
        for (pair<int,int> itr : mp) {
            if (mp[itr.first] > 0) {
                for (int i = 1; i < groupSize; i++) {
                    if (mp[i + itr.first] - mp[itr.first] < 0)
                        return false;
                    mp[i + itr.first] -= mp[itr.first];
                }
            }
        }
        return true;
    }
};