#ifndef CURRLOGINUSERINFO_H
#define CURRLOGINUSERINFO_H

#include <QObject>

class CurrLoginUserInfo
{
public:
    CurrLoginUserInfo(int id, QString name, int level);

    int getUserID();
    QString getUserName();
    int getUserLevel();

private:
    int ID; // 当前登陆的用户的ID
    QString Name;
    int Level; // 权限等级
};

#endif // CURRLOGINUSERINFO_H
