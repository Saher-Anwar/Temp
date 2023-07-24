//
// Created by saher on 20/07/2023.
//

#ifndef PROSIM_MESSAGE_PASSING_H
#define PROSIM_MESSAGE_PASSING_H
#include "context.h"

void send(context* sender, context* receiver);

void recv(context* receiver, context* sender);
#endif //PROSIM_MESSAGE_PASSING_H
