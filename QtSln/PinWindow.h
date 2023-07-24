#pragma once

#include <QtWidgets/QWidget>
#include "ui_PinWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PinWindowClass; };
QT_END_NAMESPACE

class PinWindow : public QWidget
{
    Q_OBJECT

public:
    PinWindow(QWidget *parent = nullptr);
    ~PinWindow();

private:
    Ui::PinWindowClass *ui;
};
