#include "Monom.h"

TDatValue * TMonom::GetCopy()
{
  TDatValue* temp = new TMonom(Coeff,Index);
  return temp;
}
