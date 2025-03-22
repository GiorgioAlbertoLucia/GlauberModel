#include <iostream>
#include <TMultiGraph.h>
#include <TStopwatch.h>
#include <TCanvas.h>
#include <TFile.h>
#include "include/glauberMC.hh"

void run()
{
    const int A1 = 208;
    const int A2 = 208;
    int n_events = 1000;
    float b_max = 20; // fm
    float cross_section_inel = 3; // fm^2

    TStopwatch timer;
    timer.Start();
    GlauberOutput output = run_Glauber_mc(A1, A2, n_events, b_max, cross_section_inel);
    timer.Stop();
    std::cout << "MC ended in: " << timer.RealTime() << " s" << std::endl;
    
    auto outfile = TFile::Open("output/GlauberMC.root", "recreate");
    output.g_Npart.SetMarkerStyle(20);
    output.g_Npart.Write();
    output.g_Ncoll.SetMarkerStyle(20);
    output.g_Ncoll.Write();
}