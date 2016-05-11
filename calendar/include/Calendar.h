#ifndef CALENDAR_H
#define CALENDAR_H

#include <vector>
#include <string>
#include "Date.h"
#include "Event.h"


class Calendar
{
public:
	Calendar(std::string name = "<New Calendar>");
	Calendar(const Calendar& other);
	Calendar& operator=(const Calendar& other);
	~Calendar();
	std::string getName() const;
	void rename(const std::string&);
	void addEvent(const Date&, int, int, std::string = "Event", std::string = "", std::string = "");
	bool isFree(const Date& date, int hour) const;
	friend std::ostream& operator<< (std::ostream&, const Calendar&);
	Calendar& operator+= (const Calendar& other);
	bool hasEventAt(std::string, const Date&, int);
	int numEventsC() const;
	Date earliestVisitedDateC();
	int timeSpentInCenturyC(int century) const;


protected:
private:
	std::string name;
	std::vector<Event*> events;
	void init(const Calendar& other);
	void destroy();
};

#endif // CALENDAR_H


