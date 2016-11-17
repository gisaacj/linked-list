/*********************************************************** 
题目要求:
初始化单链表list;
依次采用尾插法插入a、b、c、d、e元素;
输出单链表; 
输出单链表的长度;
判断单链表是否为空;
输出单链表的第三个元素;
输出元素'a'的位置;
在第四个元素位置上插入'f'元素;
输出单链表;
删除单链表上第三个元素;
输出单链表;
释放单链表; 
************************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct List{
	char var;
	struct List *next;
}List;

List *CreateList(List * L,int n);				//创建链表 
void DestoryList(List * L);						//摧毁链表 
int ListEmpty(List * L);						//判断表是否为空 
int ListLength(List * L);						//得到表的长度 
char GetElem(List * L,int pos);					//得到指定位置表的元素 
int GetPos(List * L,char elem);					//得到指定元素的表的位置
void ListInsert(List * L,int pos,char elem);	//在指定位置插入新元素
void ListDelete(List * L,int pos);				//删除指定位置的元素 
void PrintList(List * L);						//打印整个链表 

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
