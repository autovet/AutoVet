#include <vetabnormality.h>

VetAbnormality::VetAbnormality()
	: VetDataEntry()
{
	mName = "";
	mDescription = "";
}

VetAbnormality::VetAbnormality(QString name)
	: VetDataEntry()
{
	mName = name;
	mDescription = "";
}

VetAbnormality::VetAbnormality(QString name, QString description)
	: VetDataEntry()
{
	mName = name;
	mDescription = description;
}

VetAbnormality::VetAbnormality(QString name, QString description, QStringList pseudoNames)
	: VetDataEntry()
{
	mName = name;
	mDescription = description;
	mPseudoNames = pseudoNames;
}

int VetAbnormality::pseudoNameCount()
{
	return mPseudoNames.size();
}

void VetAbnormality::addPseudoName(QString pseudoName)
{
	mPseudoNames.append(pseudoName);
}

void VetAbnormality::setName(QString name)
{
	mName = name;
}

void VetAbnormality::setDescription(QString description)
{
	mDescription = description;
}

void VetAbnormality::setPseudoNames(QStringList pseudoNames)
{
	mPseudoNames = pseudoNames;
}

QString VetAbnormality::name()
{
	return mName;
}

QString VetAbnormality::description()
{
	return mDescription;
}

QStringList& VetAbnormality::pseudoNames()
{
	return mPseudoNames;
}

QString VetAbnormality::pseudoName(int index)
{
	if(index < pseudoNameCount())
	{
		return mPseudoNames[index];
	}
	return "";
}
