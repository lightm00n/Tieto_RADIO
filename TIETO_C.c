// include'y plików z funkcjami
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "calculating_cpu.h"
#include "showing_data.h"

//pthread_mutex_t sygnalizacja = PTHREAD_MUTEX_INITIALIZER;
struct imp_datas { 					// struktura globalna, tam beda skladowane dane ze proc/stat.

	 unsigned int cpu_user;
	 unsigned int cpu_nice;
	 unsigned int cpu_system;
	 unsigned int cpu_idle;
	 unsigned int cpu_iowait;
	 unsigned int cpu_irq;
	 unsigned int cpu_softirq;

	 double cpu_usage_result;			// zapis zuzycia cpu

};

void *readData() //funkcja do wczytywania pliku stat/proc
{
	//pthread_mutex_lock(&sygnalizacja);
	FILE *readingdata = fopen("/proc/stat", "r");			//mutexy trzeba dorzucic
	if (readingdata == NULL)
	{
		fprintf(stderr, "Problem with open file \n");
		exit(1);
	}
	struct imp_datas *load_data;
	int number_of_cpu = -1;
	int load_skip = number_of_cpu+1;
	int counter = 0;
	char character;

	while((counter < load_skip) && ((character = fgetc(readingdata)) != EOF))
	{
	       if (character == '\n')
	        counter++;
	}

	char temp_array[255];
	fscanf(readingdata, "%s %d %d %d %d %d %d %d", temp_array, &(load_data->cpu_user), &(load_data->cpu_nice), &(load_data->cpu_system),
			&(load_data->cpu_idle), &(load_data->cpu_iowait), &(load_data->cpu_irq), &(load_data->cpu_softirq));
	//pthread_mutex_unlock(&sygnalizacja);
	fclose(readingdata);
	sleep(2);

}

int main(int argc, char** argv)
{

	pthread_t Reader;		//tutaj tworzy obiekty wątkow
	pthread_t Analyzer;
	pthread_t Printer;

	pthread_create(&Reader, NULL, readData, NULL); //tutaj przydzielamy odpowiednie funkcje
    //pthread_create(&Analyzer, NULL, *calculating_cpu_z, NULL);
	//pthread_create(&Printer, NULL, *printing_data_s, NULL);

	void* test;
	pthread_join(Reader, &test);
	//pthread_join(Analyzer, &test);
	//pthread_join(Printer, &test);

}


