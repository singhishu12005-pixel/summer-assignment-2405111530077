class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> numbers;

        for (int i = 0; i < tokens.size(); i++) {

            string curr = tokens[i];

            if (curr == "+" || curr == "-" ||
                curr == "*" || curr == "/") {

                int right = numbers.top();
                numbers.pop();

                int left = numbers.top();
                numbers.pop();

                int value = 0;

                if (curr == "+")
                    value = left + right;
                else if (curr == "-")
                    value = left - right;
                else if (curr == "*")
                    value = left * right;
                else
                    value = left / right;

                numbers.push(value);
            }
            else {
                numbers.push(stoi(curr));
            }
        }

        return numbers.top();
    }
};
