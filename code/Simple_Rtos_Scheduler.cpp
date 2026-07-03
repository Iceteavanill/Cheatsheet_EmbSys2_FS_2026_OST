
#include "Scheduler.hpp"
#include "Dispatcher.hpp"
#include "Task.hpp"
#include "stm32g4xx_hal.h"

void Scheduler::AddTask(ITask* task, uint32_t delay_tick) {
	// The delay is relative to the current tick. The absolute time is needed for the task scheduling.
	uint32_t time = HAL_GetTick() + delay_tick;
	task->SetScheduledTime(time);
	// Push ScheduledTask in queue.
	delayQueue.push_back(task);
}

void Scheduler::RemoveTask(ITask *task){
	auto tasks_match = [task](ITask* t){return task == t;};
	delayQueue.erase(std::remove_if(delayQueue.begin(), delayQueue.end(), tasks_match));
}

void Scheduler::Run() {
    for(auto task : delayQueue){
        if(task->GetScheduledTime() < HAL_GetTick()){
            dispatcher.AddTask(task);
            RemoveTask(task);
        }
    }
	dispatcher.Run(); // Execute dispatched tasks.
}