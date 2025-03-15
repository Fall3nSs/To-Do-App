#pragma once
#include <iostream>
#include <fstream>

class Task {
public:
	int id;
	std::string description;
};

class DynamicArray {
private:
	Task* tasks;
	int size;
	int capacity;

	void reSize(int newCap) 
	{
		Task* temp = new Task[newCap];
		for (int i = 0; i < size; i++)
		{
			temp[i] = tasks[i];
		}
		delete[] tasks;
		tasks = temp;
		capacity = newCap;
		temp = nullptr;
	}
public:
	DynamicArray(int defaultCap = 2) : size(0), capacity(defaultCap)
	{
		tasks = new Task[defaultCap];
	}
	~DynamicArray()
	{
		delete[] tasks;
	}

	void Add(Task newTask)
	{
		if (size == capacity)
		{
			capacity++;
			reSize(capacity);
		}
		tasks[size] = newTask;
		size++;
	}

	void Delete(int id)
	{
		id--;
		if (id < 0 || id >= size) return;

		if (id != size - 1)
		{
			for (int i = id; i < size - 1; i++)
			{
				tasks[i].description = tasks[i + 1].description;
			}
		}
		else
		{
			tasks[id] = Task();
		}
		size--;
	
	}

	void Display() {
		for (int i = 0; i < size; i++)
		{
			std::cout << tasks[i].id + 1 << " " << tasks[i].description << "\n";
		}
	}

	Task GetTask(int id) const
	{
		return tasks[id];
	}

	int GetSize() const
	{
		return size;
	}

};