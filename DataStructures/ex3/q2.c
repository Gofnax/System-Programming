#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef char DATA;

typedef struct node 
{
	char			value;
	struct node*	next;
}NODE;

typedef struct 
{
	NODE anchor;
}LIST;

LIST* L_sort(LIST* pList);
void L_init(LIST* pList);
NODE* L_insert(NODE* pNode, char Value);

LIST* L_sort(LIST* pList)
{
    LIST* pList2 = (LIST*)malloc(sizeof(LIST));
    L_init(pList2);
	NODE* pNode1 = pList->anchor.next;
    NODE* pNode2 = &pList2->anchor;

	int count_end = 0, max_start = 0, max_end = 0;

	while (pNode1 != NULL)
	{
		if ((65 <= pNode1->value && pNode1->value <= 90) || (97 <= pNode1->value && pNode1->value <= 122))
			count_end++;
		else if (pNode1->value == '*') 
		{
			count_end++;
			if (max_end < count_end)
			{
				max_start += max_end;
				max_end = count_end;
			}
			count_end = 0;
		}
		pNode1 = pNode1->next;
	}

	pNode1 = &pList->anchor;
	int s = max_start;

    for(int i = 0; i < max_start; i++)
    {
        pNode1 = pNode1->next;
    }

	while (max_start <= max_end + s)
	{
		
		L_insert(pNode2, pNode1->value);
		pNode1 = pNode1->next;	
        pNode2 = pNode2->next;
		max_start++;
	}

    return pList2;
}

void L_init(LIST* pList)
{
	if ( pList == NULL ) 	
		return;

	pList->anchor.next = NULL;
}

NODE* L_insert(NODE* pNode, char Value)
{
	NODE* tmp;

	if ( !pNode ) 
		return NULL;

	tmp = (NODE*)malloc(sizeof(NODE));	// new node

	if ( tmp != NULL )
    {
		tmp->value = Value;
		tmp->next = pNode->next;
		pNode->next = tmp;
	}
	return tmp;
}

void L_print(LIST* pList)
{
	if(pList == NULL)
		return;
	NODE* tmp = pList->anchor.next;
	while(tmp != NULL)
	{
		printf("%c ", tmp->value);
	}
	printf("\n");
}

int main(void)
{
	LIST l1;
	L_init(&l1);
	L_insert(&l1.anchor, '*');
	L_insert(&l1.anchor, 'a');
	L_insert(&l1.anchor, '*');
	L_insert(&l1.anchor, 'c');
	L_insert(&l1.anchor, 'b');
	L_insert(&l1.anchor, 'a');
	L_insert(&l1.anchor, '*');
	L_insert(&l1.anchor, 'b');
	L_insert(&l1.anchor, 'a');
	L_print(&l1);
	LIST* l2 = L_sort(&l1);
	L_print(l2);
}