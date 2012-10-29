#ifndef VETDATAMANAGER_H
#define VETDATAMANAGER_H

#include <vetdataconnection.h>

class VetDataManager
{

	public:
		
		~VetDataManager();

		static void setConnection(VetDataConnection *connection); // Takes ownership of the connection

		static void update(VetAbnormality &entry); // Depending on the entry, either saves, loads or edits
		static void save(VetAbnormality &entry);
		static void edit(VetAbnormality &entry);
		static void load(VetAbnormality &entry);

	protected:

		VetDataManager();
		static VetDataManager* instance();

	private:

		static VetDataManager* mManager;
		VetDataConnection *mConnection;

};

#endif
