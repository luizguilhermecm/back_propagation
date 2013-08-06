#include "neuronio.h"
#include <iostream>

using namespace std;

void Neuronio::SetLimiar(float pLimiar)
{
        limiar = pLimiar;
}

float Neuronio::GetLimiar()
{
        return limiar;
}

void Neuronio::SetSomaPonderada(float pSomaPonderada)
{
        soma_ponderada = pSomaPonderada;
}

float Neuronio::GetSomaPonderada()
{
        return soma_ponderada;
}

void Neuronio::SetSigmoide(float pSigmoide)
{
        sigmoide = pSigmoide;
}

float Neuronio::GetSigmoide()
{
        return sigmoide;
}

void Neuronio::SetPesoA(float pPesoA)
{
        pesoA = pPesoA;
}

float Neuronio::GetPesoA()
{
        return pesoA;
}

void Neuronio::SetPesoB(float pPesoB)
{
        pesoB = pPesoB;
}

float Neuronio::GetPesoB()
{
        return pesoB;
}


void Neuronio::SetA(Neuronio * pA)
{
        a = pA;
}

Neuronio * Neuronio::GetA()
{
        return a;
}

void Neuronio::SetB(Neuronio * pB)
{
        b = pB;
}

Neuronio * Neuronio::GetB()
{
        return b;
}

float Neuronio::GetResult()
{
        if (this->a){
                float result = this->GetA()->GetResult() * this->GetPesoA() 
                        + this->GetB()->GetResult() * this->GetPesoB();
                this->SetSomaPonderada(result - this->GetLimiar());

                cout << "soma ponderada: " << this->GetSomaPonderada() << endl;

                float sig = (1 / (1 + exp(this->GetSomaPonderada())));
                cout << "sigmoide: " << sig << endl;
                SetSigmoide(sig);

                if (result >= this->GetLimiar())
                        return 1;
                else 
                        return 0;
        }
        else {
                return this->pesoA; 
        }



}
