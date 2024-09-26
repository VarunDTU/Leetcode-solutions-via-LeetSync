class MyCalendarThree {
        map<int, int> mp;
public:

    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
         int current_bookings = 0;
        mp[startTime]++;
        mp[endTime]--;
        int ans=0;
        for (auto itr : mp) {
            current_bookings += itr.second;
            ans=max(ans,current_bookings);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */