#include <vetdataconnection.h>

VetDataConnection::VetDataConnection()
{
	mHostName = "";
	mDatabaseName = "";
	mUserName = "";
	mPassword = "";
	mPort = -1;
	mType = "";
	open();
}

VetDataConnection::VetDataConnection(QString hostName, QString databaseName)
{
	mHostName = hostName;
	mDatabaseName = databaseName;
	mUserName = "";
	mPassword = "";
	mPort = -1;
	mType = "";
	open();
}

VetDataConnection::VetDataConnection(QString hostName, QString databaseName, int port)
{
	mHostName = hostName;
	mDatabaseName = databaseName;
	mUserName = "";
	mPassword = "";
	mPort = port;
	mType = "";
	open();
}

VetDataConnection::VetDataConnection(QString hostName, QString databaseName, QString userName, QString password)
{
	mHostName = hostName;
	mDatabaseName = databaseName;
	mUserName = userName;
	mPassword = password;
	mPort = -1;
	mType = "";
	open();
}

VetDataConnection::VetDataConnection(QString hostName, QString databaseName, int port, QString userName, QString password)
{
	mHostName = hostName;
	mDatabaseName = databaseName;
	mUserName = userName;
	mPassword = password;
	mPort = port;
	mType = "";
	open();
}

VetDataConnection::VetDataConnection(const VetDataConnection &other)
{
	mHostName = other.mHostName;
	mDatabaseName = other.mDatabaseName;
	mUserName = other.mUserName;
	mPassword = other.mPassword;
	mPort = other.mPort;
	mType = other.mType;
	open();
}

VetDataConnection::~VetDataConnection()
{
	close();
}

void VetDataConnection::setError(QSqlError error)
{
	mError = error;
}

QSqlError VetDataConnection::error()
{
	return mError;
}

bool VetDataConnection::hasError()
{
	return mError.type() != QSqlError::NoError;
}

bool VetDataConnection::testConnection()
{
	bool opened = open();
	close();
	return opened;
}

bool VetDataConnection::open()
{
	close();
	if(mType != "")
	{
		mDatabase = QSqlDatabase::addDatabase(mType, "connection");
		mDatabase.setHostName(mHostName);
		mDatabase.setDatabaseName(mDatabaseName);
		mDatabase.setUserName(mUserName);
		mDatabase.setPassword(mPassword);
		mDatabase.setPort(mPort);
		if(mDatabase.open())
		{
			return initialize();
		}
	}
	return false;
}

void VetDataConnection::close()
{
	mDatabase.close();
	QSqlDatabase::removeDatabase("connection");
}

QSqlQuery VetDataConnection::execute(QString query)
{
	QSqlQuery result = mDatabase.exec(query);
	setError(result.lastError());
	return result;
}

void VetDataConnection::setType(QString type)
{
	mType = type;
	open();
}

void VetDataConnection::setHostName(QString hostName)
{
	mHostName = hostName;
	open();
}

void VetDataConnection::setDatabaseName(QString databaseName)
{
	mDatabaseName = databaseName;
	open();
}

void VetDataConnection::setUserName(QString userName)
{
	mUserName = userName;
	open();
}

void VetDataConnection::setPassword(QString password)
{
	mPassword = password;
	open();
}

void VetDataConnection::setPort(int port)
{
	mPort = port;
	open();
}

QString VetDataConnection::hostName()
{
	return mHostName;
}

QString VetDataConnection::databaseName()
{
	return mDatabaseName;
}

QString VetDataConnection::userName()
{
	return mUserName;
}

QString VetDataConnection::password()
{
	return mPassword;
}

int VetDataConnection::port()
{
	return mPort;
}
