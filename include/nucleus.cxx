#include "nucleus.hh"
#include <iostream>
#include <cmath>
#include <TF1.h>
#include <TRandom3.h>

Nucleus::Nucleus(const int A, const char * pdf_type, const char * name):
    m_A(A),
    m_name(name)
{
    if (strcmp(pdf_type, "2pF") == 0)
    {
        generate_nucleus_2pF();
    }
    else
    {
        std::cerr << "Unknown pdf type: " << pdf_type << std::endl;
        exit(1);
    }
}

void Nucleus::generate_nucleus_2pF()
{
    m_coordinates.clear();
    m_coordinates.reserve(m_A);

    // 2-parameter Fermi distribution parameters (from experiment - FNAE slides)
    float r0 = 1.2 * pow(m_A, 1./3.) - 0.86 * pow(m_A, -1./3.); // fm
    float d = 0.54; // fm
    float rho0 = 0.16;  // nucleons/fm^3

    TF1 pdf("pdf", "[0] / (1 + exp((x - [1]) / [2]))", 0, 10);
    pdf.SetParameters(rho0, r0, d);

    for (int i = 0; i < m_A; i++)
    {
        float r = 0;
        float theta = 0;
        
        // Generate random r, theta
        r = pdf.GetRandom();
        theta = gRandom->Uniform(0, 2 * TMath::Pi());

        float x = r * cos(theta);
        float y = r * sin(theta);

        m_coordinates.push_back(Vector2d(x, y));
    }
}

/**
 * Shift the coordinates of all nucleons by a given vector
*/
void Nucleus::shift(const Vector2d& shift)
{
    for (int i = 0; i < m_A; i++)
    {
        m_coordinates[i] += shift;
    }
}

TGraph* Nucleus::draw()
{
    TGraph *graph = new TGraph(m_A);
    for (int i = 0; i < m_A; i++)
    {
        graph->SetPoint(i, m_coordinates[i].x(), m_coordinates[i].y());
    }
    return graph;
}
