#ifndef GAMELOG_H
#define GAMELOG_H

#include <string>
#include <vector>

using namespace std;

class Gamelog{
private:
	string startTime, endTime, roundResult, logName;
	int rounds{1}, wins{0}, losses{0}; //Number of rounds played, number of wins and losses for player
	vector<string> results; //Records the result (win/loss) of each round

public:
	Gamelog();
	~Gamelog();

	void startRound();
	void endRound(const int);
};

#endif