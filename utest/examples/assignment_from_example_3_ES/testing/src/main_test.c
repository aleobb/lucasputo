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

#include "../inc/firstTest.h"
#include "../inc/secondTest.h"
#include "../inc/thirdTest.h"
#include "../inc/fourthTest.h"
#include "../inc/fifthTest.h"

void startTesting(int testGroup)
{


    switch(testGroup)
    {
        case 1:
            // Start Group 01
            utest_printStartTesting("initEmployees()");
            utest_init();
            utest_startTest(firstTestCase00,firstTestSetup,">Case[Verifica el retorno de la funcion al inicializar correctamente el array]");
            utest_startTest(firstTestCase01,firstTestSetup,">Case[Analiza si fue inicializado correctamente el array]");
            utest_startTest(firstTestCase02,firstTestSetup,">Case[Verifica el retorno de la funcion al recibir un puntero NULL]");
            utest_startTest(firstTestCase03,firstTestSetup,">Case[Verifica el retorno de la funcion al recibir una longitud invalida]");
            utest_printStatistics("initEmployees()");
            // End Group 01
            break;

        case 2:
            // Start Group 02
            utest_printStartTesting("addEmployees()");
            utest_init();
            utest_startTest(secondTestCase01,secondTestSetup,">Case[Verifica el retorno de la funcion al agregar correctamente un empleado]");
            utest_startTest(secondTestCase02,secondTestSetup,">Case[Verifica el contenido del array luego de agregar correctamente empleados]");
            utest_startTest(secondTestCase03,secondTestSetup,">Case[Verifica el retorno de la funcion al agregar un empleado de mas]");
            utest_startTest(secondTestCase04,secondTestSetup,">Case[Verifica el retorno de la funcion al recibir un puntero NULL]");
            utest_startTest(secondTestCase05,secondTestSetup,">Case[Verifica el retorno de la funcion al recibir una longitud invalida]");
            utest_printStatistics("addEmployees()");
            // End Group 02
            break;

        case 3:
            // Start Group 03
            utest_printStartTesting("findEmployeeById()");
            utest_init();
            utest_startTest(thirdTestCase01,thirdTestSetup,">Case[Verifica el retorno de la funcion al encontrar un empleado]");
            utest_startTest(thirdTestCase02,thirdTestSetup,">Case[Verifica el contenido del empleado encontrado]");
            utest_startTest(thirdTestCase03,thirdTestSetup,">Case[Verifica el retorno de la funcion al recibir un puntero NULL]");
            utest_startTest(thirdTestCase04,thirdTestSetup,">Case[Verifica el retorno de la funcion al recibir una longitud invalida]");
            utest_startTest(thirdTestCase05,thirdTestSetup,">Case[Verifica el retorno de la funcion al no encontrar un empleado]");
            utest_printStatistics("findEmployeeById()");
            // End Group 03
            break;

        case 4:
            // Start Group 04
            utest_printStartTesting("removeEmployeeById()");
            utest_init();
            utest_startTest(fourthTestCase01,fourthTestSetup,">Case[Verifica el retorno de la funcion al remover correctamente un empleado]");
            utest_startTest(fourthTestCase02,fourthTestSetup,">Case[Verifica el contenido del empleado al eliminarlo]");
            utest_startTest(fourthTestCase03,fourthTestSetup,">Case[Verifica el retorno de la funcion al recibir un puntero NULL]");
            utest_startTest(fourthTestCase04,fourthTestSetup,">Case[Verifica el retorno de la funcion al recibir una longitud invalida]");
            utest_printStatistics("removeEmployeeById()");
            // End Group 04
            break;

        case 5:
            // Start Group 05
            utest_printStartTesting("sortEmployeeByName()");
            utest_init();
            utest_startTest(fifthTestCase01,fifthTestSetup,">Case[Verifica el retorno de la funcion al ordenar correctamente el array]");
            utest_startTest(fifthTestCase02,fifthTestSetup,">Case[Verifica el contenido del array luego de ordenar de manera ascendente]");
            utest_startTest(fifthTestCase03,fifthTestSetup,">Case[Verifica el contenido del array luego de ordenar de manera descendente]");
            utest_startTest(fifthTestCase04,fifthTestSetup,">Case[Verifica el retorno de la funcion al recibir un puntero NULL]");
            utest_startTest(fifthTestCase05,fifthTestSetup,">Case[Verifica el retorno de la funcion al recibir una longitud invalida]");

            utest_printStatistics("sortEmployeeByName()");
            // End Group 05
            break;

    }


}
