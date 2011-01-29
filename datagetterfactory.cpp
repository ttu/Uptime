#include "datagetterfactory.h"

DataGetterFactory::DataGetterFactory()
{
}

WindowsDataGetterFactory::WindowsDataGetterFactory()
{
}

DataGetter* WindowsDataGetterFactory::returnDataGetter()
{
    return new WinDataGetter();
}

UnixDataGetterFactory::UnixDataGetterFactory()
{
}

DataGetter* UnixDataGetterFactory::returnDataGetter()
{
    return new UnixDataGetter();
}
