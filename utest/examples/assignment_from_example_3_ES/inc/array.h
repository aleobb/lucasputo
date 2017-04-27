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

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}typedef employee;

int sortEmployeeByName(employee* pEmployee, int length, int order);
employee* findEmployeeById(employee* pEmployee, int length,int id);
int printEmployees(employee* pEmployee, int length);
int addEmployee(employee* pEmployee, int length, int id, char name[],char lastName[],float salary,int sector);
int removeEmployee(employee* pEmployee, int length, int id);
int initEmployees(employee* pEmployee, int length);
