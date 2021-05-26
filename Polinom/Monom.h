#pragma once
#include <iostream>
#include "DatValue.h"
using namespace std;

class TMonom;
typedef TMonom *PTMonom;

class TMonom : public TDatValue
{
protected:
  float Coeff; // ����������� ������
  int   Index; // ������ (������� ��������)
public:
  TMonom(float cval = 1, int ival = 0) : Coeff(cval), Index(ival) { }
  virtual ~TMonom() { }
  virtual TDatValue* GetCopy(); // ���������� �����
  void  SetCoeff(float cval) { Coeff = cval; }
  float GetCoeff(void) { return Coeff; }
  void  SetIndex(int ival) { Index = ival; }
  int   GetIndex(void) { return Index; }
  TMonom& operator=(const TMonom &tm)
  {
    Coeff = tm.Coeff;
    Index = tm.Index;
    return *this;
  }
  int operator==(const TMonom &tm)
  {
    return (Coeff == tm.Coeff) && (Index == tm.Index);
  }
  int operator<(const TMonom &tm)
  {
    return Index < tm.Index;
  }
  friend ostream& operator<<(ostream &os, TMonom &tm)
  {
    os << tm.Coeff << "(" << tm.Index << ")";
    return os;
  }
  friend class TPolinom;
};
