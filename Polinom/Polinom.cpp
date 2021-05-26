#include "Polinom.h"

TPolinom::TPolinom(int monoms[][2], int km)
{


  PTMonom pm = new TMonom(0, -1);

  for (int i = 0; i < km; i++)
  {
    pm = new TMonom(monoms[i][0], monoms[i][1]);
    InsLast(pm);
  }
}

TPolinom::TPolinom(TPolinom & q)
{
  PTMonom pm = new TMonom(0, -1);

  for (q.Reset(); !q.IsListEnded(); q.GoNext())
  {
    pm = q.GetMonom();
    InsLast(pm->GetCopy());
  }
}

TPolinom& TPolinom::operator+( TPolinom  q)
{
  PTMonom pm, qm, rm,t;
  Reset(); q.Reset();
  TPolinom temp;
  while (1)
  {
    pm = GetMonom(); qm = q.GetMonom();
    if (pm->Index < qm->Index) {
      rm = new TMonom(qm->Coeff, qm->Index);
      temp.InsLast(rm); q.GoNext();
    }
    else if (pm->Index > qm->Index) {
      rm = new TMonom(pm->Coeff, pm->Index);
      temp.InsLast(rm); GoNext();
    }
    else {
      pm->Coeff += qm->Coeff;
      if (pm->Coeff != 0) {
        rm = new TMonom(pm->Coeff, pm->Index);
        temp.InsLast(rm);
        GoNext(); q.GoNext(); 
      } else { GoNext(); q.GoNext(); }
    }
    if (IsListEnded() || q.IsListEnded()) {
      if (!q.IsListEnded()) {
        while (!q.IsListEnded()) {
          qm = q.GetMonom();
          rm = new TMonom(qm->Coeff, qm->Index);
          temp.InsLast(rm); q.GoNext(); } 
      }else {
        while (!IsListEnded()) {
          qm = GetMonom();
          rm = new TMonom(qm->Coeff, qm->Index);
          temp.InsLast(rm); GoNext();
        }
      }
        ListLen--;
        break;
    }
  }
  (*this) = temp;
  return *this;
}

TPolinom & TPolinom::operator=(TPolinom & q)
{
  DelList();
  for (q.Reset(); !q.IsListEnded(); q.GoNext()) {
    PTMonom pMonom = q.GetMonom();
    InsLast(pMonom->GetCopy());
  }
  return *this; 
}

//if (pLast == pCurrLink || q.IsListEnded()) {
//  pm = GetMonom();
//  t = new TMonom(pm->Coeff, pm->Index);
//  if (!q.IsListEnded()) {
//    pm = GetMonom();
//    t = new TMonom(pm->Coeff, pm->Index);
//    DelCurrent();
//    while (!q.IsListEnded()) {
//      qm = q.GetMonom();
//      if (pm->Index < qm->Index || (pm->Index == NULL)) {
//        qm = q.GetMonom();
//        rm = new TMonom(qm->Coeff, qm->Index);
//        InsLast(rm); q.GoNext();
//      }
//      else {
//        InsLast(t); pm->Index = NULL;
//      }
//    } if (pm->Index != NULL) {
//      InsLast(t);
//    }
//  }
//  ListLen--;
//  break;
//}