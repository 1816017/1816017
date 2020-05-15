#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(int x, int y);
	~Vector2();
	int x;		// xÀ•W
	int y;		// yÀ•W

	// ‘ã“ü‰‰Zq
	Vector2& operator = (const Vector2& vec);

	// “Yš‰‰Zq
	int& operator[] (int i);

	// ”äŠr‰‰Zq
	bool operator == (const Vector2& vec) const;
	bool operator != (const Vector2& vec) const;
	bool operator <= (const Vector2& vec) const;
	bool operator >= (const Vector2& vec) const;
	bool operator < (const Vector2& vec) const;
	bool operator > (const Vector2& vec) const;

	// ’P€‰‰Zq
	Vector2& operator += (const Vector2& vec);
	Vector2& operator -= (const Vector2& vec);
	Vector2& operator += (const int k);
	Vector2& operator -= (const int k);
	Vector2& operator *= (const int k);
	Vector2& operator /= (const int k);
	Vector2  operator + ()const;
	Vector2  operator - ()const;
};
// ÍŞ¸ÄÙ‚Ì‰‰Z
// VECTOR2 + int
Vector2 operator + (const Vector2& u, const int v);
// VECTOR2 - int
Vector2 operator - (const Vector2& u, const int v);
// VECTOR2 * int
Vector2 operator * (const Vector2& u, const int v);
// VECTOR2 / int
Vector2 operator / (const Vector2& u, const int v);
// VECTOR2 % int
Vector2 operator % (const Vector2& u, const int v);
// VECTOR2 + VECTOR2
Vector2 operator + (const Vector2& u, const Vector2& v);
// VECTOR2 - VECTOR2
Vector2 operator - (const Vector2& u, const Vector2& v);
//VECTOR2 / VECTOR2
Vector2 operator/(const Vector2& u, const Vector2& v);