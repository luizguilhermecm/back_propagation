#include <iostream>
#include "neuronio.h"
#include <time.h>

using namespace std;

float alpha = 0.9;
float erro = 0;
int esperado = 0;

/* pY é o resultado obtido */
float DeltaK (float pY, float perro)
{
        float delta_k = pY * (1 - pY) * perro;
        return delta_k;
}

int main (int argc, char * argv[])
{
        srand(time(NULL));
        /* cinco neuronios */
        /* neuronio de entrada x1 */
        Neuronio * x1 = new Neuronio();
        x1->SetPesoA(atof(argv[1]));
        x1->SetLimiar(0);

        /* neuronio de entrada x2 */
        Neuronio * x2 = new Neuronio();;
        x2->SetPesoA(atof(argv[2]));
        x2->SetLimiar(0);

        /* limiar e peso do mid_1 */
        Neuronio * mid_1 = new Neuronio();
        
        mid_1->SetLimiar(0.5);
        mid_1->SetPesoA((float)(rand()%20)/10-1);
        mid_1->SetPesoB((float)(rand()%20)/10-1);
//        mid_1->SetPesoA(1);
//        mid_1->SetPesoB(1);
        mid_1->SetA(x1);
        mid_1->SetB(x2);

        /* limiar e peso do mid_2 */
        Neuronio * mid_2 = new Neuronio();

        mid_2->SetLimiar(1.5);
        mid_2->SetPesoA((float)(rand()%20)/10-1);
        mid_2->SetPesoB((float)(rand()%20)/10-1);
//        mid_2->SetPesoA(1);
//        mid_2->SetPesoB(1);
        mid_2->SetA(x1);
        mid_2->SetB(x2);

        /* neuronio de saida */
        Neuronio * out = new Neuronio();
        out->SetLimiar(0.5);

        out->SetA(mid_1);
        out->SetPesoA((float)(rand()%20)/10-1);
        out->SetPesoA(1);

        out->SetB(mid_2);
        out->SetPesoB((float)(rand()%20)/10-1);
//        out->SetPesoB(-2);

        cout << "----------------" << endl;
        cout << "Pesos" << endl;
        cout << "mid_1_A => " << mid_1->GetPesoA() << endl;
        cout << "mid_1_B => " << mid_1->GetPesoB() << endl;
        cout << "mid_2_A => " << mid_2->GetPesoA() << endl;
        cout << "mid_2_B => " << mid_2->GetPesoB() << endl;
        cout << "out_A   => " << out->GetPesoA() << endl;
        cout << "out_B   => " << out->GetPesoB() << endl;
        cout << "----------------" << endl;
        for (int i = 1; i < 40; i++){
                if (i%4 +1 == 1){
                        x1->SetPesoA(0);
                        x2->SetPesoA(0);
                        esperado = 0;
                } else if (i%4 +1 == 2){
                        x1->SetPesoA(0);
                        x2->SetPesoA(1);
                        esperado = 1;
                } else if (i%4 +1 == 3){
                        x1->SetPesoA(1);
                        x2->SetPesoA(0);
                        esperado = 1;
                } else if (i%4 +1 == 1){
                        x1->SetPesoA(1);
                        x2->SetPesoA(1);
                        esperado = 0;
                }

                float result = out->GetResult();
                cout << result << endl;
                erro = esperado - result;

                out->AtualizaPesosK(DeltaK(result, erro), alpha);
        }
        return 0;
}
