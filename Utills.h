//
// Created by Madalin on 05/16/20.
//
#include <random>
#define FI 4.1
#include <chrono>
#include <algorithm>

std::random_device rd;
std::mt19937 gen(rd());

class Utills{
public:

    static double RosenBrock(std::vector<double> x){
        return (1 - x[0]) * (1 - x[0]) + 100 * (x[1] - x[0] * x[0]) * (x[1] - x[0] * x[0]);
    }
    static double Rastrigin(std::vector<double> x){
        return 20 + (x[0]*x[0] - 10*cos(2*M_PI*x[0])) + (x[1]*x[1] - 10*cos(2*M_PI*x[1]));
    }

    static std::vector<double> random_vect(int dim, double min, double max){
        std::vector<double> rndVec(dim);
        std::uniform_real_distribution<double> dis(min, max);
        for (int i = 0; i < dim; i++)
            rndVec[i] = dis(gen);

        return rndVec;
    }

    static std::vector<double> VecOp(std::vector<double> v1, std::vector<double> v2, double coef){ //v = v1 + coef*v2
        std::vector<double> v;
        for (unsigned int i = 0; i < v1.size(); i++){
            v.push_back(v1[i] + coef*v2[i]);
        }
        return v;
    }

    static std::vector<double> VUniform(std::vector<double> v){
        std::vector<double> out;
        std::uniform_real_distribution<double> dis(0, FI/2);
        for(auto i:v)
            out.push_back(i*dis(gen));
        return out;
    }

    static std::vector<double> VScale(std::vector<double> v, double coef){
        std::vector<double> vec;
        vec.reserve(v.size());
        for(double i : v)
            vec.push_back(coef*i);
        return vec;
    }

};
