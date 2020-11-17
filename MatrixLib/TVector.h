#ifndef _TVECTOR_H_
#define _TVECTOR_H_

#include <iostream>

template <class ValType>
class TVector
{
protected:
  ValType* pVector;
  int Size;       
  int StartIndex; 
public:
  TVector(int s = 10, int si = 0);
  TVector(const TVector& v);                
  ~TVector();
  int GetSize() { return Size; }            
  int GetStartIndex() { return StartIndex; } 
  ValType& operator[](int pos);             
  bool operator==(const TVector& v) const;  
  bool operator!=(const TVector& v) const;  
  TVector& operator=(const TVector& v);     

  
  TVector  operator+(const ValType& val);   
  TVector  operator-(const ValType& val);   
  TVector  operator*(const ValType& val);   


  TVector  operator+(const TVector& v);     
  TVector  operator-(const TVector& v);     
  ValType  operator*(const TVector& v);     

  friend std::istream& operator>>(std::istream& in, TVector& v)
  {
    for (int i = 0; i < v.Size; i++)
      in >> v.pVector[i];
    return in;
  }
  friend std::ostream& operator<<(std::ostream& out, const TVector& v)
  {
    for (int i = 0; i < v.Size; i++)
      out << v.pVector[i] << ' ';
    return out;
  }
};


template<typename ValType>
TVector<ValType>::TVector(int s, int si)
  : Size(s), StartIndex(si)
{
  if (Size < 0)
    throw "negative vector size";
  if (StartIndex < 0)
    throw "negative startindex";
  pVector = new ValType[s];
  for (int i = 0; i < s; i++)
    pVector[i] = 0;
}

template<typename ValType>
TVector<ValType>::TVector(const TVector& v)
  : Size(v.Size), StartIndex(v.StartIndex), pVector(nullptr)
{
  pVector = new ValType[Size];
  for (int i = 0; i < Size; i++)
    pVector[i] = v.pVector[i];
}

template<typename ValType>
TVector<ValType>::~TVector()
{
  if (pVector != nullptr)
    delete[] pVector;
}

template<typename ValType>
bool TVector<ValType>::operator==(const TVector& v) const
{
  if ((Size != v.Size) || (StartIndex != v.StartIndex))
    return false;
  for (int i = StartIndex; i < Size; i++)
    if (pVector[i] != v.pVector[i])
      return false;
  return true;
}

template<typename ValType>
bool TVector<ValType>::operator!=(const TVector& v) const
{
  return !(*this == v);
}

template<typename ValType>
TVector<ValType>& TVector<ValType>::operator=(const TVector& v)
{
  if (this != &v)
  {
    if (Size != v.Size)
    {
      Size = v.Size;
      delete[] pVector;
      pVector = new ValType[Size];
    }
    StartIndex = v.StartIndex;
    for (int i = 0; i < Size; i++)
      pVector[i] = v.pVector[i];
  }
  return *this;
}

template<typename ValType>
TVector<ValType> TVector<ValType>::operator+(const ValType& val)
{
  TVector result(Size, StartIndex);
  for (int i = StartIndex; i < Size; i++)
    result.pVector[i] = pVector[i] + val;
  return result;
}

template<typename ValType>
TVector<ValType> TVector<ValType>::operator-(const ValType& val)
{
  TVector result(Size, StartIndex);
  for (int i = StartIndex; i < Size; i++)
    result.pVector[i] = pVector[i] - val;
  return result;
}

template<typename ValType>
TVector<ValType> TVector<ValType>::operator*(const ValType& val)
{
  TVector result(Size, StartIndex);
  for (int i = StartIndex; i < Size; i++)
    result.pVector[i] = pVector[i] * val;
  return result;
}

template<typename ValType>
TVector<ValType> TVector<ValType>::operator+(const TVector& v)
{
  if ((Size != v.Size) || (StartIndex != v.StartIndex))
    throw "Different sizes of vectors";
  TVector result(Size, StartIndex);
  for (int i = StartIndex; i < Size; i++)
    result.pVector[i] = pVector[i] + v.pVector[i];
  return result;
}

template<typename ValType>
TVector<ValType> TVector<ValType>::operator-(const TVector& v)
{
  if ((Size != v.Size) || (StartIndex != v.StartIndex))
    throw "Different sizes of vectors";
  TVector result(Size, StartIndex);
  for (int i = StartIndex; i < Size; i++)
    result.pVector[i] = pVector[i] - v.pVector[i];
  return result;
}

template<typename ValType>
ValType TVector<ValType>::operator*(const TVector& v)
{
  if ((Size != v.Size) || (StartIndex != v.StartIndex))
    throw "Different sizes of vectors";
  ValType result = 0;
  for (int i = StartIndex; i < Size; i++)
    result += pVector[i] * v.pVector[i];
  return result;
}

template<typename ValType>
ValType& TVector<ValType>::operator[](int pos)
{
  if ((pos < StartIndex) || (pos >= Size))
    throw "Wrong position";
  return pVector[pos];
}

#endif