/*
 * testvoltage.cpp
 *
 *  Created on: Dec 5, 2019
 *      Author: user
 */

//============================================================================
// Name        : TestPMSwEng.cpp
// Author      : SH
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include "voltagedivider.h"
#include "math.h"
#include <assert.h>

using namespace std;

int main()
{
  double Eingangsspannung[] = {3, 4.5, 2.2, 5.6};
  double Ausgangsspannung[] = {2.043478261, 1.607142857, 0.9075, 2.94566474};
  double R1[] = {560, 180, 470, 820};
  double R2[] = {1200, 100, 330, 1000};
  double x;
  double y;

  VoltageDivider TestClass;

  int z = 0;
  for (z = 0; z <= 2; z++)
  {
    TestClass.setU1(Eingangsspannung[z]);
    TestClass.setU2(Ausgangsspannung[z]);
    x = TestClass.getR1();
    y = TestClass.getR2();
    assert(R1[z] == x);
    assert(R2[z] == y);
  }
  cout << "Test successful!" << endl;

  return 0;
}





