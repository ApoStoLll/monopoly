#include "pch.h"
#include "controller.h"

void Controler::caraganda(Player &player) {
	player.setPosition(player.random(40));
	Sleep(1000);
	view.pprintMap(players, cards, 0, 0, player.getNumber());
	action(player);
}
void Controler::fas(Player &player) {
	int j = 0;
	for (int i = 0; i < cards.size(); i++)
		if (cards[i]->getNumberOfShops() > 0) j += cards[i]->getNumberOfShops();
	player.setMoney(player.getMoney() - j * 30000);
	view.fasView(j);
}
void Controler::kazna(Player &player) {
	int i = player.random(4);
	int l = ((50 + player.random(150)) * 1000);
	bool o = true;
	if (i == 1) {
		player.setMoney(player.getMoney() + l);
		view.kaznaView(l, o);
	}
	else {
		o = false;
		player.setMoney(player.getMoney() - l);
		view.kaznaView(l, o);
	}

}
void Controler::naezd(Player &player) {
	int j = ((10 + player.random(50)) * 1000);
	int i = view.naezd(j);
	int k = player.random(4);
	if (i == 0){
		player.setMoney(player.getMoney() - j); 
		view.naezdPlata(j);
	}
	if (i == 1){ 
			if (k == 1 || k == 2 || k == 3) { player.setMoney(player.getMoney() - j * 2); view.naezdLose(j * 2); }
			else 
		view.naezdWin();
	}
}
void Controler::birga(Player &player) {
	int k = viewConsole.birgaStavka();
	if (k >= 100000) k = 100000;
	if (k < 0) k = 1;
	int n = view.birga();
	int a = player.random();
	int b = player.random();
	if (n == 3 && n < (a + b)) {
		player.setMoney(player.getMoney() + 2 * k);
		view.birgaWin(2 * k);
	}
	if (n == 3 && n >= (a + b)) {
		player.setMoney(player.getMoney() - k);
		view.birgaLose(k);
	}
	if (n == 7 && n < (a + b)) {
		player.setMoney(player.getMoney() + 4 * k);
		view.birgaWin(4 * k);
	}
	if (n == 7 && n >= (a + b)) {
		player.setMoney(player.getMoney() - k);
		view.birgaLose(k);
	}
		if (n == 9 && n < (a + b)) {
			player.setMoney(player.getMoney() + 8 * k);
			view.birgaWin(8 * k);
		}
		if (n == 9 && n >= (a + b)) {
			player.setMoney(player.getMoney() - k);
			view.birgaLose(k);
		}

}
void Controler::inverse(Player &player,int a,int b) {
	player.setPosition(player.getPosition() - a - b);
}
void Controler::present(Player &player1, Player &player2) {
	int k = player1.random(2);
	int y = ((25 + player1.random(35)) * 1000);
	if (k == 1) {
		bool o = true;
		player1.setMoney(player1.getMoney() + y);
		player2.setMoney(player2.getMoney() - y);
		view.avosView(y, o);
	}
	else {
		bool o = false;
		player2.setMoney(player2.getMoney() + y);
		player1.setMoney(player1.getMoney() - y);
		view.avosView(y, o);
	}
}
void Controler::avos(Player &player) {
	int i = player.random(1);
	if (i == 1) {
		Player *player2;
		if (player.getNumber() == 1) player2 = &players[0];
		else player2 = &players[1];
		present(player, *player2);
	}
	if (i == 2) {
		int a = player.random();
		int b = player.random();
		bool o = true;
		int k = a + b;
		view.avosView(k, o);
		inverse(player, a, b);
	}
	if (i == 3) {
		bool o = true;
		int k = (25 + player.random(175) * 1000);
		player.setMoney(player.getMoney() + k);
		view.kaznaView(k, o);
	}
	if (i == 4) {
		bool o = false;
		int k = (25 + player.random(175) * 1000);
		player.setMoney(player.getMoney() - k);
		view.kaznaView(k, o);
	}
	if (i == 5) caraganda(player);
}
void Controler::kanikulu(Player &player) {
	int k = (200 + player.random(200)) * 1000;
	bool o = true;
	player.setMoney(player.getMoney() + k);
	view.kaznaView(k,o);

}
void Controler::svazi(Player &player) {
	if (player.getCountchin() == 0) {
		player.setCountchin(1);
	}
	else {
		player.setCountchin(0);
		int i = player.random(2);
		int k = player.random(40);
		if (i == 1) {
			int l = (50 + player.random(125) * 10000);
			bool o = true;
			player.setMoney(player.getMoney() + l);
			view.kaznaView(l, o);
		}
		if (i == 2) {
			bool b = true;
			player.setPosition(k);
			player.buyCard(cards[player.getPosition()]);
			player.setMoney(player.getMoney() + cards[player.getPosition()]->getPrice());
			player.setPosition(23);
			view.zemlyaView(k, b);
		}
	}
}
void Controler::rusbiznes(Player &player) {
	if (player.getCountrus() == 0) {
		player.setCountrus(1);
	}
	else {
		player.setCountrus(0);
		int i = player.random(4);
		int k = player.random(40);
		if (i = 1) {
			for (int i = 0; i < cards.size(); i++)
				if (cards[i]->getNumberOfShops() == 0) cards[i]->buy(-1);//rusbiznes zabral kart
			i = 4;//esli y igroka vezde est domiki,y nego zaberut dengi
		}
		if (i = 2) 	player.setMoney(player.getMoney() + (player.random(50) + player.random(75) + player.random(325)) * 10000);
		if (i = 3) {
			player.setPosition(k);
			player.buyCard(cards[player.getPosition()]);
			player.setMoney(player.getMoney() + cards[player.getPosition()]->getPrice());
			player.setPosition(27);
		}
		if (i = 4) player.setMoney(player.getMoney() - (player.random(50) + player.random(75) + player.random(325)) * 10000);
	}
}
void Controler::jail(Player &player) {
	if (player.getCountjail() > 4) 
		player.setCountjail(0);
	else {
		int i = 0;
		if (player.getMoney() > 50000)  i = viewConsole.jailask();
		int a = player.random();
		int b = player.random();
		if (i == 1) {
			player.setCountjail(0);
			player.setMoney(player.getMoney() - 50000);
		}
		else {
			if (a == b) player.setCountjail(0);
			else player.setCountjail(player.getCountjail() + 1);
		}
	}
}
void Controler::reide(Player &player) {
	int k = viewConsole.askReide();
	int l = player.random(4);
	if (l == 1) {
		player.setPosition(k);
		player.buyCard(cards[player.getPosition()]);
		player.setMoney(player.getMoney() + cards[player.getPosition()]->getPrice());
		player.setPosition(32);
	}
	else player.setPosition(k);
	player.buyCard(cards[player.getPosition()]);
	player.setMoney(player.getMoney() - cards[player.getPosition()]->getPrice());
	player.setPosition(32);
}
void Controler::love(Player &player) {
	kazna(player);
}
void Controler::nalogi(Player &player) {
	player.setMoney(player.getMoney()*0.8);//20 percent 
}
bool Controler::choose(Player &player) {
	if ((cards[player.getPosition()]->getOwner() == -1) //���� �� �������
		&& (player.getMoney() > cards[player.getPosition()]->getPrice())) return true;
	else return false;
}
void Controler::menu(Player &player) {
	while (true) {
		int n = viewConsole.textMenu();
		if (n == 0) return;
		if (n > 0 && n < 100) player.buyShop(n);
		if (n < 0 && n != -100) player.sellShop(n);
		if (n == 100) pledgeCard(player);
		if (n == 101) repledgeCard(player);
		if (n == 102)  change(player);
	}
}
void Controler::pledgeCard(Player &player) {
	int i = viewConsole.zal();
	int j = player.getPosition();
	player.setPosition(i);
	player.setMoney(player.getMoney() + (cards[player.getPosition()]->getPrice()) / 2);
	player.setPosition(j);
}
void Controler::repledgeCard(Player &player) {
	int i = viewConsole.razzal();
	int j = player.getPosition();
	player.setPosition(i);
	player.setMoney(player.getMoney() - (cards[player.getPosition()]->getPrice()));
	player.setPosition(j);
}
bool Controler::lose(Player &player) {
	while (true) {
		int i = viewConsole.help();
		if (i = 1) {
			int k = viewConsole.textMenu();
			player.sellShop(k);
			if (player.getMoney() > 0) break;
		}
		if (i = 2) {
			pledgeCard(player);
			if (player.getMoney() > 0) break;
		}
		if (i = 0) {
			return false;
		}
	}
	return true;
}
void Controler::okCard(Player &player) {
	if (choose(player)) {	//���� ������� ����� � ������� �������� �� �������
		if (view.skipOrBuy()) {
			//view.drawCard(player.getPosition(),player.getNumber());
			player.buyCard(cards[player.getPosition()]);
		}// ���� ��� ������
		//if (viewConsole.skipOrBuy()) player.buyCard(cards[player.getPosition()]); // ���� ��� ������
	}
	else
		if (cards[player.getPosition()]->getOwner() > -1) {
			player.payRent(players[cards[player.getPosition()]->getOwner()]);
			view.rentView(player.getNumber(), players[cards[player.getPosition()]->getOwner()].getNumber(), cards[player.getPosition()]->getPriceRent());
		}
	//����� ������
}
void Controler::action(Player &player) {
	if (cards[player.getPosition()]->getType() == -1) okCard(player);
	if (cards[player.getPosition()]->getType() == 1) caraganda(player);
	if (cards[player.getPosition()]->getType() == 2) fas(player);
	if (cards[player.getPosition()]->getType() == 3) kazna(player);
	if (cards[player.getPosition()]->getType() == 4) naezd(player);
	if (cards[player.getPosition()]->getType() == 5) birga(player);
	if (cards[player.getPosition()]->getType() == 6) avos(player);
	if (cards[player.getPosition()]->getType() == 7) kanikulu(player);
	if (cards[player.getPosition()]->getType() == 8) svazi(player);
	if (cards[player.getPosition()]->getType() == 9) rusbiznes(player);
	if (cards[player.getPosition()]->getType() == 10) if (player.getCountjail() == 0) player.setCountjail(1);
	if (cards[player.getPosition()]->getType() == 11) reide(player);
	if (cards[player.getPosition()]->getType() == 12) love(player);
	if (cards[player.getPosition()]->getType() == 13) nalogi(player);
}
void Controler::step(Player &player) {
	int a = player.random();
	int b = player.random();
	if (cards[player.getPosition()]->getType() == 10) jail(player);
	if (player.getCountjail() == 0) {
		if ((player.getPosition() + a + b) / 40 > 0) player.setMoney(player.getMoney() + 200000);
		player.setPosition((player.getPosition() + a + b) % 40); // ��������� �������
	}
	viewConsole.printMap(a, b, player.getNumber());
	view.pprintMap(players, cards, a, b, player.getNumber());//�������� �����
	action(player);
	view.createMap(players[0].getMoney(), players[1].getMoney(), a, b, players);
	if (player.getCountjail()==0) if (a == b) step(player);
}
void Controler::gameCycle() {
	int i = 0;
	view.loadMap();
	while (players.size() > 1) {
		if (i == players.size()) i = 0;
		step(players[i]);	//��������
		if (players[i].getMoney() < 0) {
			if (lose(players[i])) players.erase(players.begin() + i);
		}
		if (players[i].getCountjail()==0)view.menu();
		//menu(players[i]);	//������� ����
		i++;	//��������� �����	
	}
}
void Controler::change(Player &player1) {
	std::cout << "num of player\n";
	int plyr = viewConsole.change();
	std::cout << "sum\n";
	int sum = viewConsole.change();
	std::cout << "your card\n";
	int num1 = viewConsole.change();
	std::cout << "another card\n";
	int num2 = viewConsole.change();
	Player &player2 = players[plyr];
	//if (player1.checkMoney(sum) && player2.checkMoney(-sum) && player1.checkCard(num1) && player2.checkCard(num2)) {
		player1.changeCard(player2, num2);
		player2.changeCard(player1, num1);
		player1.pay(sum, player2);
	//}
	//else std::cout << "Change impossible\n";
}
std::vector<Card*> Controler::createCards() {
	std::vector<Card*> cards;
	int k = 1000;
	RoflanCard *start = new RoflanCard(0, 0); // ������ ������ (�����)
	cards.push_back(start);
	UsefullCard *cabSeti = new UsefullCard(1, 60 * k, 2 * k, 0); // ��������� ����
	cards.push_back(cabSeti);
	RoflanCard *karaganda = new RoflanCard(2, 1); // ����������
	cards.push_back(karaganda);
	UsefullCard *magisSeti = new UsefullCard(3, 60 * k, 4 * k, 0); // ����� ����
	cards.push_back(magisSeti);
	RoflanCard *fas = new RoflanCard(4, 2); // �.�.�.
	cards.push_back(fas);
	UsefullCard *autotrans = new UsefullCard(5, 200 * k, 25 * k, 1); // ���������
	cards.push_back(autotrans);
	UsefullCard *ats = new UsefullCard(6, 100 * k, 6 * k, 2); // ���
	cards.push_back(ats);
	UsefullCard *svaz = new UsefullCard(7, 100 * k, 8 * k, 2); // �����
	cards.push_back(svaz);
	RoflanCard *kazna = new RoflanCard(8, 3); // �����
	cards.push_back(kazna);
	UsefullCard *sputnic = new UsefullCard(9, 120 * k, 10 * k, 2); // ����������� �����
	cards.push_back(sputnic);
	RoflanCard *naezd = new RoflanCard(10, 4); // �����
	cards.push_back(naezd);
	UsefullCard *autoprom = new UsefullCard(11, 140 * k, 12 * k, 3); // ��������
	cards.push_back(autoprom);
	RoflanCard *birga = new RoflanCard(12, 5); // �����
	cards.push_back(birga);
	UsefullCard *aviaprom = new UsefullCard(13, 140 * k, 14 * k, 3); // ��������
	cards.push_back(aviaprom);
	UsefullCard *verf = new UsefullCard(14, 160 * k, 16 * k, 3); // �����
	cards.push_back(verf);
	UsefullCard *gdtrans = new UsefullCard(15, 50 * k, 25 * k, 1); // �� �����
	cards.push_back(gdtrans);
	UsefullCard *tipography = new UsefullCard(16, 180 * k, 18 * k, 3); // ����������
	cards.push_back(tipography);
	RoflanCard *avos = new RoflanCard(17, 6); // �����
	cards.push_back(avos);
	UsefullCard *radio = new UsefullCard(18, 180 * k, 20 * k, 3); // ������������
	cards.push_back(radio);
	UsefullCard *televishka = new UsefullCard(19, 200 * k, 22 * k, 3); // ���������
	cards.push_back(televishka);
	RoflanCard *kanikulu = new RoflanCard(20, 7); // ������ ������
	cards.push_back(kanikulu);
	UsefullCard *strah = new UsefullCard(21, 220 * k, 24 * k, 5); // ����� ���
	cards.push_back(strah);
	UsefullCard *invest = new UsefullCard(22, 220 * k, 26 * k, 5); // ������ ���
	cards.push_back(invest);
	RoflanCard *svazi = new RoflanCard(23, 8); // ������ � ����������
	cards.push_back(svazi);
	UsefullCard *credit = new UsefullCard(24, 240 * k, 28 * k, 5); // ������ ���
	cards.push_back(credit);
	UsefullCard *aviatrans = new UsefullCard(25, 50 * k, 25 * k, 1); // ���������
	cards.push_back(aviatrans);
	UsefullCard *sibir = new UsefullCard(26, 260 * k, 30 * k, 6); // ����� ���
	cards.push_back(sibir);
	RoflanCard *rusbiznes = new RoflanCard(27, 9); // ������� ������
	cards.push_back(rusbiznes);
	UsefullCard *lesopilka = new UsefullCard(28, 260 * k, 32 * k, 6); // ����� ���
	cards.push_back(lesopilka);
	UsefullCard *mebel = new UsefullCard(29, 280 * k, 34 * k, 6); // ����� ���
	cards.push_back(mebel);
	RoflanCard *jail = new RoflanCard(30, 10); // ����������
	cards.push_back(jail);
	UsefullCard *neft = new UsefullCard(31, 300 * k, 36 * k, 7); // �������� ��������
	cards.push_back(neft);
	RoflanCard *reide = new RoflanCard(32, 11); // ���������� ������
	cards.push_back(reide);
	UsefullCard *neftvishki = new UsefullCard(33, 300 * k, 38 * k, 7); // ������� �����
	cards.push_back(neftvishki);
	UsefullCard *neftzavod = new UsefullCard(34, 320 * k, 40 * k, 7); // �������� �����
	cards.push_back(neftzavod);
	UsefullCard *mortrans = new UsefullCard(35, 200 * k, 25 * k, 1); // ��� �����
	cards.push_back(mortrans);
	RoflanCard *love = new RoflanCard(36, 12); // ������ (����)
	cards.push_back(love);
	UsefullCard *gold = new UsefullCard(37, 350 * k, 42 * k, 8); // ������� ������
	cards.push_back(gold);
	RoflanCard *nalohpolice = new RoflanCard(38, 13); // ��������� (�� �����) 
	cards.push_back(nalohpolice);
	UsefullCard *almazi = new UsefullCard(39, 400 * k, 44 * k, 8); // minecraft ������ (�� � �����)
	cards.push_back(almazi);
	return cards;
}
std::vector<Player> Controler::createPlayers() {
	std::vector<Player> players;
	Player player1(1500000, 0);
	Player player2(1500000, 1);
	players.push_back(player1);
	players.push_back(player2);
	return players;
}