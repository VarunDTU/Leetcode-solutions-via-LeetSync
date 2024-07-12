class Solution {
public:
    void helper(int n,vector<string>&ans,string temp){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        if(temp.size()==0||temp[temp.size()-1]=='1'){
            temp.push_back('1');
            helper(n,ans,temp);
            temp.pop_back();
            temp.push_back('0');
            helper(n,ans,temp);
        }
        else{
            temp.push_back('1');
            helper(n,ans,temp);
        }
        return ;
    }
    vector<string> validStrings(int n) {
        vector<string>ans;
        string temp="";
        helper(n,ans,temp);
        return ans;
    }
};