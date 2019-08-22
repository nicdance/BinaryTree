#include "BinaryTree.h"



BinaryTree::BinaryTree()
{
	m_pRoot = nullptr;
}


BinaryTree::~BinaryTree()
{
}

void BinaryTree::draw(aie::Renderer2D* renderer, TreeNode* selected)
{
	draw(renderer, m_pRoot, 640, 680, 640, selected);
}
void BinaryTree::draw(aie::Renderer2D* renderer, TreeNode* pNode, int x, int y,
	int horizontalSpacing, TreeNode* selected)
{
	horizontalSpacing /= 2;
	if (pNode != nullptr) {
		if (pNode->hasLeft()) {
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x - horizontalSpacing, y - 80);
			draw(renderer, pNode->getLeft(), x - horizontalSpacing,
				y - 80, horizontalSpacing, selected);
		}
		if (pNode->hasRight()) {
			renderer->setRenderColour(1, 0, 0);
			renderer->drawLine(x, y, x + horizontalSpacing, y - 80);
			draw(renderer, pNode->getRight(), x + horizontalSpacing,
				y - 80, horizontalSpacing, selected);
		}
		pNode->draw(renderer, x, y, (selected == pNode));
	}
}

bool BinaryTree::isEmpty() const
{
	if (m_pRoot == nullptr)
	{
		return true;
	}
	return false;
}

void BinaryTree::insert(int a_nValue) 
{
	// If the tree is empty, the value is inserted at the root
	if (m_pRoot == nullptr) 
	{
		m_pRoot = new TreeNode(a_nValue);
	}
	else 
	{
		// Set the current node to the root
		TreeNode * currentNode = m_pRoot;
		TreeNode * parent = nullptr;
		// While the current node is not null
		while (currentNode != nullptr)
		{
			parent = currentNode;
			// If the value to be inserted is less than the value in the current node
			if (a_nValue <  currentNode->getData())
			{
				// Set the current node to the left child and continue
				currentNode = currentNode->getLeft();
			} 
			// If the value to be inserted is greater than the current node
			else if (a_nValue > currentNode->getData())
			{
				// Set the current node to the right child and continue
				currentNode = currentNode->getRight();
			}
			// If the value to be inserted is the same as the value in the current node
			else 
			{
				return;
			}
		}
		// If value to be inserted is less than parent
		if (a_nValue < parent->getData() ) 
		{
			// insert value as left child node
			parent->setLeft(new TreeNode(a_nValue));
		}
		// otherwise insert value as right child node
		else 
		{
			parent->setRight(new TreeNode(a_nValue));
		}
	}
}

// If I have timewill come back and try recursive.

bool BinaryTree::findNode(int a_nSearchValue, TreeNode** ppOutNode, TreeNode** ppOutParent){
	// The find() function could be implemented as a recursive function or using a while loop.If you find
	// the former easier, you may wish to modify your class accordingly.
	// Set the current node to the root
	TreeNode * currentNode = m_pRoot;
	TreeNode * parent;
	// While the current node is not null
	while (currentNode != nullptr)
	{
		parent = currentNode;
		//if the search value equals the current node value,
		if (currentNode->getData() == a_nSearchValue)
		{
			//return the current node and its parent
			*ppOutNode = currentNode;
			*ppOutParent = parent;
			return true;
		}
		// otherwise
		else {
			// If the search value is less than the current node
			if (a_nSearchValue < currentNode->getData())
			{
				// set the current node to the left child
				currentNode = currentNode->getLeft();
			}
			//otherwise set the current node to the right child
			else if (a_nSearchValue > currentNode->getData())
			{
				currentNode = currentNode->getRight();
			}
				
			
		}
	// end While
	}
	// If the loop exits, then a match was not found, so return false
	return false;
}

void BinaryTree::remove(int value)
{
	// find the value in the tree, obtaining a pointer to the node and its parent
	TreeNode * currentNode = m_pRoot;
	TreeNode * parent;
	TreeNode * minimumParent;
	findNode(value, &currentNode, &parent);
	// If the current node has a right branch, then
	if (currentNode->getRight() != nullptr) {
		currentNode = currentNode->getRight();
		// find the minimum value in the right branch by iterating down the left branch of the
		// current node’s right child until there are no more left branch nodes
		while (currentNode->getLeft() != nullptr)
		{
			minimumParent = currentNode;
			currentNode = currentNode->getLeft();
		}
		// copy the value from this minimum node to the current node
		parent->getRight()->setData(currentNode->getData());
		// find the minimum node’s parent node(the parent of the node you are deleting)
		// if you are deleting the parent’s left node
		if (value < parent->getData())
		{
			// set this left child of the parent to the right child of the minimum node
			parent->setLeft(currentNode);
		}
		// if you are deleting the parent’s right node
		if(value > parent->getData())
		{
			// set the right child of the parent to the minimum node’s right child
			parent->setRight(currentNode);
		}
	}
	else if (currentNode->getLeft() != nullptr) {
		// If the current node has no right branch
			// if we are deleting the parent’s left child, set the left child of the parent to the left
				// child of the current node
			// If we are deleting the parent’s right child, set the right child of the parent to the left
				// child of the current node
			// If we are deleting the root, the root becomes the left child of the current node
	}
}


TreeNode* BinaryTree::find(int a_nValue)
{
	bool found = false;
	TreeNode * currentNode = m_pRoot;
	while (!found) 
	{
		if (a_nValue < currentNode->getData())
		{
			currentNode = currentNode->getLeft();
		}
		else if (a_nValue < currentNode->getData())
		{
			currentNode = currentNode->getRight();
		}
		else 
		{
			return currentNode;
		}
	}
	return nullptr;
}