class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        //mitbbs8080's approach
        vector<string>ans;
        string temp;
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                for(int k=1;k<=3;k++){
                    for(int l=1;l<=3;l++){
                        if(i+j+k+l==s.length()){
                            int a=stoi(s.substr(0,i));
                            int b=stoi(s.substr(i,j));
                            int c=stoi(s.substr(i+j,k));
                            int d=stoi(s.substr(i+j+k,l));
                            if(a<=255&&b<=255&&d<=255&&c<=255){
                                temp=to_string(a)+"."+to_string(b)+"."+to_string(c)+"."+to_string(d);
                                if(temp.length()==s.length()+3) ans.push_back(temp);
                            }
                        }
                        
                        
                    }
                }
            }
        }
        return ans;    
    }
};