#include"functii.h"

double convert(short v[], short poz, int locci, double mind, double maxd)
{
	double val = 0;
	int i;
	for (i = poz*locci; i < poz*locci + locci; i++)//cu locci
		if (v[i])
			val = val + pow(2, (poz*locci + locci - i - 1));
	val = mind + val*(maxd - mind) / (pow(2, locci) - 1);
	return val;
}

double rosenbrock(short v[], short n, int locci, double mind, double maxd)
{
	int i;
	double suma = 0, param[30];
	spargeCromozom(param, v, n, locci, mind, maxd);
	for (i = 0; i < n - 1; i++)
	{
		suma = suma + 100 * (param[i + 1] - param[i] * param[i])*(param[i + 1] - param[i] * param[i]) + (1 - param[i])*(1 - param[i]);
	}
	return suma;
}

double rastrigin(short v[], short n, int locci, double mind, double maxd)
{
	int i;
	double suma = 0, param[30];
	spargeCromozom(param, v, n, locci, mind, maxd);
	for (i = 0; i < n; i++)
		suma = suma + (param[i] * param[i] - 10 * cos(2 * PI * param[i]));
	suma = suma + 10 * n;
	return suma;
}

double six_hump_camel(short v[], short n, int locci, double mind, double maxd)
{
	double suma = 0, param[2];
	param[0]=convert(v, 0, locci, mind, maxd);
	param[1] = convert(v, 1, locci, mind+1, maxd+1);
	suma = (4 - 2.1*param[0] * param[0] + param[0] * param[0] * param[0] * param[0] / 3)*param[0] * param[0] + param[0] * param[1] + (-4 + 4 * param[1] * param[1])* param[1] * param[1];
	return suma;
}

double griewangk(short v[], short n, int locci, double mind, double maxd)
{
	int i;
	double prod = 1, suma = 0, param[30];
	spargeCromozom(param, v, n, locci, mind, maxd);
	for (i = 0; i < n; i++)
		suma = suma + (param[i] * param[i] / 4000);
	for (i = 0; i < n; i++)
		prod = prod*(cos(param[i] / sqrt(i)));
	return suma - prod + 1;
}

void spargeCromozom(double param[], short v[], short n, int locci, double mind, double maxd)
{
	int i;
	for (i = 0; i < n; i++)
	{
		param[i] = convert(v, i, locci, mind, maxd);
	}
}

void genereaza_cromozom(short v[], short n, int locci)
{
	for (int i = 0; i < n*locci; i++)
		v[i] = rand() % 2;
}
double optimize_fitness(double value, int max,fct functia)
{
	return (-1)*value + max;
}

void mutatie(short p[],short c[], double Pm ,short n, int locci)
{
	int i,nr=n*locci;
	memcpy(c, p, sizeof(short)*n*locci);
	double rata_pe_locus,rata_stab;
	for (i = 0; i < nr; i++)
		if (((double)(rand() % 99 + 1) / 100) <= Pm)
			if (c[i] == 0)
				c[i] = 1;
			else
				c[i] = 0;
}

void incrucisare(short p1[], short p2[], short c1[],short c2[],short n, int locci, short taieri)
{
	int punct_taiere[10];
	long i,j,aux;
	memcpy(c1, p1, sizeof(short)*n*locci);
	memcpy(c2, p2, sizeof(short)*n*locci);
	
	for (i = 1; i <= taieri; i++)
		punct_taiere[i] = rand() % (n*locci);
	punct_taiere[0] = 0;
	sort(punct_taiere, taieri);
	for (i = 1; i <= taieri; i += 2)
		for (j = punct_taiere[i - 1]; j < punct_taiere[i]; j++)
			if (p1[j] != p2[j])
			{
				aux = c1[j];
				c1[j] = c2[j];
				c2[j] = aux;
			}
}

void genereaza_populatie(short pop[][200], int pop_size, short n, int locci)
{
	int i;
	for (i = 0; i < pop_size; i++)
		genereaza_cromozom(pop[i], n, locci);
}


void sort(int v[], short n)
{
	int ok, i, aux;
	do
	{
		ok = 0;
		for (i = 1; i < n; i++)
			if (v[i - 1]>v[i])
			{
				aux = v[i-1];
				v[i - 1] = v[i];
				v[i] = aux;
				ok = 1;
			}
	} while (ok);
}

void elitism(short list[], double eval[], short pop_size,int elite)
{
	int i, j,k,max_poz[10];
	double max_fitness[10];
	for (i = 0; i < elite; i++)
		max_fitness[i] = -9999;
	for (i = 0; i < pop_size; i++)
		for (j = 0; j < elite;j++)
			if (eval[i] >= max_fitness[j])
			{
				for (k = elite - 1; k >= j + 1; k--)
					max_fitness[k] = max_fitness[k - 1], max_poz[k] = max_poz[k - 1];
				max_fitness[j] = eval[i];
				max_poz[j] = i;
				break;
			}
	for (j = 0; j < elite; j++)
		list[max_poz[j]] = 1;
}

double fit_function(short v[], short n, int locci, double mind, double maxd, fct functia)
{
	double value;
	switch (functia)
	{
	case 0:
	{
		value = rosenbrock(v, n, locci, mind, maxd);
		break;
	}
	case 1:
	{
		value = rastrigin(v, n, locci, mind, maxd);
		break;
	}
	case 2:
	{
		value = griewangk(v, n, locci, mind, maxd);
		break;
	}
	default:
	{
		value = six_hump_camel(v, n, locci, mind, maxd);
	}
	}
	return value;
}



void selectie(short pop[][200], short pop_size, short & actual_pop_size, short n, int locci, double mind, double maxd, fct functia, double Pm, double Pc, int elite)
{
	int i, j,new_pop_size;
	double eval[200], T = 0, p[200], q[201], fitness[200],max=-99999,r;
	double new_pop[200][200];
	for (i = 0; i < actual_pop_size; i++)
	{
		fitness[i] = fit_function(pop[i], n, locci, mind, maxd, functia);
		if (fitness[i] >= max)
			max = fitness[i];
	}
	for (i = 0; i < actual_pop_size; i++)
	{
		eval[i] = optimize_fitness(fitness[i], max,functia);
		T += eval[i];
	}
	for (i = 0; i < actual_pop_size; i++)
		p[i] = eval[i] / T;
	q[0] = 0;
	for (i = 0; i < actual_pop_size; i++)
		q[i + 1] = p[i] + q[i];

	for (i = 0; i < pop_size; i++)
	{
		//srand(time(NULL)+i*n+locci +T );
		r = (double)(rand() % 999 + 1) / 1000;
		for (j = 0; j < actual_pop_size; j++)
			if (r >= q[j] && r < q[j + 1])
			{
				memcpy(new_pop[i], pop[j], sizeof(short)*n*locci);
				break;
			}
	}
	actual_pop_size = pop_size;
	for (i = 0; i < pop_size;i++)
		memcpy(pop[i], new_pop[i], sizeof(short)*n*locci);
	//elitism(list, eval, pop_size, elite);
}



double AG(double Pm, double Pc, int nr_generatii, int pop_size, int elite,short taieri ,short nr_param, double mind, double maxd, fct functia)
{
	short pop[200][200], actual_pop_size;
	int locci, i, new_n=0, a, b, j,an,bn;
	double r, min, fitness;
	locci = ceil(log2((maxd - mind)*pow(10, prec)));
	genereaza_populatie(pop, pop_size, nr_param, locci);
	/*
	for (j = 0; j < pop_size; j++)
	{
		fitness = fit_function(pop[j], nr_param, locci, mind, maxd,functia);
		cout << fitness << " ";
	}
	cout << "\n";*/
	min = 999999999;

	actual_pop_size = pop_size;
	for (i = 0; i < nr_generatii; i++)
	{
		for (j=0; j < pop_size; j++)
		{
			r = (double)(rand() % 99 + 1) / 100;
			if (r<=Pc)
			{
				r = (double)(rand() % 99 + 1) / 100;
				if (r <= Pc)
				{
					a = rand() % actual_pop_size;
					b = rand() % actual_pop_size;

					incrucisare(pop[a], pop[b], pop[actual_pop_size], pop[actual_pop_size], nr_param, locci, taieri);
					actual_pop_size += 2;
				}
			}
			r = (double)(rand() % 99 + 1) / 100;
			if (r<=Pm)
			{
				a = rand() % actual_pop_size;

				mutatie(pop[a], pop[actual_pop_size], Pm, nr_param, locci);
				actual_pop_size++;
			}
		}
		selectie(pop, pop_size, actual_pop_size, nr_param, locci, mind, maxd, functia, Pm, Pc, elite);
		min = 9999999;
		for (j = 0; j < actual_pop_size; j++)
		{
			fitness = fit_function(pop[j], nr_param, locci, mind, maxd,functia);
			//cout << fitness << " ";
			if (fitness < min)
				min = fitness;
		}
		//cout << "Generatia " << i << " cu min " << min << "\n";
	}
	//cout << min << "\n";
	return min;
}

double rmhc(int n, int locci, double mind, double maxd, fct tip)
{
	short max_hilltop[3000], hilltop[3000];
	int i, loccus, max_rep;
	double max_fitness, fitness;

	genereaza_cromozom(max_hilltop, n, locci);
	
	max_fitness = fit_function(hilltop, n, locci, mind, maxd, tip);
	
	max_rep = n*locci * 3;

	for (i = 0; i < max_rep; i++)
	{
		memcpy(hilltop, max_hilltop, (sizeof(short))*n*locci);
		
		loccus = rand() % (n*locci);

		if (hilltop[loccus])
			hilltop[loccus] = 0;
		else
			hilltop[loccus] = 1;

		fitness= fit_function(hilltop, n, locci, mind, maxd, tip);

		if (fitness <= max_fitness)
		{
			memcpy(max_hilltop, hilltop,(sizeof(short))*n*locci);
			max_fitness = fitness;
		}
	}
	return max_fitness;
}

double nahc(int n, int locci, double mind, double maxd, fct tip)
{
	short max_hilltops[3000], max_hilltop[3000], hilltop[3000];
	int i, loccus, max_rep, increase = 1, cromo_len = n*locci;
	double max_fitness, fitness, fitness_candidat;

	genereaza_cromozom(max_hilltop, n, locci);

	max_fitness = fit_function(hilltop, n, locci, mind, maxd, tip);
	
	while (increase)
	{
		increase = 0; // modif aici
					  //memcpy(max_hilltop, max_hilltops, 3000 * (sizeof(int)));
		for (i = 0; i <cromo_len; i++)
		{
			memcpy(hilltop, max_hilltop, (sizeof(short))*n*locci);

			if (hilltop[i])
				hilltop[i] = 0;
			else
				hilltop[i] = 1;

			fitness = fit_function(hilltop, n, locci, mind, maxd, tip);
				

			if (fitness <= max_fitness)
			{
				memcpy(max_hilltop, hilltop, (sizeof(short))*n*locci);
				max_fitness = fitness;
				increase = 1;
			}
			//			cout << fitness<< "\n";
		}
	}
	return max_fitness;

}

double sahc(int n, int locci, double mind, double maxd, fct tip)
{
	short max_hilltops[3000], max_hilltop[3000], hilltop[3000];
	int i, loccus, max_rep, increase = 1, cromo_len = n*locci;
	double max_fitness, fitness, fitness_candidat;
	//max_rep = cromo_len * 3;

	genereaza_cromozom(max_hilltops, n, locci);
	
	max_fitness = fit_function(hilltop, n, locci, mind, maxd, tip);
	
	while (increase)
	{
		increase = 0;
		memcpy(max_hilltop, max_hilltops, (sizeof(short))*n*locci);
		for (i = 0; i <cromo_len; i++)
		{
			memcpy(hilltop, max_hilltop, (sizeof(short))*n*locci);

			if (hilltop[i])
				hilltop[i] = 0;
			else
				hilltop[i] = 1;

			fitness = fit_function(hilltop, n, locci, mind, maxd, tip);
			
			
			if (fitness <= max_fitness)
			{
				memcpy(max_hilltops, hilltop, (sizeof(short))*n*locci);
				max_fitness = fitness;
				increase = 1;
			}
			//	cout << fitness << "\n";
		}
	}
	return max_fitness;
}

double simulated_annealing(int n, int locci, double mind, double maxd, double temperature_step, fct tip)
{
	short max_hilltops[3000], max_hilltop[3000], hilltop[3000];
	int i, cromo_len = n*locci, max_rep, loccus;
	double max_fitness, fitness, fitness_candidat, temperature, probabilitatea, prob_acceptare;
	temperature = TEMP_MAX;
	max_rep = cromo_len * 3;

	genereaza_cromozom(max_hilltop, n, locci);
	
	max_fitness = fit_function(hilltop, n, locci, mind, maxd, tip);

	while (temperature>0.0001)
	{
		for (i = 0; i < max_rep; i++)
		{
			memcpy(hilltop, max_hilltop, (sizeof(short))*n*locci);

			loccus = rand() % (n*locci);

			if (hilltop[loccus])
				hilltop[loccus] = 0;
			else
				hilltop[loccus] = 1;


			fitness = fit_function(hilltop, n, locci, mind, maxd, tip);

			if (fitness <= max_fitness)
			{
				memcpy(max_hilltop, hilltop, (sizeof(short))*n*locci);
				max_fitness = fitness;
			}
			else
			{
				probabilitatea = (1 + rand() % 99) / 100;
				prob_acceptare = pow(euler, max_fitness - fitness) / temperature;
				if (probabilitatea < prob_acceptare)
				{
					memcpy(max_hilltop, hilltop, (sizeof(short))*n*locci);
					max_fitness = fitness;
				}
			}
		}
		temperature = temperature*temperature_step;

	}
	return max_fitness;
}

double metoda_aleasa(int nr_param, int locci, double temperature_step, double mind, double maxd, fct functia, metoda met)
{
	double value;
	switch (met)
	{
		case 0:
			value = rmhc(nr_param, locci, mind, maxd, functia);
			break;
		case 1:
			value = sahc(nr_param, locci, mind, maxd, functia);
			break;
		case 2:
			value = nahc(nr_param, locci, mind, maxd, functia);
			break;
		default:
			value = simulated_annealing(nr_param, locci, mind, maxd, temperature_step, functia);
	}
	return value;
}


double min_t1(int nr_param, int repetitii, double temperature_step ,double mind, double maxd, fct functia, metoda met)
{
	double min=999999,value;
	int locci, i;
	locci = ceil(log2((maxd - mind)*pow(10, prec)));
	for (i = 0; i < repetitii; i++)
	{
		value = metoda_aleasa(nr_param, locci, temperature_step, mind, maxd, functia, met);
		if (value < min)
			min = value;
	}
	return min;
}