class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int>ct(1001,0),ca(1001,0);
        for(int i=0;i<target.size();i++){
            ct[target[i]]++;
            ca[arr[i]]++;
        }
        return ct==ca?true:false;
    }
};