#include "TIETO_C.c"

double *calculating_cpu()
{
	struct imp_datas *prev_for_idle, *now_for_idle, *result;

	int prev_idle = (prev_for_idle->cpu_idle) + (now_for_idle->cpu_iowait);
	int curr_idle = (now_for_idle->cpu_idle) + (now_for_idle->cpu_iowait);

	int name_idle_prev = (prev_for_idle->cpu_user) + (prev_for_idle->cpu_nice) + (prev_for_idle->cpu_system) + (prev_for_idle->cpu_irq) + (prev_for_idle->cpu_softirq);
	int name_idle_curr = (now_for_idle->cpu_user) + (now_for_idle->cpu_nice) + (now_for_idle->cpu_system) + (now_for_idle->cpu_irq) + (now_for_idle->cpu_softirq);

	int total_cpu_prev = prev_idle + name_idle_prev;
	int total_cpu_curr = curr_idle + name_idle_curr;

	double total_cpud = (double)total_cpu_curr - (double)total_cpu_prev;
	double total_idled = (double)curr_idle - (double)prev_idle;

	double usage = (1000 * (total_cpud - total_idled) / total_cpud + 1) / 10 ;

	fscanf(usage, "%d", &(result->cpu_usage_result) );

}
