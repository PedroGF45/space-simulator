#pragma once
#include <cmath>

class Vector3D {

	private:
		double x, y, z;

	public:
		Vector3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {};

		double getX() const { return x; };
		double getY() const { return y; };
		double getZ() const { return z; };

		Vector3D operator/(const double other) const {
			return Vector3D(x / other, y / other, z / other);
		}

		Vector3D operator*(const double other) const {
			return Vector3D(x * other, y * other, z * other);
		}

		Vector3D operator+(const Vector3D& other) const {
			return Vector3D(x + other.getX(), y + other.getY(), z + other.getZ());
		}

		Vector3D operator-(const Vector3D& other) const {
			return Vector3D(x - other.getX(), y - other.getY(), z - other.getZ());
		}

		Vector3D& operator+=(const Vector3D& other) {
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}

		double getMagnitude() const {
			return sqrt(x*x + y*y + z*z);
		}
};