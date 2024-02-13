typedef struct
{
    int day;
    int month;
    int year;
}Date;

typedef enum { } planeType;

typedef struct
{
    planeType type;
    int serialNumber;
}Plane;

#define IATA_LEN 3
typedef struct
{
    char* name;
    char* country;
    char code[IATA_LEN + 1];
}Airport;

typedef struct
{
    Airport** airportArr;
    int count;
}AirportManager;

typedef struct
{
    char srcCode[IATA_LEN + 1];
    char desCode[IATA_LEN + 1];
    Plane thePlane;
    Date theDate;
}Flight;

typedef struct
{
    char* name;
    Flight** flightArr;
    int flightCount;
    Plane* planeArr;
    int planeCount;
}Airline;
