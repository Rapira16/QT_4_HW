#include "mainwindow.h"
#include <QApplication>

void MainWindow::switchLanguage(QString language)
{
translater.load("switchlang_" + language);
qApp->installTranslator(&translater);
QString str = tr("Switch language on ");
rusB->setText(str + "Русский");
frB->setText(str + "Francais");
jaB->setText(str + "日本語");
enB->setText(str + "English");
QLabel *labels[] = {l0, l1, l2, l3};
QString list[] =
{
tr("Hello"),
tr("What is you name?"),
tr("I'm going to learn Qt"),
tr("Bye-Bye!")
};
for (int i = 0; i < 4; i++)
{
labels[i]->setText(tr("This is l") + QString::number(i) + ": " +
list[i]);
labels[i]->resize(700, 30);
}

}
void MainWindow::clickSwitch()
{
QObject *obj = sender(); // узнаём, от какого виджета пришел сигнал
if (obj == rusB)switchLanguage("ru");
if (obj == frB)switchLanguage("fr");
if (obj == jaB)switchLanguage("ja");
if (obj == enB)switchLanguage("en");
}

int main(int argc, char *argv[])
{
QApplication a(argc, argv);
MainWindow w;
w.resize(800, 600);
w.show();
return a.exec();
}

