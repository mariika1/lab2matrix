#pragma once
#ifndef _TMATRIX_H_
#define _TMATRIX_H_

#include "TVector.h"

template <class ValType>
class TMatrix : public TVector<TVector<ValType>>
{
  using TVector<TVector<ValType> >::pVector;
  using TVector<TVector<ValType> >::Size;
  using TVector<TVector<ValType> >::StartIndex;
public:
  TMatrix(int s = 10);
  TMatrix(const TMatrix& mt);                    
  TMatrix(const TVector<TVector<ValType> >& mt);  
  bool operator==(const TMatrix& mt) const;      
  bool operator!=(const TMatrix& mt) const;      
  TMatrix& operator= (const TMatrix& mt);        
  TMatrix  operator+ (const TMatrix& mt);        
  TMatrix  operator- (const TMatrix& mt);        

  
  friend std::istream& operator>>(std::istream& in, TMatrix& mt)
  {
    for (int i = 0; i < mt.Size; i++)
      in >> mt.pVector[i];
    return in;
  }
  friend std::ostream& operator<<(std::ostream& out, const TMatrix& mt)
  {
    for (int i = 0; i < mt.Size; i++)
      out << mt.pVector[i] << std::endl;
    return out;
  }
};

template<typename ValType>
TMatrix<ValType>::TMatrix(int s) : TVector<TVector<ValType> >(s)
{
  if (s > 0)
  {
    for (int i = 0; i < s; i++)
      pVector[i] = TVector<ValType>(s - i, i);
  }
  else throw - 1;
}

template<typename ValType>
TMatrix<ValType>::TMatrix(const TMatrix<ValType>& mt)
  : TVector<TVector<ValType> >(mt)
{
}

template<typename ValType>
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> >& mt)
  : TVector<TVector<ValType> >(mt)
{
}

template<typename ValType>
bool TMatrix<ValType>::operator==(const TMatrix<ValType>& mt) const
{
  if (Size != mt.Size)
    return false;
  for (int i = 0; i < mt.Size; i++)
    if (pVector[i] != mt.pVector[i])
      return false;
  return true;
}

template<typename ValType>
bool TMatrix<ValType>::operator!=(const TMatrix<ValType>& mt) const
{
  return !(*this == mt);
}

template<typename ValType>
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt)
{
  if (this != &mt)
  {
    if (Size != mt.Size)
    {
      delete[] pVector;
      pVector = new TVector<ValType>[mt.Size];
    }
    Size = mt.Size;
    StartIndex = mt.StartIndex;
    for (int i = 0; i < Size; i++)
      pVector[i] = mt.pVector[i];
  }
  return *this;
}

template<typename ValType>
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix& mt)
{
  return TVector<TVector<ValType> >::operator+(mt);
}

template<typename ValType>
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix& mt)
{
  return TVector<TVector<ValType> >::operator-(mt);
}

#endif