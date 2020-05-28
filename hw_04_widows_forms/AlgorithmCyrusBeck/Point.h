#pragma once

#include <cstdint>

namespace LM
{

	struct Point
	{
		float x, y;

		Point()
			: x(0.0f), y(0.0f)
		{ }

		Point(float v)
			: x(v), y(v)
		{ }

		Point(float _x, float _y)
			: x(_x), y(_y)
		{ }

		inline float& operator[](uint32_t i)
		{
			return (&x)[i];
		}

		inline Point& operator+=(const Point& v)
		{
			this->x += v.x;
			this->y += v.y;
			return *this;
		}

		inline Point& operator-=(const Point& v)
		{
			this->x -= v.x;
			this->y -= v.y;
			return *this;
		}

		inline Point& operator*=(float scalar)
		{
			this->x *= scalar;
			this->y *= scalar;
			return *this;
		}
		
		inline Point& operator/=(float scalar)
		{
			this->x /= scalar;
			this->y /= scalar;
			return *this;
		}
	};

	inline Point operator+(const Point& v1, const Point& v2)
	{
		return Point(v1.x + v2.x, v1.y + v2.y);
	}

	inline Point operator-(const Point& v1, const Point& v2)
	{
		return Point(v1.x - v2.x, v1.y - v2.y);
	}

	inline Point operator*(const Point& v1, float scalar)
	{
		return Point(v1.x * scalar, v1.y * scalar);
	}

	inline Point operator/(const Point& v1, float scalar)
	{
		return Point(v1.x / scalar, v1.y / scalar);
	}

	inline float dot(const Point& v1, const Point& v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}

	inline Point cross(const Point& v)
	{
		return Point(-v.y, v.x);
	}

	inline float cross(const Point& v1, const Point& v2)
	{
		return v1.x * v2.y - v1.y * v2.x;
	}

	inline float length(const Point& v)
	{
		return sqrt(v.x * v.x + v.y * v.y);
	}

	struct Line
	{
		Point A, B;
		
		Line(const Point& v1, const Point& v2)
			: A(v1), B(v2)
		{ }

		inline Point& operator[](uint32_t i)
		{
			return (&A)[i];
		}
	};

}