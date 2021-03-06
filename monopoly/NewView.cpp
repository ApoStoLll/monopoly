#include "pch.h"
#include <iostream>
#include "view.h"
using namespace sf;

int pos1(int pos) {
		if (pos > 10 && pos < 20) return 97;
		if (pos > 30) return 767;
		if (pos <= 10) return 767 - pos * 67;
		if (pos >= 20 && pos <= 30) return 97 + pos % 20 * 67;
	}
int pos2(int pos) {
		if (pos > 10 && pos < 20) return 707 - pos % 10 * 63;
		if (pos > 30) return 77 + pos % 30 * 63;
		if (pos <= 10) return 707;
		if (pos >= 20 && pos <= 30) return 37;
	}
int MMenu(sf::RenderWindow &window) {
		Texture menuTexture;
		menuTexture.loadFromFile("images/m.png");
		Sprite menu(menuTexture);
		int menuNum = 0;
		menu.setPosition(500, 500);
		window.draw(menu);
		window.display();
		while (true)
		{
			menuNum = 0;
			if (IntRect(500, 500, 300, 50).contains(Mouse::getPosition(window))) { menu.setColor(Color::Blue); menuNum = 1; }
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (menuNum == 1) return 1;
			}
		}
	}
bool SkipOr(RenderWindow &window) {
		Texture menuTexture1, menuTexture2;
		menuTexture1.loadFromFile("images/111.png");
		menuTexture2.loadFromFile("images/222.png");
		Sprite menu1(menuTexture1), menu2(menuTexture2);
		bool isMenu = 1;
		int menuNum = 0;
		menu1.setPosition(300, 300);
		menu2.setPosition(400, 300);
		window.draw(menu1);
		window.draw(menu2);
		window.display();
		while (true)
		{
			menuNum = 0;
			//window.clear();
			if (IntRect(300, 300, 300, 50).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Blue); menuNum = 1; }
			if (IntRect(400, 300, 300, 50).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Blue); menuNum = 2; }
			if (Mouse::isButtonPressed(Mouse::Left)) {
				if (menuNum == 1) return 1;
				if (menuNum == 2) return 0;
			}
		}
	}
void pprintMap(RenderWindow &window, std::vector<Player> &players, std::vector<Card*> cards, int a, int b, int num)
	{
		Texture map;
		map.loadFromFile("images/1.png");
		Sprite mapa;
		mapa.setTexture(map);
		mapa.setPosition(0, 0);
		Texture player1, player2;
		player1.loadFromFile("images/2.png");
		player2.loadFromFile("images/3.png");
		Sprite player11, player22, going;
		player11.setTexture(player1);
		player22.setTexture(player2);
		if (num == 0) { going.setTexture(player1); going.setPosition(500, 350); }
		else { going.setTexture(player2); going.setPosition(500, 350); }
		player11.setPosition(pos1(players[0].getPosition()), pos2(players[0].getPosition()));
		player22.setPosition(pos1(players[1].getPosition()) + 2, pos2(players[1].getPosition()) + 2);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(mapa);
		window.draw(player11);
		window.draw(player22);
		window.draw(going);
		window.display();
	}




