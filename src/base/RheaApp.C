#include "RheaApp.h"

// Moose includes
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

// Kernels
#include "RheaTimeDerivative.h"
#include "RheaMass.h"
#include "RheaMomentum.h"
#include "RheaEnergy.h"
#include "RheaRadiation.h"
#include "RheaArtificialVisc.h"
#include "RheaForcingFunction.h"
#include "RheaForcingFunctionStream.h"

// Auxkernels
#include "PressureAux.h"
#include "TemperatureAux.h"
#include "InternalEnergyAux.h"
#include "VelocityAux.h"
#include "MachNumberAux.h"
#include "RadTempAux.h"

// BCs
#include "RheaBCs.h"

// ICs
#include "InitialConditions.h"

// Userobjects
#include "EquationOfState.h"
#include "JumpGradientInterface.h"

//Materials
#include "ComputeMaterials.h"


template<>
InputParameters validParams<RheaApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

RheaApp::RheaApp(const std::string & name, InputParameters parameters) :
    MooseApp(name, parameters)
{
  srand(processor_id());

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  RheaApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  RheaApp::associateSyntax(_syntax, _action_factory);
}

RheaApp::~RheaApp()
{
}

void
RheaApp::registerApps()
{
  registerApp(RheaApp);
}

void
RheaApp::registerObjects(Factory & factory)
{
      // Kernels
      registerKernel(RheaTimeDerivative);
      registerKernel(RheaMass);
      registerKernel(RheaMomentum);
      registerKernel(RheaEnergy);
      registerKernel(RheaRadiation);
      registerKernel(RheaArtificialVisc);
      registerKernel(RheaForcingFunction);
      registerKernel(RheaForcingFunctionStream);
      
      // Auxkernels
      registerAux(PressureAux);
      registerAux(TemperatureAux);
      registerAux(InternalEnergyAux);
      registerAux(VelocityAux);
      registerAux(MachNumberAux);
      registerAux(RadTempAux);
      
      // BCs
      registerBoundaryCondition(RheaBCs);
      
      // ICs
      registerInitialCondition(InitialConditions);
      
      // Userobjects
      registerUserObject(EquationOfState);
      registerUserObject(JumpGradientInterface);
      
      // Materials
      registerMaterial(ComputeMaterials);
}

void
RheaApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
