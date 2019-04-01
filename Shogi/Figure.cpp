#include "Figure.h"


Figures::Figures(float x, float y, int side, String FS, String FT, bool HaveTransform)
{

	roots[10][10];
	memset(roots, 0, sizeof(roots));
	isMove = false; isClicked = false;
	float X, Y;
	X = x;
	Y = y;
	check = false;
	checkmate = false;
	transformation = 0;
	String FileDef = FS;
	String FileTrans = FT;
	SpriteD.setOrigin(75 / 2, 75 / 2);


	//***************************Описываем изображение фигуры в обычном виде*************************//

	ImageD.loadFromFile("images/" + FileDef);
	TextureD.loadFromImage(ImageD);
	SpriteD.setTexture(TextureD);
	SpriteD.setTextureRect(IntRect(33, 709, 55, 65));
	SpriteD.setPosition(1235, 815);

	///////////////////////////////////////////////////////////////////////////////////////////////////

	//********************Описываем изображение фигуры в трансформированном виде*********************//

	ImageSwap.loadFromFile("images/" + FileTrans);
	TextureSwap.loadFromImage(ImageSwap);
	SpriteSwap.setTexture(TextureSwap);
	SpriteSwap.setTextureRect(IntRect(100, 710, 85, 80));
	SpriteSwap.setPosition(655, 135);
	
	///////////////////////////////////////////////////////////////////////////////////////////////////

}
void Figures::SetRoots(int n, int first, ...)
{
	int *pi = &first;
	while (n--)
	{
		this->roots[(*pi / 9) + 1][*pi % 9] = 1;
		pi++;
	}
}

Figures::Figures()
{

}

Figures::~Figures()
{
}
Figures* SelectedFigure(int &turn, Figures* FiguresBlack[], Figures* FiguresWhite[], int x, int y)
{
	if (turn == 2)
	{
		for (int i = 0; i < 20; i++)
		{
			if ((*FiguresBlack[i]).SpriteD.getGlobalBounds().contains(x, y))
			{
				return FiguresBlack[i];
			}
		}
		return 0;
	}
	else
	{
		for (int i = 0; i < 20; i++)
		{
			if ((*FiguresWhite[i]).SpriteD.getGlobalBounds().contains(x, y))
			{
				return FiguresWhite[i];
			}
		}
		return 0;
	}

}


