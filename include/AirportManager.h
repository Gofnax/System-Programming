#ifndef __AIR_MANAGER__
#define __AIR_MANAGER__

#include "Airport.h"
#include "list.h"

#define AIRPORT_MANAGER_FILE_NAME "airport_authority.txt"

typedef struct
{
	LIST		airportsList;
}AirportManager;

int		initManagerFromUser(AirportManager* pManager);
int		addAirport(AirportManager* pManager);
int		initAirport(Airport* pPort, AirportManager* pManager);
Airport* findAirportByCode(const AirportManager* pManager, const char* code);
int		checkUniqeCode(const char* code, const AirportManager* pManager);
void	printAirports(const AirportManager* pManager);
int		getNumOfAirports(const AirportManager* pManager);
int		saveManagerToFile(const AirportManager* pManager, const char* fileName);
int		initManager(AirportManager* pManager, const char* fileName);
int		getAirportFromFile(Airport* pAirport, FILE* fp);
void	freeManager(AirportManager* pManager);

#endif