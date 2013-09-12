#include "kee/Math.h"
#include <string.h>

namespace kee
{

Math::Math()
{
}

double Math::asciiToDouble(const char * str)
{
    const char * ptr=str;

    //check if could be a hex number
    if(strncmp(ptr,"0x",2) ==0)
    {
        ptr+=2;
        double value=0.0f;
        while(*ptr!=0 &&
              ((*ptr >='0' && *ptr <= '9')
              ||(*ptr >='a' && *ptr <= 'f')
               ||(*ptr >='A' && *ptr <= 'F'))
              )
        {
            if(*ptr >= '0' && *ptr <='9') value=value*16.0+double(*ptr - '0');
            else if(*ptr >='a' && *ptr<='f')value=value*16.0+double(*ptr -'a' +10);
            else if(*ptr >= 'A' && *ptr<='F')value=value *16.0+double(*ptr -'A' +10);

            ptr++;
        }

        return value;
    }


    return 0.0;
}

}
