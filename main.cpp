#include <iostream>
#include "sqlspruch.h"


using namespace std;

int main( int argc, char **argv )
{
TConfig Config(argc,argv);

TSpruch Spruch( Config.GetHost(),
                Config.GetUsername(),
                Config.GetPassword(),
		&Config );

QApplication a( argc, argv );

if (Spruch.Verbinden()==0)
{
	cout << Spruch.GetSpruch() << endl;
	return 0;
}
else 
{
	cout << Spruch.GetError() << endl;
	return -1;
}
}
