#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main()
{
	int i, n, cnt, sum, max_sum = INT_MIN, head, tail, max_head = INT_MAX, max_tail;

	scanf("%d", &cnt);

	for(i = 0, sum = 0; i < cnt; ++i) {
		scanf("%d", &n);

		if(INT_MAX == max_head)
			max_head = head = n;

		if(-1 == sum) {
			head = n;
			sum = 0;
		}

		if(sum + n >= 0) {
			tail = n;
			sum += n;

			if(max_sum < sum) {
				max_sum = sum;

				max_head = head;
				max_tail = tail;
			}
		}
		else
			sum = -1;
	}

	if(INT_MIN == max_sum) {
		max_sum = 0;
		max_tail = n;
	}

	printf("%d %d %d\n", max_sum, max_head, max_tail);

	return 0;
}
