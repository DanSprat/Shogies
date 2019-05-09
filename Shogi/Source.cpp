#include <SFML/Graphics.hpp>
#include "map.h"
#include "Figures.h"
#include "Header.h"

using namespace sf;
int main()

{
	int SizeBlack = 20;
	int SizeWhite = 20;
	Figures **BlackFigures;
	BlackFigures = new Figures *[20];
	Figures **WhiteFigures;
	WhiteFigures = new Figures *[20];
	Figures **NewBlack;
	//NewBlack = new Figures *[0];
	Figures **NewWHite;
	//NewWHite = new Figures *[0];

	int j = 0;
	int tempX = 0; int tempY = 0;
	int turn = 2;
	float MouseLeft = false;
	VectorMove NewCoords = { 0,0 };
	King KingWhite(1, 5, 1, "figures1.png");

	Rook RookWhite1(2, 8, 1, "figures1.png", "figures1.png");
	King KingBlack(9, 5, 2, "figures1.png");
	Rook RookBlack1(8, 8, 2, "figures1.png", "figures1.png");
	Horse HorseWhite1(1, 2, 1, "figures1.png", "figures1.png");
	Horse HorseBlack1(9, 2, 2, "figures1.png", "figures1.png");
	Horse HorseBlack2(9, 8, 2, "figures1.png", "figures1.png");
	Horse HorseWhite2(1, 8, 1, "figures1.png", "figures1.png");
	Knight KnightBlack1(8, 2, 2, "figures1.png", "figures1.png");
	Knight KnightWhite1(2, 2, 1, "figures1.png", "figures1.png");
	Pawn PawnWhite1(3, 1, 1, "figures1.png", "figures1.png");
	Pawn PawnWhite2(3, 2, 1, "figures1.png", "figures1.png");
	Pawn PawnWhite3(3, 3, 1, "figures1.png", "figures1.png");
	Pawn PawnWhite4(3, 4, 1, "figures1.png", "figures1.png");
	Pawn PawnWhite5(3, 5, 1, "figures1.png", "figures1.png");
	Pawn PawnWhite6(3, 6, 1, "figures1.png", "figures1.png");
	Pawn PawnWhite7(3, 7, 1, "figures1.png", "figures1.png");
	Pawn PawnWhite8(3, 8, 1, "figures1.png", "figures1.png");
	Pawn PawnWhite9(3, 9, 1, "figures1.png", "figures1.png");
	Pawn PawnBlack1(7, 1, 2, "figures1.png", "figures1.png");
	Pawn PawnBlack2(7, 2, 2, "figures1.png", "figures1.png");
	Pawn PawnBlack3(7, 3, 2, "figures1.png", "figures1.png");
	Pawn PawnBlack4(7, 4, 2, "figures1.png", "figures1.png");
	Pawn PawnBlack5(7, 5, 2, "figures1.png", "figures1.png");
	Pawn PawnBlack6(7, 6, 2, "figures1.png", "figures1.png");
	Pawn PawnBlack7(7, 7, 2, "figures1.png", "figures1.png");
	Pawn PawnBlack8(7, 8, 2, "figures1.png", "figures1.png");
	Pawn PawnBlack9(7, 9, 2, "figures1.png", "figures1.png");
	Silver SilverWhite1(1, 3, 1, "figures1.png");
	Silver SilverWhite2(1, 7, 1, "figures1.png");
	Silver SilverBlack1(9, 3, 2, "figures1.png");
	Silver SilverBlack2(9, 7, 2, "figures1.png");
	Gold GoldWhite1(1, 4, 1, "figures1.png");
	Gold GoldWhite2(1, 6, 1, "figures1.png");
	Gold GoldBlack1(9, 4, 2, "figures1.png");
	Gold GoldBlack2(9, 6, 2, "figures1.png");
	Arrow ArrowWhite1(1, 1, 1, "figures1.png", "figures1.png");
	Arrow ArrowWhite2(1, 9, 1, "figures1.png", "figures1.png");
	Arrow ArrowBlack1(9, 1, 2, "figures1.png", "figures1.png");
	Arrow ArrowBlack2(9, 9, 2, "figures1.png", "figures1.png");
	



	Figures *FiguresBlack[20] = {
								 &KingBlack,&ArrowBlack2,&ArrowBlack1,&GoldBlack1,&GoldBlack2,&SilverBlack1,&SilverBlack2,
								 &PawnBlack1,&PawnBlack2,&PawnBlack3,&PawnBlack4,&PawnBlack5,&PawnBlack6,&PawnBlack7,&PawnBlack8,
								 &PawnBlack9,&KnightBlack1,&HorseBlack2,&RookBlack1,&HorseBlack1
	};

	Figures *FiguresWhite[20] = {
								 &KingWhite,&ArrowWhite2,&ArrowWhite1,&GoldWhite1,&GoldWhite2,&SilverWhite1,&SilverWhite2,
								 &PawnWhite1,&PawnWhite2,&PawnWhite3,&PawnWhite4,&PawnWhite5,&PawnWhite6,&PawnWhite7,&PawnWhite8,
								 &PawnWhite9,&KnightWhite1,&HorseWhite2,&RookWhite1,&HorseWhite1
	};
	Figures *px;
	px = *FiguresBlack;
	for (int i = 0; i < 20; i++)
	{
		BlackFigures[i] = FiguresBlack[i];
	}
	for (int i = 0; i < 20; i++)
	{
		WhiteFigures[i] = FiguresWhite[i];
	}
	Figures *pa;
	pa = &RookWhite1;
	float heroteleporttimer = 0;
	Clock clock;
	/*int boardik[10][10] = { 0,0,0,0,0,0,0,0,0,0,
							0,1,1,1,1,1,1,1,1,1,
							0,0,1,0,0,0,0,0,1,0,
							0,1,1,1,1,1,1,1,1,1,
							0,0,0,0,0,0,0,0,0,0,
							0,0,0,0,0,0,0,0,0,0,
							0,0,0,0,0,0,0,0,0,0,
							0,2,2,2,2,2,2,2,2,2,
							0,0,2,0,0,0,0,0,2,0,
							0,2,2,2,2,2,2,2,2,2 };
							*/
	int boardTrue[10][10] = { 0,0,0,0,0,0,0,0,0,0,
							0,0,0,0,0,0,0,0,0,0,
							0,0,0,0,0,0,0,0,0,0,
							0,0,0,0,0,1,0,0,0,0,
							0,0,0,0,2,0,0,0,0,0,
							0,0,0,0,0,0,0,0,0,0,
							0,0,0,0,0,0,0,0,0,0,
							0,2,0,0,0,0,0,0,0,0,
							0,2,0,0,0,0,0,0,0,0,
							0,0,0,0,0,0,0,0,0,0 };
	int boardik[10][10];
	Template(boardik, boardTrue);

	Image map_image;//объект изображения для карты
	map_image.loadFromFile("images/Green.png");//загружаем файл для карты
	Texture map;//текстура карты
	map.loadFromImage(map_image);//заряжаем текстуру картинкой
	Sprite s_map;//создаём спрайт для карты
	s_map.setTexture(map);//заливаем текстуру спрайтом


	RenderWindow window(VideoMode(1920, 1080), "The Shogi Game");
	menu(window);
	Image board;
	board.loadFromFile("images/TestBoard.jpg");
	Texture boardtexture;
	boardtexture.loadFromImage(board);
	Sprite boardsprite;
	boardsprite.setTexture(boardtexture);
	boardsprite.setPosition(555, 135);

	Image cover;
	cover.loadFromFile("images/Cover.jpg");
	Texture covertexture;
	covertexture.loadFromImage(cover);
	Sprite coversprite;
	coversprite.setTexture(covertexture);
	Image Inmenu1;
	Inmenu1.loadFromFile("images/inmenu.png");
	Texture InMenu;
    InMenu.loadFromImage(Inmenu1);
	Sprite im;
	im.setTexture(InMenu);
	im.setPosition(1550, 600);


	Texture YesMusic, NoMusic;
	YesMusic.loadFromFile("images/YesMusic.png");
	NoMusic.loadFromFile("images/NoMusic.png");
	Sprite YesM(YesMusic), NoM(NoMusic);
	YesM.setPosition(1650, 50);
	NoM.setPosition(1650, 50);


	Image figure;
	figure.loadFromFile("images/figures.png");
	Texture figuretexture;
	figuretexture.loadFromImage(figure);
	Sprite figuresprite;
	figuresprite.setTexture(figuretexture);
	figuresprite.setPosition(555, 135);

	int k = 0;
	int IsMusic = 1;
	int Num;

	Music music;//создаем объект музыки
	music.openFromFile("shogi.ogg");//загружаем файл
	music.play();//воспроизводим музыку
	music.setLoop(true);

	SoundBuffer Click,Thanos;//создаём буфер для звука
	Thanos.loadFromFile("thanos.ogg");//загружаем в него звук
	Click.loadFromFile("click.ogg");
	Sound thanos(Thanos), click(Click);//создаем звук и загружаем в него звук из буфера

	while (window.isOpen())
	{
		int Num = 0;
		Vector2i pixelPos = Mouse::getPosition(window);
		Event event;
		

		while (window.pollEvent(event))
		{
			/*while (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				event.type = Event::KeyReleased;
			}

			if (event.type == Event::KeyReleased)
			{
				menu(window);
			}
			*/
			im.setColor(Color::White);
			if (IntRect(1550, 600, 400, 100).contains(Mouse::getPosition(window))) { im.setColor(Color::Yellow); Num = 1; }
			if (IntRect(1650, 50, 200, 200).contains(Mouse::getPosition(window)))  Num = 4; 
			if (Num == 1)
			{
				while (Mouse::isButtonPressed(Mouse::Left))
				{
					click.play();
					event.type = Event::MouseButtonReleased;
				}
				if (event.type == Event::MouseButtonReleased)
				{
					music.stop();
					IsMusic = 0;
					menu(window);
					music.play(); IsMusic = 1; music.setLoop(true);
					
				}
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
				
			if (event.type == Event::Closed)
				window.close();
			
			if (MouseLeft == false)
			{
				if (event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
					if (event.key.code == Mouse::Left)
					{
						pa = SelectedFigure(turn, BlackFigures, WhiteFigures, pixelPos.x, pixelPos.y,SizeBlack,SizeWhite);
						if (pa != 0)
						{
							j++;
							
							(*pa).SearchRoots(BlackFigures, WhiteFigures, boardik, *pa,SizeBlack,SizeWhite);
							(*pa).getSprite().setColor(Color::Green);//красим спрайт в зеленый,тем самым говоря игроку,что он выбрал персонажа и может сделать ход
							(*pa).getIsClicked() = true;
							event.type = Event::MouseButtonReleased;
							MouseLeft = true;
						}
					}
			}
			if (pa != 0)
			{
				if ((*pa).getIsClicked())
				{
					if (event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
						if (event.key.code == Mouse::Right)

						{
							(*pa).getIsClicked() = false;
							(*pa).getSprite().setColor(Color::White);
							MouseLeft = false;


						}


						else
							if (event.key.code == Mouse::Left)
							{
								
								if ((*pa).CheckTrue(pixelPos.x, pixelPos.y, NewCoords) == true)
								{
									cout << boardTrue[pa->getCordX()][pa->getCordY()];
									boardTrue[pa->getCordX()][pa->getCordY()] = 0;
									pa->setCordX(NewCoords.getScaleCompX());
									pa->setCordY(NewCoords.getScaleCompY());
									
									if (pa->Eating(BlackFigures, WhiteFigures, SizeBlack, SizeWhite) == 1)
									{
										
									}

									boardTrue[pa->getCordX()][pa->getCordY()] = pa->getSide();
									Template(boardik, boardTrue);
									(*pa).getIsClicked() = false;
									(*pa).getIsMove() = true;
									(*pa).getSprite().setColor(Color::White);
									MouseLeft = false;
									tempX = (575 + 40) + 5 * (NewCoords.getScaleCompY() - 1) + 80 * (NewCoords.getScaleCompY() - 1);
									tempY = (155 + 40) + 5 * (NewCoords.getScaleCompX() - 1) + 80 * (NewCoords.getScaleCompX() - 1);
									thanos.play();

								}

							}
				}

			}

		}
		if (pa != 0)
		{
			if ((*pa).getIsMove())
			{
				(*pa).getSprite().setPosition(tempX, tempY);
				(*pa).getIsMove() = false;
				turn = (turn % 2) + 1;


			}
		}


		window.clear();

		
		window.draw(coversprite);
		window.draw(boardsprite);
		if (IsMusic == 0)
		{

			window.draw(NoM);
		}
		else
		{
			window.draw(YesM);
		}
		window.draw(im);
		window.draw(KingBlack.getSprite());
		window.draw(GoldWhite1.getSprite());

		if (pa != 0)
		{
			if ((*pa).getIsClicked())

				pa->ShowRoots(TileMap, s_map, window);
		}






		window.display();
	}

	return 0;
}
