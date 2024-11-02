class Solution {
public:
    bool isCircularSentence(string sen) {
        for(int i=1;i<sen.size();i++){
            if((sen[i]==' ')&&sen[i-1]!=sen[i+1])return false;
        }
        if(sen.back()!=sen.front())return false;
        return true;
    }
};