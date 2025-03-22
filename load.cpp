#include <string>
#include <TString.h>
#include <TSystem.h>

void load(TString myopt="fast")
{
    TString opt;
    if(myopt.Contains("force"))   opt = "kfg";
    else                          opt = "kg";
    
    gSystem->AddIncludePath((std::string("-I ")+gSystem->GetWorkingDirectory()+"/build").c_str());

    // BASE CLASSES
    gSystem->CompileMacro("include/vector2d.cxx", opt.Data(), "", "build");
    gSystem->CompileMacro("include/nucleus.cxx", opt.Data(), "", "build");
}