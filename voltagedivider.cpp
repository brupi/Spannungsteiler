#include "voltagedivider.h"
#include "math.h"

VoltageDivider::VoltageDivider(double u1, double u2) :
    u1(u1), u2(u2)
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
    double e12[12] = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2}; // chooses from array

    for(int i=0 ; i<12 ; ++i){
        for(int j=0 ; j<12 ; ++j){
            if(abs(((e12[i]+e12[j])/e12[j])-(u1/u2)) < abs(((r1+r2)/r2)-(u1/u2)))
            {
                r1 = e12[i];
                r2 = e12[j];
            }
        }
    }
}
