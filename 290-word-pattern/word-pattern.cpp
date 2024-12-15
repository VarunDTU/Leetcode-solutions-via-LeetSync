class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char>patternToMap;
        unordered_map<char,string>mapToPattern;
        stringstream strStream(s);
        int patternItr=0;
        string word="";
        while(strStream>>word){
      
            if(patternToMap.find(word)==patternToMap.end()&&mapToPattern.find(pattern[patternItr])==mapToPattern.end()){
                patternToMap[word]=pattern[patternItr];
                mapToPattern[pattern[patternItr]]=word;
            }
            else{
                if(patternToMap[word]!=pattern[patternItr]||mapToPattern[pattern[patternItr]]!=word)return false;
            }
            patternItr++;
        }
        return patternItr==pattern.size()?true:false;
    }
};