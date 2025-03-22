#include <iostream>
#include <TMultiGraph.h>
#include <TCanvas.h>
#include <TRandom3.h>
#include <TMath.h>
#include "include/vector2d.hh"
#include "include/nucleus.hh"
#include "include/collision.hh"

void test()
{
    gRandom->SetSeed(105);

    Nucleus Pb1(208);
    Nucleus Pb2(208);

    // random shift
    float b = 0; // shift by 2 fm (impact parameter)
    float theta = gRandom->Uniform(0, 2 * TMath::Pi());
    std::cout << "theta = " << theta << std::endl;
    Vector2d shift(b * cos(theta), b * sin(theta));

    Pb2.shift(shift);

    float cross_section_inel = 3; // fm^2 -> 30 mb
    CollisionOutput output = perform_collision(Pb1, Pb2, cross_section_inel);
    std::cout << "Npart = " << output.Npart << "\nNcoll = " << output.Ncoll << std::endl;   

    auto g_Pb1 = Pb1.draw();
    g_Pb1->SetName("Pb1");
    g_Pb1->SetMarkerColor(kRed);
    g_Pb1->SetMarkerStyle(20);
    g_Pb1->SetMarkerSize(1);

    auto g_Pb2 = Pb2.draw();
    g_Pb2->SetName("Pb2");
    g_Pb2->SetMarkerColor(kBlue);
    g_Pb2->SetMarkerStyle(20);
    g_Pb2->SetMarkerSize(1);

    auto canvas = new TCanvas();
    canvas->DrawFrame(-20, -20, 20, 20, "; x [fm]; y [fm]");
    g_Pb1->Draw("p same");
    g_Pb2->Draw("p same");
    canvas->SaveAs("output/PbPb.pdf");
}