#include "pch.h"

#include "Node.h"
#include <gtest/gtest.h>

// PROBLEM: reverse a singly linked list

using namespace std;

NodePtr reverse_linked_list (NodePtr head)
{
	NodePtr curr=head;
	NodePtr prev, next;
	while (curr) {
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	
	return prev;
}

NodePtr reverse_linked_list_r (NodePtr prev, NodePtr head) {
	NodePtr next = head->next;
	head->next = prev;
	if (next != nullptr) {
		return reverse_linked_list_r (head, next);
	}
	return head;
}

NodePtr reverse_linked_list_recursive (NodePtr head) {
	return reverse_linked_list_r (nullptr, head);
}

namespace {
	struct test_case {
		NodePtr srcList;
		NodePtr revList;
		
		friend std::ostream& operator << (std::ostream &os, test_case const &tc) {
			os << "src: {" << *tc.srcList  << "} rev: {" << *tc.revList << "}\n";
			return os;
		}
	};
	
	struct RevLinkedListTest : testing::Test, testing::WithParamInterface<test_case> {};
}

TEST_P(RevLinkedListTest, basic) {
	auto tc = GetParam();
	auto res = reverse_linked_list(tc.srcList);
	EXPECT_EQ(*res, *tc.revList);
}

INSTANTIATE_TEST_SUITE_P(Basic, RevLinkedListTest,
	testing::Values(
		test_case {
			make_shared<Node>(1, make_shared<Node>(2, make_shared<Node>(3))),
			make_shared<Node>(3, make_shared<Node>(2, make_shared<Node>(1)))
		},
		test_case {
			make_shared<Node>(1, make_shared<Node>(1)),
			make_shared<Node>(1, make_shared<Node>(1))
		}
	)
);

TEST (RevLinkedListRecursive, Main) {

	NodePtr head = make_shared<Node> (1, make_shared<Node> (2, make_shared<Node> (3)));
	NodePtr rev = reverse_linked_list_recursive (head);
	NodePtr expected = make_shared<Node> (3, make_shared<Node> (2, make_shared<Node> (1)));
	EXPECT_EQ (*rev, *expected);
}
