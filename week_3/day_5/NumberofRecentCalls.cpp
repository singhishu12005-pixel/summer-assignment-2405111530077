class RecentCounter {
private:
    queue<int> calls;

public:
    RecentCounter() {
        
    }

    int ping(int t) {
        calls.push(t);

        while (!calls.empty() && calls.front() < t - 3000) {
            calls.pop();
        }

        return calls.size();
    }
};
