#include "Vector2.h"

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()
{
}

Vector2& Vector2::operator=(const Vector2& vec)
{
	x = vec.x;
	y = vec.y;
	return (*this);	// Ž©•ªŽ©g‚ð•Ô‚·‚Ì‚Åthis
}

int& Vector2::operator[](int i)
{
	if (i == 0)
	{
		return x;
	}
	else if (i == 1)
	{
		return y;
	}
	else
	{
		return x;
	}
}

bool Vector2::operator==(const Vector2& vec) const
{
	return ((this->x == vec.x) && (this->y == vec.y));
}

bool Vector2::operator!=(const Vector2& vec) const
{
	return !((this->x == vec.x) && (this->y == vec.y));
}

bool Vector2::operator<=(const Vector2& vec) const
{
	return ((this->x <= vec.x) && (this->y <= vec.y));
}

bool Vector2::operator>=(const Vector2& vec) const
{
	return ((this->x >= vec.x) && (this->y >= vec.y));
}

bool Vector2::operator<(const Vector2& vec) const
{
	return ((this->x < vec.x) && (this->y < vec.y));
}

bool Vector2::operator>(const Vector2& vec) const
{
	return ((this->x > vec.x) && (this->y > vec.y));
}

Vector2& Vector2::operator+=(const Vector2& vec)
{
	this->x += vec.x;
	this->y += vec.y;
	return (*this);
}

Vector2& Vector2::operator-=(const Vector2& vec)
{
	this->x -= vec.x;
	this->y -= vec.y;
	return (*this);
}

Vector2& Vector2::operator+=(const int k)
{
	x += k;
	y += k;
	return (*this);
}

Vector2& Vector2::operator-=(const int k)
{
	x -= k;
	y -= k;
	return (*this);
}

Vector2& Vector2::operator*=(const int k)
{
	x *= k;
	y *= k;
	return (*this);
}

Vector2& Vector2::operator/=(const int k)
{
	x /= k;
	y /= k;
	return (*this);
}

Vector2 Vector2::operator+() const
{
	return (*this);
}

Vector2 Vector2::operator-() const
{
	return Vector2(-this->x, -this->y);
}

Vector2 operator+(const Vector2& u, const int v)
{
	return Vector2(u.x + v, u.y + v);
}

Vector2 operator-(const Vector2& u, const int v)
{
	return Vector2(u.x - v, u.y - v);
}

Vector2 operator*(const Vector2& u, const int v)
{
	return Vector2(u.x * v, u.y * v);
}

Vector2 operator/(const Vector2& u, const int v)
{
	return Vector2(u.x * v, u.y * v);
}

Vector2 operator%(const Vector2& u, const int v)
{
	return Vector2(u.x % v, u.y % v);
}

Vector2 operator+(const Vector2& u, const Vector2& v)
{
	return Vector2(u.x + v.x, u.y + v.x);
}

Vector2 operator-(const Vector2& u, const Vector2& v)
{
	return Vector2(u.x - v.x, u.y - v.x);
}

Vector2 operator/(const Vector2& u, const Vector2& v)
{
	return Vector2(u.x / v.x, u.y / v.x);
}
