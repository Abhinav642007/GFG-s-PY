class Solution {
public:

    double solve(double b, long long e) {

        if (e == 0)
            return 1.0;

        if (e % 2 == 0) {
            double half = solve(b, e / 2);
            return half * half;
        }

        return b * solve(b, e - 1);
    }

    double power(double b, int e) {

        long long exp = e;

        if (exp < 0) {
            return 1.0 / solve(b, -exp);
        }

        return solve(b, exp);
    }
};