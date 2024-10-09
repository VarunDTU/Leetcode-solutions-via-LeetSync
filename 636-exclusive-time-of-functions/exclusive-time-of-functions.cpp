class Solution {
    vector<int> log_to_time(string log){
        stringstream ss(log);
            string id, status, time;
            getline(ss, id, ':');
            getline(ss, status, ':');
            getline(ss, time, ':');
        return {stoi(id),status!="end",stoi(time)};
        
    }
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<vector<int>>st;
        vector<int>temp;
        vector<int>vis(n,0);
        int curr=0;
        for(auto itr:logs){
            vector<int>temp=log_to_time(itr);
           // cout<<temp[0]<<temp[1]<<temp[2]<<endl;
            if(temp[1]){
                st.push(temp);
            }
            else{
                int time=(temp[2]-st.top()[2]+1);
                vis[temp[0]]+=time;
                st.pop();
                if(!st.empty())vis[st.top()[0]]-=time;
            }
            
        }
        return vis;
    }
};