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

#ifndef RHEAFORCINGFUNCTIONSTREAM_H
#define RHEAFORCINGFUNCTIONSTREAM_H

#include "Kernel.h"
#include "EquationOfState.h"

// Forward Declarations
class RheaForcingFunctionStream;

template<>
InputParameters validParams<RheaForcingFunctionStream>();

class RheaForcingFunctionStream : public Kernel
{
public:

  RheaForcingFunctionStream(const std::string & name,
             InputParameters parameters);

protected:

  virtual Real computeQpResidual();

  virtual Real computeQpJacobian();

  virtual Real computeQpOffDiagJacobian(unsigned int _jvar);
    
private:
    // Equations types
    enum EquationType
    {
        CONTINUITY = 0,
        MOMENTUM = 1,
        ENERGY = 2,
        RADIATION = 3
    };

    // Diffusion name
    std::string _equ_name;
    
    // Diffusion type
    MooseEnum _equ_type;
    
    // Constants
    const Real & _c;
    const Real & _a;
    const Real & _sigma_t;
    
    // Equation of state:
    const EquationOfState & _eos;
    
    // Material property: viscosity coefficient.
    MaterialProperty<Real> & _sigma_a;
    MaterialProperty<Real> & _D;
    MaterialProperty<Real> & _mu;
};

#endif //RHEAFORCINGFUNCTIONSTREAM_H
