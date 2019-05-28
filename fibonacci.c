#include <stdio.h>
//Fibonacci using recursion
int fib_series(int);
int main()
{
	int count, c = 0, i;
	printf("Enter number of terms: ");
	scanf("%d", &count);

	printf("\nFibonacci series:\n");
	for (i = 1; i <= count; i++)
	{
		printf("%d\n", fib_series(c));
		c++;
	}

	return 0;
}
int fib_series(int num)
{
	if (num == 0)
		return 0;
	else if (num == 1)
		return 1;
	else
		return (fib_series(num-1) + fib_series(num-2));
}
