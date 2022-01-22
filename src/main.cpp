#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "image_crypto.hpp"
#include <string>
#include <iostream>

using namespace std;
using namespace sf;

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		cout << "incorrect number of command line arguments. enter <input file> <output file> <seed> " << endl;
		return -1;
	}
	string input_file = argv[1];
	string output_file = argv[2];
	string seed = argv[3];

	FibLFSR reg(seed);

	Image image;
	if (!image.loadFromFile(input_file)) //load image from disk
	{
		cout << "Failed to open image" << endl;
		return -1;
	}

	Image image2 = image; // make a copy of the image before encryption
	Color p; // p is a pixel
	
	Vector2u size = image.getSize(); //get size of image (2 dimensional array of pixels, each pixel has a position denoted by (x,y) coordinate pair)
		
	int sizex = size.x;
	int sizey = size.y;
	
	for (int x = 0; x < sizex; x++) // iterate through matrix of pixels, access the red, green, blue components of each pixel and randomize the values
	{
		for (int y = 0; y < sizey; y++)
		{
			p = image.getPixel(x,y);
			p.r = reg.generate(30) ^ p.r;
			p.g = reg.generate(40) ^ p.g;
			p.b = reg.generate(50) ^ p.b;
			image.setPixel(x,y,p);	
		}
	}
	
	Texture texture;
	texture.loadFromImage(image);

	Sprite sprite;
	sprite.setTexture(texture);

	Texture texture2;
	texture2.loadFromImage(image2);

	Sprite sprite2;
	sprite2.setTexture(texture2);

	RenderWindow window(VideoMode(size.x, size.y),"Original Image");
	RenderWindow window2(VideoMode(sizex, sizey),"Encrypted/Decrypted Image");
	
	while (window.isOpen() && window2.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		while (window2.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window2.close();
		}

		window.clear();
		window.draw(sprite2);
		window.display();
		window2.clear();
		window2.draw(sprite);
		window2.display();
	}

	if (!image.saveToFile(output_file))
		return -1;

	return 0;
}

