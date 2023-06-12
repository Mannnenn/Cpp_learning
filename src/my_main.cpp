#include <stdio.h>
#include <iostream>
#include <my_class.h>

int main(){
  std::cout << "start main function" << std::endl;

  my_class test_instance;
  test_instance.say_hello();

  return 0;
}
