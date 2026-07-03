#pragma once
#include "Task.hpp"
#include "Dispatcher.hpp"

class Scheduler {
public:
	void AddTask(ITask *task, uint32_t delayTck);
	void RemoveTask(ITask *task);
	void Run();
private:
	std::vector<ITask*> delayQueue;
	Dispatcher dispatcher;
};
