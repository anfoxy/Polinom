#include "ItemValue.h"

TDatValue * TItemValue::GetCopy()
{
  TDatValue* temp = new TItemValue(Value);
  return temp;
}
