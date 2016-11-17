/*********************************************************** 
��ĿҪ��:
��ʼ��������list;
���β���β�巨����a��b��c��d��eԪ��;
���������; 
���������ĳ���;
�жϵ������Ƿ�Ϊ��;
���������ĵ�����Ԫ��;
���Ԫ��'a'��λ��;
�ڵ��ĸ�Ԫ��λ���ϲ���'f'Ԫ��;
���������;
ɾ���������ϵ�����Ԫ��;
���������;
�ͷŵ�����; 
************************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct List{
	char var;
	struct List *next;
}List;

List *CreateList(List * L,int n);				//�������� 
void DestoryList(List * L);						//�ݻ����� 
int ListEmpty(List * L);						//�жϱ��Ƿ�Ϊ�� 
int ListLength(List * L);						//�õ���ĳ��� 
char GetElem(List * L,int pos);					//�õ�ָ��λ�ñ��Ԫ�� 
int GetPos(List * L,char elem);					//�õ�ָ��Ԫ�صı��λ��
void ListInsert(List * L,int pos,char elem);	//��ָ��λ�ò�����Ԫ��
void ListDelete(List * L,int pos);				//ɾ��ָ��λ�õ�Ԫ�� 
void PrintList(List * L);						//��ӡ�������� 

List *CreateList(List * L,int n){
	List *p,*q;
	L = (List*)malloc(sizeof(List));
	int i;
	p = L;
	for(i = 0;i<n;i++){
		q=(List *)malloc(sizeof(List));
		q->var = (char)(97+i);
		p->next = q;
		p = q;
	}
	p->next = NULL;
	return L;
}

void DestoryList(List * L){
	free(L);
}

int ListEmpty(List * L){
	return NULL == ListEmpty;
}

int ListLength(List * L){
	int length=0;
	while(L->next!=NULL){
		L = L->next;
		length++;
	}
	return length;
}

char GetElem(List * L,int pos){
	int i;
	for(i=0;i<pos;i++)
		L = L->next;
	return L->var;
}

int GetPos(List * L,char elem){
	int i;
	for(i=0;i<ListLength(L);i++){
		L = L->next;
		if(elem==L->var)
			return i+1;
	}
	return -1;
}

void ListInsert(List * L,int pos,char elem){
	List *p;
	int i;
	for(i=0;i<pos;i++)
		L = L->next;
	p=(List*)malloc(sizeof(List));
	p->var = elem;
	p->next = L->next;
	L->next = p;
}

void ListDelete(List * L,int pos){
	int i;
	List *p;
	for(i=0;i<pos-1;i++)
		L=L->next;
	p = L->next;
	L->next = L->next->next;
	free(p);
	p=NULL;
} 

void PrintList(List * L){
	int i;
	while(L->next!=NULL){
		L=L->next;
		printf("%c",L->var);
	}
	printf("\n");
}

main(){
	List *list;
	list = CreateList(list,5);
	PrintList(list);
	printf("%d\n",ListLength(list));
	if(ListEmpty)
		printf("not empty.\n");
	else
		printf("empty.\n");
	printf("%c\n",GetElem(list,3));
	printf("%d\n",GetPos(list,'a'));
	ListInsert(list,4,'f');
	PrintList(list);
	ListDelete(list,3);
	PrintList(list);
	DestoryList(list);
} 
