#include "PinWindow.h"
#include <QMouseEvent>
#include <assert.h>

PinWindow::PinWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PinWindowClass())
{
    ui->setupUi(this);

    resize(600, 400);
    setWindowFlags(Qt::Tool | Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint);

    // �л�Pin״̬��ť
    toggleBtn = new QPushButton("toggle",this);
    toggleBtn->resize(60, 40);
    toggleBtn->move(270, 180);
    connect(toggleBtn, &QPushButton::clicked, this, [this]() {
        bPin = !bPin;
    });

    // �رհ�ť
    closeBtn = new QPushButton("close", this);
    closeBtn->resize(60, 40);
    closeBtn->move(540, 0);
    connect(closeBtn, &QPushButton::clicked, this, &QWidget::close);
}

PinWindow::~PinWindow()
{
    delete ui;
}

void PinWindow::mousePressEvent(QMouseEvent* ev)
{
    if (ev->button() == Qt::LeftButton)
    {
        bDraging = true;
        // ������ĳ�ʼλ��
        mouseStartPoint = ev->globalPos();
        // mouseStartPoint = event->pos();
        // ��ô��ڵĳ�ʼλ��
        windowTopLeftPoint = this->frameGeometry().topLeft();
    }
}

void PinWindow::mouseReleaseEvent(QMouseEvent* ev)
{
    if (ev->button() == Qt::LeftButton)
    {
        bDraging = false;
    }
}

void PinWindow::mouseMoveEvent(QMouseEvent* ev)
{
    if (!bPin && bDraging) {
        // �������ƶ��ľ���
        QPoint distance = ev->globalPos() - mouseStartPoint;
        // QPoint distance = ev->pos() - mouseStartPoint;
        // �ı䴰�ڵ�λ��
        this->move(windowTopLeftPoint + distance);
    }
}
