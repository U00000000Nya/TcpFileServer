#ifndef TCPFILESENDER_H
#define TCPFILESENDER_H

#include <QDialog>
#include <QTcpSocket>
#include <QFile>
#include <QProgressBar>
#include <QPushButton>
#include <QLabel>
#include <QDialogButtonBox>
#include <QFileDialog>
#include <QDataStream>
#include <QLineEdit>  // 引入 QLineEdit 用於 IP 和 PORT 輸入

class TcpFileSender : public QDialog
{
    Q_OBJECT

public:
    explicit TcpFileSender(QWidget *parent = nullptr);
    ~TcpFileSender();

private slots:
    void openFile();
    void start();
    void startTransfer();
    void updateClientProgress(qint64 numBytes);

private:
    QTcpSocket tcpClient;
    QFile *localFile;
    QString fileName;
    QByteArray outBlock;
    qint64 totalBytes;
    qint64 bytesWritten;
    qint64 bytesToWrite;
    qint64 loadSize;
    QProgressBar *clientProgressBar;
    QLabel *clientStatusLabel;
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *openButton;
    QDialogButtonBox *buttonBox;

    // 新增的控件：用於接收用戶輸入的 IP 和 PORT
    QLabel *ipLabel;
    QLabel *portLabel;
    QLineEdit *ipLineEdit;
    QLineEdit *portLineEdit;
};

#endif // TCPFILESENDER_H
