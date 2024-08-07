class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int current_cost=0,total_cost=0,ans=0;
        //1 2 3 4 5  3 4 5 1 2
        //
        for(int i=0;i<gas.size();i++){
            current_cost+=gas[i]-cost[i];
            total_cost+=gas[i]-cost[i];
            if(current_cost<0){
                current_cost=0;
                ans=i+1;
            }
        }
        return total_cost<0?-1:ans;

    }
};