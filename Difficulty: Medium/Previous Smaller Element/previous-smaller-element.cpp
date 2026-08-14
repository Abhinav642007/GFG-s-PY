class Solution {
public:
    vector<int> prevSmaller(vector<int>& arr) {
        vector<int> ans;
        stack<int> s;

        for (int i = 0; i < arr.size(); i++) {

            // Remove elements that are greater than or equal to current
            while (!s.empty() && s.top() >= arr[i]) {
                s.pop();
            }

            // If no smaller element exists
            if (s.empty()) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(s.top());
            }

            // Push current element for future elements
            s.push(arr[i]);
        }

        return ans;
    }
};