#include <iostream>

#include "../move.hpp"
#include "../type.hpp"

class MoveTest {
 public:
  void runtests() {
    //testDefaultConstructor();
    test_getName();
    test_setName();
    test_getPower();
    test_setPower();
    test_getEffect();
    test_setEffect();
    // test_getType();
    // test_setType();
  }

 private:
  // void testDefaultConstructor() {
  //   {
  //     Move move;
  //     if (move != Move("Struggle", 50, 100, "Recoil 50", "Normal")) {
  //       std::cout << "Test Default constructor failed" << std::endl;
  //     }
  //   }
  // }
  void test_getName() {
    Move move("Fire Blast", 110, 85, "May burn the target", "Fire");

    if (move.get_name() != "Fire Blast") {
      std::cout << "Test GetName failed!" << std::endl;
    }
  }

  void test_setName() {
    Move move;

    move.set_name("Thunderbolt");
    if (move.get_name() != "Thunderbolt") {
      std::cout << "test_setName failed!" << std::endl;
    }
  }

  void test_getPower() {
    Move move("Fire Blast", 110, 85, "May burn the target", "Fire");

    if (move.get_power() != 110) {
      std::cout << "Test get_power failed!" << std::endl;
    }
  }

  void test_setPower() {
    Move move;

    move.set_power(90);
    if (move.get_power() != 90) {
      std::cout << "test_setPower failed!" << std::endl;
    }
  }


  void test_getEffect() {
    Move move("Fire Blast", 110, 85, "May burn the target", "Fire");

    if (move.get_effect() != "May burn the target") {
      std::cout << "test_getEffect failed! Unexpected effect." << std::endl;
    }
  }

  void test_setEffect() {
    Move move;

    move.set_effect("Paralyze the target");
    if (move.get_effect() != "Paralyze the target") {
      std::cout << "test_setEffect failed! Unexpected effect." << std::endl;
    }
  }

  // void test_getType() {
  //   Move move("Fire Blast", 110, 85, "May burn the target", "Fire");

  //   if (move.get_type() != "Fire") {
  //     std::cout << "test_getType failed! Unexpected type." << std::endl;
  //   }
  // }

  // void test_setType() {
  //   Move move;
  //   Type type("Normal");

  //   move.set_type("Normal");
  //   if (move.get_type() != type) {
  //     std::cout << "test_setType failed! Unexpected type." << std::endl;
  //   }
  // }

};

int main() {
  MoveTest test;
  test.runtests();

  return 0;
}
