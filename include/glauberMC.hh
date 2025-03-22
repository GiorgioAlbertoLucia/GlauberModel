#include <iostream>
#include <TGraph.h>
#include <TRandom3.h>
#include "nucleus.hh"
#include "collision.hh"

typedef struct GlauberOutput
{
    TGraph g_Npart;  // number of participants vs impact parameter
    TGraph g_Ncoll;
} GlauberOutput;

/**
 * @brief Run a Monte Carlo Glauber simulation
 * @param A1 Mass number of the first nucleus
 * @param A2 Mass number of the second nucleus
 * @param Nevents Number of events to simulate (for each value of the impact parameter)
 * @param b_max Maximum impact parameter
 * @param cross_section_inel Inelastic cross section in fm^2
*/
GlauberOutput run_Glauber_mc(const int A1, const int A2, int n_events = 0, float b_max = 0, float cross_section_inel = 0)
{
    gRandom->SetSeed(105);
    n_events = 0 ? 100 : n_events;
    b_max = 0 ? 20 : b_max; // fm
    cross_section_inel = 0 ? 3 : cross_section_inel; // fm^2

    GlauberOutput output;
    output.g_Npart = TGraph(n_events);
    output.g_Npart.SetName("g_Npart");
    output.g_Npart.SetTitle("Number of participants; b [fm]; N_{part}");
    output.g_Ncoll = TGraph(n_events);
    output.g_Ncoll.SetName("g_Ncoll");
    output.g_Ncoll.SetTitle("Number of collisions; b [fm]; N_{coll}");

    std::cout << "\n----------------------------------------------" << std::endl;
    std::cout << "Running Glauber MC simulation";
    std::cout << "Running Glauber MC simulation";
    std::cout << "\nA1 = " << A1 << "\nA2 = " << A2;
    std::cout << "\nN events = " << n_events;
    std::cout << "\nb_max = " << b_max;
    std::cout << "\ncross_section_inel = " << cross_section_inel;
    std::cout << "\n----------------------------------------------" << std::endl;

    for (int ievent = 0; ievent < n_events; ievent++)
    {
        //std::cout << static_cast<int>(ibin/n_bins * 100) << "%\r" << std::flush;
        std::cout << int(float(ievent) / n_events * 100) << "%\r" << std::flush;
        
        Nucleus n1(A1);
        Nucleus n2(A2);

        float b = gRandom->Uniform(0, b_max);
        float theta = gRandom->Uniform(0, 2 * TMath::Pi());
        Vector2d shift(b * cos(theta), b * sin(theta));
        n2.shift(shift);

        CollisionOutput collision_output = perform_collision(n1, n2, cross_section_inel);

        output.g_Npart.SetPoint(ievent, b, collision_output.Npart);
        output.g_Ncoll.SetPoint(ievent, b, collision_output.Ncoll);
    }

    return output;
}