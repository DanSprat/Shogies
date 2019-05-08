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
	King KingWhite(3, 5, 1, "figures1.png");

	Rook RookWhite1;
	King KingBlack(4, 4, 2, "figures1.png");
	Rook RookBlack1;
	Horse HorseWhite1;
	Horse HorseBlack1;
	Horse HorseBlack2;
	Horse HorseWhite2;
	Knight KnightBlack1;
	Knight KnightWhite1;
	Pawn PawnWhite1(1, 1, 1, "figures1.png", "figures1.png");
	Pawn PawnWhite2;
	Pawn PawnWhite3;
	Pawn PawnWhite4;
	Pawn PawnWhite5;
	Pawn PawnWhite6;
	Pawn PawnWhite7;
	Pawn PawnWhite8;
	Pawn PawnWhite9;
	Pawn PawnBlack1;
	Pawn PawnBlack2;
	Pawn PawnBlack3;
	Pawn PawnBlack4;
	Pawn PawnBlack5;
	Pawn PawnBlack6;
	Pawn PawnBlack7;
	Pawn PawnBlack8;
	Pawn PawnBlack9;
	Silver SilverWhite1;
	Silver SilverWhite2;
	Silver SilverBlack1;
	Silver SilverBlack2;
	Gold GoldWhite1;
	Gold GoldWhite2;
	Gold GoldBlack1;
	Gold GoldBlack2;
	Arrow ArrowWhite1;
	Arrow ArrowWhite2;
	Arrow ArrowBlack1;
	Arrow ArrowBlack2;
	



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


	Image figure;
	figure.loadFromFile("images/figures.png");
	Texture figuretexture;
	figuretexture.loadFromImage(figure);
	Sprite figuresprite;
	figuresprite.setTexture(figuretexture);
	figuresprite.setPosition(555, 135);

	int Num;
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
			if (Num == 1)
			{
				while (Mouse::isButtonPressed(Mouse::Left))
				{
					event.type = Event::MouseButtonReleased;
				}
				if (event.type == Event::MouseButtonReleased)
				{
					menu(window);
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
		window.draw(im);
		window.draw(KingBlack.getSprite());

		if (pa != 0)
		{
			if ((*pa).getIsClicked())

				pa->ShowRoots(TileMap, s_map, window);
		}






		window.display();
	}

	return 0;
}

