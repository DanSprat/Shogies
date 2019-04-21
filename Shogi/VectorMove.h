#pragma once
class VectorMove
{

	int x, y;
public:
	int& getCompX();
	int& getCompY();

	VectorMove();
	VectorMove(int a, int b);
    ~VectorMove();
};

