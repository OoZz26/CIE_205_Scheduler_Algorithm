#pragma once
#include"PRIORITY_QUEUE.h"
#include"Process/Process.h"
#include"Processors/Processor.h"


//class Scheduler;
class SJF_processor :public Processor
{
private:
	PriorityQueue SJF_Pqueue;
	Process* run;
	int counter;
	int busy_T = 0;
	int Idle_T = 0;
	int number;
public:
	SJF_processor(int id, Scheduler* s);

	void add_process(Process* p) override;
	void remove_process(int id) override;
	void ScheduleAlgo() override;
	bool IS_IDLE() override;
	int get_counter() const;
	Process* get_run() override;
	void set_run(Process* p) override;
	PriorityQueue  get_ready();

	string Processor_Type() override;
	void PrintReady() override;
	int RDY_Duration() override;
	Process* get_fIrst_proces() override;
	int get_busy_T() override;
	int get_Idle_T() override;
	void increment_busy_time() override;
	int get_number()override;
	void set_number(int n) override;


};

