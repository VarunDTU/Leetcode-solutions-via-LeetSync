class MyCalendarTwo {
public:
    map<int, int> mp;
    MyCalendarTwo() {}

    bool book(int start, int end) {
        int current_bookings = 0;
        mp[start]++;
        mp[end]--;
        for (auto itr : mp) {
            current_bookings += itr.second;
            if (current_bookings == 3) {
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */