#include <stdio.h>

int max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

int main()
{
    int n, W;
    int wt[10], profit[10];
    int dp[10][50];
    int i, j;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &wt[i]);

    printf("Enter profits:\n");
    for(i = 1; i <= n; i++)
        scanf("%d", &profit[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    // Initialize first row and column
    for(i = 0; i <= n; i++)
        dp[i][0] = 0;

    for(j = 0; j <= W; j++)
        dp[0][j] = 0;

    // Build DP table
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= W; j++)
        {
            if(wt[i] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j],
                               profit[i] + dp[i-1][j-wt[i]]);
        }
    }

    printf("\nMaximum Profit = %d\n", dp[n][W]);

    return 0;
}