#include <cmath>
#include <iostream>

class Coordinates {
public:
	Coordinates(){}
	Coordinates(double x, double y, double z) : x(x), y(y), z(z) {}

	friend Coordinates operator-(Coordinates cord1, Coordinates cord2) {
		cord1.x -= cord2.x;
		cord1.y -= cord2.y;
		cord1.z -= cord2.z;
	
		return cord1;
	}

	double distance() {
		return sqrt(x*x + y*y + z*z);
	}

	friend std::ostream& operator<<(std::ostream& os, Coordinates s) {
		os << s.x << " " << s.y << " " << s.z << "\n";
		return os;
	}

	double x;
	double y;
	double z;
};
