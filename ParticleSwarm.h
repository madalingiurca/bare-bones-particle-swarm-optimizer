//
// Created by Madalin on 05/17/20.
//
#include <fstream>
#include "Particle.h"
#ifndef UTILLS
#define UTILLS
#include "Utills.h"
#endif
class ParticleSwarm{
public:
    int particleNo;
    int dims;
    std::vector<Particle> Particles;
    std::vector<double> bestGroupPosition;
    int maxGeneration;
    std::string logfile;

    ParticleSwarm(int particleNo, int maxGens, int dims, double dMin, double dMax, double f(std::vector<double>)) :
    dims(dims), particleNo(particleNo), maxGeneration(maxGens){
        Particles = std::vector<Particle>(particleNo);
        bestGroupPosition = Particle(dims,dMin, dMax).position;
        logfile = "";
        for(int i = 0; i < particleNo; i++){
            Particles[i] = Particle(dims,dMin, dMax);
            if(f(Particles[i].position) < f(bestGroupPosition))
                bestGroupPosition = Particles[i].position;
        }
    }

    void setLogfile(std::string filename){
        logfile = filename;
    }

    void optimize(double f(std::vector<double>)){

        std::vector<double> congComp; //componenta data de minimul individual gasit(cognitiva)
        std::vector<double> socialComp; //componenta data de legatura intre particule (sociala)
        int generation = 0;
        std::ofstream ostream;
        ostream.open(logfile);
        while(generation++ < maxGeneration){
            ostream << generation << "," << f(bestGroupPosition);
            for(auto particle:Particles){
                congComp = Utills::VecOp(particle.bestPos,particle.position,-1); //pi - xi
                socialComp = Utills::VecOp(bestGroupPosition, particle.position, -1);
                congComp = Utills::VUniform(congComp);
                socialComp = Utills::VUniform(socialComp);
                //v = v + U(0,fi/2)*(pi-xi)
                particle.velocity = Utills::VecOp(particle.velocity, congComp,1);
                //v = v + U(0,fi/2)*(pi-xi) + U(0,fi/2)*(pg - xi)
                particle.velocity = Utills::VecOp(particle.velocity, socialComp, 1);
                //v = X(v + U(0,fi/2)*(pi-xi) + U(0,fi/2)*(pg - xi))
                particle.velocity = Utills::VScale(particle.velocity,0.729);
                particle.update_pos(f);
                if(f(particle.position) < f(bestGroupPosition))
                    bestGroupPosition = particle.position;
            }
            ostream << '\n';
        }

    }


};
