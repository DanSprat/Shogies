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

}

Figures::Figures() {     }
King::King() {     }
Pawn::Pawn() {     }
Rook::Rook() {     }
Knight::Knight() {     }
Arrow::Arrow() {     }
Horse::Horse() {     }
Gold::Gold() {     }
Silver::Silver() {     }

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
bool& Figures::getIsActive()
{
	return this->isActive;
}
/*bool& Figures::SetActive()
{
	return 0;
}
*/

//////////////////////////////////////////////


Figures* SelectedFigure(int &turn, Figures* FiguresBlack[], Figures* FiguresWhite[], int x, int y, int SizeB, int SizeW)
{
	if (turn == 2)//Если ход "Черных"
	{
		for (int i = 0; i < SizeB; i++)//Проходим поочередно черные фигуры 
		{
			if ((*FiguresBlack[i]).getSprite().getGlobalBounds().contains(x, y))//Попадют ли координаты курсора по фигуре
			{
				return FiguresBlack[i];//Возращаем указатель на "Выбранную черную фигуру"
			}
		}
		return 0;
	}
	else
	{
		for (int i = 0; i < SizeW; i++)//Проходим поочередно белые фигуры
		{
			if ((*FiguresWhite[i]).getSprite().getGlobalBounds().contains(x, y))//Попадют ли координаты курсора по фигуре
			{
				return FiguresWhite[i];//Возращаем указатель на "Выбранную" белую фигуру
			}
		}
		return 0;
	}

}
King::King(int a, int b, int s, Texture& T)
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
	SpriteD.setTexture(T);
	SpriteD.setTextureRect(IntRect(34 + (85 * 5 - 85), 28 + (85 * 9 - 85), 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
	if (side == 1)
	{
		SpriteD.setRotation(180);
	}
	SpriteD.setPosition(615 + 80 * (y - 1) + 5 * (y - 1), 195 + 80 * (x - 1) + 5 * (x - 1));// тут тоже все будет зависеть от координат  p.s Разобраться с картинкой
}
Pawn::Pawn(int a, int b, int s, Texture& T)
{
	SizeOfRules = 1;
	SizeofRulesTransform = 6;
	RulesMove = new VectorMove[1];
	RulesMoveTransform = new VectorMove[6];
	side = s;
	if (side == 1)
	{
		TransformCoords = { 7,9 };
		RulesMove[0] = { 1,0 };
		RulesMoveTransform[0] = { 1,0 };
		RulesMoveTransform[1] = { 1,1 };
		RulesMoveTransform[2] = { 1,-1 };
		RulesMoveTransform[3] = { 0,1 };
		RulesMoveTransform[4] = { 0,-1 };
		RulesMoveTransform[5] = { -1,0 };

	}
	else
	{
		TransformCoords = { 3,1 };
		RulesMove[0] = { -1,0 };
		RulesMoveTransform[0] = { -1,1 };
		RulesMoveTransform[1] = { -1,0 };
		RulesMoveTransform[2] = { -1,-1 };
		RulesMoveTransform[3] = { 0,1 };
		RulesMoveTransform[4] = { 0,-1 };
		RulesMoveTransform[5] = { 1,-0 };
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
	SpriteD.setTexture(T);
	SpriteD.setTextureRect(IntRect(34 + (85 * 1 - 85), 28 + (85 * 7 - 85), 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
	if (side == 1)
	{
		SpriteD.setRotation(180);
	}
	SpriteD.setPosition(615 + 80 * (y - 1) + 5 * (y - 1), 195 + 80 * (x - 1) + 5 * (x - 1));



}
VectorMove Figures::getRulesMove(int i)
{
	return RulesMove[i];
}
Rook::Rook(int a, int b, int s, Texture &T)

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
	RulesMoveTransform[35] = { -1, 1 };
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
	SpriteD.setTexture(T);
	SpriteD.setTextureRect(IntRect(34 + (85 * 8 - 85), 28 + (85 * 8 - 85), 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
	if (side == 1)
	{
		SpriteD.setRotation(180);
	}
	SpriteD.setPosition(615 + 80 * (y - 1) + 5 * (y - 1), 195 + 80 * (x - 1) + 5 * (x - 1));

	////////////////////////////////////////////////////////////////////////////////////////////


}

Knight::Knight(int a, int b, int s, Texture& T)
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

	SpriteD.setTexture(T);
	SpriteD.setTextureRect(IntRect(34 + (85 * 2 - 85), 28 + (85 * 8 - 85), 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
	if (side == 1)
	{
		SpriteD.setRotation(180);
	}
	SpriteD.setPosition(615 + 80 * (y - 1) + 5 * (y - 1), 195 + 80 * (x - 1) + 5 * (x - 1));
}


Arrow::Arrow(int a, int b, int s, Texture& T)
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
	SpriteD.setTexture(T);
	SpriteD.setTextureRect(IntRect(34 + (85 * 1 - 85), 28 + (85 * 9 - 85), 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
	if (side == 1)
	{
		SpriteD.setRotation(180);
	}
	SpriteD.setPosition(615 + 80 * (y - 1) + 5 * (y - 1), 195 + 80 * (x - 1) + 5 * (x - 1));


}
Horse::Horse(int a, int b, int s, Texture& T)
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
	SpriteD.setTexture(T);
	SpriteD.setTextureRect(IntRect(34 + (85 * 2 - 85), 28 + (85 * 9 - 85), 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
	if (side == 1)
	{
		SpriteD.setRotation(180);
	}
	SpriteD.setPosition(615 + 80 * (y - 1) + 5 * (y - 1), 195 + 80 * (x - 1) + 5 * (x - 1));
}
Gold::Gold(int a, int b, int s, Texture&T) {
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
	SpriteD.setTexture(T);
	SpriteD.setTextureRect(IntRect(34 + (85 * 4 - 85), 28 + (85 * 9 - 85), 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
	if (side == 1)
	{
		SpriteD.setRotation(180);
	}
	SpriteD.setPosition(615 + 80 * (y - 1) + 5 * (y - 1), 195 + 80 * (x - 1) + 5 * (x - 1));

	///////////////////////////////////////////////////////////////////////////////////////////////////

}
Silver::Silver(int a, int b, int s, Texture& T)
{
	side = s;
	SizeofRulesTransform = 6;
	RulesMove = new VectorMove[5];
	RulesMoveTransform = new VectorMove[6];
	SizeOfRules = 5;
	if (side == 1)
	{
		TransformCoords = { 7,10 };
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
		TransformCoords = { 3,0 };
		RulesMove[0] = { -1,1 };
		RulesMove[1] = { -1,-1 };
		RulesMove[2] = { -1,0 };
		RulesMove[3] = { 1,-1 };
		RulesMove[4] = { 1,1 };
		RulesMoveTransform[0] = { -1,1 };
		RulesMoveTransform[1] = { -1,0 };
		RulesMoveTransform[2] = { -1,-1 };
		RulesMoveTransform[3] = { 1,0 };
		RulesMoveTransform[4] = { 0,-1 };
		RulesMoveTransform[5] = { 0,1 };

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
	SpriteD.setTexture(T);
	SpriteD.setTextureRect(IntRect(34 + (85 * 3 - 85), 28 + (85 * 9 - 85), 55, 65));//В дальнейшем координаты x,y будут перемножаться на 85  и размеры его будут 85 на 85 p.s Разобраться с картинкой
	if (side == 1)
	{
		SpriteD.setRotation(180);
	}
	SpriteD.setPosition(615 + 80 * (y - 1) + 5 * (y - 1), 195 + 80 * (x - 1) + 5 * (x - 1));

	///////////////////////////////////////////////////////////////////////////////////////////////////

}
void Figures::SearchRoots(Figures **&FiguresB, Figures**& FiguresW, int array[10][10], int SizeB, int SizeW)
{
	isZero = true;//флаг на "Нулевую матрицу ходов"
	if (isActive == 1)//Если фигура находится на доске
	{
		for (int i = 0; i < 10; i++)//заполняем всю матрицу ходов нулями
			for (int j = 0; j < 10; j++)
			{
				roots[i][j] = 0;
			}
		int i = 0;
		int  tempX = 0;//Времменая координата X
		int tempY = 0;//Временная координата Y
		for (i = 0; i < SizeOfRules; i++)//Проходим по всем векторам, по которым может двигаться фигура
		{
			tempX = x + RulesMove[i].getScaleCompX();//Для проверки доступности хода "смещаем" фигуру по X 
			tempY = y + RulesMove[i].getScaleCompY();//Для проверки доступности хода "смещаем" фигуру по Y

			if ((tempX < 10) && (tempX > 0) && (tempY < 10) && (tempY > 0))//Проверяем не вышли ли мы за пределы доски
			{
				if ((SizeOfRules > 7) && ((typeid(*this).name()) != typeid(King).name()))//Проверка на "Дальнобойности выбранной фигуры"
				{
					if ((array[tempX][tempY] != side) && ((*this).CheckCheck(FiguresB, FiguresW, array, RulesMove[i].getScaleCompX(), RulesMove[i].getScaleCompY(), SizeB, SizeW) == 1) && (CheckCheck(FiguresB, FiguresW, array, 0, 0, SizeB, SizeW) == 1))
					{
						//Выполняем проверку наличия союзной фигуры на новых координатах
						//Проверяем будет ли шах союзному королю если фигура сдивентся на новые координаты
						//Проверяем будет ли шах союзному королю если фигура останется на данном месте
						roots[tempX][tempY] = 1;//присваиваем элементу массива с "проверенными" координатам значение 1 (одить можно)
						if (array[tempX][tempY] == 0)// Проверка на пустую клетку
						{

						}
						else//Если она не пуста (значит занята фигурой противника)
						{
							if (i < 32) //Максимальное количество возможных ходов 36,до 32 они каждые 8 "векторов" движения сонаправлены и отличаются только длинной 
								while (i % 8 != 7)//фигура на одном из векторов встретила фигуру противника,прыгать через них она не может,поэтому проверять 
									//Векторы в том направлении большей длинны нет необходимости
								{
									i++;
								}



						}
					}
					else
					{
						if (CheckCheck(FiguresB, FiguresW, array, 0, 0, SizeB, SizeW) == 1)//Проверяем есть ли сейчас шах союзному королю
						{
							if (i < 32)
								while (i % 8 != 7)
								{
									i++;
								}
						}
						else //Если шах есть
						{
							if (array[tempX][tempY] != side)//и клетка не занята союзной фигурой
							{


								if ((*this).CheckCheck(FiguresB, FiguresW, array, RulesMove[i].getScaleCompX(), RulesMove[i].getScaleCompY(), SizeB, SizeW) == 1)
									//проверка шаха союзному королю при данном ходе
								{
									if (array[tempX][tempY] == 0)//Если это клетка не занята
									{
										roots[tempX][tempY] = 1;//Можем ходить на нее
										isZero = false;//Массив уже точно ненулевой 
									}
									else//Если занята (фигурой противоположной стороны)
									{
										roots[tempX][tempY] = 1;//Можем сходить на эту клетку
										if (i < 32)//Но другое перемещение в тоже направление 
											while (i % 8 != 7)//невозможно
											{
												i++;
											}
									}
								}


							}
							else//Если она занята союзной фигурой
							{
								if (i < 32)//То на нее ходить не сможем 
									while (i % 8 != 7)//И на другие клетки того же направления тоже,переходим к другому вектору
									{
										i++;
									}
							}
						}



					}
				}
				else if ((array[tempX][tempY] != side) && ((*this).CheckCheck(FiguresB, FiguresW, array, RulesMove[i].getScaleCompX(), RulesMove[i].getScaleCompY(), SizeB, SizeW) == 1))
					//Если количество возможных ходов меньше 8, проводим провекрку будет ли шах при перемещении на новые координаты
				{
					roots[tempX][tempY] = 1;//Ходить можно 
					isZero = false;//Массив ходов уже ненулевой присваиваем false
				}
				else//Тогда если шах будет
				{
					roots[tempX][tempY] = 0;//Присваиваем значение 0
				}

			}
		}
	}
	else//Если фигура лежив в руке
	{
		for (int i = 1; i < 10; i++)//Обнуляем массив
			for (int j = 1; j < 10; j++)
			{
				roots[i][j] = 1;
			}
		if ((typeid(*this).name()) == typeid(Pawn).name())//Проверяем является ли пешкой выбранная фигура
		{
			if (side == 1)//Если ходящая строная "Белые"
			{
				for (int i = 0; i < SizeW; i++)//"Проходимся" по всем белым фигурам 
				{
					if (((typeid(*FiguresW[i]).name()) == typeid(Pawn).name()) && ((*FiguresW[i]).isActive == 1) && (*FiguresW[i]).transformation == 0)
						//если фигура - Пешка, находится на доске и не перевернута
					{
						for (int j = 1; j < 10; j++)//Зануляем вертикаль на которой она стоит
						{
							roots[j][FiguresW[i]->y] = 0;
						}
					}
				}
				for (int i = 1; i < 10; i++)//Зануляем последнюю горизонталь
				{
					roots[9][i] = 0;
				}
				for (int i = 1; i < 10; i++)//Проверяем все клетки доски
				{
					for (int j = 1; j < 10; j++)
					{
						if (array[i][j] != 0)  //Если клета занята
							roots[i][j] = 0; // Ходить сюда не сможем
					}
				}
				Figures **FiguresWhite;//Создаем новый указатель на указатель на массив 
				FiguresWhite = new Figures *[SizeW + 1];//Выделяем память на 1 больше
				for (int i = 0; i < SizeW; i++)//Копируем до предпоследнего элемента  (включительной)
				{
					FiguresWhite[i] = FiguresW[i];
				}
				FiguresWhite[SizeW] = this;// Последнему присваиваем выбранную фигуру
				VectorMove Save = { this->x,this->y };//Запоминаем старые координат, чтобы потом вернуть
				bool SaveActive = this->isActive;//Запоминаем состояние фигуры
				isActive = true;//Фигура на Активна(на доске)
				for (int i = 1; i < 10; i++)//проверяем каждую клетку
					for (int j = 1; j < 10; j++)
					{
						if (roots[i][j] == 1)//на которую можно ходить
						{
							FiguresWhite[SizeW]->x = i;//перемещаем на новую координату по X
							FiguresWhite[SizeW]->y = j;//Перемещаем на новую координату по Y

							int HelpBoard[10][10];//создаю вспомогательный массив
							Template(HelpBoard, array);// Копируем в него массив состояния доски
							HelpBoard[i][j] = 1;//Текущий координам присваиваем сторону ходящей фигуры

							if (IsMate(FiguresB, FiguresWhite, 1, SizeB, SizeW + 1, HelpBoard) == 1)// Если при данном ходе будет мат
							{
								roots[i][j] = 0;//Ходить нельзя
							}
						}
					}
				isActive = false;//Возращаем состояние фигуры
				x = Save.getScaleCompX();//Координаты X
				y = Save.getScaleCompY();//Координаты Y
			}
			else // если стороная фигуры "Черная"
				//Все действия повторяются но уже для фигур черного цвета
			{
				for (int i = 0; i < SizeB; i++)
				{
					if (((typeid(*FiguresB[i]).name()) == typeid(Pawn).name()) && ((*FiguresB[i]).isActive == 1) && (*FiguresB[i]).transformation == 0)
					{
						for (int j = 1; j < 10; j++)
						{
							roots[j][FiguresB[i]->y] = 0;
						}
					}
				}
				for (int i = 1; i < 10; i++)
				{
					roots[1][i] = 0;
				}
				for (int i = 1; i < 10; i++)
				{
					for (int j = 1; j < 10; j++)
					{
						if (array[i][j] != 0)
							roots[i][j] = 0;
					}
				}
				Figures **FiguresBlack;
				FiguresBlack = new Figures *[SizeB + 1];
				for (int i = 0; i < SizeB; i++)
				{
					FiguresBlack[i] = FiguresB[i];
				}
				FiguresBlack[SizeB] = this;
				VectorMove Save = { this->x,this->y };
				bool SaveActive = this->isActive;
				isActive = true;
				for (int i = 1; i < 10; i++)
					for (int j = 1; j < 10; j++)
					{
						if (roots[i][j] == 1)
						{
							FiguresBlack[SizeB]->x = i;
							FiguresBlack[SizeB]->y = j;

							int HelpBoard[10][10];
							Template(HelpBoard, array);
							HelpBoard[i][j] = 1;

							if (IsMate(FiguresBlack, FiguresW, 1, SizeB + 1, SizeW, HelpBoard) == 1)
							{
								roots[i][j] = 0;
							}
						}
					}
				isActive = false;
				x = Save.getScaleCompX();
				y = Save.getScaleCompY();
			}
		}
		else //Есил выбранная фигура не пешка
		{
			for (int i = 1; i < 10; i++)//Ей можно ходить куда угодно 
				for (int j = 1; j < 10; j++)
					if (array[i][j] != 0)//если данная клета не занята другой фигурой
						roots[i][j] = 0;
		}
	}
}
bool Figures::CheckCheck(Figures* FiguresB[], Figures* FiguresW[], int array[10][10], int NewX, int NewY, int SizeB, int SizeW)
{
	int arrayHelp[10][10];//Вспомогательный массив для копирования в него массива состояния доски
	int mate = 0;//Флаг на окончание игры
	int KingX, KingY;//Координаты короля
	int k = -1;
	if (side == 1)//Если сторона "Белая"
	{
		if (array[x + NewX][y + NewY] == 2)//Если на новых координатах стоит черная фигура
		{
			for (int i = 0; i < SizeB; i++)//Узнаем какой у нее номер в массиве
			{
				if ((x + NewX == FiguresB[i]->x) && (y + NewY == FiguresB[i]->y))
					k = i;//Сохраняем номер
			}
		}

		KingX = (*FiguresW[0]).getCordX();//Координата белого короля по X
		KingY = (*FiguresW[0]).getCordY();//Координата белого короля по Y
		if ((x == KingX) && (y == KingY))//Если выбранная фигура Король (Белый)
		{
			KingX += NewX;//Новые координаты короля
			KingY += NewY;//Новые координаты короля
			arrayHelp[x][y] = 0;//Старая позиция короля освобождена
			arrayHelp[KingX][KingY] = 1;//Новая занята им
		}
		for (int i = 0; i < SizeB; i++)//"Проходимся" по все черным фигурам
		{
			if (i != k)//Кроме той на которую мы можем встать
			{

				Template(arrayHelp, array);//Копируем в вспомогательный массив массив текущего состояния доски 
				arrayHelp[x][y] = 0;//Клета с предыдущими координатами теперь свободна
				arrayHelp[x + NewX][y + NewY] = 1;//Клетка с новыми координатами занята белой фигурой
				if ((*FiguresB[i]).IsCheck(arrayHelp, KingX, KingY) == true)//Если фигура ставит "шахует" союзного короля выбранной фигуры
				{
					return false;//Возращаем отрицание
				}
			}
		}
		return true;

	}
	if (side == 2)
		//Для черной стороны реализация такая же
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
	int TempX;//Вспомогательная переменная для хранения координаты X
	int TempY;//Вспомогательная переменная для хранения координаты Y
	int Size = 0;//размер
	int Middle = 0;
	for (int i = 0; i < SizeOfRules; i++)//Проходимся по всем возможным векторам перемещения фигуры
	{
		if ((a == x + RulesMove[i].getScaleCompX()) && (b == y + RulesMove[i].getScaleCompY()))//Если старые координаты + вектор совпадают с координатами заданными
		{
			TempX = RulesMove[i].getScaleCompX();
			TempY = RulesMove[i].getScaleCompY();
			if (abs(TempX) > abs(TempY))//Если число координаты вектора по X больше чем по Y
			{
				Size = abs(TempX);
				TempX = TempX / abs(TempX);//нормализируем вектор
				TempY = TempY / abs(TempX);//нормализируем вектор
			}
			else
			{
				Size = abs(TempY);
				TempX = TempX / abs(TempY);//нормализируем вектор
				TempY = TempY / abs(TempY);//нормализируем вектор
			}
			for (int j = 1; j < Size; j++)
			{
				if (Arr[x + (TempX*j)][y + (TempY*j)] != 0)//Если встречаем фигуру
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
			array[i][j] = ' ';//присваниваем каждому элементу массива "Пробельный символ"

		}
	for (int i = 0; i < 10; i++)//Делаем проверку ходов фигуры
		for (int j = 0; j < 10; j++)
		{
			if (roots[i][j] == 1)//Если может ходить на i,j
			{
				array[i][j] = 'G';//присваниваем "G"
			}
		}
	for (int i = 0; i < 10; i++)//Проходимся по всему массиву
		for (int j = 0; j < 10; j++)
		{
			if (array[i][j] == 'G')  a.setTextureRect(IntRect(0, 0, 80, 80)); //Если встречаем G берем одну часть загруженной картинки(Квадрат)
			if ((array[i][j] == '0')) a.setTextureRect(IntRect(80, 0, 80, 80));//Если ноль то, берем прозрачную часть картинки
			if ((array[i][j] == ' ')) a.setTextureRect(IntRect(80, 0, 80, 80));//Если пробельный символ,то также ничего



			a.setPosition((555 - 65) + j * 80 + (5 * j), (135 - 65) + i * 80 + (5 * i));//расставляем
			//квадратики по координатам

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
	c = (y - 155) / 85 + 1;//Пребразовываем координаты курсора относительно окна,относительно доски
	b = ((x - 575) / 85 + 1);//Пребразовываем координаты курсора относительно окна,относительно доски
	if ((c > 0) && (c < 10) && (b > 0) && (b < 10))//Проверяем условие нахождение на доске
	{
		if (roots[c][b] == 1)//Если сюда холдить можно
		{
			a.getCompX() = c;
			a.getCompY() = b;
			return true;
		}
		else {
			return false;
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
bool Figures::Eating(Figures  **&b, Figures **&w, int& sizeb, int& sizew, Figures **&byB, Figures **&byW, int& sizebyB, int&sizebyW, Texture&T)
{
	Figures empty;//Создаем пустой элемент
	bool isEmpty = 0;//Наличие пустого элемента
	int k;
	if (side == 1)//Если сторона выбранной фигуры "Белые"
	{
		for (int i = 0; i < sizeb; i++)
		{
			if ((x == (*b[i]).getCordX()) && (y == (*b[i]).getCordY()))//Если кордината совпадает с координатой противоположной фигуры
			{
				b[i]->side = 1;//Меняем сторону съеденной фигуры
				b[i]->isActive = 0;//Теперь она неактивна
				b[i]->x = -100;
				b[i]->y = -100;
				Figures **NewB;
				Figures **NewW;
				sizeb -= 1;//Уменьшаем размер массива черных на 1
				sizew += 1;//Увеличиваем размер массива для белых на 1
				b[i]->ChangeRulesSide();//Меняем правила "Ходьбы фигуры"
				NewB = new Figures *[sizeb];//Создаем динамический массив
				NewW = new Figures *[sizew];//Создаем динамический массив
				if (b[i]->transformation == 1)//присваиваем состояние трансформации фигуры
				{
					b[i]->transformation = 0;//присваиваем состояние трансформации фигуры
					b[i]->Swap(T);//Пеняем правила перемещения фигуры и ее текстуру
				}
				for (int j = 0; j < sizebyW; j++)//проверяем есть ли в массиве пустой элемент
				{
					if (*byW[j] == empty)
					{
						isEmpty = true;
						k = j;//запоминаем его номер
						break;
					}
				}
				if (isEmpty == true)
				{
					byW[k] = b[i];
					byW[k]->getSprite().setPosition(500 - 70 * ((k) % 5), 365 + (-80 * ((k - 1) / 5)));//Устанавливаем на новые координаты
					(**&byW[k]).getSprite().rotate(180);//поворачиваем на 180 градусов
				}
				else
				{
					Figures **byWhite;
					sizebyW += 1;//Увеличиваем размер на 1
					byWhite = new Figures *[sizebyW];//Создаем новый динамический массив съеденных фигур
					for (int j = 0; j < sizebyW - 1; j++)
					{
						byWhite[j] = byW[j];//Копируем из исходного все элементы
					}
					byWhite[sizebyW - 1] = b[i];//последнему элементу нового массива определяем схеденную фигуру

					byW = byWhite;//Копируем в основной массив
					(**&byW[sizebyW - 1]).getSprite().setPosition(500 - 70 * ((sizebyW - 1) % 5), 365 + (-80 * ((sizebyW - 1) / 5)));//Ставим на новые координаты
					(**&byW[sizebyW - 1]).getSprite().rotate(180);//Поворачиваем на 180 градусов
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
				b = NewB;//Копируем обновленные массивы
				w = NewW;//Копируем обновленные массивы

				return true;
			}
		}
		return false;
	}
	else
	{
		//реализация части ниже аналогична
		for (int i = 0; i < sizew; i++)
		{
			if ((x == (*w[i]).getCordX()) && (y == (*w[i]).getCordY()))
			{
				w[i]->side = 2;
				w[i]->isActive = 0;
				w[i]->x = -100;
				w[i]->y = -100;
				sizew -= 1;
				sizeb += 1;
				Figures **NewB;
				Figures **NewW;

				w[i]->ChangeRulesSide();
				NewB = new Figures *[sizeb];
				NewW = new Figures *[sizew];
				if (w[i]->transformation == 1)
				{
					w[i]->transformation = 0;
					w[i]->Swap(T);
				}
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
					(**&byB[sizebyB - 1]).getSprite().setPosition(1450 + 70 * ((sizebyB - 1) % 5), 710 + 80 * ((sizebyB - 1) / 5));
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
void Figures::Swap(Texture& T)
{
	SpriteD.setTexture(T);//меняем вид объекта 
	this->transformation = 1;//меняем значение состояния трансформирования
	VectorMove *SwapRules;//Ниже и до конца меняем местами два динамических массива
	SwapRules = new VectorMove[SizeOfRules];
	for (int i = 0; i < SizeOfRules; i++)
	{
		SwapRules[i] = RulesMove[i];
	}
	int SwapSize = SizeOfRules;
	delete[] RulesMove;
	RulesMove = new VectorMove[SizeofRulesTransform];
	for (int i = 0; i < SizeofRulesTransform; i++)
	{
		RulesMove[i] = RulesMoveTransform[i];
	}
	delete[] RulesMoveTransform;
	RulesMoveTransform = new VectorMove[SwapSize];
	SizeOfRules = SizeofRulesTransform;
	SizeofRulesTransform = SwapSize;
	RulesMoveTransform = SwapRules;

}
bool IsMate(Figures* FiguresBlack[], Figures* FiguresWhite[], int turn, int SizeBlack, int SizeWhite, int array[10][10])
{
	if (turn == 1)//Если ход "белых"
	{
		for (int i = 0; i < SizeBlack; i++)
		{
			if (FiguresBlack[i]->isActive == 1)
			{
				FiguresBlack[i]->SearchRoots(FiguresBlack, FiguresWhite, array, SizeBlack, SizeWhite);//Узнаем для каждой фигуры, есть ли у нее доступные ходы
				if (FiguresBlack[i]->isZero == 0)
				{

					return false;//если их нету
				}
			}
		}
	}

	else
		//Аналогично когда ходят черные
	{
		for (int i = 0; i < SizeWhite; i++)
		{
			if (FiguresWhite[i]->isActive == 1)
			{
				FiguresWhite[i]->SearchRoots(FiguresBlack, FiguresWhite, array, SizeBlack, SizeBlack);
				if (FiguresWhite[i]->isZero == 0)
				{
					return false;
				}
			}
		}
	}
	return true;

}
void Figures::ChangeRulesSide()
{
	if (SizeOfRules < 10)//если у фигуры меньше 10
	{
		int Save = 0;//Вспомогательная переменная
		for (int i = 0; i < SizeOfRules; i++)//Все векторы меняем на противоложные по направлению
		{
			RulesMove[i].getCompX() = RulesMove[i].getScaleCompX()*(-1);
			RulesMove[i].getCompY() = RulesMove[i].getScaleCompY()*(-1);
		}
		for (int i = 0; i < SizeofRulesTransform; i++)
		{
			RulesMoveTransform[i].getCompX() = RulesMoveTransform[i].getScaleCompX()*(-1);
			RulesMoveTransform[i].getCompY() = RulesMoveTransform[i].getScaleCompY()*(-1);
		}

	}
	TransformCoords.getCompX() = abs(TransformCoords.getScaleCompX() - 10);//меняем координаты возможной трасформации
	TransformCoords.getCompY() = abs(TransformCoords.getScaleCompY() - 10);//меняем координаты обязательной трансформации
}
