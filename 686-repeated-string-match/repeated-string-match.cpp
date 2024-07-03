class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string match = "";
        while (match.size() < b.size())
            match += a;
     
        if (match.find(b) != string::npos)
            return match.size() / a.size();

        match += a;
        if (match.find(b) != string::npos)
            return (match.size() / a.size());

        return -1;
    }
};