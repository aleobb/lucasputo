/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <utest.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//INCLUDE LIBRARY TO TEST
#include "../../inc/array.h"

//DEFINES OF THIS TEST
#define LENGTH 6


static char* unsortedList[] = {"Za","Zb","Xd","Xb","Ya","Yc"};
static char* sortedListUp[] = {"Xb","Xd","Ya","Yc","Za","Zb"};
static char* sortedListDown[] = {"Zb","Za","Yc","Ya","Xd","Xb"};
static int sector[] = {1,1,2,3,4,6};
static float salary[] = {1000,1000,2000,3000,4000,8000};
static int id[] = {11,20,3,4,9,99};
static int sortedIdUp[] = {4,3,9,99,11,20};
static int sortedIdDown[] = {20,11,99,9,3,4};

static employee arrayEmployees[LENGTH];

void fifthTestSetup(void)
{
    int i;
	utest_print("Setup...\r\n");
    initEmployees(arrayEmployees, LENGTH);
    for(i=0; i < LENGTH; i++)
    {
        addEmployee(arrayEmployees, LENGTH,id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
    }
}

void fifthTestCase01(void)
{
    int r;
    r = sortEmployeeByName(arrayEmployees, LENGTH, 1);
    utest_assertEqualsIntMsg(r,0,"Error in return value <sortEmployeeByName> if ok the correct value to return is: (0)");

}

void fifthTestCase02(void)
{
    int i;
    sortEmployeeByName(arrayEmployees, LENGTH, 1);
    for (i=0;i < LENGTH;i++)
    {
        utest_assertEqualsStringMsg(arrayEmployees[i].name,sortedListUp[i],2,"Error value in <.name>");
        utest_assertEqualsIntMsg(arrayEmployees[i].id,sortedIdUp[i],"Error value in <.id>");
    }
}

void fifthTestCase03(void)
{
    int i;
    sortEmployeeByName(arrayEmployees, LENGTH, 0);
    for (i=0;i < LENGTH;i++)
    {
        utest_assertEqualsStringMsg(arrayEmployees[i].name,sortedListDown[i],2,"Error value in <.name>");
        utest_assertEqualsIntMsg(arrayEmployees[i].id,sortedIdDown[i],"Error value in <.id>");
    }
}

void fifthTestCase04(void)
{
    int r;

    r = sortEmployeeByName(NULL, LENGTH, 0);
    utest_assertEqualsIntMsg(r,-1,"Error in return value <sortEmployeeByName> if array pointer is NULL, the correct value to return is: (-1)");
}

void fifthTestCase05(void)
{
    int r;

    r = sortEmployeeByName(arrayEmployees, 0, 0);
    utest_assertEqualsIntMsg(r,-1,"Error in return value <sortEmployeeByName> if LENGTH of array is invalid, the correct value to return is: (-1)");
}




