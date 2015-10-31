#include<iostream>
#include<cassert>
using std::cout;
using std::endl;

struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};

/*
 * Delete List Node
 */
void DeleteNode(ListNode **pListHead,ListNode *pToBeDeleted)
{
	assert(pListHead != nullptr && *pListHead != nullptr);

	// Only have one node
	if((*pListHead)->m_pNext == nullptr)
	{
		delete *pListHead;
		*pListHead = nullptr;
		pToBeDeleted = nullptr;
	}
	// PToBeDeleted is a tail node
	else if(pToBeDeleted->m_pNext == nullptr)
	{
		ListNode *tmp = *pListHead;
		while(tmp->m_pNext != pToBeDeleted)
			tmp = tmp->m_pNext;
		delete tmp->m_pNext;
		tmp->m_pNext = nullptr;
		pToBeDeleted = nullptr;
	}
	//normal situlation
	else
	{
		ListNode *tmp = pToBeDeleted->m_pNext;
		pToBeDeleted->m_nValue = tmp->m_nValue;
		pToBeDeleted->m_pNext = tmp->m_pNext;
		delete tmp;
		tmp = nullptr;
	}
}


void insertNode(ListNode *head,int value)
{
	ListNode *tmp = head;
	while(tmp->m_pNext != nullptr)
		tmp = tmp->m_pNext;
	tmp->m_pNext = new ListNode;
	tmp->m_pNext->m_nValue = value; 
	tmp->m_pNext->m_pNext = nullptr;
}

/*
 * Print List
 */
void print(ListNode *head)
{
	if(head == nullptr)
		return;
	do
	{
		cout<<head->m_nValue<<" ";
		head = head->m_pNext;
	}while(head != nullptr);
	cout<<endl;
}

/*
 * Destroy List
 */
void destroy(ListNode **head)
{
	if(head == nullptr || *head == nullptr)	
		return;
	do
	{
		ListNode *tmp = *head;
		*head = (*head)->m_pNext;
	}while(*head != nullptr);
}

int main()
{
	ListNode *head = new ListNode;
	head->m_nValue = 1;
	head->m_pNext = nullptr;
	insertNode(head,2);
	insertNode(head,3);
	insertNode(head,4);
	insertNode(head,5);
	print(head);
	DeleteNode(&head,head->m_pNext);
	print(head);
	destroy(&head);
	return 0;
}
