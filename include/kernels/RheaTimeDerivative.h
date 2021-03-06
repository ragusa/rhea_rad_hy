/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef RHEATIMEDERIVATIVE
#define RHEATIMEDERIVATIVE

#include "TimeDerivative.h"

class RheaTimeDerivative;

template<>
InputParameters validParams<RheaTimeDerivative>();

class RheaTimeDerivative : public TimeDerivative
{
public:

  RheaTimeDerivative(const std::string & name,
                        InputParameters parameters);

protected:
  virtual Real computeQpResidual();

  virtual Real computeQpJacobian();

};

#endif
