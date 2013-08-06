#include <iostream>
#include "neuronio.h"
#include <time.h>

using namespace std;

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
//        out->SetPesoA(1);
        out->SetPesoA((float)(rand()%20)/10-1);

        out->SetB(mid_2);
//        out->SetPesoB(-2);
        out->SetPesoB((float)(rand()%20)/10-1);
        cout << out->GetResult() << endl;

        return 0;
}
