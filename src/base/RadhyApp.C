#include "RadhyApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<RadhyApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

RadhyApp::RadhyApp(const std::string & name, InputParameters parameters) :
    MooseApp(name, parameters)
{
  srand(processor_id());

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  RadhyApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  RadhyApp::associateSyntax(_syntax, _action_factory);
}

RadhyApp::~RadhyApp()
{
}

void
RadhyApp::registerApps()
{
  registerApp(RadhyApp);
}

void
RadhyApp::registerObjects(Factory & factory)
{
}

void
RadhyApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
