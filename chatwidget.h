#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include "channel.h"
#include "chatwidgetheader.h"
#include "chatwidgetinput.h"
#include "chatwidgetview.h"

#include <QFont>
#include <QVBoxLayout>
#include <QWidget>

class ChatWidget : public QWidget
{
    Q_OBJECT

public:
    ChatWidget(QWidget *parent = 0);
    ~ChatWidget();

    ChatWidgetView &
    getView()
    {
        return view;
    }

    Channel *
    getChannel() const
    {
        return channel;
    }

    const QString &
    getChannelName() const
    {
        return channelName;
    }

    void setChannelName(const QString &name);

    void showChangeChannelPopup();

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

private:
    Channel *channel;
    QString channelName;

    QFont font;
    QVBoxLayout vbox;
    ChatWidgetHeader header;
    ChatWidgetView view;
    ChatWidgetInput input;
};

#endif  // CHATWIDGET_H
