#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "InsertLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
// 공백 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void) {
linkedList_h* L;
L = (linkedList_h*)malloc(sizeof(linkedList_h));
L -> head = NULL; //공백 리스트 이므로 NULL로 설정
return L;
}

// 연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h(linkedList_h* L){
listNode* p;
while (L -> head != NULL) {
p = L -> head;
L -> head = L -> head -> link;
free(p);
p = NULL;
}
}

//연결 리스트를 순서대로 출력하는 연산
void printList(linkedList_h* L) {
listNode* p;
printf("L = (");
p = L -> head;
while (p != NULL) {
printf( "%s", p -> data);
p = p -> link;
if (p !=NULL) printf(", ");
}
printf(") \n");
}

void insertFirstNode(linkedList_h * L, char * x) {
        listNode*newNode;
        newNode = (listNode*)malloc(sizeof(listNode));
        strcpy(newNode -> data, x);
        newNode -> link = L -> head;
        L -> head = newNode;
}

void insertMiddleNode(linkedList_h*L, listNode *pre, char*x) {
        listNode*newNode;
        newNode = (listNode*)malloc(sizeof(listNode));
        strcpy(newNode -> data, x);
        if (L -> head == NULL) {
                newNode -> link = NULL;
                L -> head = newNode;
        }
        else if (pre == NULL) {
                newNode -> link = L -> head;
                        L -> head = newNode;
        }
        else{
                newNode -> link = pre -> link;
                pre -> link = newNode;
        }
}

void insertListNode(linkedList_h*L,char*x){
        listNode*newNode;
        listNode*temp;
        newNode = (listNode*)malloc(sizeof(listNode));
        strcpy(newNode -> data, x);
        newNode -> link = NULL;
        if (L -> head == NULL) {
                L -> head = newNode;
                return;
        }
        temp = L -> head;
        while (temp ->link !=NULL) temp = temp ->link;
        temp -> link = newNode;
}

void deleteNode(linkedList_h* L, listNode* p) {
	listNode* pre;
	if (L-> head == NULL) return;
	if (L-> head -> link == NULL) {
		free(L->head);
		L->head = NULL;
		return;
	}
	else if (p == NULL) return;
	else
	{
		pre = L->head;
		while(pre->link != p){
			pre = pre->link;
		}
		pre->link = p->link;
		free(p);
	}
}

listNode* searchNode(linkedList_h* L, char* x){
	listNode* temp;
	temp = L->head;
	while(temp != NULL)
	{
		if(!strcpy(temp->data, x)) return temp;
		temp = temp->link;
	}
	return temp;
}

void reverse (linkedList_h* L) {
	listNode* p;
	listNode* q;
	listNode* r;

	p = L -> head;
	q = NULL;
	r = NULL;

	while(p != NULL)
	{
		q = p;
		p = p->link;
		q->link = r;
		r = q;
	}
	L -> head = q;
}
