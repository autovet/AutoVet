#ifndef VETABNORMALITY_H
#define VETABNORMALITY_H

#include <vetdataentry.h>
#include <QString>
#include <QStringList>

class VetAbnormality : public VetDataEntry
{

	public:
		
		VetAbnormality();
		VetAbnormality(QString name);
		VetAbnormality(QString name, QString description);
		VetAbnormality(QString name, QString description, QStringList pseudoNames);

		int pseudoNameCount();
		void addPseudoName(QString pseudoName);

		void setName(QString name);
		void setDescription(QString description);
		void setPseudoNames(QStringList pseudoNames);

		QString name();
		QString description();
		QStringList& pseudoNames();
		QString pseudoName(int index);

	private:

		QString mName;
		QString mDescription;
		QStringList mPseudoNames;

};

#endif
