#ifndef COMPETITIONBYEARLIESTDATEVISITED_H
#define COMPETITIONBYEARLIESTDATEVISITED_H
#include "Competition.h"
#include <iostream>
#include <string>

class CompetitionByEarliestDateVisited : public Competition
{
public:
	CompetitionByEarliestDateVisited(const Date&, std::string = "");
	TimeLord winner();

};

#endif //COMPETITIONBYEARLIESTDATEVISITED_H