class Solution {
public:
    int climbStairs(int n) { 
        int n1 = 1, n2 = 2, result = n;
        // iteration
        for(int i = 3; i <= n ; i++){
            result = n1 + n2;
            n1 = n2;
            n2 = result;
        }
        return result;
    }
};
