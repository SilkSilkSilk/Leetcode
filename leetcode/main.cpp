#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

void initNode(ListNode *node)
{
	struct ListNode *temp = node;
	for (int i = 0; i < 11; i++)
	{
		temp->next = new ListNode(rand() % 1000);
		temp = temp->next;
	}
}

int lenNode(ListNode *node)
{
	struct ListNode *temp = node;
	int result = 0;
	while (temp)
	{
		result++;
		temp = temp->next;
	}
	return result;
}

void printNode(ListNode *node)
{
	struct ListNode *temp = node;
	while(temp)
	{
		cout << temp->val << " -> ";
		temp = temp->next;
	}
	cout << endl;
}

ListNode *getIntersectionNode_force(ListNode *headA, ListNode *headB) {
	while(headA)
	{
		auto temp_b = headB;
		while(temp_b)
		{
			if (temp_b == headA)
			{
				return temp_b;
			}
			temp_b = temp_b->next;
		}
		headA = headA->next;
	}
	return nullptr;
}

ListNode *getIntersectionNode_map(ListNode *headA, ListNode *headB) {
	unordered_map<ListNode*, int> map;
	while (headA)
	{
		map.insert({ headA, 0 });
		headA = headA->next;
	}

	auto temp_b = headB;
	while (temp_b)
	{
		if (map.find(temp_b) != map.end())
		{
			return temp_b;
		}
		temp_b = temp_b->next;
	}
	return nullptr;
}

ListNode *getIntersectionNode_doublepointer(ListNode *headA, ListNode *headB) 
{
	auto temp_a = headA;
	auto temp_b = headB;
	while (temp_a || temp_b)
	{
		if (!temp_a)
		{
			temp_a = headB;
		}
		if (!temp_b)
		{
			temp_b = headA;
		}
		if (temp_a == temp_b)
		{
			return temp_a;
		}
		temp_a = temp_a->next;
		temp_b = temp_b->next;
	}
	return nullptr;
}

int main()
{
	const auto node1 = new ListNode(1);
	const auto node2 = new ListNode(2);
	const auto node3 = new ListNode(3);
	const auto node4 = new ListNode(4);
	const auto node5 = new ListNode(5); 
	const auto node6 = new ListNode(6);
	node1->next = node4;
	node4->next = node5;
	node5->next = node6;

	node2->next = node3;
	node3->next = node4;
	printNode(node1);
	printNode(node2);

	auto ret = getIntersectionNode_doublepointer(node1, node2);
	if (ret)
		cout << ret->val << endl;

	return 0;
}