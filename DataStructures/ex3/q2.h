#ifndef __Q2_H__
#define __Q2_H__

#include <stdlib.h>
#include <string.h>

typedef char DATA;

typedef struct node 
{
	DATA			value;
	struct node*	next;
}NODE;

typedef struct 
{
	NODE anchor;
}LIST;

LIST* L_sort(LIST* pList);
void L_init(LIST* pList);
NODE* L_insert(NODE* pNode, DATA Value);

#endif