#include "main.h"
#include <string>
#include <iostream>
#include <fstream>

void RemoveFromFile(const std::string& fileName, int id) 
{
	id--;
	DynamicArray tempArr;
	Task tempTask;
	std::string tempLine;
	std::ifstream inFile(fileName);
	int currentId = 0;

	while (std::getline(inFile, tempLine))
	{
		if (currentId != id)
		{
			tempTask.description = tempLine;
			tempArr.Add(tempTask);
		}
		currentId++;
	}
	inFile.close();

	std::ofstream outFile(fileName, std::ios::trunc);
	
	for (int i = 0; i < tempArr.GetSize();i++) {
		outFile << tempArr.GetTask(i).description << "\n";
	}

	outFile.close();
}

int main()
{
	DynamicArray arr;
	Task tempTask;
	int counter = 0;
	std::string tempDescription;
	int id = 0;
	char choice;

	std::ifstream readFile("tasks.txt");
	

	if (!readFile)
	{
		std::cout << "Dosya okunamadı!";
		return -1;
	}

	while (std::getline(readFile, tempDescription))
	{
		tempTask.id = counter++;
		tempTask.description = tempDescription;
		arr.Add(tempTask);
	}
	
	std::cout << "----------- TO - DO -----------\n";
	while (true)
	{
		std::ofstream writeFile("tasks.txt", std::ios::app);
		std::cout << "[a]dd task\n[d]isplay tasks\n[c]omplete a task\n[q]uit\nEnter your operation : ";
		std::cin >> choice;
		switch (choice)
		{
		case 'a':
			std::cout << "Enter task description: ";
			std::cin.ignore();
			std::getline(std::cin, tempDescription);
			tempTask.id = counter++;
			tempTask.description = tempDescription;
			arr.Add(tempTask);
			writeFile << tempDescription << "\n";
			writeFile.close();
			std::cout << "\n";
			break;
		case 'd':
			arr.Display();
			std::cout << "\n";
			break;
		case 'c':
			std::cout << "Enter task id to complete: ";
			std::cin >> id;
			arr.Delete(id);
			RemoveFromFile("tasks.txt", id);
			counter--;
			std::cout << "\n";
			break;
		case 'q':
			return 0;
			break;
		default:
			std::cout << "Invalid operation\n\n";
			break;
		}
	}

}
