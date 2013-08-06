#ifndef NEURONIO_H
#define NEURONIO_H

#include <iostream>
#include <math.h>

using namespace std;


class Neuronio {
        public:
                void SetLimiar(float);
                float GetLimiar();

                float GetPesoA();
                void SetPesoA(float);

                float GetPesoB();
                void SetPesoB(float);

                float GetSomaPonderada();
                void SetSomaPonderada(float);

                float GetSigmoide();
                void SetSigmoide(float);

                float GetDeltaJ();
                void SetDeltaJ(float, float);

                void SetA(Neuronio*);
                Neuronio * GetA();

                void SetB(Neuronio*);
                Neuronio * GetB();

                float GetResult();

                float AtualizaPesosK(float, float);
                float AtualizaPesosJ(float);
        private:
                float pesoA;
                float pesoB;

                float soma_ponderada;
                float sigmoide;

                float delta_j;

                float limiar;

                Neuronio * a;
                Neuronio * b;
};

#endif
