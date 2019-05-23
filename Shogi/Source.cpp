#include <SFML/Graphics.hpp> 
#include "map.h" 
#include "Figure.h" 
#include "Header.h" 

using namespace sf;
int main()

{
	int EndGame = 0;
	Figures empty;//Нулевой (пустой) элмемент класса фигур 
	bool CanTranSform = 0;
	int X, IsMusic = 0, k = 0;
	int SizeBlack = 20;
	int SizeWhite = 20;
	int SizeByBlack = 0;
	int SizeByWhite = 0;
	Figures **BlackFigures;
	BlackFigures = new Figures *[20];
	Figures **WhiteFigures;
	WhiteFigures = new Figures *[20];
	Figures **EatenByBlack;
	Figures **EatenByWhite;
	EatenByBlack = new Figures *[1];
	EatenByWhite = new Figures *[0];
	int j = 0;
	int tempX = 0; int tempY = 0;
	int turn = 2;
	float MouseLeft = false;

	VectorMove NewCoords = { 0,0 };
	Image FiguresDef;
	FiguresDef.loadFromFile("images/figuresDef.png");
	Texture FD;
	FD.loadFromImage(FiguresDef);

	Image FiguresSwap;
	FiguresSwap.loadFromFile("images/figuresSwap.png");
	Texture FS;
	FS.loadFromImage(FiguresSwap);

	King KingWhite(1, 5, 1, FD);
	Rook RookWhite1(2, 2, 1, FD);
	King KingBlack(9, 5, 2, FD);
	Rook RookBlack1(8, 8, 2, FD);
	Horse HorseWhite1(1, 2, 1, FD);
	Horse HorseBlack1(9, 2, 2, FD);
	Horse HorseBlack2(9, 8, 2, FD);
	Horse HorseWhite2(1, 8, 1, FD);
	Knight KnightBlack1(8, 2, 2, FD);
	Knight KnightWhite1(2, 8, 1, FD);
	Pawn PawnWhite1(3, 1, 1, FD);
	Pawn PawnWhite2(3, 2, 1, FD);
	Pawn PawnWhite3(3, 3, 1, FD);
	Pawn PawnWhite4(3, 4, 1, FD);
	Pawn PawnWhite5(3, 5, 1, FD);
	Pawn PawnWhite6(3, 6, 1, FD);
	Pawn PawnWhite7(3, 7, 1, FD);
	Pawn PawnWhite8(3, 8, 1, FD);
	Pawn PawnWhite9(3, 9, 1, FD);
	Pawn PawnBlack1(7, 1, 2, FD);
	Pawn PawnBlack2(7, 2, 2, FD);
	Pawn PawnBlack3(7, 3, 2, FD);
	Pawn PawnBlack4(7, 4, 2, FD);
	Pawn PawnBlack5(7, 5, 2, FD);
	Pawn PawnBlack6(7, 6, 2, FD);
	Pawn PawnBlack7(7, 7, 2, FD);
	Pawn PawnBlack8(7, 8, 2, FD);
	Pawn PawnBlack9(7, 9, 2, FD);
	Silver SilverWhite1(1, 3, 1, FD);
	Silver SilverWhite2(1, 7, 1, FD);
	Silver SilverBlack1(9, 3, 2, FD);
	Silver SilverBlack2(9, 7, 2, FD);
	Gold GoldWhite1(1, 4, 1, FD);
	Gold GoldWhite2(1, 6, 1, FD);
	Arrow ArrowWhite1(1, 1, 1, FD);
	Arrow ArrowWhite2(1, 9, 1, FD);
	Arrow ArrowBlack1(9, 1, 2, FD);
	Arrow ArrowBlack2(9, 9, 2, FD);
	Gold GoldBlack1(9, 4, 2, FD);
	Gold GoldBlack2(9, 6, 2, FD);
	Figures *Test;

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

	for (int i = 0; i < 20; i++)
	{
		BlackFigures[i] = FiguresBlack[i];
	}
	for (int i = 0; i < 20; i++)
	{
		WhiteFigures[i] = FiguresWhite[i];
	}
	Figures *pa;
	pa = 0;
	float heroteleporttimer = 0;
	Clock clock;
	int boardTrue[10][10] = { 0,0,0,0,0,0,0,0,0,0,
	0,1,1,1,1,1,1,1,1,1,
	0,0,1,0,0,0,0,0,1,0,
	0,1,1,1,1,1,1,1,1,1,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,2,2,2,2,2,2,2,2,2,
	0,0,2,0,0,0,0,0,2,0,
	0,2,2,2,2,2,2,2,2,2 };


	int boardik[10][10];
	Template(boardik, boardTrue);

	Image map_image;//объект изображения для карты 
	map_image.loadFromFile("images/Green.png");//загружаем файл для карты 
	Texture map;//текстура карты 
	map.loadFromImage(map_image);//заряжаем текстуру картинкой 
	Sprite s_map;//создаём спрайт для карты 
	s_map.setTexture(map);//заливаем текстуру спрайтом 

	Music music;//создаем объект музыки 
	music.openFromFile("sounds/shogi.ogg");//загружаем файл 


	RenderWindow window(VideoMode(1920, 1080), "The Shogi Game");
	music.play();//воспроизводим музыку 
	music.setLoop(true);
	music.setPitch(1);

	music.setVolume(25);
	menu(window, music);
	if (music.getVolume() == 0)
	{
		IsMusic = 0;
		k = 1;
	}
	else
	{
		IsMusic = 1;
		k = 0;
	}
	Texture YesMusic, NoMusic;
	YesMusic.loadFromFile("images/YesMusic.png");
	NoMusic.loadFromFile("images/NoMusic.png");
	Sprite YesM(YesMusic), NoM(NoMusic);
	YesM.setPosition(1650, 50);
	NoM.setPosition(1650, 50);

	Image VictoryBlack;
	VictoryBlack.loadFromFile("images/BlackVictory.png");
	Texture VicB;
	VicB.loadFromImage(VictoryBlack);
	Sprite VB;
	VB.setTexture(VicB);


	Image VictoryWhite;
	VictoryWhite.loadFromFile("images/WhiteVictory.png");
	Texture VicW;
	VicW.loadFromImage(VictoryWhite);
	Sprite VW;
	VW.setTexture(VicW);



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
	im.setPosition(-50, 980);


	Image figure;
	figure.loadFromFile("images/figures.png");
	Texture figuretexture;
	figuretexture.loadFromImage(figure);
	Sprite figuresprite;
	figuresprite.setTexture(figuretexture);
	figuresprite.setPosition(555, 135);

	Image YourTurn;
	YourTurn.loadFromFile("images/YT.png");
	Texture YT;
	YT.loadFromImage(YourTurn);
	Sprite YourT;
	YourT.setTexture(YT);
	Image YesOrNo;
	YesOrNo.loadFromFile("images/YesOrNo.png");
	Texture YON;
	YON.loadFromImage(YesOrNo);
	Sprite Yes;
	Yes.setTexture(YON);
	Yes.setTextureRect(IntRect(0, 0, 200, 113));
	Sprite No;
	No.setTexture(YON);
	No.setTextureRect(IntRect(200, 0, 200, 113));
	Yes.setPosition(1420, 490);
	No.setPosition(1620, 490);
	Image Swap;
	Swap.loadFromFile("images/mbSwap.png");
	Texture mSwap;
	mSwap.loadFromImage(Swap);
	Sprite mbSwap;
	mbSwap.setTexture(mSwap);
	mbSwap.setPosition(1400, 390);

	SoundBuffer Click, Thanos;//создаём буфер для звука 
	Thanos.loadFromFile("sounds/thanos.ogg");//загружаем в него звук 
	Click.loadFromFile("sounds/click.ogg");
	Sound thanos(Thanos), click(Click);//создаем звук и загружаем в него звук из буфера 
	Image icon;
	if (!icon.loadFromFile("images/icon2.png"))
	{
		return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());
	int Num;
	while (window.isOpen())
	{


		Vector2i pixelPos = Mouse::getPosition(window);
		Event event;

		while (window.pollEvent(event))
		{
			int Num = 0;
			No.setColor(Color::White);
			Yes.setColor(Color::White);
			if (CanTranSform == 1)
			{
				if (IntRect(1420, 490, 200, 113).contains(Mouse::getPosition(window))) { Yes.setColor(Color::Green); Num = 2; }
				if (IntRect(1620, 490, 200, 113).contains(Mouse::getPosition(window))) { No.setColor(Color::Red); Num = 3; }
			}
			if (IntRect(1650, 50, 200, 200).contains(Mouse::getPosition(window))) { Num = 4; }





			im.setColor(Color::White);
			if (IntRect(-50, 980, 400, 100).contains(Mouse::getPosition(window))) { im.setColor(Color::Yellow); Num = 1; }
			if (Num == 1)
			{
				while (Mouse::isButtonPressed(Mouse::Left))
				{
					event.type = Event::MouseButtonReleased;
				}
				if (event.type == Event::MouseButtonReleased)
				{
					menu(window, music);
				}
			}
			if (Num == 2)
			{
				while (Mouse::isButtonPressed(Mouse::Left))
				{
					event.type = Event::MouseButtonReleased;
				}
				if (event.type == Event::MouseButtonReleased)
				{
					pa->Swap(FS);
					CanTranSform = 0;
					if (IsMate(BlackFigures, WhiteFigures, turn, SizeBlack, SizeWhite, boardik) == 1)
					{
						EndGame = turn;
					}
					turn = (turn % 2) + 1;

				}
			}
			if (Num == 3)
			{
				while (Mouse::isButtonPressed(Mouse::Left))
				{
					event.type = Event::MouseButtonReleased;
				}

				if (event.type == Event::MouseButtonReleased)
				{
					CanTranSform = 0;
					Num = 0;

					if (IsMate(BlackFigures, WhiteFigures, turn, SizeBlack, SizeWhite, boardik) == 1)
					{
						EndGame = turn;
					}
					turn = (turn % 2) + 1;
				}
			}
			if (Num == 4) {
				if (Mouse::isButtonPressed(Mouse::Left))
				{
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
								music.setVolume(0);
								IsMusic = 0;
							}
							else
							{
								IsMusic = 1;
								music.setVolume(25);


							}

						}
					}
				}
			}
			if (event.type == Event::Closed)
				window.close();

			if ((MouseLeft == false) && (CanTranSform == 0))
			{
				if (event.type == Event::MouseButtonPressed)//если нажата клавиша мыши 
					if (event.key.code == Mouse::Left)
					{
						j++;
						if (j == 8)
						{
							
						}
						pa = SelectedFigure(turn, BlackFigures, WhiteFigures, pixelPos.x, pixelPos.y, SizeBlack, SizeWhite);
						if (pa != 0)
						{
							(*pa).SearchRoots(BlackFigures, WhiteFigures, boardik, SizeBlack, SizeWhite);
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

									X = pa->getCordX();
									boardTrue[pa->getCordX()][pa->getCordY()];
									boardTrue[pa->getCordX()][pa->getCordY()] = 0;
									pa->setCordX(NewCoords.getScaleCompX());
									pa->setCordY(NewCoords.getScaleCompY());
									pa->Eating(BlackFigures, WhiteFigures, SizeBlack, SizeWhite, EatenByBlack, EatenByWhite, SizeByBlack, SizeByWhite, FD);
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

				thanos.setVolume(50);
				thanos.play();
				(*pa).getSprite().setPosition(tempX, tempY);
				(*pa).getIsMove() = false;
				if (pa->getIsActive() == 0)
				{
					if (turn == 1)
					{
						for (int i = 0; i < SizeByWhite; i++)
						{
							if (EatenByWhite[i] == pa)
							{
								EatenByWhite[i] = &empty;
							}

						}
					}
					else
					{
						for (int i = 0; i < SizeByBlack; i++)
						{
							if (EatenByBlack[i] == pa)
							{
								EatenByBlack[i] = &empty;
							}

						}
					}
				}
				if ((pa->getTransformation() == 0) && (pa->getIsActive() == 1))
				{
					if ((turn == 1))
					{
						if (((pa->getCordX()) >= (pa->getTransformCoordsX())) || (X >= (pa->getTransformCoordsX())))
						{
							if ((pa->getCordX()) >= (pa->getTransformCoordsY()))
							{
								pa->Swap(FS);
								turn = (turn % 2) + 1;
							}

							else
							{
								CanTranSform = 1;

							}
						}
						else
						{
							turn = (turn % 2) + 1;
						}
					}
					else
					{
						if (((pa->getCordX()) <= (pa->getTransformCoordsX())) || (X <= (pa->getTransformCoordsX())))
						{
							if (pa->getCordX() <= (pa->getTransformCoordsY()))
							{
								pa->Swap(FS);
								if (IsMate(BlackFigures, WhiteFigures, turn, SizeBlack, SizeWhite, boardik) == 1)
								{
									EndGame = turn;
								}
								turn = (turn % 2) + 1;
							}
							else
							{
								CanTranSform = 1;

							}
						}
						else
						{
							if (IsMate(BlackFigures, WhiteFigures, turn, SizeBlack, SizeWhite, boardik) == 1)
							{
								EndGame = turn;
							}
							turn = (turn % 2) + 1;
						}
					}
				}

				else
				{
					if (IsMate(BlackFigures, WhiteFigures, turn, SizeBlack, SizeWhite, boardik) == 1)
					{
						EndGame = turn;
					}
					turn = (turn % 2) + 1;
				}
				if (pa->getIsActive() == 0)
					pa->getIsActive() = 1;

			}
		}


		window.clear();


		window.draw(coversprite);
		window.draw(boardsprite);
		window.draw(im);
		if (CanTranSform == 1)
		{
			window.draw(Yes);
			window.draw(No);
			window.draw(mbSwap);
		}
		if (turn == 1)
		{
			YourT.setPosition(750, 50);
			window.draw(YourT);
		}
		else
		{
			YourT.setPosition(750, 950);
			window.draw(YourT);
		}
		window.draw(PawnBlack1.getSprite());
		window.draw(PawnBlack2.getSprite());
		window.draw(PawnBlack3.getSprite());
		window.draw(PawnBlack4.getSprite());
		window.draw(PawnBlack5.getSprite());
		window.draw(PawnBlack6.getSprite());
		window.draw(PawnBlack7.getSprite());
		window.draw(PawnBlack8.getSprite());
		window.draw(PawnBlack9.getSprite());
		window.draw(KingBlack.getSprite());
		window.draw(KnightBlack1.getSprite());
		window.draw(RookBlack1.getSprite());
		window.draw(ArrowBlack1.getSprite());
		window.draw(ArrowBlack2.getSprite());
		window.draw(HorseBlack1.getSprite());
		window.draw(HorseBlack2.getSprite());
		window.draw(GoldBlack1.getSprite());
		window.draw(GoldBlack2.getSprite());
		window.draw(SilverBlack1.getSprite());
		window.draw(SilverBlack2.getSprite());
		window.draw(PawnWhite1.getSprite());
		window.draw(PawnWhite2.getSprite());
		window.draw(PawnWhite3.getSprite());
		window.draw(PawnWhite4.getSprite());
		window.draw(PawnWhite5.getSprite());
		window.draw(PawnWhite6.getSprite());
		window.draw(PawnWhite7.getSprite());
		window.draw(PawnWhite8.getSprite());
		window.draw(PawnWhite9.getSprite());
		window.draw(KingWhite.getSprite());
		window.draw(KnightWhite1.getSprite());
		window.draw(RookWhite1.getSprite());
		window.draw(ArrowWhite1.getSprite());
		window.draw(ArrowWhite2.getSprite());
		window.draw(HorseWhite1.getSprite());
		window.draw(HorseWhite2.getSprite());
		window.draw(GoldWhite1.getSprite());
		window.draw(GoldWhite2.getSprite());
		window.draw(SilverWhite1.getSprite());
		window.draw(SilverWhite2.getSprite());
		if (IsMusic == 0)
		{
			window.draw(NoM);
		}
		else window.draw(YesM);

		if (pa != 0)
		{
			if ((*pa).getIsClicked())

				pa->ShowRoots(TileMap, s_map, window);
		}
		if (EndGame == 1)
		{
			window.draw(VB);
		}
		if (EndGame == 2)
		{
			window.draw(VW);
		}








		window.display();
	}

	return 0;
}
