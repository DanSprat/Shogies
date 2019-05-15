#include "Figure.h"
#include "VectorMove.h"

Figures::Figures(int a, int b, int side, String FS, String FT, bool HaveTransform)
{
	RulesMove = new VectorMove[1];
	roots[10][10];
	memset(roots, 0, sizeof(roots));
	isMove = false; isClicked = false;
	isActive = 1;
	x = a;
	y = b;
	transformation = 0;
	String FileDef = FS;
	String FileTrans = FT;
	SpriteD.setOrigin(55 / 2, 65 / 2);


	//***************************Описываем изображение фигуры в обычном виде*************************//

	ImageD.loadFromFile("images/" + FileDef);
	TextureD.loadFromImage(ImageD);
	SpriteD.setTexture(TextureD);
	SpriteD.setTextureRect(IntRect(34 + (85 * y - 85), 28 + (85 * x - 85), 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
	SpriteD.setPosition(1235, 815);// тут тоже все будет зависеть от координат  p.s Разобраться с картинкой

	///////////////////////////////////////////////////////////////////////////////////////////////////

	//********************Описываем изображение фигуры в трансформированном виде*********************//

	ImageSwap.loadFromFile("images/" + FileTrans);
	TextureSwap.loadFromImage(ImageSwap);
	SpriteSwap.setTexture(TextureSwap);
	SpriteSwap.setTextureRect(IntRect(100, 710, 85, 80));
	//SpriteSwap.setPosition(655, 135);

	///////////////////////////////////////////////////////////////////////////////////////////////////

}

Figures::Figures()  {     }
Figures::~Figures() {     }
King::King()        {     }
Pawn::Pawn()        {     }
Rook::Rook()        {     }
Knight::Knight()    {     }
Arrow::Arrow()      {     }
Horse::Horse()      {     }
Gold::Gold()        {     }
Silver::Silver()    {     }

//////ТУТ БУДУТ ВСЕ GET & PUT ФУНКЦИИ /////////

Sprite& Figures::getSprite()
{
	return this->SpriteD;
}
bool& Figures::getIsMove()
{
	return this->isMove;
}
bool& Figures::getIsClicked()
{
	return this->isClicked;
}
int Figures::getSizeOfRules()
{
	return this->SizeOfRules;
}
int Figures::getCordX()
{
	return this->x;
}
int Figures::getCordY()
{
	return this->y;
}
void Figures::setCordX(int a)
{
	this->x = a;
}
void Figures::setCordY(int a)
{
	this->y = a;
}
int Figures::getSide()
{
	return this->side;
}
int Figures::getTransformCoordsX()
{
	return this->TransformCoords.getScaleCompX();
}
int Figures::getTransformCoordsY()
{
	return this->TransformCoords.getScaleCompY();
}
int Figures::getTransformation()
{
	return this->transformation;
}

//////////////////////////////////////////////


Figures* SelectedFigure(int &turn, Figures* FiguresBlack[], Figures* FiguresWhite[], int x, int y, int SizeB, int SizeW)
{
	if (turn == 2)
	{
		for (int i = 0; i < SizeB; i++)
		{
			if ((*FiguresBlack[i]).getSprite().getGlobalBounds().contains(x, y))
			{
				return FiguresBlack[i];
			}
		}
		return 0;
	}
	else
	{
		for (int i = 0; i < SizeW; i++)
		{
			if ((*FiguresWhite[i]).getSprite().getGlobalBounds().contains(x, y))
			{
				return FiguresWhite[i];
			}
		}
		return 0;
	}

}
King::King(int a, int b, int s)
{
	side = s;
	RulesMove = new VectorMove[8];
	SizeOfRules = 8;
	if (side == 1)
	{
		TransformCoords = { 10,10 };
	}
	else
	{
		TransformCoords = { 0,0 };
	}
	RulesMove[0] = { 0,1 };
	RulesMove[1] = { 1,1 };
	RulesMove[2] = { 1,0 };
	RulesMove[3] = { 1,-1 };
	RulesMove[4] = { -1,1 };
	RulesMove[5] = { -1,0 };
	RulesMove[6] = { 0,-1 };
	RulesMove[7] = { -1,-1 };
	roots[10][10];
	memset(roots, 0, sizeof(roots) / 4);
	isMove = false; isClicked = false;
	isActive = true;
	x = a;
	y = b;
	transformation = 0;
	SpriteD.setOrigin(55 / 2, 65 / 2);
	check = 0;
	checkmate = 0;


	//***************************Описываем изображение фигуры в обычном виде*************************//

	ImageD.loadFromFile("images/figures1.png");
	TextureD.loadFromImage(ImageD);
	SpriteD.setTexture(TextureD);
	//SpriteD.setPosition(615 + 80 * (y - 1) + 5 * (y - 1), 195 + 80 * (x - 1) + 5 * (x - 1));// тут тоже все будет зависеть от координат  p.s Разобраться с картинкой
	SpriteD.setTextureRect(IntRect(34 + (85 * y - 85), 28 + (85 * x - 85), 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
	SpriteD.setPosition(615 + 80 * (y - 1) + 5 * (y - 1), 195 + 80 * (x - 1) + 5 * (x - 1));// тут тоже все будет зависеть от координат  p.s Разобраться с картинкой
}
Pawn::Pawn(int a, int b, int s)
{
	SizeOfRules = 1;
	SizeofRulesTransform = 6;
	RulesMove = new VectorMove[1];
	RulesMoveTransform = new VectorMove[6];
	side = s;
	if (side == 1)
	{
		TransformCoords= { 7,9 };
		RulesMove[0] = { 1,0 };
		RulesMoveTransform[0] = { 0,1 };
		RulesMoveTransform[1] = { 1,0 };
		RulesMoveTransform[2] = { 0,-1 };
		RulesMoveTransform[3] = { -1,0 };
		RulesMoveTransform[4] = { 1,1 };
		RulesMoveTransform[5] = { -1,1 };

	}
	else
	{
		TransformCoords = { 3,1 };
		RulesMove[0] = { -1,0 };
		RulesMoveTransform[0] = { 0,1 };
		RulesMoveTransform[1] = { 1,0 };
		RulesMoveTransform[2] = { 0,-1 };
		RulesMoveTransform[3] = { -1,0 };
		RulesMoveTransform[4] = { -1,-1 };
		RulesMoveTransform[5] = { 1,-1 };
	}
	isActive = true;
	roots[10][10];
	memset(roots, 0, sizeof(roots) / sizeof(roots[0][0]));
	isMove = false; isClicked = false;
	isActive = true;
	x = a;
	y = b;
	transformation = 0;
	HaveTransform = 1;
	SpriteD.setOrigin(55 / 2, 65 / 2);


	//***************************Описываем изображение фигуры в обычном виде*************************//

	ImageD.loadFromFile("images/figures1.png");
	TextureD.loadFromImage(ImageD);
	SpriteD.setTexture(TextureD);
	SpriteD.setTextureRect(IntRect(34 + (85 * y - 85), 28 + (85 * x - 85), 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
	SpriteD.setPosition(615 + 80 * (y - 1) + 5 * (y - 1), 195 + 80 * (x - 1) + 5 * (x - 1));

	///////////////////////////////////////////////////////////////////////////////////////////////////

	//********************Описываем изображение фигуры в трансформированном виде*********************//

	ImageSwap.loadFromFile("images/figures3.png");
	TextureSwap.loadFromImage(ImageSwap);
	SpriteSwap.setTexture(TextureSwap);
	SpriteSwap.setTextureRect(IntRect(100, 710, 85, 80));
	//SpriteSwap.setPosition(655, 135);

	///////////////////////////////////////////////////////////////////////////////////////////////////

}
void Figures::ChangeArr()
{

}
VectorMove Figures::getRulesMove(int i)
{
	return RulesMove[i];
}
Rook::Rook(int a, int b, int s)

{
	side = s;
	if (side == 1)
	{
		TransformCoords = { 7,10 };
	}
	else 
	{
		TransformCoords = { 3,0 };
	}
	SizeOfRules = 32;
	SizeofRulesTransform = 36;
	RulesMove = new VectorMove[32];
	RulesMoveTransform = new VectorMove[36];
	for (int i = 1; i < 9; i++)
	{
		RulesMove[i - 1] = { 1 * i,0 };
		RulesMoveTransform[i - 1] = { 1 * i,0 };

	}
	for (int i = 9; i < 17; i++)
	{
		RulesMove[i - 1] = { -1 * (i - 8),0 };
		RulesMoveTransform[i - 1] = { -1 * (i - 8),0 };
	}
	for (int i = 17; i < 25; i++)
	{
		RulesMove[i - 1] = { 0,1 * (i - 16) };
		RulesMoveTransform[i - 1] = { 0,1 * (i - 16) };
	}
	for (int i = 25; i < 33; i++)
	{
		RulesMove[i - 1] = { 0,-1 * (i - 24) };
		RulesMoveTransform[i - 1] = { 0,-1 * (i - 24) };
	}
	RulesMoveTransform[32] = { 1, -1 };
	RulesMoveTransform[33] = { 1, 1 };
	RulesMoveTransform[34] = { -1, -1 };
	RulesMoveTransform[35] = { -1, -1 };
	roots[10][10];
	memset(roots, 0, sizeof(roots) / sizeof(roots[0][0]));
	isMove = false; isClicked = false;
	isActive = true;
	x = a;
	y = b;
	transformation = 0;
	HaveTransform = 1;
	SpriteD.setOrigin(55 / 2, 65 / 2);
	

	//***************************Описываем изображение фигуры в обычном виде*************************//

	ImageD.loadFromFile("images/figures1.png");
	TextureD.loadFromImage(ImageD);
	SpriteD.setTexture(TextureD);
	SpriteD.setTextureRect(IntRect(34 + (85 * y - 85), 28 + (85 * x - 85), 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
	SpriteD.setPosition(615 + 80 * (y - 1) + 5 * (y - 1), 195 + 80 * (x - 1) + 5 * (x - 1));

	///////////////////////////////////////////////////////////////////////////////////////////////////

	//********************Описываем изображение фигуры в трансформированном виде*********************//

	ImageSwap.loadFromFile("images/figures1.png");
	TextureSwap.loadFromImage(ImageSwap);
	SpriteSwap.setTexture(TextureSwap);
	SpriteSwap.setTextureRect(IntRect(100, 710, 85, 80));
	//SpriteSwap.setPosition(655, 135);

	///////////////////////////////////////////////////////////////////////////////////////////////////


}

Knight::Knight(int a, int b, int s)
{
	side = s;
	
	if (side == 1)
	{
		TransformCoords = { 7,10 };
	}
	else
	{
		TransformCoords = { 3,0 };
	}
	SizeofRulesTransform = 36;
	SizeOfRules = 32;
	RulesMove = new VectorMove[32];
	RulesMoveTransform = new VectorMove[36];
	for (int i = 1; i < 9; i++)
	{
		RulesMove[i - 1] = { 1 * i,1 * i };
		RulesMoveTransform[i - 1] = { 1 * i,1 * i };

	}
	for (int i = 9; i < 17; i++)
	{
		RulesMove[i - 1] = { -1 * (i - 8),1 * (i - 8) };
		RulesMoveTransform[i - 1] = { -1 * (i - 8),1 * (i - 8) };
	}
	for (int i = 17; i < 25; i++)
	{
		RulesMove[i - 1] = { -1 * (i - 16),-1 * (i - 16) };
		RulesMoveTransform[i - 1] = { -1 * (i - 16),-1 * (i - 16) };
	}
	for (int i = 25; i < 33; i++)
	{
		RulesMove[i - 1] = { 1 * (i - 24),-1 * (i - 24) };
		RulesMoveTransform[i - 1] = { 1 * (i - 24),-1 * (i - 24) };
	}

	RulesMoveTransform[32] = { 1, 0 };
	RulesMoveTransform[33] = { 0, 1 };
	RulesMoveTransform[34] = { -1, 0 };
	RulesMoveTransform[35] = { 0, -1 };
	roots[10][10];
	memset(roots, 0, sizeof(roots));
	isMove = false; isClicked = false;
	isActive = true;
	x = a;
	y = b;

	transformation = 0;
	HaveTransform = 1;
	SpriteD.setOrigin(55 / 2, 65 / 2);

	//***************************Описываем изображение фигуры в обычном виде*************************//

	ImageD.loadFromFile("images/figures1.png");
	TextureD.loadFromImage(ImageD);
	SpriteD.setTexture(TextureD);
	SpriteD.setTextureRect(IntRect(34 + (85 * y - 85), 28 + (85 * x - 85), 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
	SpriteD.setPosition(615 + 80 * (y - 1) + 5 * (y - 1), 195 + 80 * (x - 1) + 5 * (x - 1));

	///////////////////////////////////////////////////////////////////////////////////////////////////

	//********************Описываем изображение фигуры в трансформированном виде*********************//

	ImageSwap.loadFromFile("images/figures1.png");
	TextureSwap.loadFromImage(ImageSwap);
	SpriteSwap.setTexture(TextureSwap);
	SpriteSwap.setTextureRect(IntRect(100, 710, 85, 80));
	//SpriteSwap.setPosition(655, 135);

	///////////////////////////////////////////////////////////////////////////////////////////////////
}


Arrow::Arrow(int a, int b, int s)
{
	side = s;
	SizeOfRules = 8;
	SizeofRulesTransform = 6;
	RulesMoveTransform = new VectorMove[6];
	RulesMove = new VectorMove[8];
	if (side == 1)
	{
		TransformCoords = { 7,9 };
		for (int i = 1; i < 9; i++)
		{
			RulesMove[i - 1] = { 1 * i,0 };
		}

	}
	else 
	{
		TransformCoords = { 3,1 };
		for (int i = 1; i < 9; i++)
		{
			RulesMove[i - 1] = { -1 * i,0 };
		}
	}
	if (side == 1)
	{
		RulesMoveTransform[0] = { 0,1 };
		RulesMoveTransform[1] = { 1,0 };
		RulesMoveTransform[2] = { 0,-1 };
		RulesMoveTransform[3] = { -1,0 };
		RulesMoveTransform[4] = { 1,1 };
		RulesMoveTransform[5] = { -1,1 };

	}
	else
	{
		RulesMoveTransform[0] = { 0,1 };
		RulesMoveTransform[1] = { 1,0 };
		RulesMoveTransform[2] = { 0,-1 };
		RulesMoveTransform[3] = { -1,0 };
		RulesMoveTransform[4] = { -1,-1 };
		RulesMoveTransform[5] = { 1,-1 };
	}
	roots[10][10];
	memset(roots, 0, sizeof(roots) / sizeof(roots[0][0]));
	isMove = false; isClicked = false;
	isActive = true;
	x = a;
	y = b;
	transformation = 0;
	HaveTransform = 1;
	SpriteD.setOrigin(55 / 2, 65 / 2);

	//***************************Описываем изображение фигуры в обычном виде*************************//

	ImageD.loadFromFile("images/figures1.png");
	TextureD.loadFromImage(ImageD);
	SpriteD.setTexture(TextureD);
	SpriteD.setTextureRect(IntRect(34 + (85 * y - 85), 28 + (85 * x - 85), 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
	SpriteD.setPosition(615 + 80 * (y - 1) + 5 * (y - 1), 195 + 80 * (x - 1) + 5 * (x - 1));

	///////////////////////////////////////////////////////////////////////////////////////////////////

	//********************Описываем изображение фигуры в трансформированном виде*********************//

	ImageSwap.loadFromFile("images/figures1.png");
	TextureSwap.loadFromImage(ImageSwap);
	SpriteSwap.setTexture(TextureSwap);
	SpriteSwap.setTextureRect(IntRect(100, 710, 85, 80));
	//SpriteSwap.setPosition(655, 135);

	///////////////////////////////////////////////////////////////////////////////////////////////////

}
Horse::Horse(int a, int b, int s)
{
	side = s;
	SizeOfRules = 2;
	SizeofRulesTransform = 6;
	RulesMoveTransform = new VectorMove[6];
	RulesMove = new VectorMove[2];
	if (side == 1)
	{
		TransformCoords = { 7,8 };
		RulesMove[0] = { 2,1 };
		RulesMove[1] = { 2,-1 };
		RulesMoveTransform[0] = { 0,1 };
		RulesMoveTransform[1] = { 1,0 };
		RulesMoveTransform[2] = { 0,-1 };
		RulesMoveTransform[3] = { -1,0 };
		RulesMoveTransform[4] = { 1,1 };
		RulesMoveTransform[5] = { -1,1 };

	}
	else
	{
		TransformCoords = { 3,2 };
		RulesMove[0] = { -2,1 };
		RulesMove[1] = { -2,-1 };
		RulesMoveTransform[0] = { 0,1 };
		RulesMoveTransform[1] = { 1,0 };
		RulesMoveTransform[2] = { 0,-1 };
		RulesMoveTransform[3] = { -1,0 };
		RulesMoveTransform[4] = { -1,-1 };
		RulesMoveTransform[5] = { 1,-1 };
	}

	roots[10][10];
	memset(roots, 0, sizeof(roots) / sizeof(roots[0][0]));
	isMove = false; isClicked = false;
	isActive = true;
	x = a;
	y = b;

	transformation = 0;
	HaveTransform = 1;
	SpriteD.setOrigin(55 / 2, 65 / 2);

	//***************************Описываем изображение фигуры в обычном виде*************************//

	ImageD.loadFromFile("images/figures1.png");
	TextureD.loadFromImage(ImageD);
	SpriteD.setTexture(TextureD);
	SpriteD.setTextureRect(IntRect(34 + (85 * y - 85), 28 + (85 * x - 85), 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
	SpriteD.setPosition(615 + 80 * (y - 1) + 5 * (y - 1), 195 + 80 * (x - 1) + 5 * (x - 1));

	///////////////////////////////////////////////////////////////////////////////////////////////////

	//********************Описываем изображение фигуры в трансформированном виде*********************//

	ImageSwap.loadFromFile("images/figures1.png");
	TextureSwap.loadFromImage(ImageSwap);
	SpriteSwap.setTexture(TextureSwap);
	SpriteSwap.setTextureRect(IntRect(100, 710, 85, 80));
	//SpriteSwap.setPosition(655, 135);

	///////////////////////////////////////////////////////////////////////////////////////////////////
}
Gold::Gold(int a, int b, int s) {
	side = s;
	SizeOfRules = 6;
	RulesMove = new VectorMove[6];
	if (side == 1)
	{
		TransformCoords = { 10,10 };
		RulesMove[0] = { 1,1 };
		RulesMove[1] = { 1,0 };
		RulesMove[2] = { 1,-1 };
		RulesMove[3] = { 0,1 };
		RulesMove[4] = { 0,-1 };
		RulesMove[5] = { -1,0 };

	}
	else
	{
		TransformCoords = { 0,0 };
		RulesMove[0] = { -1,1 };
		RulesMove[1] = { -1,0 };
		RulesMove[2] = { -1,-1 };
		RulesMove[3] = { 1,0 };
		RulesMove[4] = { 0,-1 };
		RulesMove[5] = { 0,1 };
	}
	roots[10][10];
	memset(roots, 0, sizeof(roots) / sizeof(roots[0][0]));
	isMove = false; isClicked = false;
	isActive = true;
	x = a;
	y = b;
	transformation = 0;
	SpriteD.setOrigin(55 / 2, 65 / 2);

	//***************************Описываем изображение фигуры в обычном виде*************************//

	ImageD.loadFromFile("images/figures1.png");
	TextureD.loadFromImage(ImageD);
	SpriteD.setTexture(TextureD);
	SpriteD.setTextureRect(IntRect(34 + (85 * y - 85), 28 + (85 * x - 85), 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
	SpriteD.setPosition(615 + 80 * (y - 1) + 5 * (y - 1), 195 + 80 * (x - 1) + 5 * (x - 1));

	///////////////////////////////////////////////////////////////////////////////////////////////////

}
Silver::Silver(int a, int b, int s)
{
	side = s;
	SizeofRulesTransform = 6;
	RulesMove = new VectorMove[5];
	RulesMoveTransform = new VectorMove[6];
	SizeOfRules = 5;
	if (side == 1)
	{
		TransformCoords = {7,10};
		RulesMove[0] = { 1,1 };
		RulesMove[1] = { 1,-1 };
		RulesMove[2] = { 1,0 };
		RulesMove[3] = { -1,1 };
		RulesMove[4] = { -1,-1 };
		RulesMoveTransform[0] = { 1,1 };
		RulesMoveTransform[1] = { 1,0 };
		RulesMoveTransform[2] = { 1,-1 };
		RulesMoveTransform[3] = { 0,1 };
		RulesMoveTransform[4] = { 0,-1 };
		RulesMoveTransform[5] = { -1,0 };

	}
	else
	{
		TransformCoords = { 3,1 };
		RulesMove[0] = { -1,1 };
		RulesMove[1] = { -1,-1 };
		RulesMove[2] = { -1,0 };
		RulesMove[3] = { 1,-1 };
		RulesMove[4] = { 1,1 };
	}

	roots[10][10];
	memset(roots, 0, sizeof(roots) / sizeof(roots[0][0]));
	isMove = false; isClicked = false;
	isActive = true;
	HaveTransform = 1;
	transformation = 0;
	x = a;
	y = b;

	transformation = 0;
	SpriteD.setOrigin(55 / 2, 65 / 2);

	//***************************Описываем изображение фигуры в обычном виде*************************//

	ImageD.loadFromFile("images/figures1.png");
	TextureD.loadFromImage(ImageD);
	SpriteD.setTexture(TextureD);
	SpriteD.setTextureRect(IntRect(34 + (85 * y - 85), 28 + (85 * x - 85), 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
	SpriteD.setPosition(615 + 80 * (y - 1) + 5 * (y - 1), 195 + 80 * (x - 1) + 5 * (x - 1));

	///////////////////////////////////////////////////////////////////////////////////////////////////

}
void Figures::SearchRoots(Figures *FiguresB[], Figures* FiguresW[], int array[10][10], Figures& pa, int SizeB, int SizeW)
{

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			roots[i][j] = 0;
		}
	int i = 0;
	int  tempX = 0;
	int tempY = 0;
	int k = sizeof(RulesMove);
	for (i = 0; i < SizeOfRules; i++)
	{
		tempX = x + RulesMove[i].getScaleCompX();
		tempY = y + RulesMove[i].getScaleCompY();

		if ((tempX < 10) && (tempX > 0) && (tempY < 10) && (tempY > 0))
		{
			if ((SizeOfRules > 7) && ((typeid(pa).name())!= typeid(King).name()))
			{
				if ((array[tempX][tempY] != side) && ((pa).CheckCheck(FiguresB, FiguresW, pa, array, RulesMove[i].getScaleCompX(), RulesMove[i].getScaleCompY(), SizeB, SizeW) == 1)&&(CheckCheck(FiguresB, FiguresW, pa, array, 0, 0, SizeB, SizeW) == 1))
				{
					roots[tempX][tempY] = 1;
					if (array[tempX][tempY] == 0)
					{
						
					}
					else
					{
						if (i<32)
							while (i%8!=7)
							{
								i++;
							}
						

						
					}
				}
				else
				{
					if (CheckCheck(FiguresB, FiguresW, pa, array, 0, 0, SizeB, SizeW) == 1)
					{
						if (i < 32)
							while (i % 8 != 7)
							{
								i++;
							}
					}
					else
					{
						if (array[tempX][tempY] != side)
						{


							if ((pa).CheckCheck(FiguresB, FiguresW, pa, array, RulesMove[i].getScaleCompX(), RulesMove[i].getScaleCompY(), SizeB, SizeW) == 1)
							{
								if (array[tempX][tempY] == 0)
								{
									roots[tempX][tempY] = 1;
								}
								else
								{
									roots[tempX][tempY] = 1;
									if (i < 32)
										while (i % 8 != 7)
										{
											i++;
										}
								}
							}
								
							
						}
						else
						{
							if (i < 32)
								while (i % 8 != 7)
								{
									i++;
								}
						}
					}
					
				

				}
			}
			else if ((array[tempX][tempY] != side) && ((pa).CheckCheck(FiguresB, FiguresW, pa, array, RulesMove[i].getScaleCompX(), RulesMove[i].getScaleCompY(), SizeB, SizeW) == 1))
			{
				roots[tempX][tempY] = 1;
			}
			else
			{
				roots[tempX][tempY] = 0;
			}

		}
	}	
}
bool Figures::CheckCheck(Figures* FiguresB[], Figures* FiguresW[], Figures &a, int array[10][10], int NewX, int NewY, int SizeB, int SizeW)
{
	int arrayHelp[10][10];
	//Template(arrayHelp, array);
	int mate = 0;
	int KingX, KingY;
	int k=-1;
	if (side == 1)
	{
		if (array[x + NewX][y + NewY] == 2)
		{
			for (int i = 0; i<SizeB; i++)
			{
				if ((x + NewX == FiguresB[i]->x) && (y + NewY == FiguresB[i]->y))
					k = i;
			}
		}
		
		KingX = (*FiguresW[0]).getCordX();
		KingY = (*FiguresW[0]).getCordY();
		if ((x == KingX) && (y == KingY))
		{
			KingX += NewX;
			KingY += NewY;
			arrayHelp[x][y] = 0;///
			arrayHelp[KingX][KingY] = 1;
		}
		for (int i = 0; i < SizeB; i++)
		{
			if (i != k)
			{
				
				Template(arrayHelp, array);
				arrayHelp[x][y] = 0;
				arrayHelp[x + NewX][y + NewY] = 1;
				if ((*FiguresB[i]).IsCheck(arrayHelp, KingX, KingY) == true)
				{
					return false;
				}
			}
		}
		return true;

	}
	if (side == 2)
	{
		if (array[x + NewX][y + NewY] == 1)
		{
			for (int i = 0; i < SizeW; i++)
			{
				if ((x + NewX == FiguresW[i]->x) && (y + NewY == FiguresW[i]->y))
					k = i;
			}
		}
		KingX = (*FiguresB[0]).getCordX();
		KingY = (*FiguresB[0]).getCordY();
		if ((x == KingX) && (y == KingY))
		{
			KingX += NewX;
			KingY += NewY;
			arrayHelp[x][y] = 0;///
			arrayHelp[KingX][KingY] = 2;
		}
		for (int i = 0; i < SizeW; i++)
		{
			if (i != k)
			{
				Template(arrayHelp, array);
				arrayHelp[x][y] = 0;
				arrayHelp[x + NewX][y + NewY] = 2;
             if ((*FiguresW[i]).IsCheck(arrayHelp, KingX, KingY) == true)
				{
					return false;
				}
			}
		}
		return true;
	}

}
bool Figures::IsCheck(int Arr[10][10], int a, int b)
{
	int TempX;
	int TempY;
	int Size = 0;
	int Middle = 0;
	for (int i = 0; i < SizeOfRules; i++)
	{
		if ((a == x + RulesMove[i].getScaleCompX()) && (b == y + RulesMove[i].getScaleCompY()))
		{
			TempX = RulesMove[i].getScaleCompX();
			TempY = RulesMove[i].getScaleCompY();
			if (abs(TempX) > abs(TempY))
			{
				Size = abs(TempX);
				TempX = TempX / abs(TempX);
				TempY = TempY / abs(TempX);
			}
			else
			{
				Size = abs(TempY);
				TempX = TempX / abs(TempY);
				TempY = TempY / abs(TempY);
			}
			for (int j = 1; j < Size; j++)
			{
				if (Arr[x + (TempX*j)][y + (TempY*j)] != 0)
				{
					return false;
				}
			}
			return true;
		}
	}
	if (Middle == 0)
	{
		return false;
	}

}
void Figures::ShowRoots(String *array, Sprite& a, RenderWindow& b)
{
	for (int i = 1; i < 10; i++)
		for (int j = 1; j < 10; j++)
		{
			array[i][j] = ' ';

		}
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			if (roots[i][j] == 1)
			{
				array[i][j] = 'G';
			}
		}
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			if (array[i][j] == 'G')  a.setTextureRect(IntRect(0, 0, 80, 80)); //
			if ((array[i][j] == '0')) a.setTextureRect(IntRect(80, 0, 80, 80));
			if ((array[i][j] == ' ')) a.setTextureRect(IntRect(80, 0, 80, 80));



			a.setPosition((555 - 65) + j * 80 + (5 * j), (135 - 65) + i * 80 + (5 * i));//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат

			b.draw(a);//рисуем квадратики на экран
		}
}
int* Figures::getRoots()
{
	return *roots;
}
bool Figures::CheckTrue(int x, int y, VectorMove& a)
{
	int c, b;
	c = (y - 155) / 85 + 1;
	b = ((x - 575) / 85 + 1);
	if ((c > 0) && (c < 10) && (b > 0) && (b < 10))
	{
		if (roots[c][b] == 1)
		{
			a.getCompX() = c;
			a.getCompY() = b;
			return true;
		}
	}



	return false;
}
void Template(int a[10][10], int b[10][10])
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			a[i][j] = b[i][j];
}
bool Figures::Eating(Figures  **&b, Figures **&w, int& sizeb, int& sizew, Figures **&byB, Figures **&byW, int& sizebyB, int&sizebyW)
{
	Figures empty;
	bool isEmpty=0;
	int k;
	if (side == 1)
	{
		for (int i = 0; i < sizeb; i++)
		{
			if ((x == (*b[i]).getCordX()) && (y == (*b[i]).getCordY()))
			{
				b[i]->side = 1;
				b[i]->isActive = 0;
				b[i]->x = -100;
				b[i]->y = -100;
				Figures **NewB;
				Figures **NewW;
				sizeb -= 1;
				sizew += 1;
				
				NewB = new Figures *[sizeb];
				NewW = new Figures *[sizew];
				
				for (int j = 0; j < sizebyW; j++)
				{
					if (*byW[j] == empty)
					{
						isEmpty = true;
						k = j;
						break;
					}
				}
				if (isEmpty == true)
				{
					byW[k] = b[i];
					byW[k]->getSprite().setPosition(1400+90*k, 240);
				}
				else
				{
					Figures **byWhite;
					sizebyW += 1;
					byWhite = new Figures *[sizebyW];
					for (int j = 0; j < sizebyW - 1; j++)
					{
						byWhite[j] = byW[j];
					}
					byWhite[sizebyW - 1] = b[i];
					
					byW = byWhite;
					(**&byW[sizebyW - 1]).getSprite().setPosition(500 - 80 * (sizebyW - 1), 365);
					(**&byW[sizebyW - 1]).getSprite().rotate(180);
				}
				for (int j = 0; j < i; j++)
				{
					NewB[j] = b[j];
				}
				for (int j = i; j < sizeb; j++)
				{
					NewB[j] = b[j + 1];
				}
				for (int j = 0; j < sizew - 1; j++)
				{
					NewW[j] = w[j];
				}
                NewW[sizew - 1] = b[i];
				b = NewB;
				w = NewW;
				
				return true;
			}
		}
		return false;
	}
	else
	{
		for (int i = 0; i < sizew; i++)
		{
			if ((x == (*w[i]).getCordX()) && (y == (*w[i]).getCordY()))
			{
				w[i]->side = 1;
				w[i]->isActive = 0;
				w[i]->x = -100;
				w[i]->y = -100;
				sizew -= 1;
				sizeb += 1;
				Figures **NewB;
				Figures **NewW;
				
				
				NewB = new Figures *[sizeb];
				NewW = new Figures *[sizew];
				for (int j = 0; j < sizebyB; j++)
				{
					if (*byB[j] == empty)
					{
						isEmpty = true;
						k = j;
						break;
					}
				}
					if (isEmpty == true)
					{
						byB[k] = w[i];
					}
					else
					{
						Figures **byBlack;
						sizebyB += 1;
						byBlack = new Figures *[sizebyB];
						for (int j = 0; j < sizebyB - 1; j++)
						{
							byBlack[j] = byB[j];
						}
						byBlack[sizebyB - 1] = w[i];
						byB = byBlack;
						(**&byB[sizebyB - 1]).getSprite().setPosition(1450 + 70 * ((sizebyB - 1)%5), 710 + 80*((sizebyB-1)/5));
						(**&byB[sizebyB - 1]).getSprite().rotate(180);
					}
				
				for (int j = 0; j < i; j++)
				{
					NewW[j] = w[j];
				}
				for (int j = i; j < sizew; j++)
				{
					NewW[j] = w[j + 1];
				}
				for (int j = 0; j < sizeb - 1; j++)
				{
					NewB[j] = b[j];
				}
				NewB[sizeb - 1] = w[i];
				b = NewB;
				w = NewW;
				return true;
			}
		}
		return false;
	}
}
bool operator==(Figures& left, Figures& right)
{
	
	if ((left.x == right.x) && (left.y == right.y) && (left.side == right.side) && (left.SizeOfRules == right.SizeOfRules) && (left.isActive == right.isActive))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Figures::Swap()
{
	SpriteD.setTexture(TextureSwap);
	this->transformation = 1;
	
}
