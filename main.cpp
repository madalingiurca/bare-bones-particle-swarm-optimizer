#include <iostream>
#include "ParticleSwarm.h"
using namespace std;
int main() {

    ParticleSwarm PSO1(10, 2000, 2, -10, 10, Utills::RosenBrock);
    PSO1.setLogfile("log1.csv");
    PSO1.optimize(Utills::RosenBrock);
    cout << "Rosenbrock Optimum Location\n";
    cout << PSO1.bestGroupPosition[0] << "  " << PSO1.bestGroupPosition[1] << endl;

    ParticleSwarm PSO2(10, 2000, 2, -10, 10, Utills::Rastrigin);
    PSO2.setLogfile("log2.csv");
    PSO2.optimize(Utills::Rastrigin);
    cout << "Rastrigin Optimum Location\n";
    cout << PSO2.bestGroupPosition[0] << "  " << PSO2.bestGroupPosition[1] << endl;




    return 0;

}