#include <vector>
#include <TMath.h>
#include "vector2d.hh"
#include "nucleus.hh"

typedef struct CollisionOutput 
{
    int Npart;  // number of participants
    int Ncoll;
} CollisionOutput;

/**
 * @brief Perform a collision between two nuclei
 * @param n1 First nucleus
 * @param n2 Second nucleus
 * @param cross_section Cross section of the collision in fm^2
*/
CollisionOutput perform_collision(Nucleus &n1, Nucleus &n2, float cross_section)
{
    CollisionOutput output;
    output.Npart = 0;
    output.Ncoll = 0;

    std::vector<Vector2d> nucleons1 = n1.get_coordinates();
    std::vector<Vector2d> nucleons2 = n2.get_coordinates();

    float interaction_distance = sqrt(cross_section / TMath::Pi());

    for (auto nucleon1 : nucleons1)
    {
        bool collided = false;
        for (auto nucleon2 : nucleons2)
        {
            float distance = (nucleon1 - nucleon2).magnitude();
            if (distance < interaction_distance)
            {
                output.Ncoll++;
                collided = true;
            }
        }
        if (collided) output.Npart++;
    }

    for (auto nucleon2 : nucleons2)
    {
        bool collided = false;
        for (auto nucleon1 : nucleons1)
        {
            float distance = (nucleon1 - nucleon2).magnitude();
            if (distance < interaction_distance)    collided = true;
        }
        if (collided) output.Npart++;
    }

    return output;
}