#include "DatList.h"
void TDatList::DelLink(PTDatLink pLink)
{
}

TDatList::TDatList()
{
  //PTDatLink pFirst;    // первое звено
  //PTDatLink pLast;     // последнее звено
  //PTDatLink pCurrLink; // текущее звено
  //PTDatLink pPrevLink; // звено перед текущим
  //PTDatLink pStop;     // значение указателя, означающего конец списка (=NULL)
  //int CurrPos;         // номер текущего знена (нумерация от 0)
  //int ListLen;         // количество звеньев в списке
  pFirst = pCurrLink =  pLast = pPrevLink = pStop = NULL;
  CurrPos = 0;
  ListLen = 0;
}

TDatList::TDatList(PTDatValue* listElems, int listElemsCount)
{
  if (listElemsCount > 0) {
    PTDatLink* a;
    a = new PTDatLink[listElemsCount];
    for (int i = 0; i < listElemsCount; i++) {
      a[i] = new TDatLink();
      a[i]->pValue = listElems[i];
    }
    a[listElemsCount - 1]->pNext = NULL;
    for (int i = listElemsCount - 2; i >= 0; i--) {
      a[i]->pNext = a[i + 1];
    }
    ListLen = listElemsCount;
    CurrPos = 0;
    pFirst = a[0];
    pLast = a[listElemsCount-1];
    pCurrLink = pFirst;
    pPrevLink = pLast;
    pStop = a[listElemsCount - 1]->pNext;
  }
  else {
    pFirst = pCurrLink = pPrevLink = pLast = pStop = NULL;
    CurrPos = 0;
    ListLen = 0;
    cout << "ERROR";
  }
}

PTDatLink TDatList::GetLink(PTDatValue pval, PTDatLink plink)
{
  PTDatLink temp = new TDatLink(pval, plink);
  return temp;
}



PTDatValue TDatList::GetDatValue(TLinkPos mode) const
{

  return pCurrLink->pValue;
}



int TDatList::SetCurrentPos(int pos)
{
  return 0;
}

int TDatList::GetCurrentPos(void) const
{
  return CurrPos;
}

int TDatList::Reset(void)
{
  if (!IsEmpty()) {
    CurrPos = 0;
    pCurrLink = pFirst;
    pPrevLink = pLast;
  }
  return 0;
}

bool TDatList::IsListEnded(void) const
{//PTDatLink pFirst;    // первое звено
  //PTDatLink pLast;     // последнее звено
  //PTDatLink pCurrLink; // текущее звено
  //PTDatLink pPrevLink; // звено перед текущим
  //PTDatLink pStop;     // значение указателя, означающего конец списка (=NULL)
  //int CurrPos;         // номер текущего знена (нумерация от 0)
  //int ListLen;         // количество звеньев в списке
  return CurrPos == ListLen;
}

int TDatList::GoNext(void)
{
 
  pPrevLink = pCurrLink;
  pCurrLink = pCurrLink->pNext;
  CurrPos++;
  return CurrPos;
}

void TDatList::InsFirst(PTDatValue pVal)
{
  
  PTDatLink a;
  a = new TDatLink();
  a->pValue = pVal;
  a->pNext = pFirst;
  pFirst = a;
  ListLen++;
}

void TDatList::InsLast(PTDatValue pVal)
{
  PTDatLink a=GetLink(pVal,pStop);
  if(pLast != NULL) pLast->SetNextLink(a);
  pLast = a;
  ListLen++;
  if (ListLen==1) { pFirst = a; Reset(); }
  if (IsListEnded()) pCurrLink = a; 
}

void TDatList::InsCurrent(PTDatValue pVal)
{
  //PTDatLink pFirst;    // первое звено
  //PTDatLink pLast;     // последнее звено
  //PTDatLink pCurrLink; // текущее звено
  //PTDatLink pPrevLink; // звено перед текущим
  //PTDatLink pStop;     // значение указателя, означающего конец списка (=NULL)
  //int CurrPos;         // номер текущего знена (нумерация от 0)
  //int ListLen;         // количество звеньев в списке
  if (IsEmpty() || (pCurrLink == pFirst))InsFirst(pVal);
  if (pCurrLink== pLast) {
    PTDatLink a = GetLink(pVal, pCurrLink);
    pCurrLink = a; 
    pPrevLink->SetNextLink(a);
    pLast = pCurrLink;
    ListLen++;
    CurrPos++;
  }
  else {
    PTDatLink a = GetLink(pVal, pCurrLink);
    pCurrLink = a; pPrevLink->SetNextLink(a);
    ListLen++;
    CurrPos++;
  }
}

void TDatList::DelFirst(void)
{

  pFirst = pFirst->pNext;
  ListLen--;
}

void TDatList::DelCurrent(void)
{
  if (pCurrLink == pLast) {
    pLast = pPrevLink;
    pCurrLink = pLast;
    ListLen--;
  }
  else {
    pPrevLink->SetNextLink(pCurrLink->pNext);
    pCurrLink = pCurrLink->pNext;
    ListLen--;
  }
}

void TDatList::DelList(void)
{
  pFirst = pCurrLink = pLast = pPrevLink = pStop = NULL;
  CurrPos = 0;
  ListLen = 0;

}