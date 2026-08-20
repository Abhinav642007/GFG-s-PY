class Solution {
  public:
    vector<int> preGreaterEle(vector<int>& arr) {
        //  code here
        int n = arr.size();

          // Answer array
          vector<int> ans(n);

          // Stack stores elements for which
          // we are still searching for a smaller element
          stack<int> st;

          // Traverse from right to left
          for (int i = 0; i <n; i++) {

              // Remove all elements which are
              // greater than or equal to arr[i]
              while (!st.empty() && st.top() <= arr[i]) {
                  st.pop();
              }

              // If stack is empty, there is no
              // smaller element on the right
              if (st.empty()) {
                  ans[i] = -1;
              }
              else {
                  // Top is the nearest smaller element
                  ans[i] = st.top();
              }

              // Current element may be the
              // next smaller element for someone on its left
              st.push(arr[i]);
          }

          return ans;        
    }
};