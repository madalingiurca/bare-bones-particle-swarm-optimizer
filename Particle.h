//
// Created by Madalin on 05/16/20.
//
#ifndef UTILLS
#define UTILLS
#include "Utills.h"
#endif
#include <vector>
#include <random>
#include <ostream>


class Particle{

public:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> bestPos;

    Particle(){
        bestPos = std::vector<double>(2);
    }

    Particle(int dim, double min, double max){
        position = Utills::random_vect(dim, min, max);
        velocity = std::vector<double>(dim);
        bestPos = position;
    }

    void update_pos(double f(std::vector<double>)){
        position = Utills::VecOp(position,velocity, 1); //next_pos = pos + velocity
        if(f(bestPos) > f(position))
            bestPos = position;
    }

    friend std::ostream &operator<<(std::ostream &os, const Particle &particle) {
        os << "position: " << particle.position[0] << " " << particle.position[1];
        return os;
    }

};
