#include<iostream>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<ctime>

using namespace std;

#define prec 2
#define PI 3.14159
#define euler 2.718
#define TEMP_MAX 900
#define min_rosen -2.018
#define max_rosen 2.018
#define min_rast -5.12
#define max_rast 5.12
#define min_grie -600
#define max_grie 600
#define min_six -3
#define max_six 3

enum fct { rosen, rast, grie, six };

enum metoda {rmhc_m,sahc_m,nahc_m,simA_m};

double convert(short v[], short poz, int locci, double mind, double maxd);

double rosenbrock(short v[], short n, int locci, double mind, double maxd);

double rastrigin(short v[], short n, int locci, double mind, double maxd);

double griewangk(short v[], short n, int locci, double mind, double maxd);

double six_hump_camel(short v[], short n, int locci, double mind, double maxd);

void spargeCromozom(double param[], short v[], short n, int locci, double mind, double maxd);

void genereaza_cromozom(short v[], short n, int locci);

double optimize_fitness(double value, int max ,fct functia);

void mutatie(short p[], short c[], double Pm, short n, int locci);

void incrucisare(short p1[], short p2[], short c1[], short c2[], short n, int locci, short taieri);

double AG(double Pm, double Pc, int nr_generatii,int pop_size, int elite, short taieri, short nr_param, double mind, double maxd, fct functia);

void genereaza_populatie(short pop[][200], int pop_size, short n, int locci);

void sort(int v[], short n);

void elitism(short list[],double eval[], short pop_size,int elite);

double fit_function(short v[], short n, int locci, double mind, double maxd, fct functia);

double min_t1(int nr_param, int repetitii, double temperature_step, double mind, double maxd, fct functia, metoda met);

double simulated_annealing(int n, int locci, double mind, double maxd, double temperature_step, fct tip);

double nahc(int n, int locci, double mind, double maxd, fct tip);

double rmhc(int n, int locci, double mind, double maxd, fct tip);

double sahc(int n, int locci, double mind, double maxd, fct tip);

void selectie(short pop[][200], short pop_size, short & actual_pop_size ,short n, int locci, double mind, double maxd, fct functia, double Pm, double Pc, int elite);

double metoda_aleasa(int nr_param, int locci, double temperature_step, double mind, double maxd, fct functia, metoda met);
