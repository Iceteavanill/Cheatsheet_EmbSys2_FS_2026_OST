// Dispatcher.hpp
#pragma once
#include "Task.hpp"
#include <vector>

class Dispatcher {
public:
	void AddTask(ITask* task);
	void Run(); // Run Scheduled Tasks
private:
	std::vector<ITask*> readyQueue;
};