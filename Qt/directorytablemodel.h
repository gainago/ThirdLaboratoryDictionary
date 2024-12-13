#ifndef DIRECTORYTABLEMODEL_H
#define DIRECTORYTABLEMODEL_H

#include <QHash>
#include <QAbstractTableModel>
#include <QString>
#include "memberofmodel.h"


class DirectoryTableModel : public QAbstractTableModel
{
private:
    //int cRows_; // c - count
    int cColumns_;
    QVector<memberOfModel> vectorData_;

public:
    DirectoryTableModel(int cRows, QObject* pObject = 0);

    QVariant data(const QModelIndex& index, int nRole) const;

    bool setData(const QModelIndex& index,
                 const QVariant&    value,
                 int                nRole);
    QVariant headerData(int             nSection,
                        Qt::Orientation orientation,
                        int             nRole = Qt::DisplayRole) const;

    int rowCount(const QModelIndex&) const;

    int columnCount(const QModelIndex&) const;

    bool insertRows(int         nRow,
                    int         nCount,
                    const QModelIndex& parent = QModelIndex());

    Qt::ItemFlags flags(const QModelIndex& index) const;


};

#endif // DIRECTORYTABLEMODEL_H
