#pragma once
#include "DatValue.h"

class TDatLink;
typedef TDatLink* PTDatLink;

class TDatLink
{
protected:
  PTDatValue pValue;  // ��������� �� ������ ��������
  PTDatLink pNext; // ��������� �� ��������� �����

public:
  TDatLink(PTDatValue pVal = nullptr, PTDatLink pN = nullptr)  : pNext(pN), pValue(pVal) { }
  void       SetDatValue(PTDatValue pVal) { pValue = pVal; }
  PTDatValue GetDatValue() { return pValue; }
  PTDatLink  GetNextDatLink() { return (PTDatLink)pNext; }

  PTDatLink GetNextLink() { return pNext; }
  void SetNextLink(PTDatLink pLink) { pNext = pLink; }
  void InsNextLink(PTDatLink pLink)
  {
    PTDatLink p = pNext;
    pNext = pLink;
    if (pLink != nullptr)
      pLink->pNext = p;
  }

  friend class TDatList;
};

