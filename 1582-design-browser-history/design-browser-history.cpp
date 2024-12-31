class BrowserHistory {
    vector<string> history;
    int curr;

public:
    BrowserHistory(string homepage) {
        curr = 1;
        history.push_back(homepage);
    }

    void visit(string url) {
        history.erase(history.begin() + curr, history.end());
        history.push_back(url);
        curr++;
    }

    string back(int steps) {
        curr -= steps;

        curr = max(curr, 1);

        return history[curr - 1];
    }

    string forward(int steps) {

        curr = min(curr + steps, (int)(history.size()));
        return history[curr - 1];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */