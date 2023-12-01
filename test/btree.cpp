#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;

struct NODE{
	int key;
	NODE* left;
	NODE* right;
};

NODE* createNode(int data){
	NODE* newNode = new NODE;
	newNode->key = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void Insert(NODE* &pRoot, int x){
	if (pRoot == NULL){
		pRoot = createNode(x);
		return;
	}
	if (x < pRoot->key)
		Insert(pRoot->left, x);
	else if (x > pRoot->key)
		Insert(pRoot->right,x);
}

NODE* createTree(int a[], int n){
	NODE * pRoot = new NODE;
	pRoot = NULL;
	for (int i = 0; i < n; i++)
		Insert(pRoot, a[i]);
	return pRoot;
}

void NLR(NODE* pRoot){
	if(pRoot == NULL){
		return;
	}
	cout << pRoot->key <<" ";
	NLR(pRoot->left);
	NLR(pRoot->right);
}

void LNR(NODE* pRoot){
	if(pRoot == NULL){
		return;
	}
	LNR(pRoot->left);
	cout << pRoot->key <<" ";
	LNR(pRoot->right);
}
void LRN(NODE* pRoot){
	if(pRoot == NULL){
		return;
	}
	LRN(pRoot->left);
	LRN(pRoot->right);
	cout << pRoot->key <<" ";
}
void LevelOrder(NODE* root){
	if(root==NULL){
		return;
	}
	queue<NODE*>queue;
	queue.push(root);
	while(!queue.empty())
	{
		NODE* curr=queue.front();
		cout<< curr->key <<" ";
		if(curr->left){
			queue.push(curr->left);
		}
		if(curr->right){
			queue.push(curr->right);
		}
		queue.pop();
	}
}

int Height(NODE* root) {
	if (root == NULL) {
		return 0;
	}
	
	return max(Height(root->left), Height(root->right)) + 1;
}
int countNode(NODE*root)
{
	if(root==NULL)
		return 0;
		
	return 1 + countNode(root->left)+countNode(root->right);
}
int sumNode(NODE* root){
	if (root == NULL)
		return 0;
	return sumNode(root->left) + sumNode(root->right) + root->key;
}
NODE* Search(NODE* root,int key)
{
	if(!root) return NULL;
	NODE* tmp = root;
	while(tmp)
	{
		if(key < tmp->key) tmp = tmp->left;
		else if(key > tmp->key) tmp = tmp->right;
		else return tmp;
	}
	return NULL;
}

NODE* findMin(NODE* root)
{
	if (root == NULL)
		return NULL;
	else if (root->left == NULL)
		return root;
	else return findMin(root->left);
}

void Remove(NODE*& root, int x)
{
	if (root == NULL)
		return;
	else if (x < root->key)
		Remove(root->left, x);
	else if (x > root->key)
		Remove(root->right, x);
	else
	{
		if (root->left == NULL)
		{
			NODE* tmp = root;
			root = root->right;
			delete tmp;
		}
		else if (root->right == NULL)
		{
			NODE* tmp = root;
			root = root->left;
			delete tmp;
		}
		else
		{
			NODE* minRight = findMin(root->right);
			root->key = minRight->key;
			Remove(root->right, minRight->key);
		}
	}
}
void removeTree(NODE *&pRoot)
{
	if (pRoot == NULL)
		return;
	if (pRoot->left != NULL) removeTree(pRoot->left);
	if (pRoot->right !=NULL) removeTree(pRoot->right);
	NODE* temp = pRoot;
	pRoot = NULL;
	delete temp;
}

int heightNode(NODE *pRoot, int value) {
	if (pRoot == NULL)
		return -1;
	else if (pRoot->key > value) return heightNode(pRoot->left, value);
	else if (pRoot->key < value) return heightNode(pRoot->right, value);
	else {
		if (pRoot->left == NULL && pRoot->right == NULL) return 1;
		int l = 0, r = 0;
		if (pRoot->left != NULL) l = heightNode(pRoot->left, pRoot->left->key);
		if (pRoot->right != NULL) r = heightNode(pRoot->right, pRoot->right->key);
		return (l>r? l:r) + 1;
	}
}
//15
int Level(NODE *pRoot, NODE *p)
{
	if (pRoot == NULL)
	{
		return 0;
	}
	else
	{
		if (pRoot->key > p->key)
		{
			return 1 + Level(pRoot -> left, p);
		}
		else if (pRoot -> key < p -> key)
		{
			return 1 + Level(pRoot -> right, p);
		}
		else
		{
			return 0;
		}
	}
}

int count_leaf(NODE *pRoot){
	if (pRoot == NULL){
		return 0;
	}
	else if (!pRoot->left && !pRoot->right){
		return 1; 
	}
	else {
		return count_leaf(pRoot->left) + count_leaf(pRoot->right);
	}
}
int countLess(NODE* root, int x){
	queue<NODE*> q;
	int cnt=0;
	q.push(root);
	while(!q.empty()){
		NODE* tmp=q.front();
		q.pop();
		if(tmp==NULL) continue;
		if(tmp->key<x) cnt++;
		q.push(tmp->left);
		q.push(tmp->right);
	}
	return cnt;
}
bool isCorrectNode( NODE* pRoot, int MaxValue, int MinValue)
{
	if (pRoot == NULL) return true;
	if (pRoot->key > MaxValue || pRoot->key < MinValue)
		return false;
	return isCorrectNode (pRoot->left, pRoot->key - 1, MinValue) && isCorrectNode (pRoot->right, MaxValue, pRoot->key + 1); 
	
}
bool isBST (NODE* pRoot)
{
	int MAX = 1e9;
	int MIN = -1e9;
	return isCorrectNode(pRoot, MAX, MIN);
}
void GetVectorInorder(NODE *Root, vector<int> &ans)
{
	if(Root == NULL)
		return;
	GetVectorInorder(Root->left, ans);
	ans.push_back(Root->key);
	GetVectorInorder(Root->right, ans);
}
bool isBST2(NODE *Root)
{
	vector<int> ans;
	GetVectorInorder(Root,ans);
	
	for(int i = 1; i < ans.size(); i++)
	{
		if(ans[i - 1] >= ans[i])
			return false;
	}
	return true;
}

bool isFullBST(NODE* pRoot){
	if(!pRoot)
		return 1;
	if(!pRoot->left && !pRoot->right)
		return 1;
	if((pRoot->left && !pRoot->right) || (!pRoot->left && pRoot->right))
		return 0;
	if(pRoot->left && pRoot->right)
		return isBST(pRoot) && isFullBST(pRoot->left) && isFullBST(pRoot->right);
}
int main(){
	int a[] = {6,4,9,2,5,11};
	NODE *pRoot = createTree(a, 6);
//	LevelOrder(pRoot);
	//cout << sumNode(pRoot);
//	if(Search(pRoot,7))
//		cout << "Found\n";
//	else cout <<"Not found\n";
	//NLR(pRoot);
//	NODE *search = Search(pRoot, 5);
//	cout << countLess(pRoot,7) << endl;
//	removeTree(pRoot);
//	LevelOrder(pRoot);
	NODE* temp = Search(pRoot,9);
	temp->left = createNode(7);
	if (isBST2(pRoot)) cout << "is BST\n";
	else cout << "is not BST\n";
}


