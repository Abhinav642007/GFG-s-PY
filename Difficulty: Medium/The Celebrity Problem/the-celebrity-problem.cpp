class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();

        stack<int> st;

        // Put all people into stack
        for (int i = 0; i < n; i++) {
            st.push(i);
        }

        // Eliminate non-celebrities
        while (st.size() > 1) {
            int a = st.top();
            st.pop();

            int b = st.top();
            st.pop();

            // If a knows b,
            // a cannot be celebrity
            if (mat[a][b] == 1) {
                st.push(b);
            }
            else {
                // If a doesn't know b,
                // b cannot be celebrity
                st.push(a);
            }
        }

        // Only possible candidate remains
        int candidate = st.top();

        // 1. Candidate should know nobody
        for (int i = 0; i < n; i++) {
            if (i != candidate && mat[candidate][i] == 1) {
                return -1;
            }
        }

        // 2. Everybody should know candidate
        for (int i = 0; i < n; i++) {
            if (i != candidate && mat[i][candidate] == 0) {
                return -1;
            }
        }

        return candidate;
    }
};