#include <stdio.h>
#include <math.h>
#define f(x) cos(x) - 3 * x + 1
#define g(x) (1 + cos(x)) / x * x * x - x - 1

int main()
{
    int step = 1, N;
    float x0, x1, e;
    printf("Enter initial guess: ");
    scanf("%f", &x0);
    printf("Enter tolerable error: ");
    scanf("%f", &e);
    printf("Enter maximum iteration: ");
    scanf("%d", &N);
    printf("\nStep\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
    do
    {
        x1 = g(x0);
        printf("%d\t%f\t%f\t%f\t%f\n", step, x0, f(x0), x1, f(x1));
        step = step + 1;
        if (step > N)
        {
            printf("Not Convergent.");
            return 0;
        }
        x0 = x1;
    } while (fabs(f(x1)) > e);
    printf("\nRoot is %f", x1);
    return (0);
}