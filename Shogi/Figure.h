#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "math.h"
#include "cstring"
#include "time.h"
#include "VectorMove.h"
using namespace std;
using namespace sf;
////////////////////////////////////ОБЪЯВЛЯЕМ ФИГУРЫ//////////////////////////////


class Figures
{
protected:
	Image ImageD;
	Texture TextureD;
	Sprite SpriteD;

	Image ImageSwap;
	Texture TextureSwap;
	Sprite SpriteSwap;
	bool isMove, isClicked;
	bool HaveTransform=0;//Может ли фигура трансфромироваться
	int side; //Сторона к которой принадлежит фигура
	int roots[10][10];//Матрица ходов,куда доступно ходить фигуре
	int turn, transformation;//Флаг очереди хода {0,1} и состояние трансформации {0(обычная фигура),1(трансформированная),2(выбывшая)}
	float x, y;//позиция фигуры на доске относительно левого верхнего угла
	VectorMove *RulesMove;
public:
	Sprite& getSprite();
	bool& getIsMove();
	bool& getIsClicked();
	int SearchRoots(Figures a);
	virtual void ChangeArr();
	Figures(float x, float y, int side, String FS, String FT, bool HaveTransform);
    VectorMove getRulesMove(int i);
	Figures();
	~Figures();
};
Figures* SelectedFigure(int &turn, Figures *FiguresBlack[], Figures *FiguresWhite[], int x, int y);

     ////////////CLASS OF THE KING ///////////////////////

class King :public Figures {
protected:
	VectorMove RulesMove[8] = { {0,1},{1,0},{1,1},{1,-1},{-1,1},{0,-1},{-1,0},{-1,-1} };
	bool check;//For the Kings
	bool checkmate;//also
public:
	King(float x, float y, int side, String FS);
	King();
};
////////////////////////////////////////////////////////////

//////////////////CLASS OF THE PAWN /////////////////////////
class Pawn :public Figures {
protected:
	//VectorMove *RulesMove;
	VectorMove RulesMoveTransform[6];
public:
	Pawn(float x, float y, int side, String FS, String FT);
	virtual void ChangeArr()
	{
		delete[] RulesMove;
		RulesMove = new VectorMove [6];
		for (int i = 0; i < 6; i++)
		{
			RulesMove[i] = RulesMoveTransform[i];
		}
	}
	Pawn();
};

///////CLASS OF THE ROOK ////////////////////////
class Rook :public Figures {
protected:
	//VectorMove *RulesMove;
	VectorMove RulesMoveTransform[36];
public: 
	Rook(float x, float y, int side, String FS, String FT);
	virtual void ChangeArr()
	{
		delete[] RulesMove;
		RulesMove = new VectorMove[36];
		for (int i = 0; i < 36; i++)
		{
			RulesMove[i] = RulesMoveTransform[i];
		}
	}
	Rook();
};

////////////////////////////////////////////////

/////////CLASS OF THE KNIGHT//////////////////////
class Knight:public Figures {
	VectorMove RulesMoveTransform[36];
public:
	Knight(float x, float y, int side, String FS, String FT);
	virtual void ChangeArr()
	{
		delete[] RulesMove;
		RulesMove = new VectorMove[36];
		for (int i = 0; i < 36; i++)
		{
			RulesMove[i] = RulesMoveTransform[i];
		}
	}
	Knight();

};

////////////////CLASS OF THE ARROW///////////////////////////
class Arrow:public Figures {
	VectorMove RulesMoveTransform[6];
public:
	Arrow(float x, float y, int side, String FS, String FT);
	virtual void ChangeArr()
	{
		delete[] RulesMove;
		RulesMove = new VectorMove[6];
		for (int i = 0; i < 6; i++)
		{
			RulesMove[i] = RulesMoveTransform[i];
		}
	}
	Arrow();

};

///////////////////////////////////////////////////////////////


/////////////////CLASS OF THE HORSE /////////////////////////////

class Horse:public Figures {
	VectorMove RulesMoveTransform[6];
public:
	Horse(float x, float y, int side, String FS, String FT);
	virtual void ChangeArr()
	{
		delete[] RulesMove;
		RulesMove = new VectorMove[6];
		for (int i = 0; i < 6; i++)
		{
			RulesMove[i] = RulesMoveTransform[i];
		}
	}
	Horse();

};

////////////////////////////////////////////////////////////////

//////////////CLASS OF THE GOLD////////////////////////////////////
class Gold :public Figures {
public:
	Gold(float x, float y, int side, String FS);
	Gold();
};

class Silver : public Figures {
public:
	Silver(float x, float y, int side, String FS);
	Silver();
};


