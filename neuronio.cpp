#include "neuronio.h"
#include <iostream>

using namespace std;

Neuronio::Neuronio(){
    a = NULL;
    b = NULL;
}

void Neuronio::SetLimiar(double pLimiar)
{
        limiar = pLimiar;
}

double Neuronio::GetLimiar()
{
        return limiar;
}


double Neuronio::GetDeltaJ(double pY, double pDeltaK)
{
        //delta_j = pY * (1 - pY) * this->GetPesoA() * this->GetPesoB() * pDeltaK;
        return (pY * (1 - pY) * pDeltaK * ( this->GetPesoA() + this->GetPesoB() )  );
}

void Neuronio::SetSomaPonderada(double pSomaPonderada)
{
        soma_ponderada = pSomaPonderada;
}

double Neuronio::GetSomaPonderada()
{
        return soma_ponderada;
}

void Neuronio::SetSigmoide(double pSigmoide)
{
        sigmoide = pSigmoide;
}

double Neuronio::GetSigmoide()
{
        return sigmoide;
}

void Neuronio::SetPesoA(double pPesoA)
{
        pesoA = pPesoA;
}

double Neuronio::GetPesoA()
{
        return pesoA;
}

void Neuronio::SetPesoB(double pPesoB)
{
        pesoB = pPesoB;
}

double Neuronio::GetPesoB()
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

double Neuronio::GetResult()
{
        if (this->a){
                double result = this->GetA()->GetResult() * this->GetPesoA() 
                        + this->GetB()->GetResult() * this->GetPesoB();

                this->SetSomaPonderada(result - limiar);
                //cout << "soma ponderada: " << this->GetSomaPonderada() << endl;

                double sig = (1 / (1 + exp( (-1)*soma_ponderada) ));
                //cout << "sigmoide: " << sig << endl;

                SetSigmoide(sig);

                return sigmoide;
                /**
                if(result >= limiar){
                    return 1;
                } else{
                    return 0;
                }
                /**/
        }
        else {
                return this->pesoA; 
        }
}

double Neuronio::AtualizaPesosK(double pDeltaK, double pAlpha)
{
        this->SetPesoA(this->GetPesoA() + pAlpha * this->GetA()->GetSigmoide() * pDeltaK);
        this->SetPesoB(this->GetPesoB() + pAlpha * this->GetB()->GetSigmoide() * pDeltaK);
        /**
        cout << "-------------------" << endl;
        cout << "Pesos Atualizados em OUT" << endl;
        cout << "peso Ak => " << GetPesoA() << endl;
        cout << "peso Bk => " << GetPesoB() << endl;
        /**/

        this->GetA()->AtualizaPesosJ(pDeltaK, pAlpha);
        this->GetB()->AtualizaPesosJ(pDeltaK, pAlpha);
}

double Neuronio::AtualizaPesosJ(double pDeltaK, double pAlpha)
{
        double pDeltaJ = this->GetDeltaJ( sigmoide, pDeltaK );

        this->SetPesoA(this->GetPesoA() + pAlpha * a->GetSigmoide() * pDeltaJ);
        this->SetPesoB(this->GetPesoB() + pAlpha * b->GetSigmoide() * pDeltaJ);

        //this->SetPesoA(this->GetPesoA() + pAlpha * sigmoide * pDeltaJ);
        //this->SetPesoB(this->GetPesoB() + pAlpha * sigmoide * pDeltaJ);


        /**
        cout << "-------------------" << endl;
        cout << "Pesos Atualizados em MID" << endl;
        cout << "peso Ak => " << GetPesoA() << endl;
        cout << "peso Bk => " << GetPesoB() << endl;
        /**/

}
