#include "polynomial.h"
#include <iostream>
#include <math.h>


//
// Implementation
//


// Copy constructor
Polynomial::Polynomial(const Polynomial& source)
{
	capacity = source.capacity;
	terms = source.terms;
	termArray = new Term[capacity];

	for (int i = 0; i < terms; ++i)
	{
		termArray[i] = source.GetTerm(i);
	}
}	

// Destructor
Polynomial::~Polynomial()
{
	delete [] termArray;
}


Polynomial& Polynomial::operator = (const Polynomial& source)
{
	if (this != &source) 
	{
		delete [] termArray;

		capacity = source.capacity;
		terms = source.terms;
		termArray = new Term[capacity];

		for (int i = 0; i < terms; ++i)
		{
			termArray[i] = source.GetTerm(i);
		}
	}

	return *this;
}



// Sum of *this and source polynomials
Polynomial Polynomial::operator +(const Polynomial& source)
{
	Polynomial c;
	
	int i = 0;
	int j = 0;
	int i_finish = terms-1;
	int j_finish = (source.terms)-1;
	float k;

	while ((i <= i_finish) && (j <= j_finish))
	{
		if (GetTerm(i).exp == source.GetTerm(j).exp)
		{
			k = GetTerm(i).coef + source.GetTerm(j).coef;
			if(k) c.CreateTerm(k, GetTerm(i).exp);
			++i; ++j;
		}

		else if (GetTerm(i).exp < source.GetTerm(j).exp)
		{
			c.CreateTerm(source.GetTerm(j).coef, source.GetTerm(j).exp);
			++j;
		}

		else
		{
			c.CreateTerm(GetTerm(i).coef, GetTerm(i).exp);
			++i;
		}
	}

	for (; i <= i_finish; ++i)
	{
		c.CreateTerm(GetTerm(i).coef, GetTerm(i).exp);
	}

	for (; j <= j_finish; ++j)
	{
		c.CreateTerm(source.GetTerm(j).coef, source.GetTerm(j).exp);
	}
	
	return c;
}

Polynomial Polynomial::operator - (const Polynomial& source)
{
	Polynomial c;

	int i = 0;
	int j = 0;
	int i_finish = terms-1;
	int j_finish = (source.terms)-1;
	float k;

	while ((i <= i_finish) && (j <= j_finish))
	{
		if (GetTerm(i).exp == source.GetTerm(j).exp)
		{
			k = GetTerm(i).coef - source.GetTerm(j).coef;
			if(k) c.CreateTerm(k, GetTerm(i).exp);
			++i; ++j;
		}

		else if (GetTerm(i).exp < source.GetTerm(j).exp)
		{
			c.CreateTerm((-1)*source.GetTerm(j).coef, source.GetTerm(j).exp);
			++j;
		}

		else
		{
			c.CreateTerm(GetTerm(i).coef, GetTerm(i).exp);
			++i;
		}
	}

	for (; i <= i_finish; ++i)
	{
		c.CreateTerm(GetTerm(i).coef, GetTerm(i).exp);
	}
	
	for (; j <= j_finish; ++j)
	{
		c.CreateTerm((-1) * source.GetTerm(j).coef, source.GetTerm(j).exp);
	}
	
	return c;
	
}

Polynomial Polynomial::operator * (const Polynomial& source)
{
	Polynomial c;
	
	for (int i = 0; i < terms; ++i)
	{
		for (int j = 0; j < source.terms; ++j)
		{
			Polynomial tmp;

			float k_coef = GetTerm(i).coef * source.GetTerm(j).coef;
			int k_exp = GetTerm(i).exp + source.GetTerm(j).exp;

			if (k_coef != 0)
			{
				tmp.CreateTerm(k_coef, k_exp);
			}

			c = c + tmp;
		}
	}
	
	return c;	
}

bool Polynomial::operator == (const Polynomial& source)
{
	bool ret;
	
	if (terms != source.terms)
	{
		ret = false;
	}

	else
	{
		ret = true;

		for (int i = 0; i < terms; ++i)
		{
			if ((GetTerm(i).coef != source.GetTerm(i).coef) || (GetTerm(i).exp != source.GetTerm(i).exp))
			{
				ret = false;
				break;
			}
		}
	}
	
	return ret;
}

float Polynomial::Eval(float x)
{
	float ret = 0;
	
	for (int i = 0; i < terms; ++i)
	{
		ret += GetTerm(i).coef * pow(x, GetTerm(i).exp);
	}
	
	return ret;
}

// Compute derivative of the current polynomial
Polynomial Polynomial::Derivative()
{
	Polynomial c;
	
	for (int i = 0; i < terms; ++i)
	{
		if (GetTerm(i).exp != 0)
		{
			c.CreateTerm(GetTerm(i).coef * GetTerm(i).exp, GetTerm(i).exp - 1);
		}
	}
	
	return c;	

}

void Polynomial::CreateTerm(const float coef, const int exp)
{
	if (exp < 0)
		return;
	
	if (coef == 0)
	{
		if (terms == 0)
			return;
	}

	for (int i = 0; i < terms; ++i)
	{
		if (GetTerm(i).exp == exp)
		{
			if (coef)
			{
				termArray[i].coef = coef;
				termArray[i].exp = exp;
				return;
			}

			else
			{
				for(; i < terms-1; ++i)
				{
					termArray[i] = GetTerm(i+1);
				}
				termArray[terms-1].coef = 0;
				termArray[terms-1].exp = 0;
				--terms;
				return;
			}
		}

		else if (GetTerm(i).exp < exp)
			break;
	}
	
	if (terms >= capacity)
	{
		capacity *= 2;
		Term* tmp = new Term[capacity];

		for (int i = 0; i < terms; ++i)
		{
			tmp[i] = GetTerm(i);
		}
		
		delete [] termArray;

		termArray = tmp;
	}

	termArray[terms].coef = coef;
	termArray[terms].exp = exp;
	++terms;

	for (int i = 1; i < terms; ++i)
	{
		float i_coef = GetTerm(i).coef;
		int i_exp = GetTerm(i).exp;
		int j = i-1;

		while ((j >= 0) && (GetTerm(j).exp < i_exp))
		{
			termArray[j+1].coef = GetTerm(j).coef;
			termArray[j+1].exp = GetTerm(j).exp;
			--j;
		}

		termArray[j+1].coef = i_coef;
		termArray[j+1].exp = i_exp;
	}
}
