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
/**
This function computes the pressure. It is dimension agnostic.
**/
#include "PressureAux.h"

template<>
InputParameters validParams<PressureAux>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addRequiredCoupledVar("rho", "density");
  params.addRequiredCoupledVar("rhou", "momentum");
  params.addRequiredCoupledVar("rhoE", "material total energy");
  params.addRequiredParam<UserObjectName>("eos", "Equation of state");
  return params;
}

PressureAux::PressureAux(const std::string & name, InputParameters parameters) :
    AuxKernel(name, parameters),
  // Coupled variables
    _rho(coupledValue("rho")),
    _rhou(coupledValue("rhou")),
    _rhoE(coupledValue("rhoE")),
  // User Objects for eos
    _eos(getUserObject<EquationOfState>("eos"))

{}

Real
PressureAux::computeValue()
{
    // Computes the density, the norm of the velocity and the total energy:
    Real _vel = _rhou[_qp] / _rho[_qp];
    
    // Computes the pressure
    return _eos.pressure(_rho[_qp], _vel, _rhoE[_qp]);
}
