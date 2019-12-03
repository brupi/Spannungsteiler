#include "voltagedivider.h"
#include "math.h"

VoltageDivider::VoltageDivider(double u1, double u2) : u1(u1), u2(u2)
{
  calculate();
}

void VoltageDivider::setU1(double u1)
{
  this->u1 = u1;
  calculate();
}

void VoltageDivider::setU2(double u2)
{
  this->u2 = u2;
  calculate();
}

double VoltageDivider::getU1()
{
  return u1;
}

double VoltageDivider::getU2()
{
  return u2;
}

double VoltageDivider::getR1()
{
  return r1;
}

double VoltageDivider::getR2()
{
  return r2;
}

void VoltageDivider::calculate()
{
  double e12[12] = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7,
                    3.3, 3.9, 4.7, 5.6, 6.8, 8.2};  // E12 values
  if (u1 == u2)
  {
    r1 = 0;
    r2 = 1000;
  }
  else if (u2 == 0)
  {
    r1 = 1000;
    r2 = 0;
  }
  else
  {
    double ratio = (u1 - u2) / u2;
    // normalize ratio
    int scaleup = 1;
    while (ratio >= 10)
    {
      ratio /= 10.0;
      scaleup *= 10;
    }
    int scaledown = 1;
    while (ratio < 1)
    {
      ratio *= 10.0;
      scaledown *= 10;
    }
    // calc resistors
    for (int i = 12; i >= 0; --i)
    {
      for (int j = 12; j >= 0; --j)
      {
        if (fabs((e12[i] / e12[j]) - (ratio)) <= fabs((r1 / r2) - (ratio)))
        {
          r1 = e12[i];
          r2 = e12[j];
        }
      }
    }
    // rescale resistors
    r1 *= 100 * scaleup;
    r2 *= 100 * scaledown;
  }
}
