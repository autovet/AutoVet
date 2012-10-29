#ifndef VETDATAENTRY_H
#define VETDATAENTRY_H

class VetDataEntry
{
	
	public:

		enum State
		{
			NotSynchronized, // Entry not loaded/saved
			SemiSynchronized, // Only essential data loaded (eg: id and name)
			FullySynchronized // vEverything loaded/saved
		};

		VetDataEntry();
		virtual ~VetDataEntry();

		void setId(int id);

		int id();
		VetDataEntry::State state();

	protected:

		

	private:

		int mId;
		VetDataEntry::State mState;

};

#endif
