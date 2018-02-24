#ifndef PERSON_H
#define PERSON_H
namespace diseaseSim
{
	class Person
	{
		private:
			static int numPeople;
			int id;
			bool alive;
			bool infected;
			int daysInfected;
			int timesInfected;
			int interactions;
			Person* next;
			Person* prev;

		public:
			Person();
			Person(const Person &person);
			bool isAlive();
			void setAlive(bool alive);
			bool isInfected();
			void setInfected(bool infected);
			int getDaysInfected();
			void setDaysInfected(int daysInfected);
			int getTimesInfected();
			int getInteractions();
			void setInteractions(int interactions);
			Person& getNext();
			Person& getPrev();
	
	//Avoid user breaking structure
	protected:
			void setNext(Person *person);
			void setPrev(Person *person);
			friend class Population;
			
	};
}

#endif
