#include <iostream>
#include "itemValue.h"
#include "DatList.h"
#include "Monom.h"
#include "Polinom.h"
void printList(TDatList &st)
{
  PTItemValue pVal;
  for (st.Reset(); !st.IsListEnded(); st.GoNext())
  {
    pVal = (PTItemValue)st.GetDatValue();
    cout << pVal->GetValue() << " ";
  }
  cout << endl;
}

void main()
{
  setlocale(LC_ALL, "Russian");
  cout << "Тестирование списка" << endl;
  {
    // Конструктор --------------------------------------------
    cout << "\nКонструктор --------------------------------------------" << endl;
    int elemsCount = 5;
    PTDatValue* listElems = new PTDatValue[elemsCount];
    PTItemValue pVal;
    for (int i = 0; i < elemsCount; i++)
    {
      pVal = new TItemValue(10 * i);
      listElems[i] = pVal;
    }
    TDatList st(listElems, elemsCount);
    // печать списка
    printList(st);

    // Вставить элементы списка
    cout << "\nВставить элементы списка: 11 - в начало,13 - перед текущим 12 - в конец----" << endl;
    PTItemValue iVal1 = new TItemValue(11);
    PTItemValue iVal2 = new TItemValue(12);
    PTItemValue iVal3 = new TItemValue(13);
    printList(st);
    st.Reset();
    
    st.GoNext();
    st.GoNext();
    int cur1 = st.GetCurrentPos();
    cout << "Текущий элемент: " << cur1 + 1 << endl;
    st.InsFirst(iVal1);
    st.InsLast(iVal2);
    st.InsCurrent(iVal3);
    int cur2 = st.GetCurrentPos();
    cout << "Текущий элемент: " << cur2 + 1 << endl;
    printList(st);


    // Взять текущий элемент списка
    cout << "\nВзять текущий элемент списка ------------------------------------------" << endl;
    st.Reset();
    st.GoNext();
    st.GoNext();
    int cur4 = st.GetCurrentPos();
    cout << "Текущий элемент: " << cur4+1 << endl;
    PTItemValue iVal4 = (PTItemValue)(st.GetDatValue(CURRENT));
    cout << "Элемент = " << iVal4->GetValue() << endl;
    printList(st);

    // Удалить элемент списка
    cout << "\nУдалить элементы списка: текущий, первый ----------------------------" << endl;
    printList(st);
    st.Reset();
    st.GoNext();
    st.GoNext();
    int cur5 = st.GetCurrentPos();
    cout << "Текущий элемент: " << cur5+1 << endl;
    st.DelCurrent();
    st.DelFirst();
    printList(st);
  }
  

    cout << "Тестирование полиномов" << endl;

    cout << "Тест №1" << endl;
    int ms1[][2] = { {1, 543}, {3, 432}, {5, 321}, {7, 210}, {9, 100} };
    int mn1 = sizeof(ms1) / (2 * sizeof(int));
    TPolinom p(ms1, mn1);
    cout << "1 полином" << endl << p;
    int ms2[][2] = { {2, 643}, {4, 432}, {-5, 321}, {8, 110}, {10, 50} };
    int mn2 = sizeof(ms2) / (2 * sizeof(int));
    TPolinom q(ms2, mn2);
    cout << "2 полином" << endl << q;
    TPolinom r = p + q;
    cout << "Полином-результат + " << endl << r;
    TPolinom r1 = r;
    cout << "Полином-результат = " << endl << r1;
    TPolinom c(r);
    cout << "Полином-копия = " << endl << c;
    cout << "Правильный ответ " << endl;
    cout << "2(643)  1(543)  7(432)  7(210)  8(110)  9(100)  10(50)" << endl;
    cout << endl;


    cout << "Тест №2 " << endl;
    int ms5[][2] = { {1, 543}, {3, 432}, {5, 321}, {7, 210}, {9, 30} };
    int mn5 = sizeof(ms5) / (2 * sizeof(int));
    TPolinom p3(ms5, mn5);
    cout << "1 полином" << endl << p3;
    int ms6[][2] = { {2, 643}, {4, 432}, {5, 400} };
    int mn6 = sizeof(ms6) / (2 * sizeof(int));
    TPolinom q3(ms6, mn6);
    cout << "2 полином" << endl << q3;
    TPolinom r3 = p3 + q3;
    cout << "Полином-результат  q + p " << endl << r3;
    cout << "Правильный ответ " << endl;
    cout << "2(643)  1(543)  7(432)  5(400)  5(321)  7(210)  9(30)" << endl;
    cout << endl;



    cout << "Тест №3 (последние мономы одинаковы, но coeff = 0)" << endl;
    int ms3[][2] = { {1, 543}, {3, 432}, {5, 321} };
    int mn3 = sizeof(ms3) / (2 * sizeof(int));
    TPolinom p2(ms3, mn3);
    cout << "1 полином" << endl << p2;
    int ms4[][2] = { {2, 643}, {4, 432}, {-5, 321} };
    int mn4 = sizeof(ms4) / (2 * sizeof(int));
    TPolinom q2(ms4, mn4);
    cout << "2 полином" << endl << q2;
    TPolinom r2 = p2 + q2;
    cout << "Полином-результат  q + p " << endl << r2;
    cout << "Правильный ответ " << endl;
    cout << "2(643)  1(543)  7(432)" << endl;
    cout << endl;



    cout << "Тест №4 (последние мономы одинаковы)" << endl;
    int ms7[][2] = { {1, 543}, {3, 432}, {5, 321}, {7, 210}, {9, 50} };
    int mn7 = sizeof(ms7) / (2 * sizeof(int));
    TPolinom p4(ms7, mn7);
    cout << "1 полином" << endl << p4;
    int ms8[][2] = { {2, 643}, {4, 432}, {-5, 321}, {8, 110}, {10, 50} };
    int mn8 = sizeof(ms8) / (2 * sizeof(int));
    TPolinom q4(ms8, mn8);
    cout << "2 полином" << endl << q4;
    TPolinom r4 = p4 + q4;
    cout << "Полином-результат  q + p " << endl << r4;
    cout << "Правильный ответ " << endl;
    cout << "2(643)  1(543)  7(432)  7(210)  8(110)  19(50)" << endl;
    cout << endl;



  getchar();
  getchar();
}
