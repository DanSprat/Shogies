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
	VectorMove TransformCoords;
	bool isActive;
	bool isMove, isClicked;
	bool HaveTransform = 0;//Может ли фигура трансфромироваться
	int side; //Сторона к которой принадлежит фигура
	int roots[10][10];//Матрица ходов,куда доступно ходить фигуре
	int turn, transformation;//Флаг очереди хода {0,1} и состояние трансформации {0(обычная фигура),1(трансформированная),2(выбывшая)}
	int x, y;//позиция фигуры на доске относительно левого верхнего угла
	VectorMove *RulesMove;
	VectorMove *RulesMoveTransform;
	int SizeOfRules;
	int SizeofRulesTransform;
public:
	int getTransformation();
	void Swap();
	friend bool operator==(Figures& left, Figures& right);
	bool Eating(Figures  **&b, Figures **&w, int& sizeb, int& sizew,Figures **&,Figures **&,int&,int&);
	void setCordX(int x);
	void setCordY(int y);
	int getTransformCoordsX();
	int getTransformCoordsY();
    int getSide();
	bool CheckTrue(int x, int y, VectorMove& a);
	int* getRoots();
	void ShowRoots(String *array, Sprite& a, RenderWindow& b);
	int getCordX();
	int getCordY();
	bool IsCheck(int array[10][10], int KingX, int KingY);
	bool CheckCheck(Figures *FiguresB[], Figures* FiguresW[], Figures &a, int array[10][10], int NewX, int NewY, int SizeB, int SizeW);
	int getSizeOfRules();
	Sprite& getSprite();
	bool& getIsMove();
	bool& getIsClicked();
	void SearchRoots(Figures *FiguresB[], Figures* FiguresW[], int array[10][10], Figures &pa, int SizeB, int SizeW);
	virtual void ChangeArr();
	Figures(int x, int y, int side, String FS, String FT, bool HaveTransform);
	VectorMove getRulesMove(int i);
	Figures();
	~Figures();
};
Figures* SelectedFigure(int &turn, Figures *FiguresBlack[], Figures *FiguresWhite[], int x, int y, int SizeB, int SizeW);

////////////CLASS OF THE KING ///////////////////////

class King :public Figures {
protected:

	bool check;//For the Kings
	bool checkmate;//also
public:
	King(int x, int y, int s);
	King();
};
////////////////////////////////////////////////////////////

//////////////////CLASS OF THE PAWN /////////////////////////
class Pawn:public Figures {
protected:
public:
	Pawn(int a, int b, int side);
	virtual void ChangeArr()
	{
		delete[] RulesMove;
		RulesMove = new VectorMove[6];
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
public:
	Rook(int a, int b, int s);
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
class Knight :public Figures {
public:
	Knight(int a, int b, int side);
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
class Arrow :public Figures {
public:
	Arrow(int a, int b, int side);
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

class Horse :public Figures {
public:
	Horse(int a, int b, int side);
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
	Gold(int a, int b, int side);
	Gold();
};

class Silver : public Figures {
public:
	Silver(int a, int b, int side);
	Silver();
};
void Template(int a[10][10], int b[10][10]);
