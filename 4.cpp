# define _CRT_SECURE_NO_WARNINGS//������������ʹ��scanf�Ⱥ�����Ϊ�䲻��ȫ������˺�ɽ��ô���;�����ʾ
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
typedef struct student     //����ṹ��
{
	//������
	char name[20];    //����
	char num[15];      //ѧ��
	char sex[10];     //�Ա�
	char from[20];    //����
	char political[10];    //������ò
	char phone[15];      //�ֻ���,
	char QQ[15];         //QQ��,
	char dorm[10];     //����, 
	//ָ����
	struct student *next; 
}stu;
stu *head;//����ͷ���

void screen();	//�������ҳ��
void print();	   //���˵�
void input(stu *p1);	//�������루�����ã�
stu *inputdata();	 //��������ĺ���
stu *lookdata(stu *p1); //������ݵĺ���
void insert();			//��������
void deleted();			//ɾ�����ݺ���
void find(stu *p2);		//ͨ��������������
void update(stu *p2);	//ͨ���������Ҳ��޸�����
void save(stu *p2);		//�����������ⲿ�ļ�

int main()//������
{
	int i;
	screen();
	while(1)
	{
		print();
		printf("���������ѡ��(1~9):");
		scanf("%d",&i);
		system("cls");
		switch(i)
		{
		case 1:
			inputdata();
			break;
		case 2:
			lookdata(head);
			break;
		case 3:
			insert();
			break;
		case 4:
			deleted();
			break;
		case 5:
			find(head);
			break;
		case 6:
			update(head);
			break;
		case 7:
			save(head);
			break;
		case 8:
			print();
			break;
		case 9:
			exit(1);
			break;
		}
	}
	system("cls");
}


void print()//���˵�
{
	system("cls");//����
	printf("\n\n\n");
	printf("      -----------------------------------------------------------\n\n");
	printf("      \t\t\t�༶ͨѶ¼����ϵͳ\n");
	printf("\n");
	printf("      \t\t1. ��������");
	printf("\t\t2. ��ʾ����\n");
	printf("      \t\t3. ��������");
	printf("\t\t4. ɾ������\n");
	printf("      \t\t5. �鿴����");
	printf("\t\t6. �޸�����\n");
	printf("      \t\t7. ��������");
	printf("\t\t8. �������˵�\n");
	printf("      -----------------------------------------------------------\n");
	printf("      \t\t��\t��\t��\t��\t9     \n");
	printf("      -----------------------------------------------------------\n\n");
}
 
 
void input(stu *p1)//�������루�����ã�
{
	printf("����:");
	scanf("%s",p1->name);
	printf("ѧ��:");
	scanf("%s",p1->num);
	printf("�Ա�:");
	scanf("%s",p1->sex);
	printf("����:");
	scanf("%s",p1->from);
	printf("������ò:");
	scanf("%s",p1->political);
	printf("�ֻ���:");
	scanf("%s",p1->phone);
	printf("QQ��:");
	scanf("%s",p1->QQ);
	printf("����:");
	scanf("%s",p1->dorm);
}
stu * inputdata()//��������ĺ���
{
	stu *p1,*p2;
	int i=1;
	p1=(stu *)malloc(sizeof(stu));
	if(p1!=NULL)
	{
		head=p1;
		printf("\n\t\t\t����������\n");
		printf("ps�������������롰ok�������������ݽ���\n");
		while(i)
		{
			printf("����:");
			scanf("%s",p1->name);
			if(strcmp(p1->name,"ok")==0)//�˳�
			{
				printf("\n�������!\n");
				printf("========================================================================\n");
				i=0;
				p2->next=NULL;
				free(p1);
				p1=p2;
			}
			else//��������洢����
			{
				printf("ѧ��:");
				scanf("%s",p1->num);
				printf("�Ա�:");
				scanf("%s",p1->sex);
				printf("����:");
				scanf("%s",p1->from);
				printf("������ò:");
				scanf("%s",p1->political);
				printf("�ֻ���:");
				scanf("%s",p1->phone);
				printf("QQ��:");
				scanf("%s",p1->QQ);
				printf("����:");
				scanf("%s",p1->dorm);
				printf("=====================================\n");
				p2=p1;
				p1=(stu *)malloc(sizeof(stu));
				if(p1!=NULL)
				{
					p2->next=p1;
				}
			}
		}
		return(p1->next);
	}
}
stu * lookdata(stu *p1)//�鿴���ݵĺ���
{
	printf("\n\t\t\t��ʾ����\n");
	printf("----------------------------------------------------------------------\n");
	while(p1!=NULL)
	{
		printf("����:%s\n",p1->name);
		printf("ѧ��:%s\t",p1->num);
		printf("�Ա�:%s\t",p1->sex);
		printf("����:%s\t",p1->from);
		printf("������ò:%s\t",p1->political);
		printf("�ֻ���:%s\t",p1->phone);
		printf("QQ��:%s\t",p1->QQ);
		printf("����:%s\n",p1->dorm);
		printf("======================================================================\n");
	p1=p1->next;
	}
	system("pause");
	return p1;
}


void insert()//��������
{
    int i;
    char named[20];
    stu *p1,*p2,*p3;
    p1=head;
    p3=(stu *)malloc(sizeof(stu));
    p3->next=NULL;
    printf("\n\t\t\t��������\n");
	printf("���������������:\n");
	input(p3);//�����������뺯��
	printf("\n����ѡ��\n");
	printf("1.��λ�ò���\t2.βλ�ò���\n");
	printf("���������ѡ��:");
	scanf("%d",&i);
	switch(i)
	{
	case 1://ͷ��
		{
			p3->next=p1;
			head=p3;
			break;
		}
		
	case 2://β��
		{
			while(p1->next!=NULL)
			{
				p2=p1;
				p1=p1->next;
			}
			p1->next=p3;
			break;
		}
	}
	printf("����ɹ�!\n");
	system("pause");
}
 
void deleted() //ɾ�����ݺ���
{
	stu *p1,*p2;
	char Name[20];//��Ҫɾ�����˵�����
	printf("\n\t\t\tɾ������\n");
	printf("������Ҫɾ��������:");
	scanf("%s",Name);
	p1=head;
	//��һ���������ɾ�����Ϊͷ��㣬ֻ��headָ��ڶ�����㼴��
	if(strcmp(Name,p1->name)==0)
	{
		head=p1->next;
		printf("ɾ���ɹ�!\n");
		system("pause");
		return;
	}
	//������ͷ��㣬ѭ�����������ҳ���ɾ���Ľ��
	while(p1!=NULL&&(strcmp(Name,p1->name)!=0))
	{
		p2=p1;
		p1=p1->next;
	}
	//�жϽڵ��Ƿ������������
	if(p1==NULL)
	{
		printf("���˲�����!\n");
		system("pause");
		return;
	}
	//�������жϱ�ɾ������Ƿ�Ϊβ���
	if(p1->next!=NULL)
	{
		p1=p1->next;
		p2->next=p1;
		printf("ɾ���ɹ�!\n");
		system("pause");
		return;
	}
	else
	{
		p2->next=NULL;
		printf("ɾ���ɹ�!\n");
		system("pause");
		return;
	}
}

 
void find(stu *p2)//ͨ�������鿴����
{
	char name[20];
	int b=0;//flag
	printf("\n\t\t\t�鿴����\n");
	printf("��������������˵�����:");
	scanf("%s",name);
	while(p2!=NULL)
	{
		if(strcmp(name,p2->name)==0)
		{
			printf("��Ҫ�ҵ�������\n");
			printf("����:%s\n",p2->name);
			printf("ѧ��:%s\t",p2->num);
			printf("�Ա�:%s\t",p2->sex);
			printf("����:%s\t",p2->from);
			printf("������ò:%s\t",p2->political);
			printf("�ֻ���:%s\t",p2->phone);
			printf("QQ��:%s\t",p2->QQ);
			printf("����:%s\n",p2->dorm);
			b=1;
		}
		p2=p2->next;
	}
	if(b==0)
	{
		printf("\n��Ҫ���ҵ��˲�����!\n");
	}
	system("pause");
}
 
 
void update(stu *p2)   //ͨ�����������޸�����
{
	char name[20];
	int b=0,i;
	printf("\n\t\t\t�޸�����\n");
	printf("�����뽫Ҫ�޸��˵�����:");
	scanf("%s",name);
	while(p2!=NULL)
	{
		if(strcmp(name,p2->name)==0)
		{
			printf("��ͬѧ�Ļ�����Ϣ\n");
			printf("����:%s\n",p2->name);
			printf("ѧ��:%s\t",p2->num);
			printf("�Ա�:%s\t",p2->sex);
			printf("����:%s\t",p2->from);
			printf("������ò:%s\t",p2->political);
			printf("�ֻ���:%s\t",p2->phone);
			printf("QQ��:%s\t",p2->QQ);
			printf("����:%s\n",p2->dorm);
			printf("\n��ѡ��Ҫ�޸ĵ���Ϣ\n");
			printf("\t1.����\t2.ѧ��\t3.�Ա�\t4.����\n\t5.������ò\t6.�ֻ���\t7.QQ\t8.����\n");
			printf("\n����ѡ����(1~8):");
			scanf("%d",&i);
			printf("�������޸�֮�������\n");
			switch(i)
			{
			case 1:
				printf("����:");
				scanf("%s",p2->name);
				break;
			case 2:
				printf("ѧ��:");
				scanf("%s",p2->num);
				break;
			case 3:
				printf("�Ա�:");
				scanf("%s",p2->sex);
				break;
			case 4:
				printf("����:");
				scanf("%s",p2->from);
				break;
			case 5:
				printf("������ò:");
				scanf("%s",p2->political);
				break;
			case 6:
				printf("�ֻ���:");
				scanf("%s",p2->phone);
				break;
			case 7:
				printf("QQ:");
				scanf("%s",p2->QQ);
				break;
			case 8:
				printf("����:");
				scanf("%d",p2->dorm);
				break;
			}
			printf("\n�޸ĳɹ�!\n");
			b=1;
		}
		p2=p2->next;
	}
	if(b==0)
	{
		printf("û���ҵ����˵�����!\n");
	}
	system("pause");
}
 
 
void save(stu *p2)//��������
{
	FILE *fp;
	char file[15];
	printf("\n\t\t\t��������\n");
    printf("�����ļ���:");
    scanf("%s",file);
    if((fp=fopen(file,"w"))==NULL)
    {
        printf("���ļ�ʧ��\n");
		system("pause");
		exit(0);
    }
    fprintf(fp,"����\tѧ��\t�Ա�\t����\t������ò\t�ֻ���\tQQ��\t����\n");
    while(p2!=NULL)
    {
        fprintf(fp,"%s\t",p2->name);
        fprintf(fp,"%s\t",p2->num);
        fprintf(fp,"%s\t",p2->sex);
        fprintf(fp,"%s\t",p2->from);
        fprintf(fp,"%s\t",p2->political);
        fprintf(fp,"%s\t",p2->phone);
        fprintf(fp,"%s\t",p2->QQ);
        fprintf(fp,"%s\n",p2->dorm);
        p2=p2->next;
    }
    printf("\n����ɹ�!\n");;
    fclose(fp);
	system("pause");
}
 
 
void screen()  
{
	int i;
	char s[251]={"��ӭʹ�������ȿ�������ͨѶ¼����ϵͳ��\n\n\t\t\t\t��ϵͳ����ͨѶ¼����\n\n\n\t\t\tWelcome to use address book produced by zyj\n\n\t\t\t\t management system"};
		
	printf("\n================================================================================\n");
	printf("\n\n\n\t\t\t");
	for(i=0;s[i]!=NULL;i++)
	{
		Sleep(30);//sleep�������ó������һ��ʱ�䣬�˴����ڿ������s�����ݵļ��ʱ�䣬Windows��������ʱ��Ϊ����linux��λ��
		printf("%c",s[i]);
	}
	printf("\n\n\n\t\t\t ~ ����bug�����~ o(*������*)��~ ~ ~ ~\n");
	printf("================================================================================\n");
	system("pause");
}
 
 


