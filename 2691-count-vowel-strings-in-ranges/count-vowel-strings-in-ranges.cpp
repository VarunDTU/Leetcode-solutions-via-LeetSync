class Solution {
    bool isVowelends(string s){
         int n=s.size();
       return (s[0]=='a'||s[0]=='i'||s[0]=='e'||s[0]=='o'||s[0]=='u')&&
       (s[n-1]=='a'||s[n-1]=='i'||s[n-1]=='e'||s[n-1]=='o'||s[n-1]=='u');
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>arr(n,0);
        if(isVowelends(words[0]))arr[0]=1;
        for(int i=1;i<n;i++){
            
            arr[i]=arr[i-1];
            if(isVowelends(words[i]))arr[i]++;
            
        }
        vector<int>ans;
       // for(auto itr:arr)cout<<itr;
        for(auto itr:queries){
            int first=arr[itr[1]];
       
            if(itr[0]!=0)first-=arr[itr[0]-1];
            ans.push_back(first);
        }
        return ans;

    }
};