#include "monom.h"

monom::monom(double coeff, int deg)
{
	coefficient = coeff;
	degree = deg;
}

monom::monom(const monom& tmp)
{
	coefficient = tmp.GetCoefficient();
	degree = tmp.GetDegree();
}

double monom::GetCoefficient() const
{
	return coefficient;
}

int monom::GetDegree() const
{
	return degree;
}

void monom::SetCoefficient(double coeff)
{
	coefficient = coeff;
}

void monom::SetDegree(int deg)
{
	degree = deg;
}

monom& monom::operator=(const monom& right)
{
	if (this == &right) 
		return *this;
	coefficient = right.GetCoefficient();
	degree = right.GetDegree();
	return *this;
}

bool operator==(const monom& left, const monom& right)
{
	if (left.GetCoefficient ()!= right.GetCoefficient())
		return false;
	if (left.GetDegree ()!= right.GetDegree())
		return false;
	return true;
}

bool operator!=(const monom& left, const monom& right)
{
	if ((left.GetCoefficient() == right.GetCoefficient()) && (left.GetDegree() == right.GetDegree()))
		return false;
	return true;
	// return !(left==right);
}

bool operator<(const monom& left, const monom& right)
{
	if (left.GetDegree() <= right.GetDegree()) 
		return true;
	else
		return false;
}

bool operator>(const monom& left, const monom& right)
{
	if (left.GetDegree() >= right.GetDegree())
		return true;
	else
		return false;
}

monom operator+(const monom& left, const monom& right)
{
	if (left.GetDegree() == right.GetDegree())
	{
		monom result(left.GetCoefficient() + right.GetCoefficient(), left.GetDegree());
		return result;
	}
	else
	{
		throw 'difD';
	}
}

monom operator-(const monom& left, const monom& right)
{
	if (left.GetDegree() == right.GetDegree())
	{
		monom result(left.GetCoefficient() - right.GetCoefficient(), left.GetDegree());
		return result;
	}
	else
	{
		throw 'difD';
	}
}

monom operator*(const monom& left, const monom& right)
{
	int x1 = left.GetDegree() / 100;
	int x2 = right.GetDegree() / 100;
	int y1 = (left.GetDegree() / 10) % 10;
	int y2 = (right.GetDegree() / 10) % 10;
	int z1 = left.GetDegree() % 10;
	int z2 = right.GetDegree() % 10;
	if ((x1 + x2) < 0 || (x1 + x2) > 9 || 
		(y1 + y2) < 0 || (y1 + y1) > 9 || 
		(z1 + z2) < 0 || (z1 + z2) > 9)
	{
		throw 'ErrD';
	}
	monom result(left.GetCoefficient()*right.GetCoefficient(), left.GetDegree() + right.GetDegree());
	return result;
}



