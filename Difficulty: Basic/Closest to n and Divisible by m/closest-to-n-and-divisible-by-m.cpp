class Solution {
  public:
    int closestNumber(int n, int m) {
        // code here
       
        int q = n / m;

            // 1st possible closest number
        int n1 = m * q;

            // 2nd possible closest number
        int n2 = (n * m) > 0 ? (m * (q + 1)) : (m * (q - 1));

            // if true, then n1 is the required closest number
        if (abs(n - n1) < abs(n - n2))
            return n1;

            // else n2 is the required closest number    
        return n2;    
        }

    
};