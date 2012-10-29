#include <vetdataentry.h>

VetDataEntry::VetDataEntry()
{
	mId = 0;
	mState = VetDataEntry::NotSynchronized;
}

VetDataEntry::~VetDataEntry()
{
}

void VetDataEntry::setId(int id)
{
	mId = id;
	if(mId != 0)
	{
		mState = VetDataEntry::SemiSynchronized;
	}
}

int VetDataEntry::id()
{
	return mId;
}

VetDataEntry::State VetDataEntry::state()
{
	return mState;
}
