class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long  sum=accumulate(chalk.begin(),chalk.end(),(long)0);
        k%=sum;
        for(int i=0;i<chalk.size();i++){
            k-=chalk[i];
            if(k<0)return i;
        }

        return -1;
    }
};