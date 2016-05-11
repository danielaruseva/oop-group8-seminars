#include <iostream>
#include "Date.h"
#include "Event.h"
#include "Calendar.h"
#include "TimeLord.h"

int main() {
	TimeLord a("The Doctor");
	a.newCalendar("10th");
	a.newEvent(Date(2005, 12, 25), 8, 23, "The Christmas Invasion", "London");
	a.newEvent(Date(1599, 4, 7), 15, 23, "The Shakespeare Code", "London");
	a.newEvent(Date(79, 8, 23), 11, 18, "The Fires of Pompeii", "Pompeii");
	a.newCalendar("11th");
	a.newEvent(Date(1890, 3, 8), 10, 21, "Vincent and the Doctor", "Arles");
	a.newEvent(Date(2020, 5, 2), 14, 24, "The Hungry Earth", "Cwmtaff");
	a.newEvent(Date(1938, 7, 14), 14, 17, "Let's Kill Hitler", "Berlin");
	
	std::cout << a << std::endl;

	std::cout << "All events: \n" << a.allArchives() << std::endl;

	(a.canVisit("FMI", Date(2016, 5, 1), 10)) ? (std::cout << "The time lord can visit FMI." << std::endl) : (std::cout << "The time lord can't visit FMI." << std::endl);
	


	system("pause");
	return 0;
}