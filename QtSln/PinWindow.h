#pragma once

#include <QtWidgets/QWidget>
#include "ui_PinWindow.h"
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class PinWindowClass; };
QT_END_NAMESPACE

class PinWindow : public QWidget
{
    Q_OBJECT

public:
    PinWindow(QWidget *parent = nullptr);
    ~PinWindow();

protected:
    virtual void mousePressEvent(QMouseEvent* ev) override;
    virtual void mouseReleaseEvent(QMouseEvent* ev) override;
    virtual void mouseMoveEvent(QMouseEvent* ev) override;

private:
    Ui::PinWindowClass *ui;
    QPushButton* toggleBtn;
    QPushButton* closeBtn;
    bool bPin = false;
    bool bDraging = false;

    QPoint      mouseStartPoint;
    QPoint      windowTopLeftPoint;
};
