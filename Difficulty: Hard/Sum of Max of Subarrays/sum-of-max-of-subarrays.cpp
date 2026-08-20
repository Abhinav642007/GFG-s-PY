class Solution {
public:
    int sumOfMax(vector<int> &arr) {

        int n = arr.size();

        // left[i] = previous greater element index
        vector<int> left(n);

        // right[i] = next greater element index
        vector<int> right(n);

        stack<int> st;

        // --------------------------------
        // 1. Previous Greater Element
        // --------------------------------
        for (int i = 0; i < n; i++) {

            // Remove smaller or equal elements
            // because we need a STRICTLY greater element
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            if (st.empty())
                left[i] = -1;
            else
                left[i] = st.top();

            st.push(i);
        }

        // Clear stack
        while (!st.empty()) {
            st.pop();
        }

        // --------------------------------
        // 2. Next Greater Element
        // --------------------------------
        for (int i = n - 1; i >= 0; i--) {

            // Remove smaller elements
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }

            if (st.empty())
                right[i] = n;
            else
                right[i] = st.top();

            st.push(i);
        }

        // --------------------------------
        // 3. Calculate contribution
        // --------------------------------
        long long ans = 0;

        for (int i = 0; i < n; i++) {

            // Number of choices on left
            long long leftChoices = i - left[i];

            // Number of choices on right
            long long rightChoices = right[i] - i;

            // Number of subarrays where arr[i]
            // is the maximum
            long long contribution =
                1LL * arr[i] * leftChoices * rightChoices;

            ans += contribution;
        }

        return (int)ans;
    }
};