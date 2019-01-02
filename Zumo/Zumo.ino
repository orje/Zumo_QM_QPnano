/*$file${.::Zumo.ino} ######################################################*/
/*
* Model: Zumo.qm
* File:  ${.::Zumo.ino}
*
* This code has been generated by QM 4.3.1 (https://www.state-machine.com/qm).
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
/*$endhead${.::Zumo.ino} ###################################################*/
#include "qpn.h" // QP-nano framework
#include "Arduino.h" // Arduino API

#include <Wire.h>
#include <Zumo32U4.h>

//============================================================================
// declare all AO classes...
/*$declare${AOs::Zumo} #####################################################*/
/*${AOs::Zumo} .............................................................*/
typedef struct Zumo {
/* protected: */
    QActive super;

/* private: */
    uint8_t leftBarrier;
    uint8_t rightBarrier;
    int16_t leftSpeed;
    int16_t rightSpeed;
} Zumo;

/* protected: */
static QState Zumo_initial(Zumo * const me);
static QState Zumo_run(Zumo * const me);
static QState Zumo_control(Zumo * const me);
static QState Zumo_accelerate(Zumo * const me);
static QState Zumo_drive(Zumo * const me);
static QState Zumo_turn(Zumo * const me);
/*$enddecl${AOs::Zumo} #####################################################*/
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
        { (QActive *)0,           (QEvt *)0,      0U                },
        { (QActive *)&AO_Zumo,    l_zumoQSto,     Q_DIM(l_zumoQSto) }
};

//============================================================================
// various constants for the application...
enum {
    BSP_TICKS_PER_SEC = 100 // number of system clock ticks in one second
};

// various signals for the application...
enum {
    BUTTON_SIG = Q_USER_SIG, // end of data
    ACC_SIG,
    DRIVE_SIG,
    TURN_SIG
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
/* Check for the minimum required QP version */
#if (QP_VERSION < 630U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpn version 6.3.0 or higher required
#endif

/*$define${AOs::Zumo} ######################################################*/
/*${AOs::Zumo} .............................................................*/
/*${AOs::Zumo::SM} .........................................................*/
static QState Zumo_initial(Zumo * const me) {
    /*${AOs::Zumo::SM::initial} */
    lcd.print("press A");
    return Q_TRAN(&Zumo_run);
}
/*${AOs::Zumo::SM::run} ....................................................*/
static QState Zumo_run(Zumo * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*${AOs::Zumo::SM::run} */
        case Q_ENTRY_SIG: {
            if (buttonA.isPressed()) {
                QACTIVE_POST((QActive *)me,
                BUTTON_SIG, 0);
                }

            QActive_armX((QActive *)me,
                0U, BSP_TICKS_PER_SEC, 0U);
            status_ = Q_HANDLED();
            break;
        }
        /*${AOs::Zumo::SM::run} */
        case Q_EXIT_SIG: {
            QActive_disarmX((QActive *)me, 0U);
            status_ = Q_HANDLED();
            break;
        }
        /*${AOs::Zumo::SM::run::BUTTON} */
        case BUTTON_SIG: {
            lcd.clear();
            status_ = Q_TRAN(&Zumo_control);
            break;
        }
        /*${AOs::Zumo::SM::run::Q_TIMEOUT} */
        case Q_TIMEOUT_SIG: {
            status_ = Q_TRAN(&Zumo_run);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}
/*${AOs::Zumo::SM::run::control} ...........................................*/
static QState Zumo_control(Zumo * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*${AOs::Zumo::SM::run::control} */
        case Q_ENTRY_SIG: {
            proxSensors.read();
            me->leftBarrier = proxSensors.countsFrontWithLeftLeds();
            me->rightBarrier = proxSensors.countsFrontWithRightLeds();

            if (
                me->leftBarrier <= 1
                && me->rightBarrier <= 1) {
                    QACTIVE_POST((QActive *)me, ACC_SIG, 0);
                    }
            else if (
                1 < me->leftBarrier
                && me->leftBarrier <= 6
                && 1 < me->rightBarrier
                && me->rightBarrier <= 6) {
                    QACTIVE_POST((QActive *)me, DRIVE_SIG, 0);
                    }
            else if (
                me->leftBarrier == 0
                && me->rightBarrier == 0) {
                    QACTIVE_POST((QActive *)me, TURN_SIG, 0);
                    }

            QActive_armX((QActive *)me,
                0U, BSP_TICKS_PER_SEC, 0U);
            status_ = Q_HANDLED();
            break;
        }
        /*${AOs::Zumo::SM::run::control} */
        case Q_EXIT_SIG: {
            QActive_disarmX((QActive *)me, 0U);
            status_ = Q_HANDLED();
            break;
        }
        /*${AOs::Zumo::SM::run::control::Q_TIMEOUT} */
        case Q_TIMEOUT_SIG: {
            status_ = Q_TRAN(&Zumo_control);
            break;
        }
        /*${AOs::Zumo::SM::run::control::ACC} */
        case ACC_SIG: {
            status_ = Q_TRAN(&Zumo_accelerate);
            break;
        }
        /*${AOs::Zumo::SM::run::control::DRIVE} */
        case DRIVE_SIG: {
            status_ = Q_TRAN(&Zumo_drive);
            break;
        }
        /*${AOs::Zumo::SM::run::control::TURN} */
        case TURN_SIG: {
            status_ = Q_TRAN(&Zumo_turn);
            break;
        }
        default: {
            status_ = Q_SUPER(&Zumo_run);
            break;
        }
    }
    return status_;
}
/*${AOs::Zumo::SM::run::control::accelerate} ...............................*/
static QState Zumo_accelerate(Zumo * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*${AOs::Zumo::SM::run::control::accelerate} */
        case Q_ENTRY_SIG: {
            me->leftSpeed = me->leftSpeed + 50;
            me->rightSpeed = me->rightSpeed + 50;

            motors.setSpeeds(me->leftSpeed, me->rightSpeed);
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&Zumo_control);
            break;
        }
    }
    return status_;
}
/*${AOs::Zumo::SM::run::control::drive} ....................................*/
static QState Zumo_drive(Zumo * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*${AOs::Zumo::SM::run::control::drive} */
        case Q_ENTRY_SIG: {
            me->leftSpeed = -18 * pow((me->rightBarrier - 1),2) + 400;
            me->rightSpeed = -18 * pow((me->leftBarrier - 1),2) + 400;
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&Zumo_control);
            break;
        }
    }
    return status_;
}
/*${AOs::Zumo::SM::run::control::turn} .....................................*/
static QState Zumo_turn(Zumo * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*${AOs::Zumo::SM::run::control::turn} */
        case Q_ENTRY_SIG: {
            motors.setSpeeds(50U, 0U);
            status_ = Q_HANDLED();
            break;
        }
        default: {
            status_ = Q_SUPER(&Zumo_control);
            break;
        }
    }
    return status_;
}
/*$enddef${AOs::Zumo} ######################################################*/
//...
