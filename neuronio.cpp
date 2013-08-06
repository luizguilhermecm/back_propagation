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

void Neuronio::SetDeltaJ(float pY, float pDeltaK)
{
        delta_j = pY * (1 - pY) * this->GetPesoA() * this->GetPesoB() * pDeltaK;
}

float Neuronio::GetDeltaJ()
{
        return delta_j;
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

         //       cout << "soma ponderada: " << this->GetSomaPonderada() << endl;

                float sig = (1 / (1 + exp(this->GetSomaPonderada())));
        //        cout << "sigmoide: " << sig << endl;

                SetSigmoide(sig);

                return GetSigmoide();
        }
        else {
                return this->pesoA; 
        }
}

float Neuronio::AtualizaPesosK(float pDeltaK, float pAlpha)
{
        this->SetPesoA(this->GetPesoA() + pAlpha * this->GetA()->GetSigmoide() * pDeltaK);
        this->SetPesoB(this->GetPesoA() + pAlpha * this->GetA()->GetSigmoide() * pDeltaK);
        cout << "-------------------" << endl;
        cout << "Pesos Atualizados em OUT" << endl;
        cout << "peso Ak => " << GetPesoA() << endl;
        cout << "peso Bk => " << GetPesoB() << endl;

        this->GetA()->AtualizaPesosJ(pAlpha);
        this->GetB()->AtualizaPesosJ(pAlpha);
}

float Neuronio::AtualizaPesosJ(float pAlpha)
{
        this->SetPesoA(this->GetPesoA() + pAlpha * this->GetA()->GetSigmoide() * this->GetDeltaJ());
        this->SetPesoB(this->GetPesoA() + pAlpha * this->GetA()->GetSigmoide() * this->GetDeltaJ());
        cout << "-------------------" << endl;
        cout << "Pesos Atualizados em MID" << endl;
        cout << "peso Ak => " << GetPesoA() << endl;
        cout << "peso Bk => " << GetPesoB() << endl;

}
