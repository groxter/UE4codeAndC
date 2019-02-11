
#include "stdafx.h"
#include "Coordinator.h"

Coordinator::Coordinator()
{
	finishTask = 0;
}

Coordinator::~Coordinator()
{

}

bool Coordinator::AddTask(const Task* task) // We use its state machine to know what to do with the task. 
{                                           // Should be managed by the Coordinator or not.
	switch (task->currentState)
	{
	case READY: return true;
        break;

	case WAITING: return false;
		break;

	case FINISH: return false;
		break;

	case OUT: return false;
		break;
	}
}

void Coordinator::TaskComplete(const Task* task) // Print result
{
	cout << "Task: " << task->id << endl;
	cout << "is Balanced?: ";
	(task->isBalancedTree) ? cout << " True " << endl : cout << " False" << endl;
	cout << " " << endl;
}

bool Coordinator::TaskShouldYield(const Task* task) { return task->currentState == WAITING; }


int Coordinator::manageTasks()
{
	int cont = 0;

	while (finishTask < SIZE) // if all Task have been updated and we do not have all the Task finished. Then start over.
	{
			if (AddTask(tasks[cont]))  // We add to the Coordinator management if is Ready
				                       // if is Waiting it means that the Task was waiting to continue its rutine so
					                       // We add it as well in order to accomplish its goal.
	       	{
					tasks[cont]->yield = false;
				    tasks[cont]->update();                
			}
			
			else if (tasks[cont]->currentState == FINISH) // The task has the resoult of the tree then do not update
				                                          // again this Task.
			{
				TaskComplete(tasks[cont]);
				finishTask++;
				tasks[cont]->currentState = OUT;
			}
		if (TaskShouldYield(tasks[cont])) tasks[cont]->yield = true; 
		                                                  
														
		if(tasks[cont]->yield) cout << "The task number : "<< tasks[cont]->id <<" overpass the 0.00002s second asingned to work, switching to another task... " << endl;
		cont++;

		if (cont >= SIZE) 
		{
			cont = 0;
			for (int x = 0; x < SIZE; x++)
			{
				if (tasks[x]->currentState == WAITING)
				{
					tasks[x]->currentState = READY;
					tasks[x]->yield = false;
				}
			}
		}
		std::this_thread::sleep_for(0.5s);
	}

	cout << "System finished." << endl;
	return 0;
}