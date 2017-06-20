#include <Arduino.h>
#include <LiquidCrystal.h>
#include "reloj.h"
#include "timer.h"


#define SEMAFOROS_STATE_DEFAULT 0
#define SEMAFOROS_STATE_CHANGING 1
#define SEMAFOROS_STATE_SECUNDARYGREEN 2

#define INDEX_ROJO_1 0
#define INDEX_AMARILLO_1 1
#define INDEX_VERDE_1 2
#define INDEX_PEAT_ROJO_1 3
#define INDEX_PEAT_VERDE_1 4
#define INDEX_ROJO_2 5
#define INDEX_AMARILLO_2 6
#define INDEX_VERDE_2 7
#define INDEX_PEAT_ROJO_2 8
#define INDEX_PEAT_VERDE_2 9



/// Aclaraciones respecto de los define de las luces leds:
/// Las letras R, A, V representan los Leds Rojo, Amarillo y Verde respectivamente.
/// El agregado _P indican que esos leds corresponden al semaforo peatonal
/// El agregado _DOS indican que corresponden a los leds del semaforo secundario (tanto vehicular como peatonal)
///
/// Luces Semaforo Peatonal Principal:
#define R_P 8
#define V_P 9
/// Luces Semaforo Principal:
#define R 10
#define A 11
#define V 12

/// Luces Semaforo Peatonal Secundario:
#define R_P_DOS 2
#define V_P_DOS 3
/// Luces Semaforo Secundario:
#define R_DOS 4
#define A_DOS 5
#define V_DOS 6

/// Boton de demanda de cruce peatonal:
#define BOTON 0
/// Sensor de vehiculo en calle secundaria:
#define SENSOR 1

/// Cantidad total de luces led por semaforo:
#define LEDSQTY 5

/// Prototipos de funciones a utilizar:
void setStatus(int status);

/// Se define array de uso global con los leds ordenados por grupos (Posic 0-3, 4-5 y 6-9)
int arrayLeds[SIZE] = {V, R_P, R_DOS, V_P_DOS, A, A_DOS, V_DOS, R_P_DOS, R, V_P};
int arrayStatus[SIZE] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0}; /// Se define el estado de los leds a su valor inicial o por defecto.


/// Variables globales auxiliares:
unsigned int intervalo = 500;
unsigned long marcaTiempo = 0;
int flag = 0;

//Prototipo de funciones:
void writeStatus(int posicionInicio, int posicionFin, int status);
void parpadeo(int led);

void semaforo_setup()
{
    /// 


    /// Se inicializan los PINES correspondientes a todos los leds definidos en el array como salida digital.
    for (int i = 0; i < LEDSQTY; i++)
    {
        pinMode(arrayLeds[i], OUTPUT);
        digitalWrite(arrayLeds[i], arrayStatus[i]);
    }

    /// Se inicializan los PINES correspondientes a boton y sensor como entrada digital.
    pinMode(BOTON, INPUT);
    pinMode(SENSOR, INPUT);
}

void semaforo_loop()
{
    if (digitalRead(BOTON) == 0)
    {
        cambio(0);
        /// marcaTiempo=millis();
        /// if ( (millis()-marcaTiempo) > 700 )
        delay(700);
        cambio(1);
    }
}

void cambio(int estado)
{
    int verde = 0;
    int verdePeaton = 3;
    int amarillo = 4;
    int pivot = 5;

    if (estado == 1)
    {
        verde = 6;
        verdePeaton = 9;
        amarillo = 5;
        pivot = 3;
    }

    marcaTiempo = millis() + 500; /// Al detectar que se presiono el boton esta linea agrega 2 segundos (+ el tiempo del intervalo) al inicio de la secuencia de cambios de luces del semaforo.
    while (flag < 7)
    {
        if ((millis() - marcaTiempo) > intervalo)
        {
            marcaTiempo = millis();
            if (flag < 5)
                parpadeo(verde);
            if (flag > 1)
                parpadeo(verdePeaton);
            if (flag == 4)
                parpadeo(amarillo);
            flag++;
        }
    }
    flag = 0;
    writeStatus(0, pivot, 0 + estado);
    writeStatus(pivot + 1, 9, 1 - estado);
}

void writeStatus(int posicionInicio, int posicionFin, int status)
{
    for (int i = posicionInicio; i <= posicionFin; i++) // cambia el estado de los leds desde la posicion inicio hasta la posicion fin
        digitalWrite(arrayLeds[i], status);             // cambia el estado de los leds (encendido/apagado) segun el valor indicado en el arrayStatus
}

void parpadeo(int led)
{
    if (arrayStatus[led] == 0)
        arrayStatus[led] = 1;
    else
        arrayStatus[led] = 0;
    digitalWrite(arrayLeds[led], arrayStatus[led]);
}







void ledsOnOff(*SemaforoStruct semaforo, int rojo, int amarillo, int verde, int rojoPeatonal, int verdePeatonal)
{
    for (int i = 0; i < LEDSQTY; i++)
        digitalWrite(arrayLeds[i], arrayStatus[i]);
    
    semaforo->rojo = rojo;
    semaforo->amarillo = amarillo;
    semaforo->verde = verde;
    semaforo->rojoPeatonal = rojoPeatonal;
    semaforo->verdePeatonal = verdePeatonal;
}




void semaforoStatusSet(*SemaforoStruct semaforo, int rojo, int amarillo, int verde, int rojoPeatonal, int verdePeatonal)
{
    semaforo->rojo = rojo;
    semaforo->amarillo = amarillo;
    semaforo->verde = verde;
    semaforo->rojoPeatonal = rojoPeatonal;
    semaforo->verdePeatonal = verdePeatonal;
}

