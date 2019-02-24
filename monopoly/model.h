#pragma once
#include <vector>
#include <iostream>
#include <ctime>
#ifndef MONOPOLY_MODEL_H
#define MONOPOLY_MODEL_H
class Card {
private:
	int position; //Íîìåð ïî ñ÷åòó
public:
	Card(int pos) : position(pos) {}
	virtual void buyShop(int number) {}
	virtual void buy(int owner) {}
	//void caraganda(Player &player) {}
	virtual int getPosition() { return position; }
	virtual void setPrice(int price) { }
	virtual void setPriceRent(int priceRent) { }
	virtual void setColor(int color) { }
	virtual void setPrizeShop(int prizeShop) { }
	virtual void setNumberOfShops(int numberOfShops) { }
	virtual int getPrice()  { return -10; }
	virtual int getPriceRent()  { return -10; }
	virtual int getColor()  { return -10; }
	virtual int getPriceShop()  { return -10; }
	virtual int getNumberOfShops()  { return -10; }
	virtual int getOwner()  { return -10; }
	virtual int getType() { return -10; }
};

class UsefullCard : public Card {
private:
	int price;//Öåíà êàðòî÷êè
	int priceRent; //Öåíà àðåíäû
	int color; // Öâåò(òèï) 8 øò
	int priceShop; // Öåíà äîìèêà
	int numberOfShops; // Êîëè÷åñòâî äîìèêîâ
	int owner; // Íîìåð èãðîêà, êîòîðîìó ïðåíàäëåæèò
public:
	UsefullCard(int num) : Card(num) { }
	UsefullCard(int num, int price, int priceRent, int color) : Card(num) {
		this->price = price;
		this->priceRent = priceRent;
		this->color = color;
		owner = -1;
	}
	virtual void buy(int owner) override { this->owner = owner; }
	virtual void setPrice(int price) override { UsefullCard::price = price; }
	virtual void setPriceRent(int priceRent) override { UsefullCard::priceRent = priceRent; }
	virtual void setColor(int color) override { UsefullCard::color = color; }
	virtual void setPrizeShop(int prizeShop) override { UsefullCard::priceShop = prizeShop; }
	virtual void setNumberOfShops(int numberOfShops) override { this->numberOfShops = numberOfShops; }
	virtual int getPrice()  override { return price; }
	virtual int getPriceRent()  override { return priceRent; }
	virtual int getColor()  override { return color; }
	virtual int getPriceShop()  override { return priceShop; }
	virtual int getNumberOfShops()  override { return numberOfShops; }
	virtual int getOwner()  override { return owner; }
	virtual int getType() override { return -1; }
};

class RoflanCard : public Card {
private:
	int type;
public:
	RoflanCard(int num, int type) : Card(num) { this->type = type;  }
	//void caraganda(Player &player);
	virtual int getType() { return type; }
};

class Player {
private:
	int number;
	int money;
	int position;
	std::vector<Card*> cards;
public:
	Player(int m_money, int num) : number(num), money(m_money), position(0) {}
	Card& findCard(int pos);
	void buyCard(Card card);
	int random(int num = 6); // Âîçâðàùàåò ñóììó êóáèêîâ ðàíäîìíûõ
	void payRent(Player &player);
	void sell();
	void change();
	void buyShop(int number);
	void createShop(int number);
	void setMoney(int money) { this->money = money; }
	void setPosition(int position) { Player::position = position; }
	int getNumber()  { return number; }
	int getMoney()  { return money; }
	int getPosition()  { return position; }
	std::vector<Card*> getCards() { return cards; }
};
#endif //MONOPOLY_MODEL_H
