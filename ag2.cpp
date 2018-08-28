#include"functii.h"


int main()
{
	
	int i,min_t,nr_param,repetitii;
	double fit,temperature_step=0.99,mind,maxd;
	fct functia;

	ofstream fout("rezultate.txt");

	nr_param=5;
	repetitii=100;
	temperature_step = 0.99;
	mind=min_rosen;
	maxd=max_rosen;
	functia=rosen;
	
	fit = AG(0.06, 0.1, repetitii, 30, 5, 4, nr_param, mind, maxd, functia);
	fout <<fit<<"\n";
	fit = min_t1(nr_param,repetitii,temperature_step, mind, maxd, functia,rmhc_m);
	fout <<fit << "\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, sahc_m);
	fout <<fit << "\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, nahc_m);
	fout <<fit << "\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, simA_m);
	fout <<fit << "\n";
	fout << "\n";

	nr_param = 15;
	
	fit = AG(0.06, 0.1, repetitii, 30, 5, 4, nr_param, mind, maxd, functia);
	fout << fit << "\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, rmhc_m);
	fout << fit << "\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, sahc_m);
	fout << fit << "\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, nahc_m);
	fout << fit << "\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, simA_m);
	fout << fit << "\n";
	fout << "\n";
	
	nr_param = 30;
	
	fit = AG(0.06, 0.1, repetitii, 30, 5, 4, nr_param, mind, maxd, functia);
	fout << fit << "\n";
	cout << "done.\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, rmhc_m);
	fout << fit << "\n";
	cout << "done.\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, sahc_m);
	fout << fit << "\n";
	cout << "done.\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, nahc_m);
	fout << fit << "\n";
	cout << "done.\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, simA_m);
	fout << fit << "\n";
	fout << "\n\n\n";

	nr_param = 5;
	repetitii = 100;
	temperature_step = 0.99;
	mind = min_rast;
	maxd = max_rast;
	functia = rast;
	
	fit = AG(0.06, 0.1, repetitii, 30, 5, 4, nr_param, mind, maxd, functia);
	fout << fit << "\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, rmhc_m);
	fout << fit << "\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, sahc_m);
	fout << fit << "\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, nahc_m);
	fout << fit << "\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, simA_m);
	fout <<fit << "\n";
	fout << "\n";

	nr_param = 15;

	fit = AG(0.06, 0.1, repetitii, 30, 5, 4, nr_param, mind, maxd, functia);
	fout << fit << "\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, rmhc_m);
	fout << fit << "\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, sahc_m);
	fout << fit << "\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, nahc_m);
	fout << fit << "\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, simA_m);
	fout << fit << "\n";
	fout << "\n";
	
	nr_param = 30;

	fit = AG(0.06, 0.1, repetitii, 30, 5, 4, nr_param, mind, maxd, functia);
	fout << fit << "\n";
	cout << "done.\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, rmhc_m);
	fout << fit << "\n";
	cout << "done.\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, sahc_m);
	fout << fit << "\n";
	cout << "done.\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, nahc_m);
	fout << fit << "\n";
	cout << "done.\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, simA_m);
	fout << fit << "\n";
	fout << "\n\n\n";

	nr_param = 5;
	repetitii = 100;
	temperature_step = 0.99;
	mind = min_six;
	maxd = max_six;
	functia = six;
	
	fit = AG(0.06, 0.1, repetitii, 30, 5, 4, nr_param, mind, maxd, functia);
	fout << fit << "\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, rmhc_m);
	fout << fit << "\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, sahc_m);
	fout << fit << "\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, nahc_m);
	fout << fit << "\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, simA_m);
	fout <<fit << "\n";
	fout << "\n";

	nr_param = 15;

	fit = AG(0.06, 0.1, repetitii, 30, 5, 4, nr_param, mind, maxd, functia);
	fout << fit << "\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, rmhc_m);
	fout << fit << "\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, sahc_m);
	fout << fit << "\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, nahc_m);
	fout << fit << "\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, simA_m);
	fout << fit << "\n";
	fout << "\n";
	
	nr_param = 30;

	fit = AG(0.06, 0.1, repetitii, 30, 5, 4, nr_param, mind, maxd, functia);
	fout << fit << "\n";
	cout << "done.\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, rmhc_m);
	fout << fit << "\n";
	cout << "done.\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, sahc_m);
	fout << fit << "\n";
	cout << "done.\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, nahc_m);
	fout << fit << "\n";
	cout << "done.\n";
	fit = min_t1(nr_param, repetitii, temperature_step, mind, maxd, functia, simA_m);
	fout << fit << "\n";
	fout << "\n";


	system("pause");
	return 0;
}