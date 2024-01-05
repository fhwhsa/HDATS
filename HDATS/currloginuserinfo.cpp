#include "currloginuserinfo.h"

CurrLoginUserInfo::CurrLoginUserInfo(int id, QString name, int level)
{
    ID = id;
    Name = name;
    Level = level;
}

int CurrLoginUserInfo::getUserID()
{
    return ID;
}

QString CurrLoginUserInfo::getUserName()
{
    return Name;
}

int CurrLoginUserInfo::getUserLevel()
{
    return Level;
}
