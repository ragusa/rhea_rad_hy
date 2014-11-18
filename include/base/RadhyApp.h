#ifndef RADHYAPP_H
#define RADHYAPP_H

#include "MooseApp.h"

class RadhyApp;

template<>
InputParameters validParams<RadhyApp>();

class RadhyApp : public MooseApp
{
public:
  RadhyApp(const std::string & name, InputParameters parameters);
  virtual ~RadhyApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* RADHYAPP_H */
