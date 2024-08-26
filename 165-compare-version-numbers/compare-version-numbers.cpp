class Solution {
public:
    int compareVersion(string version1, string version2) {
        int s1 = 0, e1 = 0, s2 = 0, e2 = 0;
        while (e1 < version1.size() || e2 < version2.size()) {
            string a1 = "0", a2 = "0";
            while (e1 < version1.size() && version1[e1] != '.') {
                a1 += version1[e1];
                e1++;
            }
            while (e2 < version2.size() && version2[e2] != '.') {
                a2 += version2[e2];
                e2++;
            }
            e1++;
            e2++;
            s1=e1;
            s2=e2;
          
            if(stoi(a1)==stoi(a2))continue;
            if(stoi(a1)>stoi(a2))return 1;
            else return -1;
            
        }
        return 0;
    }
};