//二叉树
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;
//创建结点
BTNode* BuyNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (!newnode)
	{
		perror("malloc,fail");
		exit(1);
	}
	newnode->_data = x;
	newnode->_left = NULL;
	newnode->_right = NULL;
	return newnode;
}
//创建二叉树
BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);

	node1->_left = node2;
	node1->_right = node4;
	node2->_left = node3;
	node4->_left = node5;
	node4->_right = node6;
	node6->_right = node7;
	return node1;
}
//二叉树前序遍历
void PrevOrder(BTNode* root)
{
	if (!root)
	{
		printf("N ");
		return;
	}
	printf("%d ", root->_data);
	PrevOrder(root->_left);
	PrevOrder(root->_right);
}
//二叉树中序遍历
void InOrder(BTNode* root)
{
	if (!root)
	{
		printf("N ");
		return;
	}
	InOrder(root->_left);
	printf("%d ", root->_data);
	InOrder(root->_right);
}
//二叉树后序遍历
void PostOrder(BTNode* root)
{
	if (!root)
	{
		printf("N ");
		return;
	}
	PostOrder(root->_left);
	PostOrder(root->_right);
	printf("%d ", root->_data);
}

//二叉树总结点的个数
int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->_left) + TreeSize(root->_right) + 1;
}
//二叉树叶子结点的个数
int TreeLeafSize(BTNode* root)
{
	if (!root)
	{
		return 0;
	}
	else if (!(root->_left && root->_right))
	{
		return 1;
	}
	return TreeLeafSize(root->_left) + TreeLeafSize(root->_right);
}
//二叉树的高度
int Treeheight(BTNode* root)
{
	if (!root)
	{
		return 0;
	}
	return 	(int)fmax(Treeheight(root->_left), Treeheight(root->_right)) + 1;
}
// 二叉树第k层结点个数
int TreeLeveKSize(BTNode* root, int k)
{
	if (!root)
	{
		return 0;
	}
	else if (k == 1)
	{
		return 1;
	}
	else
	{
		return TreeLeveKSize(root->_left, k - 1) + TreeLeveKSize(root->_right, k - 1);
	}
}
// 二叉树查找值为x的结点
BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (!root)
	{
		return NULL;
	}
	if (root->_data == x)
	{
		return root;
	}
	BTNode* ret1 = TreeFind(root->_left, x);
	if (ret1)
	{
		return ret1;
	}
	//BTNode* ret2 = TreeFind(root->_right, x);
	//if (ret2)
	//{
	//	return ret2;
	//}
	//return NULL;
	return TreeFind(root->_right, x);
}
//二叉树的销毁
void TreeDestroy(BTNode* root)
{
	if (!root)
	{
		return;
	}
	TreeDestroy(root->_left);
	TreeDestroy(root->_right);
	free(root);
}
//二叉树的层序遍历(借助队列)
typedef BTNode* QDataType;
typedef struct QListNode//队列
{
	struct QListNode* next;
	QDataType val;
}QNode;
typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;
void QueueInit(Queue* pq)//队列初始化
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
void QueuePush(Queue* pq, QDataType x)//队尾入列
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (!newnode)
	{
		perror("malloc fail");
		exit(1);
	}
	newnode->val = x;
	newnode->next = NULL;
	if (pq->ptail == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}
void QueuePop(Queue* pq)//队头出列
{
	assert(pq && pq->size != 0);
	//Queue* next = pq->phead->next;
	//free(pq->phead);
	//pq->phead = next;
	//if (pq->phead == pq->ptail)
	//{
	//	pq->phead = pq->ptail = NULL;
	//}
	//pq->size--;
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	pq->size--;
}
QDataType QueueFront(Queue* pq)//访问队头元素
{
	assert(pq);
	return pq->phead->val;
}
bool QueueEmpty(Queue* pq)//判断队列是否为空
{
	assert(pq);
	return pq->size == 0;
}
void QueueDestroy(Queue* pq)//队列的销毁
{
	assert(pq);
	while (pq->phead)
	{
		QNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
void TreeLevelOrder(BTNode* root)//二叉树的层序遍历(借助队列)
{
	assert(root);
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%d ", front->_data);
		if (front->_left)
		{
			QueuePush(&q, front->_left);
		}
		if (front->_right)
		{
			QueuePush(&q, front->_right);
		}
	}
	QueueDestroy(&q);
}
//判断二叉树是否为完全二叉树(借助队列)
bool TreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (!front)
		{
			break;
		}
		QueuePush(&q, front->_left);
		QueuePush(&q, front->_right);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
}
int main()
{
	BTNode* ret = CreatBinaryTree();
	////printf("前序:>\n");
	////PrevOrder(ret);
	////printf("\n中序:>\n");
	////InOrder(ret);
	////printf("\n后序:>\n");
	////PostOrder(ret);
	//printf("TreeSize:%d", TreeSize(ret));//二叉树总结点的个数

	//printf("\n");

	//printf("TreeLeafSize:%d", TreeLeafSize(ret));//二叉树叶子结点的个数

	//printf("\n");

	//printf("Treeheight:%d", Treeheight(ret));//二叉树的高度

	//printf("\n");

	//int k = 0;
	//scanf("%d", &k);
	//printf("TreeLeve%dSize:%d", k, TreeLeveKSize(ret, k));//求二叉树的第k行的结点数

	//printf("\n");

	//BTNode* node = TreeFind(ret, 4);// 二叉树查找值为x的结点
	//printf("%d", node->_data);
	//TreeLevelOrder(ret); //二叉树的层序遍历(借助队列)
	int sum = TreeComplete(ret);
	printf("%d", sum);
	return 0;
}
