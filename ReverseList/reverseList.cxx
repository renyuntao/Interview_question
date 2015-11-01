#include<iostream>
#include<cassert>
using std::cout;
using std::endl;

struct ListNode
{
	int m_nValue;
	ListNode *m_pNext;
};


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
 * Reverse link list
 */
ListNode* ReverseList(ListNode *head)
{
	if(head == nullptr)
		return nullptr;
	ListNode *pCurr = head;
	ListNode *pPrev = nullptr;
	ListNode *pNext = head->m_pNext;
	head->m_pNext = nullptr;
	while(pNext != nullptr)
	{
		pPrev = pCurr;
		pCurr = pNext;
		pNext = pCurr->m_pNext;
		pCurr->m_pNext = pPrev;
	}
	return pCurr;
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
	ListNode *reverse = ReverseList(head);
	print(reverse);
	destroy(&reverse);
	return 0;
}
