#include "bee.h"

#include <algorithm>
#include <iostream>
#include <numeric>

using namespace BeeColony;

Hive::Hive(
    int number_workers,
    int number_inactive,
    int number_scout,
    Coordinate start_pos,
    Coordinate food,
    float buzz,
    int steps
) : bees(bees), steps(steps), step(0u),
    engine(std::random_device()()),
    uniform_dist(0, number_workers + number_inactive + number_scout - 1)
{
    for (int i = 0; i < number_inactive; ++i) {
        bees.emplace_back(Role::Inactive, start_pos, food, buzz);
    }
    for (int i = 0; i < number_workers; ++i) {
        bees.emplace_back(Role::Worker, start_pos, food, buzz);
    }
    for (int i = 0; i < number_workers; ++i) {
        bees.emplace_back(Role::Scout, start_pos, food, buzz);
    }
}

void Bee::waggle(double jiggle) {
    if (get_role() == Role::Inactive) {
        return;
    }
    position.x += jiggle;
}


