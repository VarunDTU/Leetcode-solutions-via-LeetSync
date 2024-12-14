class Twitter {
private:
    unordered_map<int,set<int>>followerList;
    unordered_map<int,vector<pair<int,int>>>tweets;
    int count;
public:
    Twitter() {
        count=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++count,tweetId});
        
    }
    
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>q;
        vector<int>feed;
        for(auto tweet:tweets[userId])q.push(tweet);
        for(auto follower:followerList[userId]){
            for(auto tweet:tweets[follower]){
                q.push(tweet);
            }
        }   
        for(int i=0;i<10&&!q.empty();i++){feed.push_back(q.top().second),q.pop();}
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        followerList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId)followerList[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */