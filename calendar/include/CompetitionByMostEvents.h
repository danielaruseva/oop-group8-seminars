#ifndef COMPETITIONBYMOSTEVENTS_H
#define COMPETITIONBYMOSTEVENTS_H

#include "Competition.h"
#include <iostream>
#include <string>


class CompetitionByMostEvents : public Competition
{
public:
	CompetitionByMostEvents(const Date&, std::string = "");;
	TimeLord winner();


};

#endif // COMPETITIONBYMOSTEVENTS_H