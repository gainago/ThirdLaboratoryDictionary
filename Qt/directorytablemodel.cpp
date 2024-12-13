#include "directorytablemodel.h"
#include <QDebug>

DirectoryTableModel::DirectoryTableModel(int cRows, QObject* pObject)
    :   QAbstractTableModel(pObject)
    ,   cColumns_(3)
    ,   vectorData_(QVector<memberOfModel>(cRows))
{
}

QVariant DirectoryTableModel::data(const QModelIndex& index, int nRole) const
{
    if(!index.isValid()){
        return QVariant();
    }

    if((nRole == Qt::DisplayRole || nRole == Qt::EditRole) &&
        vectorData_.size() > index.row()){
        switch(index.column()){
            case 0:{
            return QVariant(vectorData_[index.row()].getOperation().GetQStringRepresentation());
            }
            case 1:{
                return vectorData_[index.row()].getTime();
                break;
            }
            case 2:{
                return vectorData_[index.row()].getSize();
                break;
            }
            default: break;
        }
    }

    return QVariant();


}

bool DirectoryTableModel::setData(const QModelIndex& index,
             const QVariant&    value,
             int                nRole)
{
    /*if(index.isValid())
        qDebug() << "AAA";

    if(nRole == Qt::EditRole)
        qDebug() << "BBB";

    if(index.row() < dArray_.GetCapacity())
        qDebug() << "CCC";*/

    if((index.isValid()) && (nRole == Qt::EditRole) && (index.row() < vectorData_.size())) {
        memberOfModel priviousMember = vectorData_[index.row()];
        switch(index.column()){
        case 0:{
            EnumClass tmpEnumClass  = static_cast<EnumClass>(value.value<int>());
            memberOfModel tmpMember(tmpEnumClass,
                                    priviousMember.getTime(),
                                    priviousMember.getSize());
            vectorData_[index.row()] = tmpMember;
            emit dataChanged(index, index);
            return true;
            break;
        }
        case 1:{
            double tmpTime(value.value<double>());
            memberOfModel tmpMember(priviousMember.getOperation(),
                                    tmpTime,
                                    priviousMember.getSize());
            vectorData_[index.row()] = tmpMember;
            emit dataChanged(index, index);
            return true;
            break;
        }
        case 2:{
            int tmpSize(value.value<int>());
            memberOfModel tmpMember(priviousMember.getOperation(),
                                    priviousMember.getTime(),
                                    tmpSize);
            vectorData_[index.row()] = tmpMember;
            emit dataChanged(index, index);
            return true;
            break;
        }
        default: break;
        }
    }
    //emit dataChanged(index, index);
    return false;
}

QVariant DirectoryTableModel::headerData(int             nSection,
                                        Qt::Orientation orientation,
                                        int             nRole) const
{
    if(nRole != Qt::DisplayRole){
        return QVariant();
    }
    if(orientation == Qt::Horizontal){
        switch(nSection){
            case 0:{
                return QVariant(QString("Operation"));
                break;
            }
            case 1:{
                return QVariant(QString("time"));
                break;
            }
            case 2:{
                return QVariant(QString("size"));
                break;
            }
            default:{
                break;
            }
        }
    } else{
        return QVariant(nSection);
    }

    return QVariant();
}


int DirectoryTableModel::rowCount(const QModelIndex&) const
{
    return vectorData_.size();
}

int DirectoryTableModel::columnCount(const QModelIndex&) const
{
    return cColumns_;
}

bool DirectoryTableModel::insertRows(int         nRow,
                int         nCount,
                const QModelIndex& parent)
{
    if(parent.isValid() || nRow != vectorData_.size()){
        return false;
    }

    beginInsertRows(QModelIndex(), nRow, nRow + nCount -1);
    for(int i = 0; i < nCount; ++i){
        vectorData_.resize(vectorData_.size() + 1);
    }
    endInsertRows();

    return true;
}

Qt::ItemFlags DirectoryTableModel::flags(const QModelIndex& index) const
{
    Qt::ItemFlags flags = QAbstractTableModel::flags(index);

    return flags;
}
