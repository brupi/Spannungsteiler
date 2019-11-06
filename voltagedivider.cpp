#include "voltagedivider.h"

VoltageDivider::VoltageDivider(double u1, double u2, double r1) :
    u1(u1), u2(u2), r1(r1), r2(0)
{
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

void VoltageDivider::setR1(double r1)
{
    this->r1 = r1;
    calculate();
}

double VoltageDivider::getR2()
{
    return r2;
}

// returns r2
void VoltageDivider::calculate()
{
   r2 = r1/((u1/u2)-1);
}

void VoltageDivider::chooseFromE12()
{
    // chooses from array
    r1 = 1;
    r2 = 2;
}
