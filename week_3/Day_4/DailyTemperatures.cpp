class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();

        vector<int> result(n, 0);

        stack<int> pendingDays;

        for (int currentDay = 0; currentDay < n; currentDay++) {

            while (!pendingDays.empty() &&
                   temperatures[currentDay] >
                   temperatures[pendingDays.top()]) {

                int previousDay = pendingDays.top();
                pendingDays.pop();

                result[previousDay] = currentDay - previousDay;
            }

            pendingDays.push(currentDay);
        }

        return result;
    }
};
