#include <stdio.h>
#include <stdlib.h> 
#include <math.h>
#include "definition.h"
#include <conio.h>

int main(int argc, char *argv[]) {
	SearchTree Tree;
N:	Tree=null;
	int temp;
	int flag=0;//�˵�ѡ���� 
  printf("���������ݣ���-1����:\n");
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
		printf("\n�˵���1:���룬2��ɾ����3���޸ģ�4����ѯ��5���������룬6���˳�\n");
		scanf("%d",&flag);
		
		switch(flag)
		{
			case 1://���� 
					{
						printf("������Ҫ��������ݣ���-1����:\n");
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
						printf("������Ҫɾ�������ݣ���-1����:\n");
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
						printf("������Ҫ�޸ĵ����֣���-1����\n");
						scanf("%d",&temp);
						while(temp!=-1)
						{
							Tree = Delete(temp,Tree);
							scanf("%d",&temp);				
						}
						printf("������Ҫ�޸��ɵ��������ݣ���-1����:\n");
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
							printf("������Ҫ��ѯ������\n");
							scanf("%d",&temp);
							printf("%d���������������ǣ�%d\n",temp,FindMid(temp,Tree));
							printf("%d���������������ǣ�%d\n",temp,FindPre(temp,Tree));
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

