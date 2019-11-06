#include "voltagedivider.h"
#include "math.h"

VoltageDivider::VoltageDivider(double u1, double u2) :
    u1(u1), u2(u2), r1(1), r2(1)
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

double VoltageDivider::getR1()
{
    return r1;
}

double VoltageDivider::getR2()
{
    return r2;
}

// returns r2
void VoltageDivider::calculate()
{
    //r2 = r1/((u1/u2)-1);
    chooseFromE12();
}

void VoltageDivider::chooseFromE12()
{
    double e12[12] = {1.0, 1.2, 1.5, 1.8, 2.2, 2.7, 3.3, 3.9, 4.7, 5.6, 6.8, 8.2}; // chooses from array
    //double ratio = u1/u2;

    for(int i=0 ; i<12 ; ++i){
        for(int j=0 ; j<12 ; ++j){
            if(abs((e12[i]/e12[j])-(u1/u2)) < abs((r1/r2)-(u1/u2)))
            {
                r1 = e12[i];
                r2 = e12[j];
            }
        }
    }
}
