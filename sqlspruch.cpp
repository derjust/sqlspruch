#include "sqlspruch.h"
#include <iostream>
using namespace std;


TSpruch::TSpruch(QString Host,QString Username,QString Password, TConfig* Config)
{
	myHost = Host;
	myUsername = Username;
	myPassword = Password;
	myConfig = Config;
}

int TSpruch::Verbinden()
{
QString SQLQuery;
int ID;
SQLQuery = "";
qInitNetworkProtocols();
QSqlDatabase *SpruchDB = QSqlDatabase::addDatabase( "QMYSQL3" );

srand(static_cast<unsigned>(time(0)));
ID = (rand() % 3340);

if ( ! SpruchDB ) 
{
	myError = "Keine MySQL-Treiber gefunden";
	return -1;
}
else
{
	SpruchDB->setHostName( myHost );
	SpruchDB->setDatabaseName( "sprueche" );
	SpruchDB->setUserName( myUsername  );
	SpruchDB->setPassword( myPassword );
	if( SpruchDB->open() ) 
	{
		SQLQuery = "SELECT Spruch  FROM `sprueche` WHERE ID='";
		SQLQuery.append(QString::number(ID));
		SQLQuery.append("'");
		QSqlQuery query( SQLQuery );
		if( query.isActive() ) 
		{
			while( query.next() ) 
			{
				mySpruch = Zeilenumbruch(query.value( 0 ).toString());
			}
		}
		SQLQuery = "SELECT Autor  FROM `sprueche` WHERE ID='";
		SQLQuery.append(QString::number(ID));   
		SQLQuery.append("'");
		query = SQLQuery ;
		if( query.isActive() ) 
		{
			while( query.next() ) 
			{
				myAutor = Zeilenumbruch(query.value( 0 ).toString());
			}
		}    
	}
	else
	{
		myError = "Konnte keine Verbindung zum MySQL-Server aufbauen!";
		return -1;
	}
}
return 0;
}

QString TSpruch::Zeilenumbruch(QString Text)
{
unsigned int alt=0, neu=0, letzter=0;
if (Text.length() > myConfig->GetZeilenumbruch())
{
	while ( Text.find(' ',alt) >= 0)
	{
		while ( (neu - letzter)  <  myConfig->GetZeilenumbruch() )
		{
			alt = neu+1;
			neu = Text.find(' ', alt);
		}
		if (neu > Text.length())
		{ 
			break; 
		}
		Text[neu] = '\n';
		letzter = neu;
	}
}

return Text;
}

QString TSpruch::GetSpruch()
{
QString Temp;
Temp = mySpruch;
if (myAutor != "")
{
	Temp = Temp + "\n" + "[" + myAutor +"]";
}
return Temp;
}

QString TSpruch::GetError()
{
return myError;
}
