#include <iostream>
#include "Date.h"
#include "Event.h"
#include "Calendar.h"
#include "TimeLord.h"
#include "Competition.h"
#include "CompetitionByMostEvents.h"
#include "CompetitionByEarliestDateVisited.h"
#include "CompetitionByMostTimeSpent15.h"     

int main() {
	TimeLord a("The Doctor");
	a.newCalendar("10th");
	a.newEvent(Date(2005, 12, 25), 8, 23, "The Christmas Invasion", "London");
	a.newEvent(Date(1599, 4, 7), 15, 23, "The Shakespeare Code", "London");
	a.newEvent(Date(79, 8, 23), 11, 18, "The Fires of Pompeii", "Pompeii");
	a.newCalendar("11th");
	a.newEvent(Date(1890, 3, 8), 10, 21, "Vincent and the Doctor", "Arles");
	a.newEvent(Date(2020, 5, 2), 14, 24, "The Hungry Earth", "Cwmtaff");
	a.newCalendar("12th");
	a.newEvent(Date(1190, 2, 15), 10, 21, "Robot of Sherwood", "Sherwood Forest");
	a.newEvent(Date(2014, 12, 24), 10, 21, "Last Christmas", "North Pole");
	a.newEvent(Date(5343, 12, 25), 16, 21, "The Husbands of River Song", "Mendorax Dellora");
	TimeLord b("The Master");
	b.newCalendar("Master's Calendar");
	b.newEvent(Date(2008, 6, 5), 8, 16, "The Sound of Drums", "London");
	b.newEvent(Date(2014, 11, 1), 9, 15, "Dark Water", "London");
	b.newEvent(Date(1138, 7, 26), 17, 19, "The Magician's Apprentice", "Essex");
	TimeLord r("River Song");
	r.newCalendar("River's Calendar");
	r.newEvent(Date(5125, 6, 27), 10, 16, "A Good Man Goes to War", "Demon's Run");
	r.newEvent(Date(5343, 12, 25), 16, 21, "The Husbands of River Song", "Mendorax Dellora");
	r.newEvent(Date(1428, 12, 29), 17, 20, "Dinner with Jeanne d'Arc", "Paris");


	CompetitionByMostEvents c(Date(2014, 12, 24), "North Pole");
	c.register_(a);
	c.register_(b);
	c.register_(r);

	std::cout << "The winner of c is: \n" << c.winner() << std::endl; //This competition is won by the Master because The Doctor can't be present

	CompetitionByEarliestDateVisited d(Date(17, 5, 17), "Rome");
	d.register_(a);
	d.register_(b);
	d.register_(r);

	std::cout << "The winner of d is: \n" << d.winner() << std::endl;

	CompetitionByMostTimeSpent15 e(Date(2012, 1, 7), "Paris");
	e.register_(a);
	e.register_(b);
	e.register_(r);

	std::cout << "The winner of e is: \n" << e.winner() << std::endl;

	std::cout << "Competition c: \n" << e << std::endl;

	system("pause");
	return 0;
}