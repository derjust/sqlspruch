#include "configuration.h"

using namespace std;

TConfig::TConfig(int argc, char **argv)
{
int opt=0;
while((opt = getopt(argc, argv, "h:u:p:z:") )!= -1) 
{ 
	switch(opt) 
	{ 
		case 'h':  
			myHost = optarg;
			break;
		
		case 'u':
			myUsername = optarg;
			break;
			
		case 'p':
			myPassword = optarg;
			break;	
		case 'z':
			myZeilenumbruch = atoi(optarg);
			break;
		
		default:
			myError = "Falsche Parameter\n-h für Host\n-u für Username\n-p für Passwort";
			break;
	}
}
if ((myHost == "") || ( myUsername == ""))
{
	cout << "Es fehlen Parameter:" << endl;
	cout << "-h <host>" << endl;
	cout << "-u <username>" << endl;
	cout << "-p <password>" << endl;
	cout << "-z <zeilenumbruch>" << endl <<flush;
}
}

QString TConfig::GetHost()
{
return myHost;
}

QString TConfig::GetUsername()
{
return myUsername;
}

QString TConfig::GetPassword()
{
return myPassword;
}

QString TConfig::GetError()
{
return myError;
}

unsigned int TConfig::GetZeilenumbruch()
{
return myZeilenumbruch;
}
