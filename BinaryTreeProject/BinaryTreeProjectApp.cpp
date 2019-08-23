#include "BinaryTreeProjectApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "ImGui.h"
aie::Font* g_systemFont = nullptr;

BinaryTreeProjectApp::BinaryTreeProjectApp() {

}

BinaryTreeProjectApp::~BinaryTreeProjectApp() {

}

bool BinaryTreeProjectApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	g_systemFont = new aie::Font("../bin/font/consolas.ttf", 32);

	/*m_binaryTree.insert(100);
	m_binaryTree.insert(150);
	m_binaryTree.insert(125);
	m_binaryTree.insert(110);
	m_binaryTree.insert(140);
	m_binaryTree.insert(175);
	m_binaryTree.insert(160);
	m_binaryTree.insert(200);
	m_binaryTree.insert(50);
	m_binaryTree.insert(75);
	m_binaryTree.insert(25);
	m_binaryTree.insert(10);
	m_binaryTree.insert(40);
	m_binaryTree.insert(60);
	m_binaryTree.insert(90);
	m_binaryTree.insert(125);
	m_binaryTree.insert(15);*/
	return true;
}

void BinaryTreeProjectApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void BinaryTreeProjectApp::update(float deltaTime) {

	aie::Input* input = aie::Input::getInstance();
	static int value = 0;
	ImGui::InputInt("Value", &value);
	if (ImGui::Button("Insert", ImVec2(50, 0)))
	{
		m_binaryTree.insert(value);
		m_selectedNode = m_binaryTree.find(value);
	}
	if (ImGui::Button("Remove", ImVec2(50, 0)))
	{
		m_binaryTree.remove(value);
	}
	if (ImGui::Button("Find", ImVec2(50, 0)))
	{
		m_selectedNode = m_binaryTree.find(value);
	}
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void BinaryTreeProjectApp::draw() {

	// wipe the screen to the background colour
	clearScreen();
	// begin drawing sprites
	m_2dRenderer->begin();
	// draw your stuff here!
	m_binaryTree.draw(m_2dRenderer, m_selectedNode);
	// output some text
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);
	// done drawing sprites
	m_2dRenderer->end();
}