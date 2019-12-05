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

using namespace std;

int main() {
  double Eingangsspannung[] = {3, 4.5, 2.2, 5.6, 1.1, 9.3, 6.9, 3, 4.5, 2.2, 5.6, 1.1, 9.3, 6.9, 4};
  double Ausgangsspannung[] = {2.04, 1.61, 0.91, 2.95, 0.84, 4.98, 1.68, 0.96, 2.89, 1.29, 2.65, 0.26, 4.32, 5.22, 1.30};
  double R1[] = {2.2, 1.8, 4.7, 8.2, 1, 1.3, 5.6, 4.7, 1, 3.3, 9.1, 3.3, 1.5, 1.8, 6.2};
  double R2[] = {4.7, 1, 3.3, 9.1, 3.3, 1.5, 1.8, 2.2, 1.8, 4.7, 8.2, 1, 1.3, 5.6, 3};
  double x;
  double y;

  VoltageDivider TestClass;

  TestClass.setU1(Eingangsspannung[0]);
  TestClass.setU2(Ausgangsspannung[0]);
  x = TestClass.getR1();
  y = TestClass.getR2();



  cout << x << endl;
  cout << y << endl;

/*
  for (int i = 0; i <= 14; i++) {
  cout << Eingangsspannung[i] << "  " << Ausgangsspannung[i] << "  " << R1[i] << "  " << R2[i] << endl;
  }
  for (int i = 0; i <= 14; i++) {
  cout << (Eingangsspannung[i]/(R1[i] + R2[i])) * R2[i] << endl;
  }
  */
  // silas
  return 0;
}



