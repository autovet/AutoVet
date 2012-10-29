#ifndef VETDATACONNECTION_H
#define VETDATACONNECTION_H

#include <vetabnormality.h>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlResult>

class VetDataConnection
{
	
	public: 

		VetDataConnection();
		VetDataConnection(QString hostName, QString databaseName);
		VetDataConnection(QString hostName, QString databaseName, int port);
		VetDataConnection(QString hostName, QString databaseName, QString userName, QString password);
		VetDataConnection(QString hostName, QString databaseName, int port, QString userName, QString password);
		VetDataConnection(const VetDataConnection &other);
		virtual ~VetDataConnection();

		QSqlError error();
		bool hasError();
		bool testConnection();

		void setHostName(QString hostName);
		void setDatabaseName(QString databaseName);
		void setUserName(QString userName);
		void setPassword(QString password);
		void setPort(int port);

		QString hostName();
		QString databaseName();
		QString userName();
		QString password();
		int port();

	protected:

		void setError(QSqlError error);
		bool open();
		void close();
		QSqlQuery execute(QString query);
		void setType(QString type);

		virtual bool initialize() = 0;

		virtual bool insert(VetAbnormality &entry) = 0;
		virtual bool update(VetAbnormality &entry) = 0;
		virtual bool select(VetAbnormality &entry) = 0;

	private:

		QString mHostName;
		QString mDatabaseName;
		QString mUserName;
		QString mPassword;
		int mPort;
		QString mType;
		QSqlDatabase mDatabase;
		QSqlError mError;

};

#endif
