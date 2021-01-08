#include <SFML/Graphics.hpp>
#include"Player.h"
#include<string>
#include<ctime>
#include<time.h>
#include<cstdlib>
#include<fstream>
using namespace std;
using namespace sf;
const int x=20; 
const int y=20;
Clock mtimer;
void Intialize(RenderWindow& window, RectangleShape shape[x][y], player player, enemy enemy, Texture& W, Texture& s,
			   Texture& w, Texture& f, Texture& a, Texture& h, Texture& m, Texture& d, Texture& fl, Texture& C2,  RectangleShape& spikes, RectangleShape& water,
			   RectangleShape& fire, RectangleShape& ammunition, RectangleShape& heart, RectangleShape& monster)
{
	window.create(VideoMode(1000, 1000), "The Dungeon Crawler");
	ifstream map;
	map.open("Map.txt");
	if (!map)
	{
		cout << "unable to open file";
		exit(1);
	}

	string line;
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
	//r.loadFromFile("assets/enemy.png");
	//p.loadFromFile("assets/player.png");
	

	char arr[20][20];
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

				for (int j = 0; j< line.length(); j++)
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
					//	else if (line[j] == 'c')
						//	shape[i][j].setTexture(&C2);
						//else if (line[j] == 'y')
							//shape[i][j].setTexture(&C1);
				}

			}

		}


		int j, i;

		while (window.isOpen())
		{
			Event event;

			while (window.pollEvent(event))
			{

				if (((player.getX()) == (shape[0][1].getPosition().x)) && (player.getY()) == (shape[0][1].getPosition().y))
					player.move(900, 900);
				else
					if (((player.getX()) == (shape[15][4].getPosition().x)) && (player.getY()) == (shape[15][4].getPosition().y))
						player.move(150, -100);
					else
						if (((player.getX()) == (shape[12][19].getPosition().x)) && (player.getY()) == (shape[12][19].getPosition().y))
							player.move(-900, -250);
						else
							if (((player.getX()) == (shape[2][18].getPosition().x)) && (player.getY()) == (shape[2][18].getPosition().y))
								player.move(-300, 300);

				if (mtimer.getElapsedTime().asMilliseconds() >= 200)
				{
					if (event.key.code == Keyboard::Up)

					{
						j = player.getX() / 50;
						i = player.getY()/ 50;

						if (arr[i - 1][j] != 'x')
							player.move(0, -50);
						//if (arr[player.getX()][player.getY()]=='h')
						//player.addhealth();
						//shape[player.getX()][player.getY()].setTexture(&f1)
						//else if(player.getX()][player.getY()]=='a')
						//player.addammunition();
						//
						std::cout << i * 50 << j * 50;
					}
					else if (event.key.code == Keyboard::Down)
					{
						j = player.getX() / 50;
						i = player.getY() / 50;
						std::cout << i * 50 << j * 50;

						if (arr[i + 1][j] != 'x')
							player.move(0, 50);
					}
					else if (event.key.code == Keyboard::Left)
					{
						j = player.getX() / 50;
						i = player.getY() / 50;

						if (arr[i][j - 1] != 'x')
							player.move(-50, 0);
						std::cout << i * 50 << j * 50 << endl;
					}
					else if (event.key.code == Keyboard::Right)
					{
						j = player.getX() / 50;
						i = player.getY() / 50;

						if (arr[i][j + 1] != 'x')
							player.move(50, 0);
						std::cout << j * 50 << i * 50;
					}
					mtimer.restart();
				}

				window.clear();

				for (int i = 0; i < 20; i++)
				{
					for (int j = 0; j < 20; j++)
					{
						window.draw(shape[i][j]);
					}
				}
				player.drawTo(window);
				enemy.drawTo(window);
				window.display();

			}
		}
}

int main()
{
	
	RectangleShape shape[20][20];
	player p; enemy e;
	RectangleShape spikes,  water,  fire,  ammunition, enemy, heart,  monster, player;
	 Texture s,  w,  f,  a,  h,  m,  fl,  W,  d,  C2;
	RenderWindow window;
	 Intialize(window, shape, p ,e , W, s,
		 w, f, a, h, m, d, fl, C2, spikes, water, fire, ammunition, heart, monster);

	 

	return 0;
}