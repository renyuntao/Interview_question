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
 * Merge tow sorted link list
 */
ListNode* mergeTwoLinkList(ListNode *head1,ListNode *head2)
{
	if(head1 == nullptr)
		return head2;
	else if(head2 == nullptr)
		return head1;

	if(head1->m_nValue <= head2->m_nValue)
		head1->m_pNext = mergeTwoLinkList(head1->m_pNext,head2);
	else
		head2->m_pNext = mergeTwoLinkList(head1,head2->m_pNext);
	if(head1->m_nValue <= head2->m_nValue)
		return head1;
	else
		return head2;
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
	ListNode *head1 = new ListNode;
	head1->m_nValue = 1;
	head1->m_pNext = nullptr;
	insertNode(head1,3);
	insertNode(head1,5);
	insertNode(head1,7);
	ListNode *head2 = new ListNode;
	head2->m_nValue = 2;
	head2->m_pNext = nullptr;
	insertNode(head2,4);
	insertNode(head2,6);
	insertNode(head2,8);
	ListNode *merge = mergeTwoLinkList(head1,head2);
	print(merge);
	destroy(&merge);
	return 0;
}
