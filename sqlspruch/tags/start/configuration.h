#include "unistd.h"
#include <cstdlib>
#include <qstring.h>
#include <iostream>

using namespace std;

class TConfig
{
private:
	QString myHost;
	QString myUsername;
	QString myPassword;
	QString myError;
	unsigned int myZeilenumbruch;

public:
	TConfig(int argc, char **argv);
	QString GetUsername();
	QString GetPassword();
	QString GetHost();
	QString GetError();
	unsigned int GetZeilenumbruch();
};
