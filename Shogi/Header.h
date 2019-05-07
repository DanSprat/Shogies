#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "math.h"
using namespace sf;

void menu(RenderWindow & window)
{
	int IsMusic=1;
	Texture NewGame, Rules, Exit, Figur, BackBackGround, menuRules1, menuRules2, Musica,YesMusic,NoMusic;
	YesMusic.loadFromFile("images/YesMusic.png");
	NoMusic.loadFromFile("images/NoMusic.png");
	NewGame.loadFromFile("images/11111.png");
	Rules.loadFromFile("images/222.png");
	Exit.loadFromFile("images/333.png");
	Figur.loadFromFile("images/444.png");
	BackBackGround.loadFromFile("images/Cover.jpg");
	menuRules1.loadFromFile("images/r1.png");
	Musica.loadFromFile("images/music.png");
	menuRules2.loadFromFile("images/r2.png");
	Sprite menu1(NewGame), menu2(Rules), menu3(Exit), menu4(Figur), menubbg(BackBackGround), menuR1(menuRules1);
	Sprite menuR2(menuRules2), Mus(Musica),YesM(YesMusic),NoM(NoMusic);
	bool isMenu = 1;
	int Num = 0;// номер пункта меню 
	menu1.setPosition(760, 250);
	menu2.setPosition(760, 550);
	menu3.setPosition(760, 700);
	menu4.setPosition(760,400);
	YesM.setPosition(1650, 50);
	NoM.setPosition(1650, 50);

	menubbg.setPosition(0, 0);
	Music music;//создаем объект музыки
	music.openFromFile("shogi.ogg");//загружаем файл
	music.play();//воспроизводим музыку
	music.setLoop(true);
	int k=0;

	////////////////////////////////МЕНЮ/////////////////// 
	while (isMenu) {
		Event event;
		while (window.pollEvent(event))
		{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menu4.setColor(Color::White);
		Mus.setColor(Color::White);
		Num = 0;
		window.clear();


		if (IntRect(760, 250, 400, 100).contains(Mouse::getPosition(window))) { menu1.setColor(Color::Yellow); Num = 1; }
		if (IntRect(760, 550, 400, 100).contains(Mouse::getPosition(window))) { menu2.setColor(Color::Yellow); Num = 2; }
		if (IntRect(760, 700, 400, 100).contains(Mouse::getPosition(window))) { menu3.setColor(Color::Yellow); Num = 3; }
		if (IntRect(760, 400, 400, 100).contains(Mouse::getPosition(window))) { menu4.setColor(Color::Yellow); Num = 5; }
		if (IntRect(1650, 50, 200, 200).contains(Mouse::getPosition(window))) { Mus.setColor(Color::Yellow); Num = 4; }

		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (Num == 1)
				isMenu = false;
			if (Num == 2)
			{

				window.draw(menuR1);
				window.display();

				while (!Keyboard::isKeyPressed(Keyboard::Escape));
			}
			if (Num == 3)
			{
				window.close(); isMenu = false;
			}
			if (Num == 4) {
				int Check = 1;
				while (Mouse::isButtonPressed(Mouse::Left))
				{
					if (!IntRect(1650, 50, 200, 200).contains(Mouse::getPosition(window)))
					{
						Check = 0;
						break;
					}
				
				}

				if (Check == 1)
				{
					event.type = Event::MouseButtonReleased;


				if (event.type == Event::MouseButtonReleased)
				{
					k++;
					if ((k % 2) == 1) {
						music.stop();
						IsMusic = 0;
					}
					else
					{
						IsMusic = 1;
						music.play();
						music.setLoop(true);

					}

				}
			}
			}
			if (Num == 5) {
				window.draw(menuR2);
				window.display();

				while (!Keyboard::isKeyPressed(Keyboard::Escape));

			}

		}
	}
		window.draw(menubbg);
		if (IsMusic == 0)
		{
		
		window.draw(NoM);
	    }
		else
		{
			window.draw(YesM);
		}
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.draw(menu4);
		window.display();
	}
	////////////////////////////////////////////////////

}
	
