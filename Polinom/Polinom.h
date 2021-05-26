#pragma once
#include "DatList.h"
#include "Monom.h"

class TPolinom : public TDatList
{
public:
  TPolinom(int monoms[][2] = nullptr, int km = 0);
  TPolinom(TPolinom &q);            // ����������� �����������
  TPolinom& operator+(TPolinom q); // �������� ���������
  TPolinom& operator=(TPolinom &q); // ������������
  PTMonom GetMonom() { return (PTMonom)GetDatValue(); }

  friend ostream& operator<<(ostream &os, TPolinom &q) {
    
    for (q.Reset(); !q.IsListEnded(); q.GoNext())
    {
      cout << *q.GetMonom() << "  " ;
    }
    cout << endl;
    return os;
  }
};

