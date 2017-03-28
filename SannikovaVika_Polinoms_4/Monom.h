#pragma once
class monom
{
private:
	double coefficient;
	int degree;
public:
	monom (double coefficient = 0, int degree = -1);
	monom (const monom &tmp);
	double GetCoefficient() const; //для чего мы делаем их константными
	int GetDegree() const;
	void SetCoefficient(double coeff = 0);
	void SetDegree(int deg = 0);

	monom& operator =(const monom& right); //second
	friend bool operator ==(const monom& left, const monom& right); //first second
	friend bool operator !=(const monom& left, const monom& right); //first second
	friend bool operator <(const monom& left, const monom& right); //first second
	friend bool operator >(const monom& left, const monom& right); //first second
	friend monom operator +(const monom& left, const monom& right); //first second
	friend monom operator -(const monom& left, const monom& right); //first second
	friend monom operator *(const monom& left, const monom& right); //first second

};