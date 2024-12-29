class Solution {
    bool ans(string name,string typed,int i,int j){
        if(name.size()==i&&typed.size()==j)return true;
           if(name.size()==i||typed.size()==j)return false;
        
        if(name[i]==typed[j])return ans(name,typed,i+1,j+1)||ans(name,typed,i,j+1);
         return false;
        
    }
        
public:
    bool isLongPressedName(string name, string typed) {
        //if(name.size()<typed.size())return false;
        return ans(name,typed,0,0);
    }
};