#ifndef VOLTAGEDIVIDER_H
#define VOLTAGEDIVIDER_H

class VoltageDivider
{
 public:
  /// \brief sets the given parameters and calls the function calculate
  /// \pre u1 > u2
  /// \param u1 input voltage
  /// \param u2 output voltage
  VoltageDivider(double u1 = 1, double u2 = 1);

  /// \brief sets the parameter u1 and calls the function calculate
  /// \param u1 input voltage
  void setU1(double u1);

  /// \brief sets the parameter u2 and calls the function calculate
  /// \param u2 output voltage
  void setU2(double u2);

  /// \brief gets the parameter u1
  /// \return double input voltage
  double getU1();

  /// \brief gets the parameter u2
  /// \return double output voltage
  double getU2();

  /// \brief gets the parameter R1
  /// \return double upper resistor
  double getR1();

  /// \brief gets the parameter R2
  /// \return double lower resistor
  double getR2();

 private:
  void calculate();
  double u1;
  double u2;
  double r1;
  double r2;
};

#endif  // VOLTAGEDIVIDER_H
