class Solution {
public:
    string reverseVowels(string s) {
        vector<int>hold;
        for(int i=0;i<s.size();i++){
            char itr=s[i];
            if(itr=='A'||itr=='E'||itr=='I'||itr=='O'||itr=='U'||itr=='a'||itr=='e'||itr=='i'||itr=='o'||itr=='u')hold.push_back(i);
            
        }
        int st=0,e=hold.size()-1;
      
        while(st<e){
            swap(s[hold[st]],s[hold[e]]);
            
            st++;
            e--;
        }
        return s;
    }
};