#include <iostream>
#include <fstream>
#include <cmath>

double ECalc(double t)
{
    return sin(t);
}
double ECalcDerivativ(double t)
{
    return cos(t);
}

int main() 
{
    std::ofstream dataFile("data.txt");

    const double C = 0.1;
    double R = 1;
    double tau = R * C;
    double t0 = 0;
    double Q0 = 0;
    double dt = 0.02;
    double I = 0;
    double Q = Q0;
    double ss = 0;
    double E = 3;
    double Uc = 0;
    double Ur = 0;
    double DerivativE = ECalcDerivativ(t0);
    double IntE = 0;
    // Первый этап
    dataFile << "t\tI\tQ\tE\tUr\tUc\tss\tDerE\tIntE\tUc/DerE\tUr/IntE\n";
    for(double k=0;k<=4;k+=dt)
    {
        E = ECalc(k);
        Q += I * dt;
        Uc = Q / C;
        Ur = E - Uc;
        I = Ur / R;
        ss += E * dt;
        DerivativE = ECalcDerivativ(k);
        IntE += cos(k)*(-1);
        dataFile << k << "\t" << I << "\t" << Q << "\t" << E << "\t" << Ur << "\t"<<Uc<< "\t" << Uc << "\t" << DerivativE << "\t" << IntE << "\t" << Uc/DerivativE << "\t" << Ur / IntE << "\n";
    }

    dataFile.close();
        std::ofstream scriptFile("plot_script.gnu"); // создаём скрипт который потом будет использоваться для создания графика
        scriptFile << "set title 'RC circuit versus time'\n";
        scriptFile << "set xlabel 'Time (s)'\n";
        scriptFile << "set ylabel 'E (V), DerE (V), Uc/DerE (V), Uc (V)'\n";
        scriptFile << "plot 'data.txt' using 1:4 with lines title 'E', ";
        scriptFile << "'' using 1:7 with lines title 'DerE',";
        scriptFile << "'' using 1:9 with lines title 'Uc/DerE',";
        scriptFile << "'' using 1:6 with lines title 'Uc'\n";
        scriptFile << "pause mouse close\n";
        scriptFile.close();
             
        std::ofstream scriptFile2("plot_script2.gnu"); // создаём скрипт который потом будет использоваться для создания графика
        scriptFile2 << "set title 'E with DerE and IntE'\n";
        scriptFile2 << "set xlabel 'Time (s)'\n";
        scriptFile2 << "set ylabel 'E (V),Ur/IntE (V), Ur (V), IntE (V)'\n";
        scriptFile2 << "plot 'data.txt' using 1:4 with lines title 'E', ";
        scriptFile2 << "'' using 1:10 with lines title 'Ur/IntE',";
        scriptFile2 << "'' using 1:5 with lines title 'Ur',";
        scriptFile2 << "'' using 1:8 with lines title 'IntE'\n";
        scriptFile2 << "pause mouse close\n";
        scriptFile2.close();

        std::system("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\" plot_script.gnu");
        std::system("\"C:\\Program Files\\gnuplot\\bin\\gnuplot.exe\" plot_script2.gnu");

    return 0;
}