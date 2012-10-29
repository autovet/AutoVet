#include <QApplication>

#include <QString>
#include <vetsqliteconnection.h>

int main(int argc, char *argv[])
{
	QApplication application(argc, argv);
	
	VetAbnormality a("thename", "thedescription");
	a.addPseudoName("ps1");
	a.addPseudoName("ps2");
	VetSqliteConnection c("", "/home/visore/AutoVet/install/autovet.db");
	c.insert(a);

	application.exec();

	return 0;
}

