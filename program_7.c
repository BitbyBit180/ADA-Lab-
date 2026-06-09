#include <stdio.h>

int main()
{
    int n, i;
    float w[10], p[10], ratio[10];
    float capacity, profit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter weight and profit: ");
        scanf("%f %f", &w[i], &p[i]);

        ratio[i] = p[i] / w[i];
    }

    printf("Enter capacity: ");
    scanf("%f", &capacity);

    // Sort by ratio
    for(i = 0; i < n - 1; i++)
    {
        int j;
        for(j = i + 1; j < n; j++)
        {
            if(ratio[i] < ratio[j])
            {
                float temp;

                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = w[i];
                w[i] = w[j];
                w[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        if(capacity >= w[i])
        {
            profit += p[i];
            capacity -= w[i];
        }
        else
        {
            profit += p[i] * (capacity / w[i]);
            break;
        }
    }

    printf("Maximum Profit = %.2f", profit);

    return 0;
}