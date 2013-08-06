#include "neuronio.h"

void Neuronio::SetLimiar(float pLimiar)
{
        limiar = pLimiar;
}

float Neuronio::GetLimiar()
{
        return limiar;
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
                cout << "soma ponderada: " << result << endl;
                if (result >= this->GetLimiar())
                        return 1;
                else 
                        return 0;
        }
        else {
                return this->pesoA; 
        }



}
