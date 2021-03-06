/*.$file${.::blinky.ino} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*
* Model: Zumo_blinky.qm
* File:  ${.::blinky.ino}
*
* This code has been generated by QM 5.0.0 <www.state-machine.com/qm/>.
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
/*.$endhead${.::blinky.ino} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
#include "qpn.h"     // QP-nano framework

//============================================================================
// declare all AO classes...
/*.$declare${AOs::Blinky} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*.${AOs::Blinky} ..........................................................*/
typedef struct Blinky {
/* protected: */
    QActive super;
} Blinky;

/* protected: */
static QState Blinky_initial(Blinky * const me);
static QState Blinky_off(Blinky * const me);
static QState Blinky_on(Blinky * const me);
/*.$enddecl${AOs::Blinky} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
//...

// AO instances and event queue buffers for them...
Blinky AO_Blinky;
static QEvt l_blinkyQSto[10]; // Event queue storage for Blinky
//...

//============================================================================
// QF_active[] array defines all active object control blocks ----------------
QActiveCB const Q_ROM QF_active[] = {
    { (QActive *)0,           (QEvt *)0,        0U                  },
    { (QActive *)&AO_Blinky,  l_blinkyQSto,     Q_DIM(l_blinkyQSto) }
};

//============================================================================
// various constants for the application...
enum {
    BSP_TICKS_PER_SEC = 100, // number of system clock ticks in one second
    LED_L = LED_BUILTIN      // the pin number of the on-board LED (L)
};

//............................................................................
void setup() {
    // initialize the QF-nano framework
    QF_init(Q_DIM(QF_active));

    // initialize all AOs...
    QActive_ctor(&AO_Blinky.super, Q_STATE_CAST(&Blinky_initial));

    // initialize the hardware used in this sketch...
    pinMode(LED_L, OUTPUT); // set the LED-L pin to output
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
/*.$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*. Check for the minimum required QP version */
#if (QP_VERSION < 670U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpn version 6.7.0 or higher required
#endif
/*.$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/*.$define${AOs::Blinky} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/
/*.${AOs::Blinky} ..........................................................*/
/*.${AOs::Blinky::SM} ......................................................*/
static QState Blinky_initial(Blinky * const me) {
    /*.${AOs::Blinky::SM::initial} */
    QActive_armX((QActive *)me, 0U, BSP_TICKS_PER_SEC,
        BSP_TICKS_PER_SEC/2U);
    // Only the second BSP_TICKS_PER_SEC has an effect.
    return Q_TRAN(&Blinky_off);
}
/*.${AOs::Blinky::SM::off} .................................................*/
static QState Blinky_off(Blinky * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*.${AOs::Blinky::SM::off} */
        case Q_ENTRY_SIG: {
            digitalWrite(LED_L, LOW);
            status_ = Q_HANDLED();
            break;
        }
        /*.${AOs::Blinky::SM::off::Q_TIMEOUT} */
        case Q_TIMEOUT_SIG: {
            status_ = Q_TRAN(&Blinky_on);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}
/*.${AOs::Blinky::SM::on} ..................................................*/
static QState Blinky_on(Blinky * const me) {
    QState status_;
    switch (Q_SIG(me)) {
        /*.${AOs::Blinky::SM::on} */
        case Q_ENTRY_SIG: {
            digitalWrite(LED_L, HIGH);
            status_ = Q_HANDLED();
            break;
        }
        /*.${AOs::Blinky::SM::on::Q_TIMEOUT} */
        case Q_TIMEOUT_SIG: {
            status_ = Q_TRAN(&Blinky_off);
            break;
        }
        default: {
            status_ = Q_SUPER(&QHsm_top);
            break;
        }
    }
    return status_;
}
/*.$enddef${AOs::Blinky} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
//...
