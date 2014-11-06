#ifndef    __DEFINITION_H__
#define    __DEFINITION_H__
  //代码部分
#define null NULL
struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;

SearchTree MakeEmpty (SearchTree T);//建立空树
Position Find(int X,SearchTree T);//查找元素X的位置
Position FindMin(SearchTree T);//找到树中的最小值，并返回位置指针
Position FindMax(SearchTree T);//找到树中的最大值，并返回位置指针
SearchTree Insert(int X,SearchTree T);//插入
SearchTree Delete(int X,SearchTree T);//删除
int Height(Position P);//计算AVL节点的高度 
int Max(int T1,int T2);//得到最大深度 
int Retrieve(Position P);//

Position SingleRotateLeft(Position K2);//
Position SingleRotateRight(Position K2);//
Position DoubleRotateLeft(Position K3);//
Position DoubleRotateRight(Position K3);//
void PrintMid(SearchTree T);//中序遍历打印出来 
void PrintPre(SearchTree T);//先序遍历打印出来 

void Print(SearchTree Tree);//打印出二叉树，中序+先序 
void ReOrder(SearchTree T);

SearchTree  Tree;
struct TreeNode//树节点的定义 
{
	int Element;
	SearchTree Left;
	SearchTree Right;
	int Height; 
};


#endif



