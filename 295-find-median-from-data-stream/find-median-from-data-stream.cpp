class MedianFinder {
    priority_queue<int> maxQ;
    priority_queue<int, vector<int>, greater<int>> minQ;

public:
    MedianFinder() {
        while (!maxQ.empty())
            maxQ.pop();
        while (!minQ.empty())
            minQ.pop();
    }

    void addNum(int num) {
        if (maxQ.empty() || maxQ.top() > num)
            maxQ.push(num);
        else
            minQ.push(num);

        if (maxQ.size() > minQ.size() + 1) {
            minQ.push(maxQ.top());
            maxQ.pop();
        } else if (maxQ.size()+1 < minQ.size() ) {
            maxQ.push(minQ.top());
            minQ.pop();
        }
    }

    double findMedian() {
        if (maxQ.size() == minQ.size()) {
            if (maxQ.size() == 0)
                return 0;
            return (double)(maxQ.top() + minQ.top()) / 2.0;
        }
        return (maxQ.size() > minQ.size()) ? maxQ.top() : minQ.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */