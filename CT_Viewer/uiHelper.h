#pragma once
#ifndef UIHELPER_H
#define UIHELPER_H
#include "ui_CT_Viewer.h"
#include <QString>
#include <QMap>
#include <QProgressDialog>

void displayMetaInfo(Ui::CT_ViewerClass& ui, const QMap<QString, QString>& map);
QString displayDetails(const QMap<QString, QString>& map);
QProgressDialog* createProgressDialog(QString title, QString prompt, int range);

#endif