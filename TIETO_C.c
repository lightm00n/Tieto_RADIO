// include'y plików z funkcjami
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

struct imp_datas { 					// struktura globalna, tam skladujemy dane
	int table_of_data[100][100];			// wczytane dane z proc/stat
	int saved_datas[100];			// tablica z obliczonym zuzyciem do pozniejszego wyswietlenia danych
};
//int results[100];
void *readData(void *args) ///funkcja do wczytywania pliku stat/proc cmake 2.6
{
	FILE* our_stat;
	our_stat = fopen("/proc/stat", "r");
	if (our_stat == NULL)
	{
		printf("Problem to read file");
		exit(0);
	}
	struct imp_datas values;
	int temp_array[100];
	int i = 0;

	fscanf(our_stat, "%d," ,&temp_array[i]);

	for (i = 0; i < 100; i++){
		values.table_of_data[i] = temp_array[i];
	}
	//for (i = 0; i < 100; i++){
			printf("%d,", values.table_of_data[i]);
		//}
}

void main(void)
{
	pthread_t thread_Reader;// 1 watek - Reader, on otrzyma funkcje
	pthread_create(&thread_Reader, NULL, &readData, NULL);
	printf("Postał wątek.");
	pthread_join(thread_Reader, NULL);
// 2 watek ktory bedzie liczyl

// itd. wg zadania
}
