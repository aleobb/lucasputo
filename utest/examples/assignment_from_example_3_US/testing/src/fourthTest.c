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
static int sector[] = {1,1,2,3,4,6};
static float salary[] = {1000,1000,2000,3000,4000,8000};
static int id[] = {11,20,3,4,9,99};

static employee arrayEmployees[LENGTH];

void fourthTestSetup(void)
{
    int i;
	utest_print("Setup...\r\n");
    initEmployees(arrayEmployees, LENGTH);
    for(i=0; i < LENGTH; i++)
    {
        addEmployee(arrayEmployees, LENGTH,id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
    }

}

void fourthTestCase01(void)
{
    int i,r;
    i = 2;
    r = removeEmployee(arrayEmployees, LENGTH, id[i]);
    utest_assertEqualsIntMsg(r,0,"Error in return value <removeEmployees> if ok the correct value to return is: (0)");
}

void fourthTestCase02(void)
{
    int i,r;
    for(i=0; i < LENGTH; i++)
    {
        r = removeEmployee(arrayEmployees, LENGTH, id[i]);
        utest_assertEqualsIntMsg(r,0,"Error in return value <removeEmployees> correct value to return is: (0)");
    }
    for (i=0;i < LENGTH;i++)
    {
        utest_assertEqualsIntMsg(arrayEmployees[i].isEmpty,1,"Error value in <.isEmpty> if is removed the correct value is: (1)");
        utest_assertEqualsIntMsg(arrayEmployees[i].id,id[i],"Error value in <.id>");
        utest_assertEqualsStringMsg(arrayEmployees[i].name,unsortedList[i],2,"Error value in <.name>");
        utest_assertEqualsStringMsg(arrayEmployees[i].lastName,unsortedList[i],2,"Error value in <.lastName>");
        utest_assertEqualsFloatMsg(arrayEmployees[i].salary,salary[i],"Error value in <.salary>");
        utest_assertEqualsIntMsg(arrayEmployees[i].sector,sector[i],"Error value in <.sector>");
    }
}

void fourthTestCase03(void)
{
    int i,r;
    i = 0;
    r = removeEmployee(NULL, LENGTH, id[i]);
    utest_assertEqualsIntMsg(r,-1,"Error in return value <removeEmployees> if array pointer is NULL, the correct value to return is: (-1)");
}

void fourthTestCase04(void)
{
    int i,r;
    i = 0;
    r = removeEmployee(arrayEmployees, 0, id[i]);
    utest_assertEqualsIntMsg(r,-1,"Error in return value <removeEmployees> if LENGTH of array is invalid, the correct value to return is: (-1)");
}




