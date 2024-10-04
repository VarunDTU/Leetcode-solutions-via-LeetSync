class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int s=0,e=skill.size()-1;
        if(skill.size()%2!=0)return -1; 
        int sum=skill[e]+skill[s];
        long long ans=0;
        while(s<e){
         
            if(skill[e]+skill[s]==sum)ans+=(long long)skill[e]*skill[s];
            else return -1;
            s++;
            e--;
        }
        return ans;

    }
};