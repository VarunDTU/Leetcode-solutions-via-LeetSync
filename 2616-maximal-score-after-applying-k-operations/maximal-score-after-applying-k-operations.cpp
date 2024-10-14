class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int>q;
        for(auto &itr:nums)q.push(itr);
        long long sum=0;
        while(k--){
            long long temp=q.top();
            q.pop();
            sum+=temp;
            q.push(ceil((double)temp/3));
        }
        return sum;
    }
};