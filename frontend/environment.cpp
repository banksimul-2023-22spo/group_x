#include "environment.h"

Environment::Environment()
{

}

QString Environment::getBaseUrl()
{
    return "http://localhost:3000";
    //tarvittaessa helppo muuttaa
    //esimerkiksi
    //return "https://azure.com/myapp";
    //return "http://ipv4.fiddler.fi:3000";
}
