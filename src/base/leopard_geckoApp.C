#include "leopard_geckoApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
leopard_geckoApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

leopard_geckoApp::leopard_geckoApp(InputParameters parameters) : MooseApp(parameters)
{
  leopard_geckoApp::registerAll(_factory, _action_factory, _syntax);
}

leopard_geckoApp::~leopard_geckoApp() {}

void 
leopard_geckoApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<leopard_geckoApp>(f, af, s);
  Registry::registerObjectsTo(f, {"leopard_geckoApp"});
  Registry::registerActionsTo(af, {"leopard_geckoApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
leopard_geckoApp::registerApps()
{
  registerApp(leopard_geckoApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
leopard_geckoApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  leopard_geckoApp::registerAll(f, af, s);
}
extern "C" void
leopard_geckoApp__registerApps()
{
  leopard_geckoApp::registerApps();
}
