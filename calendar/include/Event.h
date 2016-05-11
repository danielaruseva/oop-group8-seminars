#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
#include "Date.h"
class Event
{
public:
	Event(const Date&, int, int,
		std::string title = "<Untitled Event>", std::string place = "", std::string description = "");
	~Event();
	bool isInProgress(const Date&, int) const;
	friend std::ostream& operator<< (std::ostream&, const Event&);
	friend std::istream& operator>> (std::istream&, Event&);
	bool isHappeningAt(std::string, const Date&, int);
	Date getDate();
	int getCenturyE();

protected:
	Date date;
	int startHour;
	int endHour;
	std::string title;
	std::string place;
	std::string description;
	virtual std::ostream& write(std::ostream& out) const;
};

#endif // EVENT_H


