#ifndef NEURONIO_H
#define NEURONIO_H

#include <iostream>
#include <math.h>

using namespace std;


class Neuronio {
        public:
                Neuronio();

                void SetLimiar(double);
                double GetLimiar();

                double GetPesoA();
                void SetPesoA(double);

                double GetPesoB();
                void SetPesoB(double);

                double GetSomaPonderada();
                void SetSomaPonderada(double);

                double GetSigmoide();
                void SetSigmoide(double);

                void SetA(Neuronio*);
                Neuronio * GetA();

                void SetB(Neuronio*);
                Neuronio * GetB();

                double GetResult();

                double AtualizaPesosK(double, double);
                double AtualizaPesosJ(double, double);
        private:
                double pesoA;
                double pesoB;

                double soma_ponderada;
                double sigmoide;

                double limiar;

                Neuronio * a;
                Neuronio * b;

                double GetDeltaJ(double, double);
};

#endif
