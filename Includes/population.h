#ifndef POPULATION_H
#define POPULATION_H
#include "person.h"
#include "disease.h"
#include <string>
#include <time.h>
#include <iostream>

namespace diseaseSim
{

	class Population
	{
		protected:
			int numInfected;
			int numDead;
			int numAlive;
		private:
			int startSize;
			int minInteractions;
			int maxInteractions;
			int size;
			Person* head;
			Person* tail;
			Disease* disease;
			void linkHeadTail();
			void selectInfected(int numInfected);

	public:
		Population();
		Population(int size, int infected, int minInteractions, int maxInteractions, Disease &disease);
		~Population();
		void empty();
		int getMinInteractions();
		void setMinInteractions(int interactions);
		int getMaxInteractions();
		void setMaxInteractions(int interactions);
		bool isAlive();
		int getNumAlive();
		int getSize();
		int getNumDead();
		int getStartSize();
		int getNumInfected();
		Person& get(int i);
		Person* getHead();
		void setHead(Person &person);
		Person* getTail();
		void setTail(Person &person);
		void remove(Person &person);
		void insertFirst(Person person);
		void interact();
		
		Population(Population& population);
		std::string getCdlData();
		void printStats();

	};


}
#endif
