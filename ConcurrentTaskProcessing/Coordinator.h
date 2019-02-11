

#include<iostream>
#include "Task.h"

#ifndef COORDINATOR_H
#define COORDINATOR_H
using namespace std;

const int SIZE = 6;

class Coordinator
{

public:

	Task* tasks[SIZE];
	Coordinator();
	~Coordinator();

	// Adds a task to be managed by the Coordinator;
	// Returns true if successful, false otherwise
	bool AddTask(const Task* task);

	// Should be called by a managed Task when it is complete
	void TaskComplete(const Task * task);

	// Must be called regularly by a Task during Task::Update;
	// Returns true if Task::Update should return immediately.
	// Returns false if okay to keep running
	bool TaskShouldYield(const Task * task);

	
	// Coordinator Management
	int manageTasks();
	

private:

	int finishTask;
};
#endif