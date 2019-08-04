/*$file${.::Zumo.ino} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*
* Model: Zumo.qm
* File:  ${.::Zumo.ino}
*
* This code has been generated by QM 4.5.1 (https://www.state-machine.com/qm).
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*/
/*$endhead${.::Zumo.ino} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
#include "qpn.h" // QP-nano framework
#include "Arduino.h" // Arduino API

#include <Wire.h>
#include <Zumo32U4.h>

//============================================================================
// declare all AO classes...
/*$declare${AOs::Zumo} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*${AOs::Zumo} .............................................................*/
typedef struct Zumo {
/* protected: */
    QActive super;

/* private: */
    uint8_t leftProx = 0;;
    uint8_t rightProx = 0;;
    uint16_t leftSpeed = 0;;
    uint16_t rightSpeed = 0;;
} Zumo;

/* protected: */
static QState Zumo_initial(Zumo * const me);
static QState Zumo_start(Zumo * const me);
static QState Zumo_drive_control(Zumo * const me);
static QState Zumo_drive_backwards(Zumo * const me);
static QState Zumo_turn(Zumo * const me);
static QState Zumo_drive(Zumo * const me);
static QState Zumo_ctrl(Zumo * const me);
static QState Zumo_turnRight(Zumo * const me);
static QState Zumo_turnLeft(Zumo * const me);
static QState Zumo_ctrl(Zumo * const me);
/*$enddecl${AOs::Zumo} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
//...

// AO instances, other objects and event queue buffers for them...
Zumo AO_Zumo;

// Other objects
Zumo32U4LCD lcd;
Zumo32U4ButtonA buttonA;
Zumo32U4ProximitySensors proxSensors;
Zumo32U4Motors motors;
LSM303 compass;
// Zumo32U4Encoders encoders;

static QEvt l_zumoQSto[10]; // Event queue storage for Zumo
//...

//============================================================================
// QF_active[] array defines all active object control blocks ----------------
QActiveCB const Q_ROM QF_active[] = {
        {(QActive *)0,        (QEvt *)0,  0U               },
        {(QActive *)&AO_Zumo, l_zumoQSto, Q_DIM(l_zumoQSto)}
};

//============================================================================
// various constants for the application...
enum {
    BSP_TICKS_PER_SEC = 100U, // number of system clock ticks in one second

    collisionDetect = -1400,  // experimental threshold

    // Funktionsgleichung: y = a * x + e
    a =  -50,                 // Steigung f�r's Regeln
    e = 300U,                 // Scheitelpunkt y

    turnSpeed = 80            // speed for turning around
};

// various signals for the application...
enum {
    BUTTON_SIG = Q_USER_SIG,  // end of data
    COLLISION_SIG,
    FREE_SIG,
    DECIDE_SIG,
    BACK_SIG
};

//............................................................................
void setup() {
    // initialize the QF-nano framework
    QF_init(Q_DIM(QF_active));

    // initialize all AOs...
    QActive_ctor(&AO_Zumo.super, Q_STATE_CAST(&Zumo_initial));

    // init the compass for collision detection
    Wire.begin();
    compass.init();
    compass.enableDefault();

    // init the proximity sensors
    proxSensors.initFrontSensor();
}

//............................................................................
void loop() {
    QF_run(); // run the QF-nano framework
}

//============================================================================
// interrupts...
ISR(TIMER4_COMPA_vect) {
    QF_tickXISR(0); // process time events for tick rate 0
}

//============================================================================
// QF callbacks...
void QF_onStartup(void) {
// 1/1024 prescaler, interrupt enabling...
TCCR4B = (1U << CS43) | (1U << CS41) | (1U << CS40); // CK/1024
TIMSK4 = (1U << OCIE4A); // Interrupt enabled
TCNT4  = 0U;

// set the output-compare register based on the desired tick frequency
OCR4A  = (F_CPU / BSP_TICKS_PER_SEC / 1024U) - 1U;
}

//............................................................................
void QV_onIdle(void) { // called with interrupts DISABLED
    // Put the CPU and peripherals to the low-power mode. You might
    // need to customize the clock management for your application,
    // see the datasheet for your particular AVR MCU.
    SMCR = (0 << SM0) | (1 << SE); // idle mode, adjust to your project
    QV_CPU_SLEEP(); // atomically go to sleep and enable interrupts
}
//............................................................................
void Q_onAssert(char const Q_ROM * const file, int line) {
    // implement the error-handling policy for your application!!!
    QF_INT_DISABLE(); // disable all interrupts
    QF_RESET();  // reset the CPU
}

//============================================================================
// define all AO classes (state machine)...
/*$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/* Check for the minimum required QP version */
#if (QP_VERSION < 650U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpn version 6.5.0 or higher required
#endif
/*$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/*$define${AOs::Zumo} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*${AOs::Zumo} .............................................................*/
/*${AOs::Zumo::SM} .........................................................*/
static QState Zumo_initial(Zumo * const me) {
    /*${AOs::Zumo::SM::initial} */
    lcd.print("press A");
    return Q_TRAN(&Zumo_start);
}
/*${AOs::Zumo::SM::start} ..................................................*/
static QState Zumo_start(Zumo * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*${AOs::Zumo::SM::start} */
        case Q_ENTRY_SIG: {
            if (buttonA.isPressed()) {
                lcd.clear();
                QACTIVE_POST((QActive *)me,
                BUTTON_SIG, 0U);
                }

            QActive_armX((QActive *)me,
                0U, BSP_TICKS_PER_SEC / 10U, 0U);
            status_ = Q_HANDLED();
            break;
        }
        /*${AOs::Zumo::SM::start::BUTTON} */
        case BUTTON_SIG: {
            status_ = Q_TRAN(&Zumo_drive_control);
            break;
        }
        /*${AOs::Zumo::SM::start::Q_TIMEOUT} */
        case Q_TIMEOUT_SIG: {
            status_ = Q_TRAN(&Zumo_start);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}
/*${AOs::Zumo::SM::start::drive_control} ...................................*/
static QState Zumo_drive_control(Zumo * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*${AOs::Zumo::SM::start::drive_control} */
        case Q_ENTRY_SIG: {
            ledGreen(1); // debug
            lcd.clear(); // debug

            compass.read();

            lcd.clear();
            lcd.gotoXY(0, 0);
            lcd.print("x ");
            lcd.print(compass.a.x);
            lcd.gotoXY(0, 1);
            lcd.print("y ");
            lcd.print(compass.a.y);

            if((compass.a.x < collisionDetect) || (compass.a.y < collisionDetect)) {
                QACTIVE_POST((QActive *)me, COLLISION_SIG, 0U);
                }
            else {
                QACTIVE_POST((QActive *)me, FREE_SIG, 0U);
                }

            QActive_armX((QActive *)me,
                0U, BSP_TICKS_PER_SEC / 10U, 0U);
            status_ = Q_HANDLED();
            break;
        }
        /*${AOs::Zumo::SM::start::drive_control::COLLISION} */
        case COLLISION_SIG: {
            ledRed(1);
            ledYellow(0);
            ledGreen(0);
            status_ = Q_TRAN(&Zumo_drive_backwards);
            break;
        }
        /*${AOs::Zumo::SM::start::drive_control::FREE} */
        case FREE_SIG: {
            status_ = Q_TRAN(&Zumo_drive);
            break;
        }
        /*${AOs::Zumo::SM::start::drive_control::Q_TIMEOUT} */
        case Q_TIMEOUT_SIG: {
            status_ = Q_TRAN(&Zumo_drive_control);
            break;
        }
        default: {
            status_ = Q_SUPER(&Zumo_start);
            break;
        }
    }
    return status_;
}
/*${AOs::Zumo::SM::start::drive_control::drive_backwards} ..................*/
static QState Zumo_drive_backwards(Zumo * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*${AOs::Zumo::SM::start::drive_control::drive_backwards} */
        case Q_ENTRY_SIG: {
            motors.setSpeeds(-turnSpeed, -turnSpeed);

            QActive_armX((QActive *)me,
                0U, BSP_TICKS_PER_SEC, 0U);
            status_ = Q_HANDLED();
            break;
        }
        /*${AOs::Zumo::SM::start::drive_control::drive_backwards::Q_TIMEOUT} */
        case Q_TIMEOUT_SIG: {
            ledRed(0);
            ledYellow(1);
            ledGreen(0);
            status_ = Q_TRAN(&Zumo_turn);
            break;
        }
        default: {
            status_ = Q_SUPER(&Zumo_drive_control);
            break;
        }
    }
    return status_;
}
/*${AOs::Zumo::SM::start::drive_control::drive_backwards::turn} ............*/
static QState Zumo_turn(Zumo * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*${AOs::Zumo::SM::start::drive_control::drive_backwards::turn} */
        case Q_ENTRY_SIG: {
            motors.setSpeeds(turnSpeed, -turnSpeed);

            QActive_armX((QActive *)me,
                0U, BSP_TICKS_PER_SEC, 0U);
            status_ = Q_HANDLED();
            break;
        }
        /*${AOs::Zumo::SM::start::drive_control::drive_backwards::turn::Q_TIMEOUT} */
        case Q_TIMEOUT_SIG: {
            ledRed(0);
            ledYellow(0);
            ledGreen(0);

            QACTIVE_POST((QActive *)me, BACK_SIG, 0U);
            status_ = Q_TRAN(&Zumo_turn);
            break;
        }
        /*${AOs::Zumo::SM::start::drive_control::drive_backwards::turn::BACK} */
        case BACK_SIG: {
            status_ = Q_TRAN(&Zumo_drive_control);
            break;
        }
        default: {
            status_ = Q_SUPER(&Zumo_drive_backwards);
            break;
        }
    }
    return status_;
}
/*${AOs::Zumo::SM::start::drive_control::drive} ............................*/
static QState Zumo_drive(Zumo * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*${AOs::Zumo::SM::start::drive_control::drive} */
        case Q_ENTRY_SIG: {
            proxSensors.read();
            me->leftProx =
                proxSensors.countsFrontWithLeftLeds();
            me->rightProx =
                proxSensors.countsFrontWithRightLeds();

            lcd.clear();
            lcd.gotoXY(0, 0);
            lcd.print("l=");
            lcd.print(me->leftProx);
            lcd.print("  r=");
            lcd.print(me->rightProx);

            QACTIVE_POST((QActive *)me, DECIDE_SIG, 0U);
            status_ = Q_HANDLED();
            break;
        }
        /*${AOs::Zumo::SM::start::drive_control::drive::DECIDE} */
        case DECIDE_SIG: {
            /*${AOs::Zumo::SM::start::drive_control::drive::DECIDE::[s<5]} */
            if (me->leftProx < 5U
                && me->rightProx < 5U)
            {
                ledRed(0);
                ledYellow(0);
                ledGreen(1);
                status_ = Q_TRAN(&Zumo_ctrl);
            }
            /*${AOs::Zumo::SM::start::drive_control::drive::DECIDE::[sL>=5]} */
            else if (me->leftProx >= 5U) {
                ledRed(0);
                ledYellow(1);
                ledGreen(0);
                status_ = Q_TRAN(&Zumo_turnRight);
            }
            /*${AOs::Zumo::SM::start::drive_control::drive::DECIDE::[sR>=5]} */
            else if (me->rightProx >= 5U) {
                ledRed(0);
                ledYellow(1);
                ledGreen(0);
                status_ = Q_TRAN(&Zumo_turnLeft);
            }
            else {
                status_ = Q_UNHANDLED();
            }
            break;
        }
        default: {
            status_ = Q_SUPER(&Zumo_drive_control);
            break;
        }
    }
    return status_;
}
/*${AOs::Zumo::SM::start::drive_control::drive::ctrl} ......................*/
static QState Zumo_ctrl(Zumo * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*${AOs::Zumo::SM::start::drive_control::drive::ctrl} */
        case Q_ENTRY_SIG: {
            motors.setSpeeds(turnSpeed, 0U);
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&Zumo_drive);
            break;
        }
    }
    return status_;
}
/*${AOs::Zumo::SM::start::drive_control::drive::turnRight} .................*/
static QState Zumo_turnRight(Zumo * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*${AOs::Zumo::SM::start::drive_control::drive::turnRight} */
        case Q_ENTRY_SIG: {
            motors.setSpeeds(0U, turnSpeed);
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&Zumo_drive);
            break;
        }
    }
    return status_;
}
/*${AOs::Zumo::SM::start::drive_control::drive::turnLeft} ..................*/
static QState Zumo_turnLeft(Zumo * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*${AOs::Zumo::SM::start::drive_control::drive::turnLeft} */
        case Q_ENTRY_SIG: {
            me->leftSpeed = a * me->rightProx + e;
            me->rightSpeed = a * me->leftProx + e;

            motors.setSpeeds(me->leftSpeed, me->rightSpeed);
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&Zumo_drive);
            break;
        }
    }
    return status_;
}
/*$enddef${AOs::Zumo} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
//...
