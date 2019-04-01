#include <SFML/Graphics.hpp>
#include "Figure.h"
using namespace sf;
int main()

{
	int tempX = 0; int tempY = 0;
	int turn = 2;
	float MouseLeft = false;
	Figures KingWhite;
	//Figures KingBlack;
	Figures RookWhite1;
	Figures RookWhite2;
	Figures RookBlack1;
	Figures RookBlack2;
	Figures KnightWhite1;
	Figures KnightWhite2;
	Figures KnightBlack1;
	Figures KnightBlack2;
	Figures PawnWhite1;
	Figures PawnWhite2;
	Figures PawnWhite3;
	Figures PawnWhite4;
	Figures PawnWhite5;
	Figures PawnWhite6;
	Figures PawnWhite7;
	Figures PawnWhite8;
	Figures PawnWhite9;
	Figures PawnBlack1;
	Figures PawnBlack2;
	Figures PawnBlack3;
	Figures PawnBlack4;
	Figures PawnBlack5;
	Figures PawnBlack6;
	Figures PawnBlack7;
	Figures PawnBlack8;
	Figures PawnBlack9;
	Figures SilverWhite1;
	Figures SilverWhite2;
	Figures SilverBlack1;
	Figures SilverBlack2;
	Figures GoldWhite1;
	Figures GoldWhite2;
	Figures GoldBlack1;
	Figures GoldBlack2;
	Figures ArrowWhite1;
	Figures ArrowWhite2;
	Figures ArrowBlack1;
	Figures ArrowBlack2;
	Figures KingBlack(9, 9, 2, "figures1.png", "figures1.png", false);

	Figures *FiguresBlack[20] = {
								 &KingBlack,&ArrowBlack2,&ArrowBlack1,&GoldBlack1,&GoldBlack2,&SilverBlack1,&SilverBlack2,
								 &PawnBlack1,&PawnBlack2,&PawnBlack3,&PawnBlack4,&PawnBlack5,&PawnBlack6,&PawnBlack7,&PawnBlack8,
								 &PawnBlack9,&KnightBlack1,&KnightBlack2,&RookBlack1,&RookBlack2
	};

	Figures *FiguresWhite[20] = {
								 &KingWhite,&ArrowWhite2,&ArrowWhite1,&GoldWhite1,&GoldWhite2,&SilverWhite1,&SilverWhite2,
								 &PawnWhite1,&PawnWhite2,&PawnWhite3,&PawnWhite4,&PawnWhite5,&PawnWhite6,&PawnWhite7,&PawnWhite8,
								 &PawnWhite9,&KnightWhite1,&KnightWhite2,&RookWhite1,&RookWhite2
	};
	Figures *pa;
	pa = &KingWhite;
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


	KingBlack.SetRoots(5, 1, 2, 3, 5, 8);
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
							(*pa).SpriteD.setColor(Color::Green);//красим спрайт в зеленый,тем самым говоря игроку,что он выбрал персонажа и может сделать ход
							(*pa).isClicked = true;
							event.type = Event::MouseButtonReleased;
							MouseLeft = true;
						}
					}
			}
			if (pa != 0)
			{
				if ((*pa).isClicked)
				{
					if (event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
						 if (event.key.code == Mouse::Right)

						{
							(*pa).isClicked = false;
							(*pa).SpriteD.setColor(Color::White);
							MouseLeft = false;
							
							
						}
				
					//if (event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
						 else
						if (event.key.code == Mouse::Left)
						{
							(*pa).isClicked = false;
							(*pa).isMove = true;
							(*pa).SpriteD.setColor(Color::White);
							MouseLeft = false;
							tempX = (pixelPos.x);
							tempY = pixelPos.y;

					    }
				}
				
			}

		}
		if (pa != 0)
		{
			if ((*pa).isMove)
			{
				(*pa).SpriteD.setPosition(tempX, tempY);
				(*pa).isMove = false;
			}
		}


		window.clear();
		window.draw(coversprite);
		window.draw(boardsprite);
		window.draw(KingBlack.SpriteD);
		window.display();
	}

	return 0;
}
