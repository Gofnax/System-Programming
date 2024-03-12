#ifndef DATETIME_H_
#define DATETIME_H_

#define LEN 100

typedef struct
{
	unsigned hour;
	unsigned min;
	unsigned sec;
}Time;

typedef struct
{
	unsigned day;
	unsigned month;
	unsigned year;
	Time theTime;
	char sign[LEN];
} Date;

void printDate(const Date* pDate);
void printToFile(const Date* pDate, const char* fileName);
void printToScreen(const Date* pDate);
void createMsgByCondition(const Date* pDate, char* msg);

void createMaxMsg(const Date* pDate, char* msg);
void createRegMsg(const Date* pDate, char* msg);
void createMsg(const Date* pDate, char* msg);
void createTimeMsg(const Time* pTime, char* msg);

//#define TO_FILE
#define ENGLISH
//#define FRENCH


//#define MSG_MAX
#define MSG_REG






#endif /* DATETIME_H_ */
