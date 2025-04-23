#include <stdio.h>
#include <math.h>

#define R 8.314 // Universal gas constant (J/mol.K)
#define Cv 0.742   // Specific heat capacity at constant volume (J/gK) 
#define M 28   // Molar Mass of Nitrogen (g) 

int main() {
    double P1 = 100000.0; // Initial pressure (Pa)
    double T1 = 298.0; // Initial temperature (K)
    double m = 2000.0; // Mass of nitrogen (g)
    double N = m / M;
    double V1 = (N * R * T1)/ P1; // Initial volume
    double n_range[5] = {1.0, 1.1, 1.2, 1.3, 1.4}; // Range of polytropic index


    // For polytropic process, PV^n = C

    for (int i = 0; i < 5; i++) 
     {
        double n = n_range[i];
        double C = P1 * pow(V1, n);      // We know, P2/P1=(V1/V2)^n and since V2=V1/2 
        double V2 = V1 / 2.0;                    
        double P2 = P1 * pow(V1/V2, n);

        double W = 0.0;
        if (n != 1.0) {
            W = (C * (pow(V2 , 1.0 - n) - pow(V1 , 1.0 - n))/ (1.0 - n)) ;
        } else {
            W = P1 * V1 * log(V2 / V1);
        }
        
        double T2 = T1 * pow(V1/V2, n - 1.0); 
        double dU = m * Cv * (T2 - T1);
        double Q = W + dU;

        printf("Polytropic Index (n) = %.1f\nBoundary Work (W) = %.2f\nHeat Transfer (Q) = %.2f", n, W, Q);
        printf("\n\n");
    }

    return 0;
}