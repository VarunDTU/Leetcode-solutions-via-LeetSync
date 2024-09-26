class MyCalendar {
    set<pair<int,int>>s;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto l=s.lower_bound({start,end});
        if(l!=s.end()&&l->first<end)return false;
        if(l!=s.begin()){
            l--;
            if(l->second>start)return false;
        }
        s.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */