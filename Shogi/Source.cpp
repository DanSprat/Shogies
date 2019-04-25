#include <SFML/Graphics.hpp>
#include "Figures.h"
using namespace sf;
int main()

{
	int tempX = 0; int tempY = 0;
	int turn = 2;
	float MouseLeft = false;
	King KingWhite;
	King KingBlack(9, 9, 2, "figures1.png");
	Rook RookWhite1(6, 5, 1, "figures1.png", "figures1.png");
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
	Figures *pa;
	pa = &RookWhite1;
	float heroteleporttimer = 0;
	Clock clock;
	int boardik[10][10] = { 0,0,0,0,0,0,0,0,0,0,
							0,1,1,1,1,1,1,1,1,1,
							0,0,1,0,0,0,0,0,1,0,
							0,1,1,1,1,1,1,1,1,1,
							0,0,0,0,0,0,0,0,0,0,
							0,0,0,0,0,0,0,0,0,0,
							0,0,0,0,0,0,0,0,0,0,
							0,2,2,2,2,2,2,2,2,2,
							0,0,2,0,0,0,0,0,2,0,
							0,2,2,2,2,2,2,2,2,2 };


	RenderWindow window(VideoMode(1920, 1080), "The Shogi Game");
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


	Image figure;
	figure.loadFromFile("images/figures.png");
	Texture figuretexture;
	figuretexture.loadFromImage(figure);
	Sprite figuresprite;
	figuresprite.setTexture(figuretexture);
	figuresprite.setPosition(555, 135);
	while (window.isOpen())
	{
		Vector2i pixelPos = Mouse::getPosition(window);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (MouseLeft == false)
			{
				if (event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
					if (event.key.code == Mouse::Left)
					{
						pa = SelectedFigure(turn, FiguresBlack, FiguresWhite, pixelPos.x, pixelPos.y);
						if (pa != 0)
						{
							(*pa).SearchRoots(boardik, *pa);
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
								(*pa).getIsClicked() = false;
								(*pa).getIsMove() = true;
								(*pa).getSprite().setColor(Color::White);
								MouseLeft = false;
								tempX = (pixelPos.x);
								tempY = pixelPos.y;

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
			}
		}


		window.clear();
		window.draw(coversprite);
		window.draw(boardsprite);
		window.draw(KingBlack.getSprite());
		window.display();
	}

	return 0;
}
