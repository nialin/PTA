BinTree Insert(BinTree BST, ElementType X)
{
	BinTree new, *pos = &BST;

	while(*pos)
		pos = (*pos)->Data < X ? &(*pos)->Right : &(*pos)->Left;

	if(!(new = malloc(sizeof(struct TNode))))
		exit(1);

	new->Data = X;
	new->Left = NULL;
	new->Right = NULL;

	*pos = new;

	return BST;
}

BinTree Delete(BinTree BST, ElementType X)
{
	BinTree del, *pos = &BST, *prior;

	while(*pos && (*pos)->Data != X)
		pos = (*pos)->Data < X ? &(*pos)->Right : &(*pos)->Left;

	if(*pos == NULL) {
		printf("Not Found\n");
		return BST;
	}

	del = *pos;

	if(!(*pos)->Left)
		*pos = (*pos)->Right;
	else if (!(*pos)->Right)
		*pos = (*pos)->Left;
	else {
		/* The prior node of a BST is the rightmost node in its left-subtree. */
		prior = &(*pos)->Left;

		while((*prior)->Right)
			prior = &(*prior)->Right;

		(*pos)->Data = (*prior)->Data;

		del = *prior;
		*prior = (*prior)->Left;
	}

	free(del);

	return BST;
}

Position Find(BinTree BST, ElementType X)
{
	while(BST && BST->Data != X)
		BST = BST->Data < X ? BST->Right : BST->Left;

	return BST;
}

Position FindMin(BinTree BST)
{
	if(!BST)
		return NULL;

	while(BST->Left)
		BST = BST->Left;

	return BST;
}

Position FindMax(BinTree BST)
{
	if(!BST)
		return NULL;

	while(BST->Right)
		BST = BST->Right;

	return BST;
}
