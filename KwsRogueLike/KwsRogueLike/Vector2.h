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
	bool operator%(int n); //Vector2�^�I�u�W�F�N�g�̂Q�̕ϐ���n�Ŋ���؂�邩�𔻕ʂ���
};

