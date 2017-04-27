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

void thirdTestSetup(void)
{
	int i;
	utest_print("Setup...\r\n");
    initEmployees(arrayEmployees, LENGTH);
    for(i=0; i < LENGTH; i++)
    {
        addEmployee(arrayEmployees, LENGTH,id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
    }
}

void thirdTestCase01(void)
{
    int i;
    employee* pEmployee;
    i = 4;

    pEmployee = findEmployeeById(arrayEmployees, LENGTH, id[i]);
    utest_assertNotNullMsg(pEmployee,"Error the pointer is NULL");


}

void thirdTestCase02(void)
{
    int i;
    employee* pEmployee;
    i = 4;

    pEmployee = findEmployeeById(arrayEmployees, LENGTH, id[i]);

    utest_assertNotNullMsg(pEmployee,"Error the pointer is NULL");
    utest_assertEqualsIntMsg(pEmployee->id,id[i],"Error value in <.id>");
    utest_assertEqualsStringMsg(pEmployee->name,unsortedList[i],2,"Error value in <.name>");
    utest_assertEqualsStringMsg(pEmployee->lastName,unsortedList[i],2,"Error value in <.lastName>");
    utest_assertEqualsFloatMsg(pEmployee->salary,salary[i],"Error value in <.salary>");
    utest_assertEqualsIntMsg(pEmployee->sector,sector[i],"Error value in <.sector>");
    utest_assertEqualsIntMsg(pEmployee->isEmpty,0,"Error value in <.isEmpty> the correct value is: (0)");

}

void thirdTestCase03(void)
{
    int i;
    employee* pEmployee;
    i = 0;
    pEmployee = findEmployeeById(NULL, LENGTH, id[i]);
    utest_assertNullMsg(pEmployee,"Error in return value <addEmployees> if array pointer is NULL, the correct value to return is: (NULL)");
}

void thirdTestCase04(void)
{
    int i;
    employee* pEmployee;
    i = 0;
    pEmployee = findEmployeeById(arrayEmployees, 0, id[i]);
    utest_assertNullMsg(pEmployee,"Error in return value <addEmployees> if LENGTH of array is invalid, the correct value to return is: (NULL)");
}




