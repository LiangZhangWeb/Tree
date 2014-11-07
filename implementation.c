#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "definition.h"




SearchTree MakeEmpty (SearchTree T)//把一棵树清空 
{
	if(T!=null)
	{
		MakeEmpty(T->Left);//递归实现 
		MakeEmpty(T->Right);
		free(T);		
	}

}

/*Position Find(int X,SearchTree T)//查找元素X的位置
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
int FindMid(int X,SearchTree T)//查找元素X的位置
{
	int num=0;
	if(T==null)
	{
		//printf("错误：二叉树为空");
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

int FindPre(int X,SearchTree T)//查找元素X的先序遍历位置
{
	int num=0;
	if(T==null)
	{
		//printf("错误：二叉树为空");
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

Position FindMin(SearchTree T)//找到树中的最小值，并返回位置指针
{
	if(T==null)
	{
		printf("错误：二叉树为空");
		return null;
	}
	else if(T->Left==null)
			return T;
		else
			return FindMin(T->Left);
}

Position FindMax(SearchTree T)//找到树中的最大值，并返回位置指针
{
	if(T==null)
	{
		printf("错误：二叉树为空");
		return null;
	}
	else if(T->Right==null)
			return T;
		else
			return FindMax(T->Right);
}
	
SearchTree Insert(int X,SearchTree T)//插入
{
	int i=0,j=0;
	if(T==null)//当找到最后那个可以插入的叶子、或叶子的上一级即可完成插入 
	{
		T=malloc(sizeof(struct TreeNode));
		if(T==null)
			printf("致命错误，内存溢出！！！");
		else
		{
			T->Element=X;
			T->Left=T->Right=null;
			T->Height = 0; 
		}			
	}
	else
	 if(X<T->Element)//递归实现 
	{
		T->Left = Insert(X,T->Left);
		if(Height(T->Left)-Height(T->Right)==2)
			if(X<T->Left->Element)
				T=SingleRotateLeft(T);
			else
				T=DoubleRotateLeft(T);
	}		
	else if(X>T->Element)//递归实现 
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
	
/*SearchTree Delete(int X,SearchTree T)//删除
{
	Position Tem;
	
	if(T==null)
		printf("树中没有%d元素",X);
	else if(X<T->Element)
		{
			T->Left = Delete(X,T->Left);
			T->Height=Max(Height(T->Left),Height(T->Right))+1;
			if(Height(T->Right)-Height(T->Left)==2)
				if(T->Right->Right!=null)//此时要用右单螺旋 
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
		 			 	  
		 	  else if(T->Left&&T->Right)//分两种情况：T有两子孩子，有一个或零个孩子 
		 	  		{
		 	  			Tem = FindMin(T->Right);
		 	  			T = Tem;
						T->Right = Delete(Tem->Element,T->Right); 
						if(Height(T->Left)-Height(T->Right)==2)//判断删除元素后是否需要旋转进行重新排列 
							if(X<T->Left->Element)
								T=SingleRotateLeft(T);
							else
								T=DoubleRotateLeft(T);
						
		 	  		}
		 	  		else //一个或零个孩子 ，这种情况不需要重新排列。 
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
	
SearchTree Delete(int X,SearchTree T)//删除后要调整高度，各种判断条件太麻烦了，所以删完遍历一遍，然后重新插入一遍就OK 
{
	SearchTree ReOrderTree;
	Position Tem;
	
	if(T==null)
		printf("树中没有%d元素",X);
	else if(X<T->Element)
		{
			T->Left = Delete(X,T->Left);
		}
		
		 else if(X>T->Element)
			 {
			 	T->Right = Delete(X,T->Right);
			 }
		 			 	  
		 	  else if(T->Left&&T->Right)//分两种情况：T有两子孩子，有一个或零个孩子 
		 	  		{
		 	  			Tem = FindMin(T->Right);
		 	  			T = Tem;
						T->Right = Delete(Tem->Element,T->Right); 						
		 	  		}
		 	  		else //一个或零个孩子 ，这种情况不需要重新排列。 
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
	
int Height(Position P)//计算AVL节点的高度 	
{
	if(P==null)
		return -1;
	else 
		return P->Height; 
} 
	
int Max(int T1,int T2)//得到最大深度	
{
	return  (T1-T2>=0)?T1:T2;//三元选择 
}
	
void PrintMid(SearchTree T)//中序打印出来
{
	if(T==null)
	{
		printf("错误，链表为空！");
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

void PrintPre(SearchTree T)//先序遍历打印出来 
{
	
	if(T==null)
		printf("错误，链表为空！");
	else
	{
		if(T->Left!=null)
			PrintPre(T->Left);		
		
		if(T->Right!=null)
			PrintPre(T->Right);
			
		printf(" %d ",T->Element );
		
	}
}	
	
	
 Position SingleRotateLeft(Position K2)//左单螺旋 
{
	Position K1;

	K1=K2->Left;
	K2->Left=K1->Right;
	K1->Right=K2;
	
	K2->Height=Max(Height(K2->Left),Height(K2->Right))+1;
	K1->Height=Max(Height(K1->Left),Height(K1->Right))+1;
	
	return K1;
	
}	

Position SingleRotateRight(Position K2)//右单螺旋  
{
	Position K1;
	
	K1=K2->Right;
	K2->Right=K1->Left;
	K1->Left=K2;
	
	K2->Height=Max(Height(K2->Left),Height(K2->Right))+1;
	K1->Height=Max(Height(K1->Left),Height(K1->Right))+1;
	
	return K1;
	
}

Position DoubleRotateLeft(Position K3)//左双螺旋 
{
	K3->Left= SingleRotateRight(K3->Left);
	
	return  SingleRotateLeft(K3);
}

Position DoubleRotateRight(Position K3)//右双螺旋 
{
	K3->Left= SingleRotateLeft(K3->Right);
	
	return  SingleRotateLeft(K3);
}

void Print(SearchTree Tree)//打印出二叉树，中序+先序 唯一确定 
{
	printf("这个二叉树的中序遍历结果是：\n");
	PrintMid(Tree);
	printf("\n这个二叉树的先序遍历结果是：\n");
	PrintPre(Tree); 
	printf("\n");
} 



void ReOrder(SearchTree T)//对二叉树的重新排布 
{	
	if(T==null)
	{
		return;
	}
		
	else
	{
		Tree = Insert(T->Element,Tree);//通过递归把被破坏的二叉树的元素重新插入到全局变量Tree 
		if(T->Left!=null)
			ReOrder(T->Left);
		if(T->Right!=null)
			ReOrder(T->Right);
	}
}

		
int Num(SearchTree T)//一个二叉树中有多少个元素	
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
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
