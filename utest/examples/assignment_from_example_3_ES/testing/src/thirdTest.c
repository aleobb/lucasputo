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
    utest_assertNotNullMsg(pEmployee,"Error en valor de retorno, si se encontro un empleado el valor es distinto de NULL");


}

void thirdTestCase02(void)
{
    int i;
    employee* pEmployee;
    i = 4;

    pEmployee = findEmployeeById(arrayEmployees, LENGTH, id[i]);

    utest_assertNotNullMsg(pEmployee,"Error en valor de retorno, si se encontro un empleado el valor es distinto de NULL");
    utest_assertEqualsIntMsg(pEmployee->id,id[i],"Error de valor en <.id>");
    utest_assertEqualsStringMsg(pEmployee->name,unsortedList[i],2,"Error de valor en <.name>");
    utest_assertEqualsStringMsg(pEmployee->lastName,unsortedList[i],2,"Error de valor en <.lastName>");
    utest_assertEqualsFloatMsg(pEmployee->salary,salary[i],"Error de valor en <.salary>");
    utest_assertEqualsIntMsg(pEmployee->sector,sector[i],"Error de valor en <.sector>");
    utest_assertEqualsIntMsg(pEmployee->isEmpty,0,"Error de valor en <.isEmpty> el valor correcto para\nindicar que la posicion esta ocupada es (0)");

}

void thirdTestCase03(void)
{
    int i;
    employee* pEmployee;
    i = 0;
    pEmployee = findEmployeeById(NULL, LENGTH, id[i]);
    utest_assertNullMsg(pEmployee,"Error en valor de retorno, si se recibe un puntero NULL el valor a retornar es (NULL)");
}

void thirdTestCase04(void)
{
    int i;
    employee* pEmployee;
    i = 0;
    pEmployee = findEmployeeById(arrayEmployees, 0, id[i]);
    utest_assertNullMsg(pEmployee,"Error en valor de retorno, si se recibe una logitud erronea [length < 1]\nel valor a retornar es (NULL)");
}


void thirdTestCase05(void)
{

    employee* pEmployee;

    pEmployee = findEmployeeById(arrayEmployees, LENGTH, 1000);
    utest_assertNullMsg(pEmployee,"Error en valor de retorno, si no se encontro un empleado\nel valor a retornar es (NULL)");


}

