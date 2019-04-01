#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "math.h"
#include "cstring"
#include "time.h"
using namespace std;
using namespace sf;
////////////////////////////////////ОБЪЯВЛЯЕМ ФИГУРЫ//////////////////////////////


class Figures
{
public:
	Image ImageD;
	Texture TextureD;
	Sprite SpriteD;

	Image ImageSwap;
	Texture TextureSwap;
	Sprite SpriteSwap;

	bool isMove, isClicked;
	bool HaveTransform;//Может ли фигура трансфромироваться
	bool check;//For the Kings
	bool checkmate;//also
	int side; //Сторона к которой принадлежит фигура
	int roots[10][10];//Матрица ходов,куда доступно ходить фигуре
	int turn, transformation;//Флаг очереди хода {0,1} и состояние трансформации {0(обычная фигура),1(трансформированная),2(выбывшая)}
	int SearchRoots(Figures a);
	float x, y;//позиция фигуры на доске относительно левого верхнего угла
	Figures(float x, float y, int side, String FS, String FT, bool HaveTransform);
	Figures();
	~Figures();
	void SetRoots(int n, int first, ...);
};
Figures* SelectedFigure(int &turn, Figures *FiguresBlack[], Figures *FiguresWhite[], int x, int y);



