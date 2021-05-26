#pragma once
#include <iostream>
#include "DatValue.h"
using namespace std;

class TItemValue;
typedef TItemValue *PTItemValue;

class TItemValue : public TDatValue
{
protected:
  int   Value; // значение
public:
  TItemValue(int ival = 0) : Value(ival) { }
  virtual ~TItemValue() { }
  virtual TDatValue* GetCopy(); // изготовить копию
  void  SetValue(int ival) { Value = ival; }
  int   GetValue(void) { return Value; }
  TItemValue& operator=(const TItemValue &tm)
  {
    Value = tm.Value;
    return *this;
  }
  int operator==(const TItemValue &tm)
  {
    return (Value == tm.Value);
  }
  int operator<(const TItemValue &tm)
  {
    return Value < tm.Value;
  }
  friend ostream& operator<<(ostream &os, TItemValue &tm)
  {
    os << tm.Value;
    return os;
  }

};
