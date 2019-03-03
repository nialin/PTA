#include <stdio.h>
#include <limits.h>


int main()
{
	int i, n, cnt, sum, max_sum = 0;

	scanf("%d%d", &cnt, &n);

	for(i = 1, sum = n; i < cnt; ++i) {
		scanf("%d", &n);

		if(sum < 0)
			sum = n;
		else
			sum += n;

		if(max_sum < sum)
			max_sum = sum;
	}

	printf("%d\n", max_sum);

	return 0;
}
