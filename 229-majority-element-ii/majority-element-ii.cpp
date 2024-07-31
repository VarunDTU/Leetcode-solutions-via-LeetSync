class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> el1 = {0, -1}, el2 = {0, -1};
        for (int itr : nums) {
            if (el2[1] == itr)
                el2[0]++;
            else if (el1[1] == itr)
                el1[0]++;
            else if (el1[0] <= 0)
                el1 = {1, itr};
            else if (el2[0] <= 0)
                el2 = {1, itr};
            
            else {
                el1[0]--;
                el2[0]--;
            }
        }
        int c1 = 0, c2 = 0;
        for (auto itr : nums) {
            if (itr == el1[1])
                c1++;
            else if (itr == el2[1])
                c2++;
        }
        cout<<el1[1]<<c1;
        cout<<el2[1]<<c2;
        vector<int> ans;
        if (3*c1 > nums.size())
            ans.push_back(el1[1]);
        if (3*c2 > nums.size() )
            ans.push_back(el2[1]);
        return ans;
    }
};