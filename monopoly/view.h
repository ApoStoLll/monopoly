#pragma once
#include <string>
#include <iostream>
#include "model.h"
#ifndef MONOPOLY_VIEW_H
#define MONOPOLY_VIEW_H
class GraphView {
private:
	int pos1(int pos);
	int pos2(int pos);
	sf::RenderWindow *window;
	sf::Texture map;
	sf::Sprite mapa;
	sf::Texture player1, player2,p1g,p2g, menuTexture1, menuTexture2, menuTexture,naezdM,naezdW,naezdL,naezdP,birgaP,birgaL,birgaW;
	sf::Texture cp0[40];
	sf::Texture cp1[40];
	sf::Sprite player11, player22, going,menu1, menu2,naezdT,naezdWW,naezdLL,naezdPP,birgaT,birgaLL,birgaWW;
	sf::Sprite cop0[40];
	sf::Sprite cop1[40];
	sf::Font font;//����� 
	sf::Text text1, text2, text3, text4, text5,text6,text7,text8,text9,text10,text11,zemlya,birgatext;//������� ������ 

public:
	GraphView(){}
	GraphView(sf::RenderWindow *window) {
		this->window = window;
	
	}
	void createMap(int a, int b, int c, int d, std::vector<Player> &players);
	void drawMap();
	int menu();
	bool skipOrBuy();
	void pprintMap(std::vector<Player> &players, std::vector<Card*> cards, int a, int b, int num);
	void loadMap();
	bool naezd(int money);
	void rentView(int a,int b,int rentPrice);
	void drawBought(std::vector<Player> &players);
	void fasView(int j);
	void kaznaView(int l,bool k);
	void avosView(int l, bool k);
	void naezdWin();
		void naezdLose(int money);
		void naezdPlata(int money);
		int birga();
	void birgaWin(int money);
	void birgaLose(int money);
	void zemlyaView(int k, bool b);
	//void buznisVoid(int l);

};

class View {
private:
	std::vector<Player> *players;
	std::vector<Card*> *cards;
public:
	View() {}
	View(std::vector<Player> *player, std::vector<Card*> *card) {
		 players = player;
		 cards = card;
	}
	int change();
	int textMenu();
	int zal();
	int razzal();
	int help();
	int naezdOrPolice();
	int birgaStavka();
	int birgaRisk();
	int jailask();
	bool skipOrBuy();
	void printMap( int a, int b, int num);
	char findOwner(int number);
	int askReide();
};
#endif //MONOPOLY_VIEW_H