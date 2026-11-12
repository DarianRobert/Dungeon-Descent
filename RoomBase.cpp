#include "RoomBase.h"
#include <iostream>
#include <string>
#include <vector>

RoomBase::RoomBase(const std::string &name) : type(name)
{
}

string RoomBase::getType()
{
    return type;
}

vector<string> RoomBase::getChoices(int, int)
{
    return vector<string>();
}

string RoomBase::getImageFileName(int)
{
    return imageFileName;
}

string RoomBase::getTextFileName(int)
{
    return textFileName;
}

RoomBase::RoomBase()
{
}

string RoomBase::getbtnChoice1(Character &)
{
    return string();
}

string RoomBase::getbtnChoice2(Character &)
{
    return string();
}

string RoomBase::getbtnChoice3(Character &)
{
    return string();
}

string RoomBase::getbtnChoice4(Character &)
{
    return string();
}
