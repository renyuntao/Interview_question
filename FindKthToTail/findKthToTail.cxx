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
 * Find K-th To Tail with traversal link list only once.
 */
ListNode* FindKthToTail(ListNode* head,unsigned int k)
{
	if(head == nullptr || k <= 0)
		return nullptr;
	ListNode *first = head;
	ListNode *second = head;
	bool secondGo = false;
	unsigned int counter = 0;
	while(first->m_pNext != nullptr)
	{
		if(!secondGo)
		{
			first = first->m_pNext;
			if((++counter) >= k-1)
			{
				secondGo = true;
				if(counter > k-1)
					second = second->m_pNext;
			}
		}
		else
		{
			first = first->m_pNext;
			second = second->m_pNext;
		}
	}
	if(!secondGo)
		return nullptr;
	return second;
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
	ListNode *tmp = FindKthToTail(head,2);
	if(tmp != nullptr)
		cout<<tmp->m_nValue<<endl;
	else
		cout<<"K is greater or less than the number of link list.\n";
	destroy(&head);
	return 0;
}
