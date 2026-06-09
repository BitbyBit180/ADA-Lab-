#include <stdio.h>

int main()
{
    int n, a[20];
    int i, j, target;
    int found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    int total = 1 << n;   // 2^n

    for(i = 0; i < total; i++)
    {
        int sum = 0;

        // Calculate subset sum
        for(j = 0; j < n; j++)
        {
            if(i & (1 << j))
                sum += a[j];
        }

        // Check target
        if(sum == target)
        {
            found = 1;

            printf("{ ");

            for(j = 0; j < n; j++)
            {
                if(i & (1 << j))
                    printf("%d ", a[j]);
            }

            printf("}\n");
        }
    }

    if(!found)
        printf("No solution exists\n");

    return 0;
}