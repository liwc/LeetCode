// 2_addTwoNumbers.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	/*ListNode* p = l1;
	ListNode* q = l2;
	ListNode* l = NULL;
	ListNode* r = NULL;

	int carry = 0;
	while (p != NULL && q != NULL)
	{
		ListNode* temp = new ListNode((p->val + q->val + carry) % 10);
		if (r == NULL)
		{
			r = temp;
			l = r;
		}
		else
		{
			r->next = temp;
			r = r->next;
		}

		carry = (p->val + q->val + carry) / 10;
		p = p->next;
		q = q->next;
	}

	while (p != NULL)
	{
		ListNode* temp = new ListNode((p->val + carry) % 10);
		if (r == NULL)
		{
			r = temp;
			l = r;
		}
		else
		{
			r->next = temp;
			r = r->next;
		}

		p = p->next;
	}
		
	while (q != NULL)
	{
		ListNode* temp = new ListNode((q->val + carry) % 10);
		if (r == NULL)
		{
			r = temp;
			l = r;
		}
		else
		{
			r->next = temp;
			r = r->next;
		}

		q = q->next;
	}

	if (carry != 0)
	{
		ListNode* temp = new ListNode(carry % 10);
		if (r == NULL)
		{
			r = temp;
			l = r;
		}
		else
		{
			r->next = temp;
			r = r->next;
		}
	}*/

	ListNode* head = &ListNode(0);
	ListNode* curr = head;
	ListNode* p = l1;
	ListNode* q = l2;
	int carry = 0;
	while (p != NULL || q != NULL)
	{
		int pVal = (p != NULL ? p->val : 0);
		int qVal = (q != NULL ? q->val : 0);
		int sum = pVal + qVal + carry;
		curr->next = new ListNode(sum % 10);
		curr = curr->next;
		carry = sum / 10;

		if (p != NULL) p = p->next;
		if (q != NULL) q = q->next;
	}

	if (carry > 0)
	{
		curr->next = new ListNode(1);
		curr = curr->next;
	}

	return head->next;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ListNode l11 = ListNode(2);
	ListNode l12 = ListNode(4);
	ListNode l13 = ListNode(3);
	l11.next = &l12;
	l12.next = &l13;

	ListNode l21 = ListNode(5);
	ListNode l22 = ListNode(6);
	ListNode l23 = ListNode(7);
	l21.next = &l22;
	l22.next = &l23;

	ListNode* l = addTwoNumbers(&l11, &l21);
	ListNode* p = l;
	ListNode* q = p;
	while (p != NULL)
	{
		cout << p->val << " ";
		
		q = p;
		p = p->next;
		delete q;
	}
	cout << endl;

	system("pause");
	return 0;
}

