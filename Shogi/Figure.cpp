#include "Figure.h"


Figures::Figures(float x, float y, int side, String FS, String FT, bool HaveTransform)
{

	roots[10][10];
	memset(roots, 0, sizeof(roots));
	isMove = false; isClicked = false;
	float X, Y;
	X = x;
	Y = y;
	transformation = 0;
	String FileDef = FS;
	String FileTrans = FT;
	SpriteD.setOrigin(55 / 2, 65 / 2);


	//***************************Описываем изображение фигуры в обычном виде*************************//

	ImageD.loadFromFile("images/" + FileDef);
	TextureD.loadFromImage(ImageD);
	SpriteD.setTexture(TextureD);
	SpriteD.setTextureRect(IntRect(33, 709, 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
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

Figures::Figures()
{

}
Figures::~Figures()
{
}
King::King()
{

}
Pawn::Pawn()
{

}
Rook::Rook()
{

}
Knight::Knight()
{

}
Arrow::Arrow()
{

}
Horse::Horse()
{

}
Gold::Gold()
{

}
Silver::Silver()
{

}

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

//////////////////////////////////////////////


Figures* SelectedFigure(int &turn, Figures* FiguresBlack[], Figures* FiguresWhite[], int x, int y)
{
	if (turn == 2)
	{
		for (int i = 0; i < 20; i++)
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
		for (int i = 0; i < 20; i++)
		{
			if ((*FiguresWhite[i]).getSprite().getGlobalBounds().contains(x, y))
			{
				return FiguresWhite[i];
			}
		}
		return 0;
	}

}
King::King(float x, float y, int side, String FS)
{
	roots[10][10];
	memset(roots, 0, sizeof(roots));
	isMove = false; isClicked = false;
	float X, Y;
	X = x;
	Y = y;
	transformation = 0;
	String FileDef = FS;
	SpriteD.setOrigin(55 / 2, 65 / 2);
	check = 0;
	checkmate = 0;


	//***************************Описываем изображение фигуры в обычном виде*************************//

	ImageD.loadFromFile("images/" + FileDef);
	TextureD.loadFromImage(ImageD);
	SpriteD.setTexture(TextureD);
	SpriteD.setTextureRect(IntRect(33, 709, 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
	SpriteD.setPosition(1235, 815);// тут тоже все будет зависеть от координат  p.s Разобраться с картинкой
}
Pawn::Pawn(float x, float y, int side, String FS, String FT)
{
	RulesMove = new VectorMove[1];
	if (side == 1)
	{
		RulesMove[0] = { 0,1 };
		RulesMoveTransform[0] = { 0,1 };
		RulesMoveTransform[1] = { 1,0 };
		RulesMoveTransform[2] = { 0,-1 };
		RulesMoveTransform[3] = { -1,0 };
		RulesMoveTransform[4] = { 1,1 };
		RulesMoveTransform[5] = { -1,1 };

	}
	else
	{
		RulesMove[0] = { 0,-1 };
		RulesMoveTransform[0] = { 0,1 };
		RulesMoveTransform[1] = { 1,0 };
		RulesMoveTransform[2] = { 0,-1 };
		RulesMoveTransform[3] = { -1,0 };
		RulesMoveTransform[4] = { -1,-1 };
		RulesMoveTransform[5] = { 1,-1 };
	}

	roots[10][10];
	memset(roots, 0, sizeof(roots));
	isMove = false; isClicked = false;
	float X, Y;
	X = x;
	Y = y;
	transformation = 0;
	HaveTransform = 1;
	String FileDef = FS;
	String FileTrans = FT;
	SpriteD.setOrigin(55 / 2, 65 / 2);


	//***************************Описываем изображение фигуры в обычном виде*************************//

	ImageD.loadFromFile("images/" + FileDef);
	TextureD.loadFromImage(ImageD);
	SpriteD.setTexture(TextureD);
	SpriteD.setTextureRect(IntRect(33, 709, 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
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
void Figures::ChangeArr()
{

}
VectorMove Figures::getRulesMove(int i)
{
	return RulesMove[i];
}
Rook::Rook(float x, float y, int side, String FS, String FT)
{
	RulesMove = new VectorMove[32];
	for (int i = 1; i < 9; i++)
	{
		RulesMove[i-1] = { 1 * i,0 };
		RulesMoveTransform[i - 1] = { 1 * i,0 };

    }
	for (int i = 9; i < 17; i++)
	{
		RulesMove[i-1] = { -1 * (i-8),0 };
		RulesMoveTransform[i - 1] = { -1 * (i - 8),0 };
	}
	for (int i = 17; i < 25; i++)
	{
		RulesMove[i-1] = { 0,1* (i - 16) };
		RulesMoveTransform[i - 1] = { 0,1 * (i - 16) };
	}
	for (int i = 25; i < 33; i++)
	{
		RulesMove[i-1] = { 0,-1* (i - 24) };
		RulesMoveTransform[i - 1] = { 0,-1 * (i - 24) };
	}
	RulesMoveTransform[32] = { 1, -1 };
	RulesMoveTransform[33] = { 1, 1 };
	RulesMoveTransform[34] = { -1, -1 };
	RulesMoveTransform[35] = { -1, -1 };
	
	roots[10][10];
	memset(roots, 0, sizeof(roots));
	isMove = false; isClicked = false;
	float X, Y;
	X = x;
	Y = y;
	transformation = 0;
	HaveTransform = 1;
	String FileDef = FS;
	String FileTrans = FT;
	SpriteD.setOrigin(55 / 2, 65 / 2);

	//***************************Описываем изображение фигуры в обычном виде*************************//

	ImageD.loadFromFile("images/" + FileDef);
	TextureD.loadFromImage(ImageD);
	SpriteD.setTexture(TextureD);
	SpriteD.setTextureRect(IntRect(33, 709, 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
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

Knight::Knight(float x, float y, int side, String FS, String FT)
{
	RulesMove = new VectorMove[32];
	for (int i = 1; i < 9; i++)
	{
		RulesMove[i - 1] = { 1 * i,1*i };
		RulesMoveTransform[i - 1] = { 1 * i,1*i };

	}
	for (int i = 9; i < 17; i++)
	{
		RulesMove[i - 1] = { -1 * (i - 8),1* (i - 8) };
		RulesMoveTransform[i - 1] = { -1 * (i - 8),1 * (i - 8) };
	}
	for (int i = 17; i < 25; i++)
	{
		RulesMove[i - 1] = { -1 * (i - 16),-1 * (i - 16) };
		RulesMoveTransform[i - 1] = { -1 * (i - 16),-1 * (i - 16) };
	}
	for (int i = 25; i < 33; i++)
	{
		RulesMove[i - 1] = { 1 * (i - 16),-1 * (i - 16) };
		RulesMoveTransform[i - 1] = { 1 * (i - 16),-1 * (i - 16) };
	}

	RulesMoveTransform[32] = { 1, 0 };
	RulesMoveTransform[33] = { 0, 1 };
	RulesMoveTransform[34] = { -1, 0 };
	RulesMoveTransform[35] = { 0, -1 };
	roots[10][10];
	memset(roots, 0, sizeof(roots));
	isMove = false; isClicked = false;
	float X, Y;
	X = x;
	Y = y;
	transformation = 0;
	HaveTransform = 1;
	String FileDef = FS;
	String FileTrans = FT;
	SpriteD.setOrigin(55 / 2, 65 / 2);

	//***************************Описываем изображение фигуры в обычном виде*************************//

	ImageD.loadFromFile("images/" + FileDef);
	TextureD.loadFromImage(ImageD);
	SpriteD.setTexture(TextureD);
	SpriteD.setTextureRect(IntRect(33, 709, 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
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


Arrow::Arrow(float x, float y, int side, String FS, String FT)
{
	RulesMove = new VectorMove[16];
	for (int i = 1; i < 9; i++)
	{
		RulesMove[i - 1] = { 0,1 * i };
	}
	for (int i = 9; i < 17; i++)
	{
		RulesMove[i - 1] = { 0,-1 * (i-8) };
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
	memset(roots, 0, sizeof(roots));
	isMove = false; isClicked = false;
	float X, Y;
	X = x;
	Y = y;
	transformation = 0;
	HaveTransform = 1;
	String FileDef = FS;
	String FileTrans = FT;
	SpriteD.setOrigin(55 / 2, 65 / 2);

	//***************************Описываем изображение фигуры в обычном виде*************************//

	ImageD.loadFromFile("images/" + FileDef);
	TextureD.loadFromImage(ImageD);
	SpriteD.setTexture(TextureD);
	SpriteD.setTextureRect(IntRect(33, 709, 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
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
Horse::Horse(float x, float y, int side, String FS, String FT)
{
	RulesMove = new VectorMove[2];
	if (side == 1)
	{
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
	memset(roots, 0, sizeof(roots));
	isMove = false; isClicked = false;
	float X, Y;
	X = x;
	Y = y;
	transformation = 0;
	HaveTransform = 1;
	String FileDef = FS;
	String FileTrans = FT;
	SpriteD.setOrigin(55 / 2, 65 / 2);

	//***************************Описываем изображение фигуры в обычном виде*************************//

	ImageD.loadFromFile("images/" + FileDef);
	TextureD.loadFromImage(ImageD);
	SpriteD.setTexture(TextureD);
	SpriteD.setTextureRect(IntRect(33, 709, 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
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
 Gold::Gold(float x, float y, int side, String FS) {
	 RulesMove = new VectorMove[6];
	 if (side == 1)
	 {
		 RulesMove[0] = { 0,1 };
		 RulesMove[1] = { 1,0 };
		 RulesMove[2] = { 0,-1 };
		 RulesMove[3] = { -1,0 };
		 RulesMove[4] = { 1,1 };
		 RulesMove[5] = { -1,1 };

	 }
	 else
	 {
		 RulesMove[0] = { 0,1 };
		 RulesMove[1] = { 1,0 };
		 RulesMove[2] = { 0,-1 };
		 RulesMove[3] = { -1,0 };
		 RulesMove[4] = { -1,-1 };
		 RulesMove[5] = { 1,-1 };
	 }
	 roots[10][10];
	 memset(roots, 0, sizeof(roots));
	 isMove = false; isClicked = false;
	 float X, Y;
	 X = x;
	 Y = y;
	 transformation = 0;
	 String FileDef = FS;
	 SpriteD.setOrigin(55 / 2, 65 / 2);

	 //***************************Описываем изображение фигуры в обычном виде*************************//

	 ImageD.loadFromFile("images/" + FileDef);
	 TextureD.loadFromImage(ImageD);
	 SpriteD.setTexture(TextureD);
	 SpriteD.setTextureRect(IntRect(33, 709, 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
	 SpriteD.setPosition(1235, 815);// тут тоже все будет зависеть от координат  p.s Разобраться с картинкой

	 ///////////////////////////////////////////////////////////////////////////////////////////////////

 }
 Silver::Silver(float x, float y, int side, String FS)
 {
	 RulesMove = new VectorMove[5];
	 if (side == 1)
	 {
		 RulesMove[0] = { 0,1 };
		 RulesMove[1] = { -1,-1 };
		 RulesMove[2] = { -1,1 };
		 RulesMove[3] = { 1,1 };
		 RulesMove[4] = { -1,1 };

	 }
	 else
	 {
		 RulesMove[0] = {1,1};
		 RulesMove[1] = { -1,1};
		 RulesMove[2] = { 0,-1 };
		 RulesMove[3] = { -1,-1 };
		 RulesMove[4] = { 1,-1 };
	 }

	 roots[10][10];
	 memset(roots, 0, sizeof(roots));
	 isMove = false; isClicked = false;
	 float X, Y;
	 X = x;
	 Y = y;
	 transformation = 0;
	 String FileDef = FS;
	 SpriteD.setOrigin(55 / 2, 65 / 2);

	 //***************************Описываем изображение фигуры в обычном виде*************************//

	 ImageD.loadFromFile("images/" + FileDef);
	 TextureD.loadFromImage(ImageD);
	 SpriteD.setTexture(TextureD);
	 SpriteD.setTextureRect(IntRect(33, 709, 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
	 SpriteD.setPosition(1235, 815);// тут тоже все будет зависеть от координат  p.s Разобраться с картинкой

	 ///////////////////////////////////////////////////////////////////////////////////////////////////
 }
 int Figures::SearchRoots(Figures a)
 {
	 int k = sizeof(RulesMove);
 }

