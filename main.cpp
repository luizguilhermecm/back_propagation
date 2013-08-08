#include <iostream>
#include "neuronio.h"
#include <time.h>

#include <cstdlib>
#include <cmath>

using namespace std;

double alpha = 0.9;
//double erro = 0;
int esperado = 0;

/* pY é o resultado obtido */
double DeltaK (double pY, double pErro)
{
        double delta_k = pY * (1 - pY) * pErro;
        return delta_k;
}

int main (int argc, char * argv[])
{

        /* ==================================================
        * INSTANCIANDO OS NEURÔNIOS
        *  ==================================================
        */ 

        srand(time(NULL));
        /* cinco neuronios */
        /* neuronio de entrada x1 */
        Neuronio * x1 = new Neuronio();
        //x1->SetPesoA(atof(argv[1]));
        //x1->SetLimiar(0);

        /* neuronio de entrada x2 */
        Neuronio * x2 = new Neuronio();;
        //x2->SetPesoA(atof(argv[2]));
        //x2->SetLimiar(0);

        /* limiar e peso do mid_1 */
        Neuronio * mid_1 = new Neuronio();
        
        mid_1->SetLimiar(0.5);
        mid_1->SetPesoA((double)(rand()%25-12)/10);
        mid_1->SetPesoB((double)(rand()%25-12)/10);
        //mid_1->SetPesoA(1);
        //mid_1->SetPesoB(1);
        mid_1->SetA(x1);
        mid_1->SetB(x2);

        /* limiar e peso do mid_2 */
        Neuronio * mid_2 = new Neuronio();

        mid_2->SetLimiar(1.5);
        mid_2->SetPesoA((double)(rand()%25-12)/10);
        mid_2->SetPesoB((double)(rand()%25-12)/10);
        //mid_2->SetPesoA(1);
        //mid_2->SetPesoB(1);
        mid_2->SetA(x1);
        mid_2->SetB(x2);

        /* neuronio de saida */
        Neuronio * out = new Neuronio();
        out->SetLimiar(0.5);

        out->SetA(mid_1);
        out->SetPesoA((double)(rand()%25-12)/10);
        //out->SetPesoA(1);

        out->SetB(mid_2);
        out->SetPesoB((double)(rand()%25-12)/10);
        //out->SetPesoB(-2);

        cout << "----------------" << endl;
        cout << "Pesos iniciais:" << endl;
        cout << "mid_1_A => " << mid_1->GetPesoA() << endl;
        cout << "mid_1_B => " << mid_1->GetPesoB() << endl;
        cout << "mid_2_A => " << mid_2->GetPesoA() << endl;
        cout << "mid_2_B => " << mid_2->GetPesoB() << endl;
        cout << "out_A   => " << out->GetPesoA() << endl;
        cout << "out_B   => " << out->GetPesoB() << endl;
        cout << "----------------" << endl;


        /* ==================================================
        * TREINAMENTO
        *  ==================================================
        */ 

        //for (int i = 1; i < 1; i++){
        double erro_total;
        do{
                erro_total = 0.0;
                for (int i = 1; i <= 4; i++){
                        //if (i%4 +1 == 1){
                        if (i == 1){
                                x1->SetPesoA(0);
                                x2->SetPesoA(0);
                                esperado = 0;
                        //} else if (i%4 +1 == 2){
                        } else if (i == 2){
                                x1->SetPesoA(0);
                                x2->SetPesoA(1);
                                esperado = 1;
                        //} else if (i%4 +1 == 3){
                        } else if (i == 3){
                                x1->SetPesoA(1);
                                x2->SetPesoA(0);
                                esperado = 1;
                        //} else if (i%4 +1 == 4){
                        } else if (i == 4){
                                x1->SetPesoA(1);
                                x2->SetPesoA(1);
                                //esperado = 1; //XOR
                                esperado = 1; //OR
                        }


                        double y_k = out->GetResult();
                        //cout << y_k << endl;
                        double erro = esperado - y_k;
                        erro_total += abs(erro);
                        out->AtualizaPesosK( DeltaK(y_k, erro), alpha );
                }
        }
        while(erro_total > 0.1);

        cout << "----------------" << endl;
        cout << "Pesos modificados:" << endl;
        cout << "mid_1_A => " << mid_1->GetPesoA() << endl;
        cout << "mid_1_B => " << mid_1->GetPesoB() << endl;
        cout << "mid_2_A => " << mid_2->GetPesoA() << endl;
        cout << "mid_2_B => " << mid_2->GetPesoB() << endl;
        cout << "out_A   => " << out->GetPesoA() << endl;
        cout << "out_B   => " << out->GetPesoB() << endl;
        cout << "----------------" << endl;


        /* ==================================================
        * TESTE DA REDE
        *  ==================================================
        */ 

        do{
                cout << "----------------" << endl;
                int op1, op2;
                cout << "Op1: ";
                cin >> op1;
                cout << "Op2: ";
                cin >> op2;

                x1->SetPesoA(op1);
                x2->SetPesoA(op2);

                double result = out->GetResult();
                bool resp;
                if(result >= out->GetLimiar() ){
                        resp = 1;
                }else{
                        resp = 0;
                }

                cout << endl;
                cout << endl << op1 << " xor " << op2 << " = " << resp << endl;
                cout << "----------------" << endl;
        }while(1);


        return 0;
}
