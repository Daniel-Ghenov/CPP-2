#include "Interface\AdminIF.h"

AdminIF::AdminIF(BaseIF& interFace, const char* username, const String& password){

    _sys = interFace.sys();
    user = _sys->logInAdmin(username, password);
}