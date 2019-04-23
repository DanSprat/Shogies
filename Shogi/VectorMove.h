#pragma once
class VectorMove
{

	int x, y;
public:
	int& getCompX();
	int& getCompY();
	int getScaleCompX();
	int getScaleCompY();

	VectorMove();
	VectorMove(int a, int b);
    ~VectorMove();
};

