#ifndef    __DEFINITION_H__
#define    __DEFINITION_H__
  //���벿��
#define null NULL
struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;

SearchTree MakeEmpty (SearchTree T);//��������
Position Find(int X,SearchTree T);//����Ԫ��X��λ��
Position FindMin(SearchTree T);//�ҵ����е���Сֵ��������λ��ָ��
Position FindMax(SearchTree T);//�ҵ����е����ֵ��������λ��ָ��
SearchTree Insert(int X,SearchTree T);//����
SearchTree Delete(int X,SearchTree T);//ɾ��
int Height(Position P);//����AVL�ڵ�ĸ߶� 
int Max(int T1,int T2);//�õ������� 
int Retrieve(Position P);//

Position SingleRotateLeft(Position K2);//
Position SingleRotateRight(Position K2);//
Position DoubleRotateLeft(Position K3);//
Position DoubleRotateRight(Position K3);//
void PrintMid(SearchTree T);//���������ӡ���� 
void PrintPre(SearchTree T);//���������ӡ���� 

void Print(SearchTree Tree);//��ӡ��������������+���� 
void ReOrder(SearchTree T);

SearchTree  Tree;
struct TreeNode//���ڵ�Ķ��� 
{
	int Element;
	SearchTree Left;
	SearchTree Right;
	int Height; 
};


#endif



