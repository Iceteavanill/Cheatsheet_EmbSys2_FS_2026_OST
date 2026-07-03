// Task.hpp
class ITask { // Abstract class!!
public:
	ITask(uint32_t time, uint8_t priority);
	virtual ~ITask() = default;
	virtual void Work() = 0;
// Comparisons operators overloads are excluded
	uint32_t GetScheduledTime() const;
	void SetScheduledTime(uint32_t t);
private:
	uint32_t time;
	uint8_t priority;
};