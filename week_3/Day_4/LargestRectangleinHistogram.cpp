class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<int> indexStack;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {

            int currentHeight = (i == n) ? 0 : heights[i];

            while (!indexStack.empty() &&
                   currentHeight < heights[indexStack.top()]) {

                int height = heights[indexStack.top()];
                indexStack.pop();

                int leftBoundary = indexStack.empty() ? -1 : indexStack.top();

                int width = i - leftBoundary - 1;

                maxArea = max(maxArea, height * width);
            }

            indexStack.push(i);
        }

        return maxArea;
    }
};
