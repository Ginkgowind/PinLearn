#include "PinWindow.h"

PinWindow::PinWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PinWindowClass())
{
    ui->setupUi(this);

    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);
}

PinWindow::~PinWindow()
{
    delete ui;
}
