#include "q2.h"

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

NODE* L_insert(NODE* pNode, DATA Value)
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
