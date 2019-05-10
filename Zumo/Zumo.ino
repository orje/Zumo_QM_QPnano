/*$file${.::Zumo.ino} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*
* Model: Zumo.qm
* File:  ${.::Zumo.ino}
*
* This code has been generated by QM 4.5.0 (https://www.state-machine.com/qm).
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
    uint8_t leftProx;
    uint8_t rightProx;
    uint16_t leftSpeed;
    uint16_t rightSpeed;
} Zumo;

/* protected: */
static QState Zumo_initial(Zumo * const me);
static QState Zumo_hmi(Zumo * const me);
static QState Zumo_measure_decide(Zumo * const me);
static QState Zumo_acc(Zumo * const me);
static QState Zumo_ctrl(Zumo * const me);
static QState Zumo_turnRight(Zumo * const me);
static QState Zumo_turnLeft(Zumo * const me);
/*$enddecl${AOs::Zumo} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
//...

// AO instances, other objects and event queue buffers for them...
Zumo AO_Zumo;

// Other objects
Zumo32U4LCD lcd;
Zumo32U4ButtonA buttonA;
Zumo32U4ProximitySensors proxSensors;
Zumo32U4Motors motors;
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
    BSP_TICKS_PER_SEC = 100, // number of system clock ticks in one second

    // https://rechneronline.de/funktionsgraphen/
    // Funktionsgleichung: y = a * (x - d) + e
    aR = -80,  // Steigung f�r's Regeln
    aA = -133, // Steigung f�r's Ausweichen
    d = 1U,    // Scheitelpunkt x
    e = 400U,  // Scheitelpunkt y

    accSpeed = 50U,
    turnSpeed = 80U // speed for turning around
};

// various signals for the application...
enum {
    BUTTON_SIG = Q_USER_SIG, // end of data
    DRIVE_SIG
};

//............................................................................
void setup() {
    // initialize the QF-nano framework
    QF_init(Q_DIM(QF_active));

    // initialize all AOs...
    QActive_ctor(&AO_Zumo.super, Q_STATE_CAST(&Zumo_initial));

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

// set the output-compare register based on the desired tick frequency
OCR4A  = (F_CPU / BSP_TICKS_PER_SEC / 1024U) - 1U;
}

//............................................................................
void QV_onIdle(void) {   // called with interrupts DISABLED
    // Put the CPU and peripherals to the low-power mode. You might
    // need to customize the clock management for your application,
    // see the datasheet for your particular AVR MCU.
    SMCR = (0 << SM0) | (1 << SE); // idle mode, adjust to your project
    QV_CPU_SLEEP();  // atomically go to sleep and enable interrupts
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
    return Q_TRAN(&Zumo_hmi);
}
/*${AOs::Zumo::SM::hmi} ....................................................*/
static QState Zumo_hmi(Zumo * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*${AOs::Zumo::SM::hmi} */
        case Q_ENTRY_SIG: {
            if (buttonA.isPressed()) {
                lcd.clear();
                QACTIVE_POST((QActive *)me,
                BUTTON_SIG, 0);
                }

            QActive_armX((QActive *)me,
                0U, BSP_TICKS_PER_SEC, 0U);
            status_ = Q_HANDLED();
            break;
        }
        /*${AOs::Zumo::SM::hmi} */
        case Q_EXIT_SIG: {
            QActive_disarmX((QActive *)me, 0U);
            status_ = Q_HANDLED();
            break;
        }
        /*${AOs::Zumo::SM::hmi::Q_TIMEOUT} */
        case Q_TIMEOUT_SIG: {
            status_ = Q_TRAN(&Zumo_hmi);
            break;
        }
        /*${AOs::Zumo::SM::hmi::BUTTON} */
        case BUTTON_SIG: {
            status_ = Q_TRAN(&Zumo_measure_decide);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}
/*${AOs::Zumo::SM::hmi::measure_decide} ....................................*/
static QState Zumo_measure_decide(Zumo * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*${AOs::Zumo::SM::hmi::measure_decide} */
        case Q_ENTRY_SIG: {
            proxSensors.read();
            me->leftProx =
                proxSensors.countsFrontWithLeftLeds();
            me->rightProx =
                proxSensors.countsFrontWithRightLeds();

            QACTIVE_POST((QActive *)me, DRIVE_SIG, 0);

            QActive_armX((QActive *)me,
                0U, BSP_TICKS_PER_SEC, 0U);
            status_ = Q_HANDLED();
            break;
        }
        /*${AOs::Zumo::SM::hmi::measure_decide} */
        case Q_EXIT_SIG: {
            QActive_disarmX((QActive *)me, 0U);
            status_ = Q_HANDLED();
            break;
        }
        /*${AOs::Zumo::SM::hmi::measure_decide::DRIVE} */
        case DRIVE_SIG: {
            /*${AOs::Zumo::SM::hmi::measure_decide::DRIVE::[prox==0]} */
            if (me->leftProx == 0
                && me->rightProx == 0)
            {
                /*${AOs::Zumo::SM::hmi::measure_decide::DRIVE::[prox==0]::[v<e]} */
                if (me->leftSpeed < e
                    && me->rightSpeed < e)
                {
                    status_ = Q_TRAN(&Zumo_acc);
                }
                else {
                    status_ = Q_UNHANDLED();
                }
            }
            /*${AOs::Zumo::SM::hmi::measure_decide::DRIVE::[prox>=1&&<=5]} */
            else if (me->leftProx >= 1U
                     && me->rightProx >= 1U
                     && me->leftProx <= 5U
                     && me->rightProx <= 5U)
            {
                status_ = Q_TRAN(&Zumo_ctrl);
            }
            /*${AOs::Zumo::SM::hmi::measure_decide::DRIVE::[prox==6]} */
            else if (me->leftProx == 6U
                     || me->rightProx == 6U)
            {
                /*${AOs::Zumo::SM::hmi::measure_decide::DRIVE::[prox==6]::[left==6]} */
                if (me->leftProx == 6U) {
                    status_ = Q_TRAN(&Zumo_turnRight);
                }
                /*${AOs::Zumo::SM::hmi::measure_decide::DRIVE::[prox==6]::[else]} */
                else {
                    status_ = Q_TRAN(&Zumo_turnLeft);
                }
            }
            else {
                status_ = Q_UNHANDLED();
            }
            break;
        }
        /*${AOs::Zumo::SM::hmi::measure_decide::Q_TIMEOUT} */
        case Q_TIMEOUT_SIG: {
            status_ = Q_TRAN(&Zumo_measure_decide);
            break;
        }
        default: {
            status_ = Q_SUPER(&Zumo_hmi);
            break;
        }
    }
    return status_;
}
/*${AOs::Zumo::SM::hmi::measure_decide::acc} ...............................*/
static QState Zumo_acc(Zumo * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*${AOs::Zumo::SM::hmi::measure_decide::acc} */
        case Q_ENTRY_SIG: {
            me->leftSpeed = me->leftSpeed + accSpeed;
            me->rightSpeed = me->rightSpeed + accSpeed;

            motors.setSpeeds(me->leftSpeed, me->rightSpeed);
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&Zumo_measure_decide);
            break;
        }
    }
    return status_;
}
/*${AOs::Zumo::SM::hmi::measure_decide::ctrl} ..............................*/
static QState Zumo_ctrl(Zumo * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*${AOs::Zumo::SM::hmi::measure_decide::ctrl} */
        case Q_ENTRY_SIG: {
            me->leftSpeed = aR * (me->rightProx - d) + e;
            me->rightSpeed = aR * (me->leftProx - d) + e;

            motors.setSpeeds(me->leftSpeed, me->rightSpeed);
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&Zumo_measure_decide);
            break;
        }
    }
    return status_;
}
/*${AOs::Zumo::SM::hmi::measure_decide::turnRight} .........................*/
static QState Zumo_turnRight(Zumo * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*${AOs::Zumo::SM::hmi::measure_decide::turnRight} */
        case Q_ENTRY_SIG: {
            motors.setSpeeds(turnSpeed, 0U);
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&Zumo_measure_decide);
            break;
        }
    }
    return status_;
}
/*${AOs::Zumo::SM::hmi::measure_decide::turnLeft} ..........................*/
static QState Zumo_turnLeft(Zumo * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*${AOs::Zumo::SM::hmi::measure_decide::turnLeft} */
        case Q_ENTRY_SIG: {
            motors.setSpeeds(0U, turnSpeed);
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&Zumo_measure_decide);
            break;
        }
    }
    return status_;
}
/*$enddef${AOs::Zumo} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
//...
