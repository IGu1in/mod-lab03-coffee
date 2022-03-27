// Copyright 2022 GHA Test Team

#include <gtest/gtest.h>
#include "Automata.h"

using std::invalid_argument;
using std::logic_error;

TEST(test1, state_accept) {
 Automata machine = Automata();
 machine.on();
 machine.coin(100);
 States res = machine.getState();
 EXPECT_EQ(Accept, res);
}

TEST(test2, index_1) {
 Automata machine = Automata();
 machine.on();
 int res = machine.choice("Latte");
 EXPECT_EQ(1, res);
}

TEST(test3, check_true) {
 Automata machine = Automata();
 machine.on();
 machine.coin(100);
 bool res = machine.check(1);
 EXPECT_EQ(true, res);
}

TEST(test4, check_false) {
 Automata machine = Automata();
 machine.on();
 machine.coin(10);
 bool res = machine.check(1);
 EXPECT_EQ(false, res);
}

TEST(test5, logic_error) {
 Automata machine = Automata();
 try {
  machine.off();
 }
 catch(logic_error err) {
  ASSERT_STREQ("Error, invalid operation", err.what());
 }
}
