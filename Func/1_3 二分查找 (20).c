Position BinarySearch( List L, ElementType X )
{
	int low = 1, high = L->Last, mid;

	while(low <= high) {
		mid = (low + high) / 2;

		if(X == L->Data[mid])
			return mid;
		if(X < L->Data[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}

	return NotFound;
}
