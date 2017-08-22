//
// Created by Matthias Hofstätter on 20.08.17.
//

#include <stdio.h>
#include "googleDriveApi.h"

int main( int argc, const char* argv[] )
{
    googleDriveApi::auth("4/7Nn4HzOdLuH0vKOZZBzXsbIagGteE5F1e90ysbyomgs", "590194775230-snrhmjb562msv07a5rvg8mj6l5tiiq0i.apps.googleusercontent.com", "XI1bBfoU5AXAFq-h5SqSas1M", "", "");
    googleDriveApi::list("","",false,"", 1000, "","", "", false, "", false, "modifiedTime");
    return 0;
}
