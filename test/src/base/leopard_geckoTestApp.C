//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "leopard_geckoTestApp.h"
#include "leopard_geckoApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
leopard_geckoTestApp::validParams()
{
  InputParameters params = leopard_geckoApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

leopard_geckoTestApp::leopard_geckoTestApp(InputParameters parameters) : MooseApp(parameters)
{
  leopard_geckoTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

leopard_geckoTestApp::~leopard_geckoTestApp() {}

void
leopard_geckoTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  leopard_geckoApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"leopard_geckoTestApp"});
    Registry::registerActionsTo(af, {"leopard_geckoTestApp"});
  }
}

void
leopard_geckoTestApp::registerApps()
{
  registerApp(leopard_geckoApp);
  registerApp(leopard_geckoTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
leopard_geckoTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  leopard_geckoTestApp::registerAll(f, af, s);
}
extern "C" void
leopard_geckoTestApp__registerApps()
{
  leopard_geckoTestApp::registerApps();
}
