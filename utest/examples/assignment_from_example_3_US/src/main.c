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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/array.h"
#define ELEMENTS 5

#include "../testing/inc/main_test.h"
#define TEST

int run(void);

int main(void)
{

    #ifdef TEST
        startTesting(1);
        //startTesting(2);
        //startTesting(3);
        //startTesting(4);
        //startTesting(5);

    #else
        run();
    #endif

    return 0;
}



int run(void)
{
    employee arrayEmployees[ELEMENTS];
    employee* pEmployee;
    int i;
    char* names[] = {"Sheldon","Penny","Howard","Raj","Leonard"};
    char* lastNames[] = {"Cooper","Penny","Wolowitz","Koothrappali","Hofstadter"};
    int sector[] = {1,1,2,3,4};
    float salary[] = {1000,1000,2000,3000,4000};
    int id[] = {11,20,3,4,9};

    initEmployees(arrayEmployees, ELEMENTS);

    for(i=0; i < ELEMENTS; i++)
    {
        addEmployee(arrayEmployees, ELEMENTS,id[i],names[i],lastNames[i],salary[i],sector[i]);
    }

    printf("\n\nOriginal List\n--------------");
    printEmployees(arrayEmployees, ELEMENTS);

    removeEmployee(arrayEmployees, ELEMENTS,20);

    sortEmployeeByName(arrayEmployees, ELEMENTS, 1);

    printf("\n\nSorted list\n--------------");
    printEmployees(arrayEmployees, ELEMENTS);


    pEmployee = findEmployeeById(arrayEmployees, ELEMENTS,9);

    if(pEmployee != NULL)
        printf("\n\nId 9 is: %s",pEmployee->name);


    return 0;
}

