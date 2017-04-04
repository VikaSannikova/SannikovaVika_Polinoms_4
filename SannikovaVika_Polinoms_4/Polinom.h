#pragma once
#include "Monom.h"
#include "List.h"

class Polinom
{
private:
	List<monom>*polinom;
public:
	Polinom();
	Polinom(const Polinom &x);
	~Polinom();
	void AddElement(monom x);
	int GetLength() const;
	void Simplify(); //упростить
	monom& operator[](int pos);
	friend Polinom& operator+(const Polinom&left, const Polinom&right);
	friend Polinom& operator-(const Polinom&left, const Polinom&right);
	friend Polinom& operator*(const Polinom&left, const Polinom&right);
	friend Polinom& operator*(const Polinom&left, const monom&right);   //ну моном и есть полином
	friend Polinom& operator+=(Polinom&left, const Polinom&right);		//чо это
	Polinom& operator=(const Polinom &right);
};