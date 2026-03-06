#include "Dispatcher.hpp"

void Dispatcher::AddTask(ITask* task) {
	readyQueue.push_back(task);
}
void Dispatcher::Run() {
	// Execute all tasks in order
	for (auto task : readyQueue) {
		task->Work();
	}
	readyQueue.clear(); // clear queue
}
