#pragma once
#include <iostream>
using namespace std;

#include "DatLink.h"

enum TLinkPos { FIRST, CURRENT, LAST };

class TDatList;
typedef TDatList *PTDatList;

class TDatList
{
protected:
  PTDatLink pFirst;    // ������ �����
  PTDatLink pLast;     // ��������� �����
  PTDatLink pCurrLink; // ������� �����
  PTDatLink pPrevLink; // ����� ����� �������
  PTDatLink pStop;     // �������� ���������, ����������� ����� ������ (=NULL)
  int CurrPos;         // ����� �������� ����� (��������� �� 0)
  int ListLen;         // ���������� ������� � ������

  void      DelLink(PTDatLink pLink); // �������� �����
public:
  TDatList();
  TDatList(PTDatValue* listElems, int listElemsCount);
  ~TDatList() { DelList(); }
  PTDatLink GetLink(PTDatValue pval=NULL, PTDatLink plink=NULL);
  // ������ --------------------------------------------------------------
  PTDatValue GetDatValue(TLinkPos mode = CURRENT) const;  // ��������
  int GetListLength()   const { return ListLen; }         // �-�� �������
  bool IsEmpty() const { return pFirst == pStop; } // ������ ����?
  // ��������� ------------------------------------------------------------
  int SetCurrentPos(int pos);           // ���������� ������� �����
  int GetCurrentPos(void) const;        // �������� ����� �������� �����
  // �������� -------------------------------------------------------------
  int Reset(void);              // ���������� �� ������ ������
  bool IsListEnded(void) const; // ������ ��������?
                                        // =true ����� ���������� GoNext 
                                        // � ���������� ����� ������
  int GoNext(void);                     // ����� ������ �������� �����
  // ������� ������� ------------------------------------------------------
  void InsFirst(PTDatValue pVal = nullptr); // �������� ����� ������
  void InsLast(PTDatValue pVal = nullptr); // �������� ���������                                                
  void InsCurrent(PTDatValue pVal = nullptr); // �������� ����� �������
  // �������� �������
  void DelFirst(void); // ������� ������ �����                  (#�2)
  void DelCurrent(void); // ������� ������� �����                 (#�2)
  void DelList(void); // ������� ���� ������

  

};

