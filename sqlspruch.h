#include <qapplication.h>
#include <qnetwork.h>
#include <qsqldriver.h>
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include "configuration.h"

using namespace std;

class TSpruch
{
private:
	QString myHost;
	QString myUsername;
	QString myPassword;
	QString mySpruch;
	QString myAutor;
	QString myError;
	QString Zeilenumbruch(QString Text);
	TConfig* myConfig;
	
public:
	TSpruch(QString Host, QString Username, QString Password, TConfig* Config);
	int Verbinden();
	QString GetSpruch();
	QString GetError();
};
