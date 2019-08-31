/*
*	@Author Nicole Dance
*	Code Design and Data Structures
*   Assessable Exercise 4 - Hashing
*/
#include "HashFunction.h"
#include "Texture.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include <iostream>



struct TextureHolder
{
	std::string		filename;
	aie::Texture *	texture;
};


aie::Texture* RetreiveTexture(std::string filename, std::vector<std::vector<TextureHolder>>& TextureManager, const int size);

int main()
{
	std::vector<TextureHolder> textures;
	std::vector<std::string> filenames;
	std::ifstream inputFile("../filenames.txt", std::ios::in);
	while (!inputFile.eof())
	{
		std::string word;
		getline(inputFile, word);
		filenames.push_back(word);
	}

	// hash processing
	const int size = 50;

	std::vector<std::vector<TextureHolder>> TextureManager;
	TextureManager.resize(size);

	for (const auto& filename : filenames)
	{
		RetreiveTexture(filename, TextureManager, size);
	}

	std::cout << "Find Random File"  << std::endl;
	const auto& stringToFind = filenames[rand() % filenames.size()];
	std::cout << "File to fine: " << stringToFind << std::endl;
	RetreiveTexture(stringToFind, TextureManager, size);

	system("pause");
	return 0;
}

aie::Texture* RetreiveTexture(std::string filename, std::vector<std::vector<TextureHolder>>& TextureManager, const int size)
{
	auto hash = 0;
	hash = HashFunction::defaultHashFunction(filename.c_str(), filename.length()) % size;
	auto& textureList = TextureManager[hash];
	if (textureList.size() > 0)
	{
		for (const auto& texture : textureList)
		{
			if (texture.filename == filename)
			{
				std::cout << "Retreived Texture " << texture.filename << " from bucket "  << hash << std::endl;
				return texture.texture;
			}
		}

	}
	aie::Texture* texture = new aie::Texture(filename.c_str());
	textureList.push_back(TextureHolder{ filename, texture });

	std::cout << "Added Texture " << filename << " to bucket " << hash << std::endl;
	return textureList.back().texture;
}