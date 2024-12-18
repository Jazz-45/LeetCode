class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
         vector<int> answer(prices.size());
    stack<int> stk;

    for (int i = 0; i < prices.size(); ++i) {
        // Apply discounts to all items in the stack that are greater than or equal to the current price
        while (!stk.empty() && prices[stk.top()] >= prices[i]) {
            int index = stk.top();
            stk.pop();
            answer[index] = prices[index] - prices[i];
        }
        
        // Add the current index to the stack for future discount checks
        stk.push(i);
    }

    // For all remaining items in the stack, there's no discount (just copy the prices)
    while (!stk.empty()) {
        int index = stk.top();
        stk.pop();
        answer[index] = prices[index];
    }

    return answer;
    }
};