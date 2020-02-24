#pragma once
class Point
{
public:
	int x, y;
	Point(int xP, int yP);
	Point();
	~Point();
	//COPY
	Point(const Point& p);

	Point add(const Point& p) const;
	Point sub(const Point& p) const;

	//OPERADOR =
	Point& operator=(const Point& outro);

	//OPERADOR ==
	bool operator==(const Point& p)const;

	//OPERADOR !=
	bool operator!=(const Point& p)const;
};

