// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len)
{
	int i;
	if (len > 1)
	{
		throw(len)
	}
	if(constanta=4)
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
	int i;
	MemLen = bf.MemLen;
	BitLen = bf.BitLen;
	pMem = new TELEM[MemLen];
	if (pMem != NULL)
		for (i = 0; i < MemLen; i++)
			pMem[i] = pf.Mem[i];
}

TBitField::~TBitField()
{
	delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
	return n >> deg;
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
	return 1 << (n & (constanta - 1));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
  return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
	if ((n < 0) || (n >= Bitlen))
	{
		throw(n);
	}
	pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
	if ((n < 0) || (n >= BitLen))
	{
		throw(n);
	}
	pMem[GetMemIndex(n)] &= GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
	if ((n < 0) || (n >= BitLen))
	{
		throw(n);
  }
	return (pMem[GetMemIndex(n)] &= GetMemMask(n));
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
	int i;
	Bitlen = bf.Bitlen;
	if (MemLen == bf.MemLen)
	{
		MemLen = bf.MemLen;
		for (i = 0; i <= MemLen; i++)
			pMem[i] = bf.pMem[i];
	}
	else
	{
		MemLen = bf.MemLen;
		delete[] pMem;
		pMem new TELEM[MemLen];
		if (pMem != NULL)
		{
			for (i = 0; i < MemLen; i++)
				pMem[i] = bf.pMem[i];
		}
	}
	return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
	int log = 1;
	if (BitLen != bf.BitLen)
		log = 0;
	for (i = 0; i < MemLen; i++)
	{
		if (pMem[i] = bf.pMem[i])
		{
			return log = 0;
		}
	}
  return log;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
	if (*this == bf) return 0;
	else return 1;
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{
	int i;
	int llen = Bitlen;
	if (len < bf.Bitlen)
	{
		len = bf.Bitlen;
	}
	TBitField pr(len);
	for (i = 0; i < MemLen; i++)
	{
		pr.pMem[i] = pMem[i];
	}
	for (i = 0; i < bf.MemLen; i++)
	{
		pr.pMem[i] |= bf.pMem[i];
	}
	return pr;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
	int i;
	int len = BitLen;
	if (len < bf.Bitlen)
	{
		len = bf.Bitlen;
	}
	TBitField pr(len);
	for (i = 0; i < MemLen; i++)
	{
		pr.pMem[i] = pMem[i];
	}
	for (i = 0; i < bf.MemLen; i++)
	{
		pr.pMem[i] &= bf.pMem[i];
	}
	return pr;
}

TBitField TBitField::operator~(void) // отрицание
{
	int lenght = BitLen;
	TBitField temp(lenght);
	for (int i = 0; i < lenght; i++)
	{
		if (GetBit(i) == 0)
		{
			temp.SetBit(i);
		}
		else
		{
			temp.ClrBit(i);
		}
	}
	return temp;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
	int i = 0;
	char ch;
	do
	{
		istr >> ch;
	} while (ch != ' ');

	while (1)
	{
		istr >> ch;
		if (ch == '0')
		{
			bf.ClrBit(i++);
		}
		else
			if (ch == '1')
			{
				bf.SetBit(i++);
		    }
			else
			{
				break;
			}
	}
	return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
	int lenght = bf.GetLenght();
	for (int i = 0; i < lenght; i++)
	{
		if (bf.GetBit(i))
		{
			ostr << 'i';
		}
		else
		{
			ostr << '0';
		}
	}
	return ostr;
}
