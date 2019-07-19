
#include "pch.h"
#include "BSTNode.h"

#include <gtest/gtest.h>

using Node = BSTNode<int>;
using NodeStack = std::stack<Node*>;
using NodeSet = std::unordered_set<Node*>;

// counts number of leaf nodes in the tree non-recursively.
size_t count_leaves (Node *tree) {

	if (tree == nullptr)
		return 0;

	size_t numLeaves = 0;
	NodeStack stack;
	stack.push (tree);
	NodeSet visitedNodes;
	Node *node = tree;
	do {
		node = stack.top ();

		if (node->left == nullptr && node->right == nullptr) {
			++numLeaves;
		}
		else if (node->left!=nullptr && visitedNodes.find(node->left)==visitedNodes.end()) {
			stack.push (node->left);
			node = node->left;
			continue;
		}
		else if (node->right!=nullptr && visitedNodes.find (node->right) == visitedNodes.end ()) {
			stack.push (node->right);
			node = node->right;
			continue;
		}

		visitedNodes.insert (node);

		stack.pop ();

	} while (!stack.empty());

	return numLeaves;
}

// counts leaf nodes without recursion & w/o hash table of visited nodes;
size_t count_leaves2 (Node *tree) {
	size_t numLeaves = 0;
	NodeStack stack;
	stack.push (tree);

	while (!stack.empty ()) {

		Node * node = stack.top ();
		stack.pop ();
		if (node->right != nullptr)
			stack.push (node->right);
		if (node->left != nullptr)
			stack.push (node->left);
		if (node->left == nullptr && node->right == nullptr)
			++numLeaves;
	}

	return numLeaves;
}

void count_leaves_r (size_t &numLeaves, Node *tree)
{
	if (tree->left == nullptr && tree->right == nullptr) {
		++numLeaves;
		std::cout << tree->value << "\n";
	}
	
	if (tree->left) {
		count_leaves_r (numLeaves, tree->left);
	}

	if (tree->right) {
		count_leaves_r (numLeaves, tree->right);
	}

}

size_t count_leaves_recursively (Node *tree)
{
	if (tree == nullptr)
		return 0;

	size_t numLeaves = 0;

	count_leaves_r (numLeaves, tree->left);
	count_leaves_r (numLeaves, tree->right);

	return numLeaves;
}

namespace {

	struct CountLeafNodesTest : testing::Test {

		Node *tree;

		void SetUp () override {

			tree = 
				new Node {8, 
					new Node {3, 
						new Node {1},
						new Node {6, 
							new Node {4},
							new Node {7}
						}
					},
					new Node {10,
						nullptr,
						new Node {14,
							new Node {13}
						}
					}
				};

		}

		void TearDown () override {
			delete tree;
		}

	};

	TEST_F (CountLeafNodesTest, Iterative) {

		size_t leaves = count_leaves (tree);
		EXPECT_EQ (leaves, 4);

	}

	TEST_F (CountLeafNodesTest, IterativeGeeks4Geeks) {

		size_t leaves = count_leaves2 (tree);
		EXPECT_EQ (leaves, 4);

	}

	TEST_F (CountLeafNodesTest, Recursive) {

		size_t leaves = count_leaves_recursively (tree);
		EXPECT_EQ (leaves, 4);

	}

}

