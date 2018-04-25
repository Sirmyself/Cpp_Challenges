#pragma once
#include <iostream>
#include <string>
#include <map>

char* s_line(void);
void line(void);
void line(std::ostream out);
void changeDefaultLine(char* newLine);
bool askIsUserDone(void);
bool askIsUserDone(char* pMessage, char pYes, char pNo);
void setErrorCode(int pIndex, std::string pMessage);
void logError(int errorCode, std::ostream& pOut);
void logError(int errorCode, std::ostream& pOut, std::string pContinueMessage);
void pause();
void pause(std::string message);