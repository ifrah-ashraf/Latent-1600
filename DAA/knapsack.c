#include <stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20], tp = 0.0;
    int i, j;
    float u = capacity;

    for (i = 0; i < n; i++)
    {
        x[i] = 0.0;
    }

    for (i = 0; i < n; i++)
    {
        if (weight[i] > u)
        {
            break;
        }
        else
        {
            x[i] = 1.0;
            tp = tp + profit[i];
            u = u - weight[i];
        }
    }

    if (i < n)
    {
        x[i] = u / weight[i];
        tp = tp + (x[i] * profit[i]);
    }

    printf("\nThe result vector is:");
    for (i = 0; i < n; i++)
    {
        printf(" %f", x[i]);
    }
    printf("\nMaximum profit is %f\n", tp);
}

int main()
{
    float weight[20], profit[20], capacity;
    int n, i, j;
    float ratio[20], temp;

    printf("Enter number of objects: ");
    scanf("%d", &n);

    printf("Enter the weights and profits of each object:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);

    for (i = 0; i < n; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    knapsack(n, weight, profit, capacity);

    return 0;
}