#ifndef VETSQLITECONNECTION_H
#define VETSQLITECONNECTION_H

#include <vetdataconnection.h>

class VetSqliteConnection : public VetDataConnection
{
	
	public:

		VetSqliteConnection();
		VetSqliteConnection(QString hostName, QString databaseName);
		VetSqliteConnection(QString hostName, QString databaseName, int port);
		VetSqliteConnection(QString hostName, QString databaseName, QString userName, QString password);
		VetSqliteConnection(QString hostName, QString databaseName, int port, QString userName, QString password);
		VetSqliteConnection(const VetSqliteConnection &other);

	//protected:

		bool initialize();

		bool insert(VetAbnormality &entry);
		bool update(VetAbnormality &entry);
		bool select(VetAbnormality &entry);

};

#endif
