#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include "definition.h"
#include <conio.h>

int main(int argc, char *argv[]) {
	SearchTree Tree;
N:	Tree=null;
	int temp;
	int flag=0;//菜单选择项 
  printf("请输入数据，以-1结束:\n");
	scanf("%d",&temp);
	while(temp!=-1)
	{
		Tree = Insert(temp,Tree);
		scanf("%d",&temp);
		//if(temp<Tree->Element);				
	}
	
	/*while(1)
	{
		if(kbhit())
		{
			temp=getch();
			if(temp=="q")
				break;
			else
				Tree = Insert(temp,Tree);
		}
	}*/
	
	Print(Tree); 
	do
	{
		printf("\n菜单：1:插入，2：删除，3：修改，4：查询，5：从新输入，6：退出\n");
		scanf("%d",&flag);
		
		switch(flag)
		{
			case 1://插入 
					{
						printf("请输入要插入的数据，以-1结束:\n");
						scanf("%d",&temp);
						while(temp!=-1)
						{
							Tree = Insert(temp,Tree);
							scanf("%d",&temp);				
						}
						Print(Tree);
						break;
					}
				case 2:
					{
						printf("请输入要删除的数据，以-1结束:\n");
						scanf("%d",&temp);
						while(temp!=-1)
						{
							Tree = Delete(temp,Tree);
							scanf("%d",&temp);				
						}
						Print(Tree);
						break;
					}
				case 3:
					{
						printf("请输入要修改的数字：以-1结束\n");
						scanf("%d",&temp);
						while(temp!=-1)
						{
							Tree = Delete(temp,Tree);
							scanf("%d",&temp);				
						}
						printf("请输入要修给成的数据数据，以-1结束:\n");
						scanf("%d",&temp);
						while(temp!=-1)
						{
							Tree = Insert(temp,Tree);
							scanf("%d",&temp);				
						}
						Print(Tree);
						break;
					}
					case 4:
						{
							printf("请输入要查询的数字\n");
							scanf("%d",&temp);
							printf("%d是中序遍历的序号是：%d\n",temp,FindMid(temp,Tree));
							printf("%d是先序遍历的序号是：%d\n",temp,FindPre(temp,Tree));
							break;
						}
					case 5:
						{
							goto N;
							break;
						}
					case 6:
						exit(EXIT_SUCCESS);
		} 
	} while(flag!=6);

	return 0;
}

