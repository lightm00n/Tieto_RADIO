// include'y plików z funkcjami
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "calculating_cpu.c"
#include "showing_data.c"

struct imp_datas { 					// struktura globalna, tam beda skladowane dane ze proc/stat.

	long cpu_user;
	long cpu_nice;
	long cpu_system;
	long cpu_idle;
	long cpu_iowait;
	long cpu_irq;
	long cpu_softirq;
	long cpu_usage_result;
};

void *readData(void *number_of_cpu) //funkcja do wczytywania pliku stat/proc cmake 2.6
{
	FILE *readingdata = fopen("proc/stat", "r");
	if (readingdata == NULL)
	{
		fprintf(stderr, "Problem with open file");
		exit(1);
	}
	struct imp_datas *load_data;
	int load_skip = number_of_cpu+1;
	int counter = 0;
	    char character;
	    while((counter < load_skip) && ((character = getc(readingdata)) != EOF))
	    {
	        if (character == '\n')
	        	counter++;
	    }
	char temp_array[255];
	fscanf(readingdata, "%d %d %d %d %d %d %d %d %d %d", &(load_data->cpu_user), &(load_data ->cpu_nice), &(load_data->cpu_system),
			&(load_data->cpu_idle), &(load_data->cpu_iowait), &(load_data->cpu_irq), &(load_data->cpu_softirq));
	fclose(readingdata);

}

void main(void)
{
	pthread_t Reader;		//tutaj tworzyy obiekty wątkow
	pthread_t Analyzer;
	pthread_t Printer;

							//tutaj przydzielamy odpowiednie funkcjes


}
