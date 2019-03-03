#include <stdio.h>
#include <limits.h>


int main()
{
	int i, n, cnt, sum, head, max_sum = INT_MIN, max_head, max_tail;

	scanf("%d%d", &cnt, &n);

	for(i = 1, sum = head = max_head = n; i < cnt; ++i) {
		scanf("%d", &n);

		if(sum < 0)
			sum = head = n;
		else
			sum += n;

		if(sum >= 0 && max_sum < sum) {
			max_sum = sum;
			max_head = head;
			max_tail = n;
		}
	}

	if(INT_MIN == max_sum) {
		max_sum = max_head > 0 ? max_head : 0;
		max_tail = n;
	}

	printf("%d %d %d\n", max_sum, max_head, max_tail);

	return 0;
}
