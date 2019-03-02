#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main()
{
	int i, n, cnt, sum, max_sum = INT_MIN;

	scanf("%d", &cnt);

	for(i = 0, sum = 0; i < cnt; ++i) {
		scanf("%d", &n);

		if(sum + n > 0) {
			sum += n;

			if(max_sum < sum)
				max_sum = sum;
		}
		else
			sum = 0;
	}

	if(INT_MIN == max_sum)
		max_sum = 0;

	printf("%d\n", max_sum);

	return 0;
}
