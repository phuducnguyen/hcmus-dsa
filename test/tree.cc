#include <iostream>
#include <queue>

using namespace std;

struct NODE {
	int key;
	NODE *left;
	NODE *right;
};

NODE *createNode(int data)
{
	NODE *newNode = new NODE;
	newNode->key = data;
	newNode->left = NULL;
	newNode->right= NULL;
	return newNode;
}

void Insert(NODE *&pRoot, int x)
{
	if (!pRoot)
	{
		pRoot = createNode(x);
		return;
	}
	else if (pRoot->key > x)
	{
		return Insert(pRoot->left, x);
	}
	else if (pRoot->key < x)
	{
		return Insert(pRoot->right, x);
	}
}

void LNR(NODE *pRoot)
{
	if (pRoot != NULL)
	{
		LNR(pRoot->left);
		cout << pRoot->key << " ";
		LNR(pRoot->right);
	}
}

NODE *createTree(int a[], int n)
{
	NODE *pRoot = NULL;
	for (int i = 0; i < n; i++)
	{
		Insert(pRoot, a[i]);
	}
	return pRoot;
}

void LevelOrder(NODE* pRoot)
{
	queue<NODE*> q;
	
	q.push(pRoot);
	
	while (!q.empty())
	{
		NODE* currNode = q.front();
		cout << currNode->key << " ";
		q.pop();
		
		if (currNode->left)
		{
			q.push(currNode->left);
		}
		
		if (currNode->right)
		{
			q.push(currNode->right);
		}
	}
}

int Height(NODE* pRoot)
{
	if (!pRoot)
	{
		return 0;
	}
	
	return 1 + max(Height(pRoot->left), Height(pRoot->right));
}

int countNode(NODE* pRoot)
{
	if (!pRoot)
	{
		return 0;
	}
	
	return 1 + countNode(pRoot->left) + countNode(pRoot->right);
}

NODE* Search(NODE* pRoot, int x)
{
	if (pRoot == NULL)
		return pRoot;
	else if (pRoot->key == x)
		return pRoot;
	else if (pRoot->key > x)
		return Search(pRoot->left, x);
	else if (pRoot->key < x)
		return Search(pRoot->right, x);
  
  return pRoot;
}

NODE* findPredecessor(NODE* currNode)
{
	NODE* predecessor = currNode->left;
	
	while (predecessor->right)
	{
		predecessor = predecessor->right;
	}
	
	return predecessor;
}

void Remove(NODE* &pRoot, int x)
{
	if(pRoot->key > x)
	{
		Remove(pRoot->left, x);
	}
	else if(pRoot->key < x)
	{
		Remove(pRoot->right, x);
	}
	else if(pRoot->key == x)
	{
	
		if (!pRoot->left && !pRoot->right)
		{
			delete pRoot;
			pRoot = NULL;
		}
		else if (pRoot->left && pRoot->right)
		{
			NODE* predecessor = findPredecessor(pRoot);
			
			pRoot->key = predecessor->key;
			
			Remove(pRoot->left, predecessor->key);
		}
		else
		{
			NODE* deleteNode = pRoot;
			if (pRoot->left)
			{
				pRoot = pRoot->left;
			}
			else
			{
				pRoot = pRoot->right;
			}
			
			delete deleteNode;
			deleteNode = NULL;
		}
	}	
}

int heightNode(NODE* pRoot, int value)
{
	if (!pRoot)
		return -1;
	NODE* findNode = Search(pRoot, value);
	if (!findNode)
		return -1;
	return Height(findNode);
}

int Level(NODE* pRoot, NODE* p)
{
	int level = 0;
	
	NODE* currNode = pRoot;
	while (currNode)
	{
		if (currNode->key > p->key)
		{
			currNode = currNode->left;
			++level;
		}
		else if (currNode->key < p->key)
		{
			currNode = currNode->right;
			++level;
		}
		else
		{
			return level;
		}
	}
	
	return -1;
}
int countLeaf(NODE *pRoot){
	if (!pRoot) return 0;
	if (!pRoot->left && !pRoot->right) {
		return 1;
	}
	return countLeaf(pRoot->left)+countLeaf(pRoot->right);
}
int main()
{
	NODE *pRoot = NULL;
	int a[] = {8, 4, 9, 7, 12, 15, 1, 6, 10,-1};
	pRoot = createTree(a, 10);
	LNR(pRoot);
	cout << endl;
	
	LevelOrder(pRoot);
	cout << endl;
	cout << "Height: " << Height(pRoot) << endl;
	cout << "Number of node(s): " << countNode(pRoot) << endl;
//  NODE *tmp = Search(pRoot, 20);
//	cout << tmp->key;
	
	int height = heightNode(pRoot, 15);
	cout << height << endl;
	
	NODE* node = Search(pRoot, 8);
	cout << Level(pRoot, node) << endl;
	
	cout << countLeaf(pRoot) << "\n";
	return 0;
}
