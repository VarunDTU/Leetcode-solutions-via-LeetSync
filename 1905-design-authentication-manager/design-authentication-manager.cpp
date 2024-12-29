class AuthenticationManager {
    unordered_map<string, int> tokenStore;
    multiset<int> tokenLifetimes;
    int lifetime = 0;

public:
    AuthenticationManager(int timeToLive) { lifetime = timeToLive; }

    void generate(string tokenId, int currentTime) {

        tokenStore[tokenId] = currentTime + lifetime;
        tokenLifetimes.insert(currentTime + lifetime);
    }

    void renew(string tokenId, int currentTime) {

        if (tokenStore.find(tokenId) == tokenStore.end())
            return;
        int oldTime = tokenStore[tokenId];
        if (oldTime <= currentTime)
            return;
        tokenStore[tokenId] = currentTime + lifetime;
        auto tokenTime = tokenLifetimes.find(oldTime);
        tokenLifetimes.erase(tokenTime);

        tokenLifetimes.insert(currentTime + lifetime);
    }

    int countUnexpiredTokens(int currentTime) {

        return distance(tokenLifetimes.upper_bound(currentTime),
                        tokenLifetimes.end());
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */