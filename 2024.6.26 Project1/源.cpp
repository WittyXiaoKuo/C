//Ô¼Éª·ò»·
typedef struct ListNode
{
	int val;
	struct Node* next;
}ListNode;
ListNode* buyNode(int x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	node->val = x;
	node->next = NULL;
	return node;
}
ListNode* createCircle(int n)
{
	ListNode* phead = buyNode(1);
	ListNode* ptail = phead;
	for (int i = 2; i <= n; i++)
	{
		ptail->next = buyNode(i);
		ptail = ptail->next;
	}
	ptail->next = phead;
	return ptail;
}
int ysf(int n, int m) {
	ListNode* prev = createCircle(n);
	ListNode* pcur = prev->next;
	int count = 1;
	while (pcur->next != pcur)
	{
		if (count == m)
		{
			prev->next = pcur->next;
			free(pcur);
			pcur = prev->next;
			count = 1;
		}
		else
		{
			prev = pcur;
			pcur = pcur->next;
			count++;
		}
	}
	return pcur->val;
}
int main()
{
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);
	int ret = ysf(a, b);
	printf("%d\n", ret);
	return 0;
}
