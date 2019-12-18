#pragma once
class point {
public:

	long double x;  
	long double y;  

	point() { 
		x = 0;
		y = 0;
	}

	point(long double yeniX, long double yeniY) {
		x = yeniX;
		y = yeniY;
	}

	~point()
	{

	}

	bool operator == (point v) {
		return ((x == v.x) && (y == v.y));
	}

	void operator =(point v) {
		x = v.x;
		y = v.y;
	}

};
