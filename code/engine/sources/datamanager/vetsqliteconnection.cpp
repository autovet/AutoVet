#include <vetsqliteconnection.h>

VetSqliteConnection::VetSqliteConnection()
	: VetDataConnection()
{
	setType("QSQLITE");
}

VetSqliteConnection::VetSqliteConnection(QString hostName, QString databaseName)
	: VetDataConnection(hostName, databaseName)
{
	setType("QSQLITE");
}

VetSqliteConnection::VetSqliteConnection(QString hostName, QString databaseName, int port)
	: VetDataConnection(hostName, databaseName, port)
{
	setType("QSQLITE");
}

VetSqliteConnection::VetSqliteConnection(QString hostName, QString databaseName, QString userName, QString password)
	: VetDataConnection(hostName, databaseName, userName, password)
{
	setType("QSQLITE");
}

VetSqliteConnection::VetSqliteConnection(QString hostName, QString databaseName, int port, QString userName, QString password)
	: VetDataConnection(hostName, databaseName, port, userName, password)
{
	setType("QSQLITE");
}

VetSqliteConnection::VetSqliteConnection(const VetSqliteConnection &other)
	: VetDataConnection(other)
{
	setType("QSQLITE");
}

bool VetSqliteConnection::initialize()
{
	execute("CREATE TABLE IF NOT EXISTS abnormality (id INTEGER NOT NULL PRIMARY KEY, name TEXT NOT NULL, description TEXT);");
	if(!hasError())
	{
		execute("CREATE TABLE IF NOT EXISTS abnormality_pseudo (id INTEGER NOT NULL PRIMARY KEY, name TEXT NOT NULL, abnormality INTEGER NOT NULL, FOREIGN KEY (abnormality) REFERENCES abnormality (id));");
		if(!hasError())
		{
			return true;
		}
	}
	return false;
}

bool VetSqliteConnection::insert(VetAbnormality &entry)
{
	QSqlQuery result = execute("INSERT INTO abnormality (name, description) VALUES ('" + entry.name() + "', '" + entry.description() + "');");
	if(!hasError())
	{
		QString id = QString::number(result.lastInsertId().toInt());
		QStringList &pseudos = entry.pseudoNames();
		for(int i = 0; i < pseudos.size(); ++i)
		{
			execute("INSERT INTO abnormality_pseudo (name, abnormality) VALUES ('" + pseudos[i] + "', " + id + ");");
		}
		if(!hasError())
		{
			return true;
		}
	}
	return false;
}

bool VetSqliteConnection::update(VetAbnormality &entry)
{

}

bool VetSqliteConnection::select(VetAbnormality &entry)
{

}
