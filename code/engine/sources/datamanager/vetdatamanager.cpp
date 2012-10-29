#include <vetdatamanager.h>

VetDataManager* VetDataManager::mManager = NULL;

VetDataManager::VetDataManager()
{
	mConnection = NULL;
}

VetDataManager::~VetDataManager()
{
	delete mConnection;
	mConnection = NULL;
}

VetDataManager* VetDataManager::instance()
{
	if(mManager == NULL)
	{
		mManager = new VetDataManager();
	}
	return mManager;
}

void VetDataManager::setConnection(VetDataConnection *connection)
{
	instance()->mConnection = connection;
}

void VetDataManager::update(VetAbnormality &entry)
{/*
	if(entry.state() == VetDataEntry::NotSynchronized)
	{
		load(entry);
	}
	else if(entry.state() == VetDataEntry::SemiSynchronized)
	{
		load(entry);
	}
	else if(entry.state() == VetDataEntry::FullySynchronized)
	{
		save(entry);
	}*/
}

void VetDataManager::save(VetAbnormality &entry)
{
	/*for(int i = 0; i < mConnections.size(); ++i)
	{
		mConnections[i]->
	}*/
}

void VetDataManager::edit(VetAbnormality &entry)
{

}

void VetDataManager::load(VetAbnormality &entry)
{

}
