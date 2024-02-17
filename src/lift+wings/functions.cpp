#include "main.h"

void liftUp() {
  lift.set_value(true);
}

void liftDown() {
  lift.set_value(false);
} 

void horWingsOut() {
  horWings.set_value(true);
}

void horWingsIn() {
  horWings.set_value(false);
}

void vertWingsDown() {
  vertWings.set_value(true);
}

void vertWingsUp() {
  vertWings.set_value(false);
}