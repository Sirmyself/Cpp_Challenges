#pragma once
#include <iostream>
static char lineStr[] = "\n\n=================================\n";

char* s_line(void);
void line(void);
void line(std::ostream out);
void changeDefaultLine(char* newLine);
bool askIsUserDone(void);
bool askIsUserDone(char* message, char yes, char no);