#pragma once

#include <vector>
#include <TGraph.h>
#include "vector2d.hh"

class Nucleus 
{
    public:

        Nucleus(const int A, const char * pdf_type = "2pF", const char * name = "");
        ~Nucleus() {};

        int get_A() { return m_A; }
        std::string get_name() { return m_name; }
        std::vector<Vector2d> get_coordinates() { return m_coordinates; }

        void shift(const Vector2d& shift);
        TGraph* draw();

    protected:
        void generate_nucleus_2pF();

    private:
        int m_A;
        std::string m_name;
        std::vector<Vector2d> m_coordinates;  // x and y positions of nucleons

};
