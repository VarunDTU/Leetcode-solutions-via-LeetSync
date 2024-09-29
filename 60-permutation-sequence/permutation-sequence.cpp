class Solution {
public:
    string getPermutation(int n, int k) {
        string temp="";
        for(int i=1;i<=n;i++)temp+=(i+'0');
        //cout<<temp<<temp.size();
       // cout<<next_permutation(temp.begin(),temp.end());
        for(int i=0;i<k-1;i++)next_permutation(temp.begin(),temp.end());
        return temp;
    }
};