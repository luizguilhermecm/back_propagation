#ifndef NEURONIO_H
#define NEURONIO_H

#include <iostream>

using namespace std;

class Neuronio {
        public:
                void SetLimiar(float);
                float GetLimiar();

                float GetPesoA();
                void SetPesoA(float);

                float GetPesoB();
                void SetPesoB(float);

                void SetA(Neuronio*);
                Neuronio * GetA();

                void SetB(Neuronio*);
                Neuronio * GetB();

                float GetResult();
        private:
                float pesoA;
                float pesoB;
                float limiar;
                Neuronio * a;
                Neuronio * b;
};

#endif
