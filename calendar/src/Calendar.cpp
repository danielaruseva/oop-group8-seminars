#include "Calendar.h"

void Calendar::init(const Calendar& other) {
	name = other.name;
	events = other.events;
	for (unsigned int i = 0; i < events.size(); i++) {
		// copy the events so that they are not shared
		// between the calendars
		events[i] = new Event(*events[i]);
	}
}

void Calendar::destroy() {
	// delete all events that we have created using new
	for (unsigned int i = 0; i < events.size(); i++) {
		delete events[i];
	}
}

Calendar::Calendar(std::string name) : name(name) {
	// empty implementation
	// events is automatically initialized
	// using its default constructor
}

Calendar::Calendar(const Calendar& other) {
	init(other);
}

Calendar::~Calendar()
{
	destroy();
}

Calendar& Calendar::operator=(const Calendar& other) {
	if (this != &other) {
		destroy();
		init(other);
	}
	return *this;
}

std::string Calendar::getName() const {
	return name;
}

void Calendar::rename(const std::string& newName) {
	name = newName;
}

bool Calendar::isFree(const Date& date, int hour) const {
	for (unsigned int i = 0; i < events.size(); i++) {
		if (events[i]->isInProgress(date, hour)) {
			return false;
		}
	}
	return true;
}

void Calendar::addEvent(const Date& date, int start, int end, std::string title, std::string place, std::string descr) {
	Event* e = new Event(date, start, end, title, place, descr);
	events.push_back(e);
}

/*
bool cancelEvent(const Event& event);
bool cancelEvents(const Date& date);
*/

std::ostream& operator<< (std::ostream& out, const Calendar& cal) {
	out << "Calendar: " << cal.name << std::endl;
	out << "Events:" << std::endl;
	for (unsigned i = 0; i < cal.events.size(); i++) {
		out << *cal.events[i];//<< std::endl;
	}
	return out;
}

Calendar& Calendar::operator+= (const Calendar& other) {
	name += other.name;
	for (unsigned int i = 0; i < other.events.size(); i++) {
		Event* e = new Event(*other.events[i]);
		events.push_back(e);
	}
	return *this;
}

bool Calendar::hasEventAt(std::string where, const Date& when, int hour) {
	for (unsigned int i = 0; i < events.size(); i++) {
		if (events[i]->isHappeningAt(where, when, hour)) {
			return true;
		}
	}
	return false;
}

int Calendar::numEventsC() const {
	return events.size();
}

Date Calendar::earliestVisitedDateC() {
	Date temp((2147483647, 12, 31));
	int idx = 0;
	for (int i = 0; i < numEventsC(); i++) {
		if (temp > events[i]->getDate()) {
			temp = events[i]->getDate();
			idx = i;
		}
	}
	return events[idx]->getDate();
}

int Calendar::timeSpentInCenturyC(int century) const {
	int count = 0;
	for (int i = 0; i < numEventsC(); i++) {
		if (events[i]->getCenturyE() == century) {
			count++;
		}
	}
	return count;
}






