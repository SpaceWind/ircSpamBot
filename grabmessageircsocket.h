#ifndef GRABMESSAGEIRCSOCKET_H
#define GRABMESSAGEIRCSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QTextEdit>
#include "ircprivmessageparser.h"
#include "abstractircsocket.h"

class GrabMessageIrcSocket : public AbstractIrcSocket
{
    Q_OBJECT
    //textEdit widget where listening bot will type incoming chat messages
    //can be NULL_PTR
    QTextEdit * textEdit_;
    //list of spambots nicknames
    QStringList * spambots_;

public:
    explicit GrabMessageIrcSocket(QObject *parent = 0);
    explicit GrabMessageIrcSocket(QString host, QString channel, QString nickname, QString pass,
                                  QStringList* words, QStringList* spambots, QTextEdit* out = 0);

signals:
    void wordAdded();


public slots:
    void parseMessage();

};

#endif // GRABMESSAGEIRCSOCKET_H
