#pragma once
#include "TreeNode.h"
#include "MemoryLeakChecker.h"

class BinaryTree 
{
	struct Node;
public:
	BinaryTree();
	~BinaryTree();
	bool isEmpty() const;
	void insert(int a_nValue);
	void remove(int a_nValue);
	TreeNode* find(int a_nValue);
	void draw(aie::Renderer2D* renderer, TreeNode* selected = nullptr);
private:
	//Find the node with the specified value.
	bool findNode(int a_nSearchValue, TreeNode** ppOutNode,	TreeNode** ppOutParent);
	void draw(aie::Renderer2D* renderer, TreeNode*, int x, int y, int horizontalSpacing, TreeNode* selected = nullptr);
	//The root node of the tree
	TreeNode* m_pRoot;
};
