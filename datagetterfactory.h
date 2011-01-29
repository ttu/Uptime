#ifndef DATAGETTERFACTORY_H
#define DATAGETTERFACTORY_H

#include "datagetter.h"

class DataGetterFactory
{
public:
    DataGetterFactory();
    virtual DataGetter* returnDataGetter() = 0;
};

class WindowsDataGetterFactory: public DataGetterFactory
{
public:
    WindowsDataGetterFactory();
    DataGetter* returnDataGetter();
};

class UnixDataGetterFactory: public DataGetterFactory
{
public:
    UnixDataGetterFactory();
    DataGetter* returnDataGetter();
};

#endif // DATAGETTERFACTORY_H
