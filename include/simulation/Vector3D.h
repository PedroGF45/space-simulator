#pragma once

class Vector3D {

	private:
		double x, y, z;

	public:
		Vector3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {};

		double getX() const { return x; };
		double getY() const { return y; };
		double getZ() const { return z; };
};