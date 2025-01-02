
#include <QApplication>
#include <QRect>
#include <QScreen>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>

#include "UIClass.h"
#include "GetNamesAndSournamesToMyString.h"
#include "GenerateArraySequencePerson.h"
#include "GetQstringFromNewWidget.h"
#include "LRUCache.h"
#include "GetHashCode.h"




UIClass::UIClass() {

    screen_ = new QRect(QApplication::screens().at(0)->geometry());

    seq_ = nullptr;

    QHBoxLayout* hLayout = new QHBoxLayout;
    QVBoxLayout* vLayout = new QVBoxLayout;

    mainWidget_ = new QWidget;
    textEdit_ = new QTextEdit;
    textEdit_->setReadOnly(true);

    QPushButton* buttonGenerateRand = new QPushButton("Generate Objects");
    QPushButton* buttonGet = new QPushButton("Get Object");
    QPushButton* buttonDisplayCache = new QPushButton("Display Cache");

    hLayout->addWidget(buttonGenerateRand);
    hLayout->addWidget(buttonGet);
    hLayout->addWidget(buttonDisplayCache);

    vLayout->addLayout(hLayout);
    vLayout->addWidget(textEdit_);

    mainWidget_->setLayout(vLayout);
    mainWidget_->resize(screen_->width() / 3, screen_->height() / 3);
    mainWidget_->move(screen_->width() / 3, screen_->height() / 3);

    QObject::connect(buttonGenerateRand, SIGNAL(clicked(bool))
                     , this, SLOT(slotGenerateRand()));
    QObject::connect(buttonGet, SIGNAL(clicked(bool))
                     , this, SLOT(slotGet()));

    QObject::connect(buttonDisplayCache, SIGNAL(clicked(bool))
                     , this, SLOT(slotDisplayCache()));

    mainWidget_->show();

    names_ = GetNamesToMyString();
    surnames_ = GetSurnamesToMyString();

    cache_ = new LRUCache<int, Person>(UIClass::GetPerson, 20, GetHashCodeInt);
}

void UIClass::slotGenerateRand()
{
    DeleteGenerateArraySequencePerson(seq_);

    getQStringFromNewWidget* getter = new getQStringFromNewWidget;
    getter->getString("Enter count of Persons", "Reset");

    QObject::connect(getter, SIGNAL(ButtonPushed(QString))
                     , this, SLOT(slotGenerateRandFinal(QString)));

}

void UIClass::slotGenerateRandFinal(QString string)
{
    bool isOk = 1;

    int count = string.toInt(&isOk);

    if(!isOk){
        QWidget* wg = new QWidget;
        QMessageBox::critical(wg, "Pay Attention"
                              , "You have to enter int");
        return;
    }

    seq_ = GenerateArraySequencePerson(count, names_, surnames_);

    textEdit_->clear();

    if(seq_ == nullptr){
        return;
    }

    for(int index = 0; index < seq_->GetLength(); ++index){
        textEdit_->append(QString::number(index));
        textEdit_->append(QString("Id: ") + QString(seq_->Get(index)->GetId().GetCharPointer()));
        textEdit_->append(QString("First Name: ") + QString(seq_->Get(index)->GetFirstName().GetCharPointer()));
        textEdit_->append(QString("Middle Name: ") + QString(seq_->Get(index)->GetMiddleName().GetCharPointer()));
        textEdit_->append(QString("Last Name: ") + QString(seq_->Get(index)->GetLastName().GetCharPointer()));
        textEdit_->append(QString("Born Year: ") + QString::number(seq_->Get(index)->GetBornYear()));
        textEdit_->append("");
    }

    textEdit_->repaint();
}

MyNamespace::ReturnValue<Person> UIClass::GetPerson(int const & index)
{
    if(seq_ == nullptr || index >= seq_->GetLength() || index < 0){
        return MyNamespace::ReturnValue<Person>(false, Person());
    }

    return MyNamespace::ReturnValue<Person>(true, *seq_->Get(index));
}

void UIClass::slotGet()
{
    getQStringFromNewWidget* getter = new getQStringFromNewWidget;
    getter->getString("Enter index of Persons", "Get");

    QObject::connect(getter, SIGNAL(ButtonPushed(QString))
                     , this, SLOT(slotGetFinal(QString)));
}

void UIClass::slotGetFinal(QString string)
{
    bool isOk = 1;

    int index = string.toInt(&isOk);

    if(!isOk){
        QWidget* wg = new QWidget;
        QMessageBox::critical(wg, "Pay Attention"
                              , "You have to enter int");
        return;
    }

    MyNamespace::ReturnValue<Person> returnPerson = cache_->Get(index);

    if(!returnPerson.IsCorrect()){
        QWidget* wg = new QWidget;
        QMessageBox::critical(wg, "Pay Attention"
                              , "You have to enter right position");
        return;
    }

    QTextEdit* displayPerson = new QTextEdit;

    displayPerson->setReadOnly(true);

    displayPerson->append(QString("Id: ") + QString(returnPerson.GetValue().GetId().GetCharPointer()));
    displayPerson->append(QString("First Name: ") + QString(returnPerson.GetValue().GetFirstName().GetCharPointer()));
    displayPerson->append(QString("Middle Name: ") + QString(returnPerson.GetValue().GetMiddleName().GetCharPointer()));
    displayPerson->append(QString("Last Name: ") + QString(returnPerson.GetValue().GetLastName().GetCharPointer()));
    displayPerson->append(QString("Born Year: ") + QString::number(returnPerson.GetValue().GetBornYear()));
    displayPerson->append("");

    displayPerson->show();

}

void UIClass::slotDisplayCache()
{
    QTextEdit* displayPersonCache = new QTextEdit;

    displayPersonCache->setReadOnly(true);

    for(auto it = cache_->dictionary_.Begin(); it != cache_->dictionary_.End(); ++it){
        (*it).GetSecond().GetFirst();
        displayPersonCache->append(QString("Id: ") + QString((*it).GetSecond().GetFirst().GetId().GetCharPointer()));
        displayPersonCache->append(QString("First Name: ") + QString((*it).GetSecond().GetFirst().GetFirstName().GetCharPointer()));
        displayPersonCache->append(QString("Middle Name: ") + QString((*it).GetSecond().GetFirst().GetMiddleName().GetCharPointer()));
        displayPersonCache->append(QString("Last Name: ") + QString((*it).GetSecond().GetFirst().GetLastName().GetCharPointer()));
        displayPersonCache->append(QString("Born Year: ") + QString::number((*it).GetSecond().GetFirst().GetBornYear()));
        displayPersonCache->append("");
    }

    displayPersonCache->show();

}
