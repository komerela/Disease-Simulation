#include "population.h"
#include <time.h>
#include <iostream>
#include <cstdlib>
//constructors
diseaseSim::Population::Population()
{
	size = 0;				//Current size of the population.
	head = NULL;			//First node of the linked List structure.
	tail = NULL;			//Last node of the linked List structure.
	startSize = 1000000;	//Size entered by user
	numInfected = 0;		//Number of infected people in the population
	numAlive = startSize;	//Number of elements to be inserted


	//Create a random disease to interact with population.
	int infectionRate = (rand() % 100) + 1;
	int deathRate = (rand() % 100) + 1;
	int incubation = (rand() % 7) + 1;
	std::string name = "" + infectionRate + deathRate;
	diseaseSim::Disease* disease = new  Disease(name,infectionRate,deathRate,incubation);
	this->disease = *&disease;

	//insert elements
	for (int i = 0; i < startSize; i++)
	{
		diseaseSim::Person newPerson = diseaseSim::Person();
		insertFirst(newPerson);
	}
	//Randomly select one infected individual
	selectInfected(1);
}

//User provides parameters to set up the population
diseaseSim::Population::Population(int size, int infected, int minInteractions, int maxInteractions,Disease &disease)
{

	this->size = 0;
	head = NULL;
	tail = NULL;
	startSize = size;

	numAlive = size;
	this->minInteractions = minInteractions;
	this->maxInteractions = maxInteractions;
	this->disease = &disease;

	for (int i = 0; i < startSize; i++)
	{
		diseaseSim::Person newPerson =  diseaseSim::Person();
		insertFirst(newPerson);
	}
 selectInfected(infected);
}

//Delete all Heap memory
diseaseSim::Population::~Population()
{
	while (head != NULL)
		remove(*head);

}

//Are there any remaining people
bool diseaseSim::Population::isAlive()
{
	if (size == 0)
	{
		return false;
	}

	return true;
}

//Return number alive in population
int diseaseSim::Population::getNumAlive()
{
	return numAlive;
}

//Return number dead in population
int diseaseSim::Population::getNumDead()
{
	return numDead;
}

//Return number of elements that the population was intitialized with
int diseaseSim::Population::getStartSize()
{
	return startSize;
}

//Return number of people infected in the population
int diseaseSim::Population::getNumInfected()
{
	return numInfected;
}

/*Select infected Persons in population
* Expensive if numInfected large.
*/
void diseaseSim::Population::selectInfected(int numInfected)
{
	int randomIndex;

	for (int i = 0; i < numInfected; i++)
	{
		//Random Index of linked List
		randomIndex = rand() % this->size;

		//Person to be infected
		diseaseSim::Person* infected = &this->get(randomIndex);

		//Ensure person slected is not already infected
		while (infected->isInfected())
		{
			randomIndex = rand() % this->size;
			infected = &this->get(randomIndex);
		}

		//Infect the individual
		infected->setInfected(true);
		infected->setDaysInfected(1);
		this->numInfected++;
	}
}

/*Each person carries out their daily bussiness, and interacts with others
Represents a day in a population where a disease is spreading*/
void diseaseSim::Population::interact()
{
	diseaseSim::Person* currentPerson = head;

	/*head == tail checks allows for last person to be eliminated if necessary.
	* If infected to long person has a likelyhood to die equal to infectionRate.
	*/
	if (head == tail  && currentPerson->getDaysInfected() >= disease->getIncubationTime())
	{
		//If rand number in range of deathRate percent kill them
		int deathDeterminant = (rand() % 100) + 1;

		if (deathDeterminant <= disease->getDeathRate())
			remove(*currentPerson);

		//Person lives
		else
		{
			currentPerson->setDaysInfected(0);
			currentPerson->setInfected(false);
			numInfected--;
		}
	}

	/*Executes if their is more than one person
	* Each person interacts with random people between min and max interactions.
	*
	*/
	else
	{
		//Take each person see if they die if not interact
		while (currentPerson != tail)
		{
			//check if current person lives or duys
			if (currentPerson->getDaysInfected() >= disease->getIncubationTime())
			{
				int deathDeterminant = (rand() % 100) + 1;

				if (deathDeterminant <= disease->getDeathRate())
				{
					//We move to the next person if the current person died
					currentPerson = &currentPerson->getNext();

					//remove to increase speed of future iterations
					//remove also changes the population stats.
					remove(currentPerson->getPrev());
				}

				else
				{

					currentPerson->setDaysInfected(0);
					currentPerson->setInfected(false);
					numInfected--; //Update population accordingly
				}
			}

			//Select a random number of interactison
			int randomInteractions = rand() % maxInteractions + minInteractions;
			if (currentPerson->isInfected())
				currentPerson->setDaysInfected(currentPerson->getDaysInfected() + 1);

			//interact
			for (int i = 0; i < randomInteractions; i++)
			{
				/* randPerson is the one who interacts with currentPerson
				* distace: how far away the current person went for the interaction
				* Allows for implimentation of neighborhoods later
				*/
				Person * randPerson = currentPerson;
				int distance = (rand() % 100) + 1; //Can be expensive if to large

				for (int j = 0; j <= distance; j++)
					randPerson = &randPerson->getNext();


				if ((currentPerson->isInfected()) && !randPerson->isInfected())
				{
					int infectionDeterminint = (rand() % 100) + 1;

					if (infectionDeterminint <= disease->getInfectionRate())
					{
						randPerson->setInfected(true);
						randPerson->setInteractions(randPerson->getInteractions() + 1);
						numInfected++;
					}
				}

				else if ((!currentPerson->isInfected()) && randPerson->isInfected())
				{

					int infectionDeterminint = (rand() % 100) + 1;
					if (infectionDeterminint <= disease->getInfectionRate())
					{
						currentPerson->setInfected(true);
						currentPerson->setDaysInfected(1);
						numInfected++;
					}
				}


			}

			currentPerson = &currentPerson->getNext();
		}//end while
	}//end else
}//end fucntion

//Accesors, and mutators
int diseaseSim::Population::getMaxInteractions()
{
	return maxInteractions;
}

void diseaseSim::Population::setMaxInteractions(int interactions)
{
	maxInteractions = interactions;
}

int diseaseSim::Population::getMinInteractions()
{
	return minInteractions;
}

void diseaseSim::Population::setMinInteractions(int interactions)
{
	minInteractions = interactions;
}

//output and data methods
std::ostream & diseaseSim::operator<<(std::ostream& os,
	diseaseSim::Population& population)
{

	os << "Number Alive: " << population.numAlive << '\n';
	os << "Number Infected: " << population.numInfected << '\n';
	os << "Number Dead: " << population.numDead << "\n\n";

	return os;
}

std::string diseaseSim::Population::getCdlData()
{
	std::string cdlString;
	cdlString = numAlive + "," + numInfected + ',' + numDead + '\n';
	return cdlString;
}

//linked list implimentation; Persons are the nodes.
diseaseSim::Person* diseaseSim::Population::getHead()
{
	return head;
}
void diseaseSim::Population::setHead(diseaseSim::Person &person)
{
	head = &person;

}
diseaseSim::Person& diseaseSim::Population::get(int i)
{
	diseaseSim::Person* person = head;
	for(int j =0; j<i; j++)
		person = &person->getNext();

	return *person;
}
diseaseSim::Person* diseaseSim::Population::getTail()
{
	return tail;
}
void diseaseSim::Population::setTail(diseaseSim::Person &person)
{
	tail = &person;
}

//NOT USED
void diseaseSim::Population::linkHeadTail()
{
	head->setPrev(tail);
	tail->setNext(head);
}


void diseaseSim::Population::empty()
{
	while (head != NULL)
		delete head;
}

/*removal
*Important unlike vector it is constant time.
*Using a linked list greatly increases speed as program progresses.
*/
void diseaseSim::Population::remove(Person &person)
{
	if (size == 1)
	{
		delete &person;
		head = NULL;
		tail = NULL;
	}

	else if (&person == head)
	{
		//take previouse node and set its next to one past head
		head->getPrev().setNext(&head->getNext());
		head = &(head->getNext());
		head->getPrev().setPrev(NULL);
		head->getPrev().setNext(NULL);
		head->setPrev(tail);
		delete &person;
		this->size--;
	}

	else if (&person == tail)
	{
		tail->getNext().setPrev(&tail->getPrev());
		tail = &(tail->getPrev());
		tail->getNext().prev= NULL;
		tail->getNext().next = NULL;
		tail->setNext(head);
		delete &person;
		this->size--;
	}

	else
	{
		person.getNext().setPrev(&person.getPrev());
		person.getPrev().setNext(&person.getNext());
		delete  &person;
		this->size--;
	}

	//update population
	numInfected--;
	numAlive--;
	numDead++;
}

//Insert at head because order does not matter.
void diseaseSim::Population::insertFirst(Person person)
{
	Person* newPerson  = new Person(person);
	if (size == 0)
	{
		head = newPerson;
		tail = newPerson;
	}

	else if (size == 1)
	{
		tail = newPerson;
		head->setNext(tail);
		tail->setPrev(head);
		head->setPrev(tail);
		tail->setNext(head);
	}

	else
	{

		newPerson->setNext(&head->getNext());
		newPerson->setPrev(head);
		head->getNext().setPrev(newPerson);
		head->setNext(newPerson);
	}
	size++;
}

//Current size of structure
int diseaseSim::Population::getSize()
{
	return this->size;
}
