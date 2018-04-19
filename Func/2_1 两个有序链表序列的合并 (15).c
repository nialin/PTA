List Merge(List L1, List L2)
{
	List head;
	PtrToNode ptr, *chosen, del_node;

	if(!(head = malloc(sizeof(struct Node))))
		exit(1);

	ptr = head;

	while(L1->Next && L2->Next) {
		chosen = L1->Next->Data < L2->Next->Data ? &L1->Next : &L2->Next;

		del_node = *chosen;
		*chosen = (*chosen)->Next;

		ptr->Next = del_node;
		ptr = ptr->Next;
	}

	chosen = L1->Next ? &L1->Next : &L2->Next;

	while(*chosen) {
		del_node = *chosen;
		*chosen = (*chosen)->Next;

		ptr->Next = del_node;
		ptr = ptr->Next;
	}

	return head;
}
