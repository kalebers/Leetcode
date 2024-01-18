// You are climbing a staircase. It takes n steps to reach the top.
//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
class Solution {
public:
    int climbStairs(int n) {
        int ways=1;
        for(int i=1; i<=n/2; i++){
            double sum = 1;
            for(int j=i; j<2*i; j++){
                sum *= (double)(n-j)/(j-i+1);
            }
            ways += sum;
        }
        return ways;
    }
};
