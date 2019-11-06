#ifndef VOLTAGEDIVIDER_H
#define VOLTAGEDIVIDER_H

class VoltageDivider
{
public:
    VoltageDivider(double u1, double u2, double r1);
    void setU1(double u1);
    void setU2(double u2);
    double getR1();
    double getR2();
private:
    void calculate();
    void chooseFromE12();
    double u1;
    double u2;
    double r1;
    double r2;
};

#endif // VOLTAGEDIVIDER_H
