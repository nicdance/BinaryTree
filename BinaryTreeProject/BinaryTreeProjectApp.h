#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "BinaryTree.h"

class BinaryTreeProjectApp : public aie::Application {
public:

	BinaryTreeProjectApp();
	virtual ~BinaryTreeProjectApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;



	BinaryTree			m_binaryTree;
	TreeNode*			m_selectedNode;
};