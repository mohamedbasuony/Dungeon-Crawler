#include <SFML/Graphics.hpp>
#include"Player.h"
#include<string>
#include<ctime>
#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;
using namespace sf;
const int x = 20;
const int y = 20;

class game
{
private:
	RenderWindow& window; RectangleShape shape[x][y]; RectangleShape player; RectangleShape enemy; Texture& W; Texture& s;
	Texture& w; Texture& f; Texture& a; Texture& h; Texture& m; Texture& d; Texture& fl; Texture& p; Texture& C2; Texture& r; RectangleShape& spikes; RectangleShape& water;
	RectangleShape& fire; RectangleShape& ammunition; RectangleShape& heart; RectangleShape& monster;
public:
	game();
	RenderWindow window;
	void loadcontent();
	void intialize();
	void update();
	void draw();
	void gamecall();
};
void game::loadcontent()
{
	W.loadFromFile("assets/wall.jpg");
	s.loadFromFile("assets/spike.png");
	w.loadFromFile("assets/water.png");
	f.loadFromFile("assets/Fire.png");
	a.loadFromFile("assets/bullet.png");
	h.loadFromFile("assets/heart.png");
	m.loadFromFile("assets/monster.gif");
	fl.loadFromFile("assets/floor.png");
	d.loadFromFile("assets/door.png");
	C2.loadFromFile("assets/cave2.png");
	//C1.loadFromFile("cave1.png");
	//r.loadFromFile("assets/enemy.png");
	//p.loadFromFile("assets/player.png");
	

}

void game::intialize()
{
	window.create(VideoMode(1000, 1000), "The Dungeon Crawler", Style::Default);
}

void game::update()
{
	int j, i;
	string line;
	ifstream mytext;
	mytext.open("Map.txt");

	for (int i = 0; mytext.good(); i++)
	{
		getline(mytext, line);

		for (int j = 0; j < line.length(); j++)
		{
			arr[i][j] = line[j];

		}
	}
	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{

			if (((player.getPosition().x) == (shape[0][1].getPosition().x)) && (player.getPosition().y) == (shape[0][1].getPosition().y))
				player.move(900, 900);
			else
				if (((player.getPosition().x) == (shape[15][4].getPosition().x)) && (player.getPosition().y) == (shape[15][4].getPosition().y))
					player.move(150, -100);
				else
					if (((player.getPosition().x) == (shape[12][19].getPosition().x)) && (player.getPosition().y) == (shape[12][19].getPosition().y))
						player.move(-900, -250);
					else
						if (((player.getPosition().x) == (shape[2][18].getPosition().x)) && (player.getPosition().y) == (shape[2][18].getPosition().y))
							player.move(-300, 300);

			if (event.key.code == Keyboard::Up)

			{
				j = player.getPosition().x / 50;
				i = player.getPosition().y / 50;

				if (arr[i - 1][j] != 'x')
					player.move(0, -25);
				std::cout << i * 50 << j * 50;
			}
			else if (event.key.code == Keyboard::Down)
			{
				j = player.getPosition().x / 50;
				i = player.getPosition().y / 50;

				if (arr[i + 1][j] != 'x')
					player.move(0, 25);
				std::cout << i * 50 << j * 50;
			}
			else if (event.key.code == Keyboard::Left)
			{
				j = player.getPosition().x / 50;
				i = player.getPosition().y / 50;

				if (arr[i][j - 1] != 'x')
					player.move(-25, 0);
				std::cout << i * 50 << j * 50;
			}
			else if (event.key.code == Keyboard::Right)
			{
				j = player.getPosition().x / 50;
				i = player.getPosition().y / 50;

				if (arr[i][j + 1] != 'x')
					player.move(25, 0);
				//std::cout << j * 50 << i * 50;
			}
		}

	}
}

void game::draw()
{
	ifstream map;
	map.open("Map.txt");
	if (!map)
	{
		cout << "unable to open file";
		exit(1);
	}
	string line;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			shape[i][j].setSize(Vector2f(50, 50));
			shape[i][j].setPosition(j * 50, i * 50);
		}
	}

	while (!map.eof())
	{
		for (int i = 0; map.good(); i++)
		{
			getline(map, line);

			for (int j = 0; j < line.length(); j++)
			{
				if (line[j] == 'x')
					shape[i][j].setTexture(&W);
				else if (line[j] == '.')
					shape[i][j].setTexture(&fl);
				else if (line[j] == 'd')
					shape[i][j].setTexture(&d);
				else if (line[j] == 'e')
					shape[i][j].setTexture(&d);
				else if (line[j] == 'm')
					shape[i][j].setTexture(&m);
				else if (line[j] == 'w')
					shape[i][j].setTexture(&w);
				else if (line[j] == 'f')
					shape[i][j].setTexture(&f);
				else if (line[j] == 'z')
					shape[i][j].setTexture(&s);
				else if (line[j] == 'h')
					shape[i][j].setTexture(&h);
				else if (line[j] == 'a')
					shape[i][j].setTexture(&a);
				else if (line[j] == 'C' || 'B' || 'r')
					shape[i][j].setTexture(&C2);
				window.clear();

				for (int i = 0; i < 20; i++)
				{
					for (int j = 0; j < 20; j++)
					{
						window.draw(shape[i][j]);
					}
				}
				window.draw(player);
				window.draw(enemy);

				window.display();
			}
		}
	}
}

void game::gamecall()
{
	intialize();
	loadcontent();
	draw();
	update();

}/*/