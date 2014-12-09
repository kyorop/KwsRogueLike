#pragma once
class Vector2
{
public:
	int x;
	int y;
public:
	Vector2();
	Vector2(int x, int y);
	~Vector2();
	bool operator%(int n); //Vector2型オブジェクトの２つの変数がnで割り切れるかを判別する
	void operator+=(const Vector2&rhs);
	const Vector2 operator+(const Vector2& rhs)const;
	const Vector2 operator-(const Vector2& rhs)const;

	void Set(int x, int y);
};