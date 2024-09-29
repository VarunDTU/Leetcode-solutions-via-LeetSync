class AllOne {
    set<pair<int,string>>s;
    map<string,int>mp;
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        if(mp.find(key)==mp.end()){
            mp[key]++;
            s.insert({1,key});
        }
        else{
            s.erase({mp[key],key});
            mp[key]++;
            s.insert({mp[key],key});
        }

    }
    
    void dec(string key) {
        if(mp[key]==1){
            mp.erase(key);
            s.erase({1,key});
        }
        else{
            s.erase({mp[key],key});
            mp[key]--;
            s.insert({mp[key],key});
        }

    }
    
    string getMaxKey() {
        if(s.size()==0)return "";
        return s.rbegin()->second;
    }
    
    string getMinKey() {
         if(s.size()==0)return "";
        return s.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */