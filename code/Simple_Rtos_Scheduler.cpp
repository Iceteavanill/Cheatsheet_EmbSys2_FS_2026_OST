#include "Scheduler.hpp"
#include "Dispatcher.hpp"
#include "Task.hpp"
#include "stm32g4xx_hal.h"

void Scheduler::AddTask(ITask* task, uint32_t delayTck) {
	uint32_t time = HAL_GetTick() + delayTck;// get absolute time (for sheduling) + delay
	task->SetScheduledTime(time);
	delayQueue.push_back(task);// Push ScheduledTask in queue.
}

void Scheduler::RemoveTask(ITask *task){
	auto tasks_match = [task](ITask* t){return task == t;};
	delayQueue.erase(std::remove_if(delayQueue.begin(), delayQueue.end(), tasks_match));
}

void Scheduler::Run() {
    for (size_t i = 0; i < delayQueue.size(); /*Empty :O */) {
        ITask* task = delayQueue[i];
        if (task->GetScheduledTime() < HAL_GetTick()) {
            dispatcher.AddTask(task);
            RemoveTask(task);// erases delayQueue[i], next element shifts into i
        } else {
            i++;// only increment if no task was removed
        }
    }
    dispatcher.Run();// Execute dispatched tasks.
}