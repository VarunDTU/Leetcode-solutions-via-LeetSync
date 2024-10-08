class Solution {
public:
static int count(int a){
    int cnt=0;
    while(a){
        a=a&(a-1);
        cnt++;
    }
    return cnt; 
}
static bool cmp(const int &a,const int &b){
    int a1=count(a);
    int b1=count(b);
    if(b1==a1)return a<b;
    return a1<b1;
}
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};