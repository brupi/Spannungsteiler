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

int main()
{
  double Eingangsspannung[] = {3, 4.5, 2.2, 5.6, 1.1, 9.3, 6.9, 3, 4.5, 2.2,
                               5.6, 1.1, 9.3, 6.9, 4};
  double Ausgangsspannung[] = {2.043478261, 1.607142857, 0.9075, 2.94566474,
                               0.84418605, 4.98214286, 1.67837838, 0.95652174,
                               2.89285714, 1.2925, 2.65433526, 0.25581395,
                               4.31785714, 5.22162162, 1.30434783};
  double R1[] = {2.2, 1.8, 4.7, 8.2, 1, 1.3, 5.6, 4.7, 1, 3.3, 9.1, 3.3, 1.5,
                 1.8, 6.2};
  double R2[] = {4.7, 1, 3.3, 9.1, 3.3, 1.5, 1.8, 2.2, 1.8, 4.7, 8.2, 1, 1.3,
                 5.6, 3};
  double x;
  double y;

  VoltageDivider TestClass;
  
  x = TestClass.setU1(Eingangsspannung[2]);
  cout << x << endl;
  
 /*
  int z = 14;
  for (z = 0; z <= 12; z++)
  {
    TestClass.setU1(Eingangsspannung[z]);
    TestClass.setU2(Ausgangsspannung[z]);
    x = TestClass.getR1();
    y = TestClass.getR2();
    cout << "R1: " << x << "||" << "R2: " << y << endl;
    cout << "Eingang: " << Eingangsspannung[z] << "||" << "Ausgang: "
         << Ausgangsspannung[z] << endl;
  }
  */
  return 0;
}




