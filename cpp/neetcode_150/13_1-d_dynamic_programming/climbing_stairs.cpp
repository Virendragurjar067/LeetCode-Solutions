/*
    Climbing stairs, either 1 or 2 steps, distinct ways to reach top
    Ex. n = 2 -> 2 (1 + 1, 2), n = 3 -> 3 (1 + 1 + 1, 1 + 2, 2 + 1)

    Bottom-up DP
    Recurrence relation: dp[i] = dp[i - 1] + dp[i - 2]
    Reach ith step in 2 ways: 1) 1 step from i-1, 2) 2 steps from i-2

    Time: O(n)
    Space: O(1)
*/

class SolutionBottomUp {
public:
    //Fibonacci series : 'one' stores ways from [n-2]
    //'two' stores ways from [n-1] 
    int climbStairs(int n) {
        int one = 1, two = 1;
        for(int i = 0; i < n - 1; ++i){
            int temp = one;
            one += two;
            two = temp;
        }
        return one;
    }
};


class SolutionTopDown {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        
        int first = 1;
        int second = 2;
        
        int result = 0;
        
        for (int i = 2; i < n; i++) {
            result = first + second;
            first = second;
            second = result;
        }
        
        return result;
    }
};
