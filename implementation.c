#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "definition.h"




SearchTree MakeEmpty (SearchTree T)//��һ������� 
{
	if(T!=null)
	{
		MakeEmpty(T->Left);//�ݹ�ʵ�� 
		MakeEmpty(T->Right);
		free(T);		
	}

}

/*Position Find(int X,SearchTree T)//����Ԫ��X��λ��
{
	if(T==null)
	{
		return null;
	}
	else if(X<T->Element)
			return Find(X,T->Left);
		else if(X>T->Element)
				return Find(X,T->Right);
			 else
			 	return T;		
} */ 
int FindMid(int X,SearchTree T)//����Ԫ��X��λ��
{
	int num=0;
	if(T==null)
	{
		//printf("���󣺶�����Ϊ��");
		return 0;
	}
	else
	{
		if(X<T->Element)
			 num = FindMid(X,T->Left);
		else if(X>T->Element)
				num = FindMid(X,T->Right)+FindMid(T->Element,T);
			 else
			 	num=Num(T->Left)+1;	
	} 	
	return num;	 	
} 

int FindPre(int X,SearchTree T)//����Ԫ��X���������λ��
{
	int num=0;
	if(T==null)
	{
		//printf("���󣺶�����Ϊ��");
		return 0;
	}
	else
	{
		if(X<T->Element)
			 num = FindPre(X,T->Left)+1;
		else if(X>T->Element)
				num = FindPre(X,T->Right)+Num(T->Left)+1;
			 else
			 	num=1;	
	} 	
	return num;	 	
}

Position FindMin(SearchTree T)//�ҵ����е���Сֵ��������λ��ָ��
{
	if(T==null)
	{
		printf("���󣺶�����Ϊ��");
		return null;
	}
	else if(T->Left==null)
			return T;
		else
			return FindMin(T->Left);
}

Position FindMax(SearchTree T)//�ҵ����е����ֵ��������λ��ָ��
{
	if(T==null)
	{
		printf("���󣺶�����Ϊ��");
		return null;
	}
	else if(T->Right==null)
			return T;
		else
			return FindMax(T->Right);
}
	
SearchTree Insert(int X,SearchTree T)//����
{
	int i=0,j=0;
	if(T==null)//���ҵ�����Ǹ����Բ����Ҷ�ӡ���Ҷ�ӵ���һ��������ɲ��� 
	{
		T=malloc(sizeof(struct TreeNode));
		if(T==null)
			printf("���������ڴ����������");
		else
		{
			T->Element=X;
			T->Left=T->Right=null;
			T->Height = 0; 
		}			
	}
	else
	 if(X<T->Element)//�ݹ�ʵ�� 
	{
		T->Left = Insert(X,T->Left);
		if(Height(T->Left)-Height(T->Right)==2)
			if(X<T->Left->Element)
				T=SingleRotateLeft(T);
			else
				T=DoubleRotateLeft(T);
	}		
	else if(X>T->Element)//�ݹ�ʵ�� 
	{
		T->Right = Insert(X,T->Right);
	   // i=Height(T->Right);
		
	//	j=Height(T->Left);
		if(Height(T->Right)-Height(T->Left)==2)
			if(X>T->Right->Element)
				T=SingleRotateRight(T);
			else
				T=DoubleRotateRight(T);
	}	
	
	T->Height=Max(Height(T->Left),Height(T->Right))+1;
	return T;		 	
}
	
/*SearchTree Delete(int X,SearchTree T)//ɾ��
{
	Position Tem;
	
	if(T==null)
		printf("����û��%dԪ��",X);
	else if(X<T->Element)
		{
			T->Left = Delete(X,T->Left);
			T->Height=Max(Height(T->Left),Height(T->Right))+1;
			if(Height(T->Right)-Height(T->Left)==2)
				if(T->Right->Right!=null)//��ʱҪ���ҵ����� 
					T=SingleRotateRight(T);
				else
					T=DoubleRotateRight(T);
		}
		
		 else if(X>T->Element)
			 {
			 	T->Right = Delete(X,T->Right);
			 	if(Height(T->Left)-Height(T->Right)==2)
				if(T->Left->Left!=null)
					T=SingleRotateLeft(T);
				else
					T=DoubleRotateLeft(T);
			 }
		 			 	  
		 	  else if(T->Left&&T->Right)//�����������T�����Ӻ��ӣ���һ����������� 
		 	  		{
		 	  			Tem = FindMin(T->Right);
		 	  			T = Tem;
						T->Right = Delete(Tem->Element,T->Right); 
						if(Height(T->Left)-Height(T->Right)==2)//�ж�ɾ��Ԫ�غ��Ƿ���Ҫ��ת������������ 
							if(X<T->Left->Element)
								T=SingleRotateLeft(T);
							else
								T=DoubleRotateLeft(T);
						
		 	  		}
		 	  		else //һ����������� �������������Ҫ�������С� 
		 	  		{
		 	  			Tem = T;
		 	  			if(T->Left==null)
		 	  				T=T->Right;
		 	  			else if(T->Right==null)
		 	  				T=T->Left;
		 	  			free(Tem);
		 	  		}
		if(T==null)
			T->Height=-1;
		else		
	   	    T->Height=Max(Height(T->Left),Height(T->Right))+1;
	   return T;
}*/
	
SearchTree Delete(int X,SearchTree T)//ɾ����Ҫ�����߶ȣ������ж�����̫�鷳�ˣ�����ɾ�����һ�飬Ȼ�����²���һ���OK 
{
	SearchTree ReOrderTree;
	Position Tem;
	
	if(T==null)
		printf("����û��%dԪ��",X);
	else if(X<T->Element)
		{
			T->Left = Delete(X,T->Left);
		}
		
		 else if(X>T->Element)
			 {
			 	T->Right = Delete(X,T->Right);
			 }
		 			 	  
		 	  else if(T->Left&&T->Right)//�����������T�����Ӻ��ӣ���һ����������� 
		 	  		{
		 	  			Tem = FindMin(T->Right);
		 	  			T = Tem;
						T->Right = Delete(Tem->Element,T->Right); 						
		 	  		}
		 	  		else //һ����������� �������������Ҫ�������С� 
		 	  		{
		 	  			Tem = T;
		 	  			if(T->Left==null)
		 	  				T=T->Right;
		 	  			else if(T->Right==null)
		 	  				T=T->Left;
		 	  			free(Tem);
		 	  		}	
	//	T->Height=Max(Height(T->Left),Height(T->Right))+1;
		Tree = null;
		ReOrder(T);
		ReOrderTree=Tree;
		Tree = null;
	   return ReOrderTree;
}	
	
int Height(Position P)//����AVL�ڵ�ĸ߶� 	
{
	if(P==null)
		return -1;
	else 
		return P->Height; 
} 
	
int Max(int T1,int T2)//�õ�������	
{
	return  (T1-T2>=0)?T1:T2;//��Ԫѡ�� 
}
	
void PrintMid(SearchTree T)//�����ӡ����
{
	if(T==null)
	{
		printf("��������Ϊ�գ�");
		return ;
	}
	
/*else
	{
		if(T->Left!=null)
			PrintMid(T->Left);
			
		printf(" %d ",T->Element );
		
		if(T->Right!=null)
			PrintMid(T->Right);
	}*/
	else if(T->Left!=null)
		  {
		  	PrintMid(T->Left);
		  }
		  printf(" %d ",T->Element );
		  if(T->Right!=null)
			PrintMid(T->Right);
		  
}	

void PrintPre(SearchTree T)//���������ӡ���� 
{
	
	if(T==null)
		printf("��������Ϊ�գ�");
	else
	{
		if(T->Left!=null)
			PrintPre(T->Left);		
		
		if(T->Right!=null)
			PrintPre(T->Right);
			
		printf(" %d ",T->Element );
		
	}
}	
	
	
 Position SingleRotateLeft(Position K2)//������ 
{
	Position K1;

	K1=K2->Left;
	K2->Left=K1->Right;
	K1->Right=K2;
	
	K2->Height=Max(Height(K2->Left),Height(K2->Right))+1;
	K1->Height=Max(Height(K1->Left),Height(K1->Right))+1;
	
	return K1;
	
}	

Position SingleRotateRight(Position K2)//�ҵ�����  
{
	Position K1;
	
	K1=K2->Right;
	K2->Right=K1->Left;
	K1->Left=K2;
	
	K2->Height=Max(Height(K2->Left),Height(K2->Right))+1;
	K1->Height=Max(Height(K1->Left),Height(K1->Right))+1;
	
	return K1;
	
}

Position DoubleRotateLeft(Position K3)//��˫���� 
{
	K3->Left= SingleRotateRight(K3->Left);
	
	return  SingleRotateLeft(K3);
}

Position DoubleRotateRight(Position K3)//��˫���� 
{
	K3->Left= SingleRotateLeft(K3->Right);
	
	return  SingleRotateLeft(K3);
}

void Print(SearchTree Tree)//��ӡ��������������+���� Ψһȷ�� 
{
	printf("����������������������ǣ�\n");
	PrintMid(Tree);
	printf("\n����������������������ǣ�\n");
	PrintPre(Tree); 
	printf("\n");
} 



void ReOrder(SearchTree T)//�Զ������������Ų� 
{	
	if(T==null)
	{
		return;
	}
		
	else
	{
		Tree = Insert(T->Element,Tree);//ͨ���ݹ�ѱ��ƻ��Ķ�������Ԫ�����²��뵽ȫ�ֱ���Tree 
		if(T->Left!=null)
			ReOrder(T->Left);
		if(T->Right!=null)
			ReOrder(T->Right);
	}
}

		
int Num(SearchTree T)//һ�����������ж��ٸ�Ԫ��	
{
	int sum=0;
//	number=0;
	if(T==null)
	{	
		return 0;
	}
	
/*else
	{
		if(T->Left!=null)
			PrintMid(T->Left);
			
		printf(" %d ",T->Element );
		
		if(T->Right!=null)
			PrintMid(T->Right);
	}*/
	else
	{
		if(T->Left!=null)
		  {
		  	//number+=Num(T->Left);
		  	sum+=Num(T->Left);
		  }
		  //number++;
		  sum++;
		  if(T->Right!=null)
			//number+=Num(T->Right);
			sum+=Num(T->Right);
	} 
	//sum=number;
//	number=0;
	return sum;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
