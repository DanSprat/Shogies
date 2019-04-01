#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "math.h"
#include "cstring"
#include "time.h"
using namespace std;
using namespace sf;
////////////////////////////////////��������� ������//////////////////////////////


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
	bool HaveTransform;//����� �� ������ ������������������
	bool check;//For the Kings
	bool checkmate;//also
	int side; //������� � ������� ����������� ������
	int roots[10][10];//������� �����,���� �������� ������ ������
	int turn, transformation;//���� ������� ���� {0,1} � ��������� ������������� {0(������� ������),1(������������������),2(��������)}
	int SearchRoots(Figures a);
	float x, y;//������� ������ �� ����� ������������ ������ �������� ����
	Figures(float x, float y, int side, String FS, String FT, bool HaveTransform);
	Figures();
	~Figures();
	void SetRoots(int n, int first, ...);
};
Figures* SelectedFigure(int &turn, Figures *FiguresBlack[], Figures *FiguresWhite[], int x, int y);



